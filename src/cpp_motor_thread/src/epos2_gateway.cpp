//Implementation of cpp_motor_thread::Epos2Gateway (declared in epos2_gateway.hpp)

#include "cpp_motor_thread/epos2_gateway.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <thread>

#include "Definitions.h"

using namespace std::chrono_literals;

namespace{
    constexpr unsigned short kNodes[] = {1, 2, 3};
    constexpr unsigned int kProfileVelocity = 1000;
    constexpr unsigned int kProfileAccel = 500;
    constexpr unsigned int kProfileDecel = 500;
    constexpr double kQcPerMotorRev = 50.0;                    //encoder quadcounts per motor revolution
    constexpr double kGearRatio = 153.0;                       //gearbox 153:1
    constexpr double kQcPerRev = kQcPerMotorRev * kGearRatio;  //7650 qc per revolution of the gearbox output
    constexpr double kMaxAngle = 25.0 * M_PI / 180.0;          //allowed motion: +-25 deg around 0 (links straight up)
    constexpr int kDriveLimitMarginQc = 10;                    //drive's own limit sits ~0.5 deg outside kMaxAngle
    constexpr long kPositionToleranceQc = 5;                   //~0.24 deg: "target reached" also needs this close
    constexpr auto kMoveTimeout = std::chrono::milliseconds(15000);
    constexpr auto kPollPeriod = std::chrono::milliseconds(10);
    constexpr auto kPublishPeriod = 100ms;

//encoder quadcounts <-> gearbox output angle [rad], 0 qc = 0 rad
double qcToRad(int qc){
    return qc * 2.0 * M_PI / kQcPerRev;
}

long radToQc(double rad){
    return std::lround(rad * kQcPerRev / (2.0 * M_PI));
}

bool withinLimits(double rad){
    return std::isfinite(rad) && std::abs(rad) <= kMaxAngle + 1e-9;
}

bool isKnownNode(unsigned short node){
    return std::find(std::begin(kNodes), std::end(kNodes), node) != std::end(kNodes);
}

//wrapper for errortext
std::string errorText(unsigned int code) {
  char info[256] = {};
  VCS_GetErrorInfo(code, info, static_cast<unsigned short> (sizeof(info)));
  char hex[16];
  std::snprintf(hex, sizeof(hex), "0x%08X", code);
  return std::string(hex) + " " + info;  
}

//wrapper for error checking of maxon motor function
void check(int ok, unsigned int errorCode, const std::string& what){
  if (!ok) throw std::runtime_error(what + " failed: " + errorText(errorCode));
}

//wrapper for node label
std::string nodeLabel(const char* action, unsigned short node) {
  return std::string(action) + " node " + std::to_string(node);
}

//profile value scaled by the travel ratio, at least 1 (EPOS rejects 0)
unsigned int scaled(unsigned int value, double ratio){
    return std::max(1u, static_cast<unsigned int>(std::lround(value * ratio)));
}

} //namespace

namespace cpp_motor_thread{

Epos2Gateway::Epos2Gateway() : Node("epos2_gateway"){

    using namespace std::placeholders;

    char device[] = "EPOS2";
    char protocol[] = "MAXON SERIAL V2";
    char interface[] = "USB";
    char port[] = "USB0";
    unsigned int err = 0;
    handle_ = VCS_OpenDevice(device, protocol, interface, port, &err);
    if(!handle_) {
      throw std::runtime_error("OpenDevice failed (USB permissions or ftdi_sio conflict?): " + errorText(err));
    }

    motor_position_publisher_ = create_publisher<sensor_msgs::msg::JointState>("motor_jointstate", 10);
    timer_ = create_wall_timer(kPublishPeriod, [this](){publishJointStates();});

    profile_position_mode_service_ = create_service<std_srvs::srv::Trigger>("profile_position_mode_srv", 
    [this](const std::shared_ptr<std_srvs::srv::Trigger::Request> request, 
        std::shared_ptr<std_srvs::srv::Trigger::Response> response){prepareProfilePosition(request, response);});

    move_profile_position_action_ = rclcpp_action::create_server<MoveProfilePosition>(
        this,
        "move_profile_position_act",
        std::bind(&Epos2Gateway::handle_goal_move_profile_position, this, _1, _2),
        std::bind(&Epos2Gateway::handle_cancel_move_profile_position, this, _1),
        std::bind(&Epos2Gateway::handle_accepted_move_profile_position, this, _1)
    );

    move_motors_action_ = rclcpp_action::create_server<MoveMotors>(
        this,
        "move_motors_act",
        std::bind(&Epos2Gateway::handle_goal_move_motors, this, _1, _2),
        std::bind(&Epos2Gateway::handle_cancel_move_motors, this, _1),
        std::bind(&Epos2Gateway::handle_accepted_move_motors, this, _1)
    );
}

Epos2Gateway::~Epos2Gateway(){
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    for (auto node : kNodes) VCS_SetDisableState(handle_, node, &err);
    VCS_CloseDevice(handle_, &err);
    std::cout << "Drives disable, device closed" << std::endl;    
}

int Epos2Gateway::getPosition(unsigned short node){
    int pos = 0;
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    check(VCS_GetPositionIs(handle_, node, &pos, &err), err, nodeLabel("GetPositionIs", node));
    return pos;
}

double Epos2Gateway::getPositionRad(unsigned short node){
    return qcToRad(getPosition(node));
}

bool Epos2Gateway::inFault(unsigned short node){
    int fault = 0;
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    check(VCS_GetFaultState(handle_, node, &fault, &err), err, nodeLabel("GetFaultState", node));
    return fault != 0;    
}

void Epos2Gateway::haltMovement(unsigned short node){
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    VCS_HaltPositionMovement(handle_, node, &err);
}

void Epos2Gateway::moveToPosition(unsigned short node, long targetQc, unsigned int velocity,
    unsigned int accel, unsigned int decel){
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    check(VCS_SetPositionProfile(handle_, node, velocity, accel, decel, &err), err,
        nodeLabel("SetPositionProfile", node));
    check(VCS_MoveToPosition(handle_, node, targetQc, 1, 1, &err), err, nodeLabel("MoveToPosition", node));
}

bool Epos2Gateway::targetReached(unsigned short node){
    int reached = 0;
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    check(VCS_GetMovementState(handle_, node, &reached, &err), err, nodeLabel("GetMovementState", node));
    return reached != 0;
}

bool Epos2Gateway::isEnabled(unsigned short node){
    int enabled = 0;
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    check(VCS_GetEnableState(handle_, node, &enabled, &err), err, nodeLabel("GetEnableState", node));
    return enabled != 0;
}

void Epos2Gateway::requireEnabled(unsigned short node){
    if (!isEnabled(node)) {
        throw std::runtime_error(nodeLabel("Drive is not enabled (call profile_position_mode_srv) on", node));
    }
}

bool Epos2Gateway::claimNodes(const std::vector<unsigned short>& nodes){
    std::lock_guard<std::mutex> lock(busy_mutex_);
    for (auto node : nodes){
        if (busy_nodes_.count(node)) return false;
    }
    busy_nodes_.insert(nodes.begin(), nodes.end());
    return true;
}

void Epos2Gateway::releaseNodes(const std::vector<unsigned short>& nodes){
    std::lock_guard<std::mutex> lock(busy_mutex_);
    for (auto node : nodes) busy_nodes_.erase(node);
}


void Epos2Gateway::prepareProfilePosition(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
    std::shared_ptr<std_srvs::srv::Trigger::Response> response){
    (void)request;
    unsigned int err = 0;
    //software position limits of the drive itself (object 0x607D), a backstop
    //behind the +-kMaxAngle checks of the action servers
    int maxLimitQc = static_cast<int>(std::floor(kMaxAngle * kQcPerRev / (2.0 * M_PI))) + kDriveLimitMarginQc;
    int minLimitQc = -maxLimitQc;
    unsigned int written = 0;
    std::string warnings;
    try {
        std::lock_guard<std::mutex> lock(vcs_mutex_);
        for (auto node : kNodes){
            check(VCS_ClearFault(handle_, node, &err), err, nodeLabel("ClearFault", node));
            //a failed limit write is reported but does not keep the drive disabled;
            //the +-25 deg checks of the action servers still apply
            if (!VCS_SetObject(handle_, node, 0x607D, 0x01, &minLimitQc, 4, &written, &err) ||
                !VCS_SetObject(handle_, node, 0x607D, 0x02, &maxLimitQc, 4, &written, &err)) {
                const std::string warning = nodeLabel("Drive position limits not set on", node) + ": " + errorText(err);
                RCLCPP_WARN(get_logger(), "%s", warning.c_str());
                warnings += "; " + warning;
            }
            check(VCS_SetEnableState(handle_, node, &err), err, nodeLabel("SetEnableState", node));
            check(VCS_ActivateProfilePositionMode(handle_, node, &err), err, 
                    nodeLabel("ActivateProfilePositionMode", node));
            check(VCS_SetPositionProfile(handle_, node, kProfileVelocity, kProfileAccel, kProfileDecel, &err), 
                    err, nodeLabel("SetProfilePosition", node));
        }
    } catch(const std::exception& e){
        //report the failing node instead of letting the exception stop the node
        RCLCPP_ERROR(get_logger(), "Profile position mode failed: %s", e.what());
        response->success = 0;
        response->message = e.what();
        return;
    }
    response->success = 1;
    response->message = "Successfully entered profile position mode" + warnings;
}

void Epos2Gateway::publishJointStates(){
    sensor_msgs::msg::JointState message;
    message.header.stamp = now();
    std::string positions;
    for (auto node : kNodes){
        //a node that cannot be read is left out; the others are still published
        try {
            const double position = getPositionRad(node);
            message.name.push_back("motor" + std::to_string(node));
            message.position.push_back(position);
            char text[64];
            std::snprintf(text, sizeof(text), " %s %.4f rad", message.name.back().c_str(), position);
            positions += text;
        } catch(const std::exception& e){
            RCLCPP_ERROR_THROTTLE(get_logger(), *get_clock(), 1000, "%s", e.what());
        }
    }
    //one throttled line for all nodes (a throttle inside the loop would only ever show the first node)
    if (!positions.empty()) RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 1000, "position%s", positions.c_str());
    if (!message.name.empty()) motor_position_publisher_->publish(message);
}

void Epos2Gateway::moveProfilePosition(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle){

    RCLCPP_INFO(get_logger(), "Executing goal");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<MoveProfilePosition::Feedback>();
    auto result = std::make_shared<MoveProfilePosition::Result>();

    
    try {
        //relative goals become absolute here, so the limit check uses the real target
        const double target = goal->absolute ? goal->goal_position : getPositionRad(goal->node) + goal->goal_position;
        if (!withinLimits(target)) {
            throw std::runtime_error(nodeLabel("Target outside the +-25 deg limit on", goal->node));
        }
        requireEnabled(goal->node);
        const long targetQc = radToQc(target);
        moveToPosition(goal->node, targetQc, kProfileVelocity, kProfileAccel, kProfileDecel);
        const auto deadline = std::chrono::steady_clock::now() + kMoveTimeout;

    
        while (true) {
            if (!rclcpp::ok()) {
                haltMovement(goal->node);
                break;
            }
            if (goal_handle->is_canceling()){
                haltMovement(goal->node);
                result->end_position = getPositionRad(goal->node);
                goal_handle->canceled(result);
                RCLCPP_INFO(get_logger(), "Goal Canceled");
                break;
            }

            const int positionQc = getPosition(goal->node);
            feedback->current_position = qcToRad(positionQc);
            goal_handle->publish_feedback(feedback);

            if (targetReached(goal->node) && std::labs(positionQc - targetQc) <= kPositionToleranceQc) {
                result->end_position = qcToRad(positionQc);
                goal_handle->succeed(result);
                RCLCPP_INFO(get_logger(), "Goal Succeeded");
                break;
            }

            if (std::chrono::steady_clock::now() > deadline) {
                haltMovement(goal->node);
                throw std::runtime_error(nodeLabel("Move timed out on", goal->node) + " at " +
                    std::to_string(positionQc) + " qc, target " + std::to_string(targetQc) + " qc");
            
            }
            std::this_thread::sleep_for(kPollPeriod);
        }
    } catch(const std::exception& e){
        RCLCPP_ERROR(get_logger(), "Move failed: %s", e.what());
        if (rclcpp::ok()) goal_handle->abort(result);
    }   
    releaseNodes({goal->node});
}

rclcpp_action::GoalResponse Epos2Gateway::handle_goal_move_profile_position(const rclcpp_action::GoalUUID & uuid,    
    std::shared_ptr<const MoveProfilePosition::Goal> goal){
        RCLCPP_INFO(get_logger(), "Received goal request, move node: %i, to %s position: %.4f rad",
            goal->node, goal->absolute ? "absolute" : "relative", goal->goal_position);
        (void)uuid;
        if (!isKnownNode(goal->node)) {
            RCLCPP_WARN(get_logger(), "Rejected goal: unknown node %i", goal->node);
            return rclcpp_action::GoalResponse::REJECT;
        }
        if (!std::isfinite(goal->goal_position) || (goal->absolute && !withinLimits(goal->goal_position))) {
            RCLCPP_WARN(get_logger(), "Rejected goal: goal_position must be finite and within +-25 deg");
            return rclcpp_action::GoalResponse::REJECT;
        }
        if (!claimNodes({goal->node})) {
            RCLCPP_WARN(get_logger(), "Rejected goal: node %i is already moving", goal->node);
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

rclcpp_action::CancelResponse Epos2Gateway::handle_cancel_move_profile_position(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle){
        RCLCPP_INFO(get_logger(), "Received request to cancel goal");
        (void) goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

void Epos2Gateway::handle_accepted_move_profile_position(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle){
        std::thread{[this, goal_handle]() {moveProfilePosition(goal_handle);}}.detach();
    }

void Epos2Gateway::moveMotors(const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle){

    const auto goal = goal_handle->get_goal();
    const std::vector<unsigned short> nodes(goal->nodes.begin(), goal->nodes.end());
    const std::size_t n = nodes.size();
    auto feedback = std::make_shared<MoveMotors::Feedback>();
    auto result = std::make_shared<MoveMotors::Result>();
    RCLCPP_INFO(get_logger(), "Executing move of %zu motors", n);

    auto haltAll = [this, &nodes](){ for (auto node : nodes) haltMovement(node); };
    auto readAll = [this, &nodes](){
        std::vector<double> positions;
        for (auto node : nodes) positions.push_back(getPositionRad(node));
        return positions;
    };

    try {
        //scale every profile by its travel: same shape, same duration -> all arrive together
        std::vector<long> targetQc(n);
        std::vector<long> travelQc(n);
        long maxTravelQc = 0;
        for (auto node : nodes) requireEnabled(node);
        for (std::size_t i = 0; i < n; ++i){
            targetQc[i] = radToQc(goal->goal_positions[i]);
            travelQc[i] = std::labs(targetQc[i] - getPosition(nodes[i]));
            maxTravelQc = std::max(maxTravelQc, travelQc[i]);
        }
        for (std::size_t i = 0; i < n; ++i){
            const double ratio = maxTravelQc > 0 ? static_cast<double>(travelQc[i]) / maxTravelQc : 1.0;
            moveToPosition(nodes[i], targetQc[i], scaled(kProfileVelocity, ratio),
                scaled(kProfileAccel, ratio), scaled(kProfileDecel, ratio));
        }
        const auto deadline = std::chrono::steady_clock::now() + kMoveTimeout;

        while (true) {
            if (!rclcpp::ok()) {
                haltAll();
                break;
            }
            if (goal_handle->is_canceling()){
                haltAll();
                result->success = false;
                result->message = "canceled";
                result->end_positions = readAll();
                goal_handle->canceled(result);
                RCLCPP_INFO(get_logger(), "Move of %zu motors canceled", n);
                break;
            }

            feedback->current_positions = readAll();
            goal_handle->publish_feedback(feedback);

            //the drive's "target reached" alone is not trusted: the position must be there too
            bool reached = true;
            std::string lagging;
            for (std::size_t i = 0; i < n; ++i){
                const long offQc = std::labs(radToQc(feedback->current_positions[i]) - targetQc[i]);
                if (!targetReached(nodes[i]) || offQc > kPositionToleranceQc) {
                    reached = false;
                    lagging += " node " + std::to_string(nodes[i]) + " " + std::to_string(offQc) + " qc off";
                }
            }
            if (reached) {
                result->success = true;
                result->message = "target reached";
                result->end_positions = readAll();
                goal_handle->succeed(result);
                RCLCPP_INFO(get_logger(), "Move of %zu motors succeeded", n);
                break;
            }

            if (std::chrono::steady_clock::now() > deadline) {
                haltAll();
                throw std::runtime_error("move of " + std::to_string(n) + " motors timed out:" + lagging);
            }
            std::this_thread::sleep_for(kPollPeriod);
        }
    } catch(const std::exception& e){
        RCLCPP_ERROR(get_logger(), "Move failed: %s", e.what());
        haltAll();
        result->success = false;
        result->message = e.what();
        if (rclcpp::ok()) goal_handle->abort(result);
    }
    releaseNodes(nodes);
}

rclcpp_action::GoalResponse Epos2Gateway::handle_goal_move_motors(const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const MoveMotors::Goal> goal){
        (void)uuid;
        const std::vector<unsigned short> nodes(goal->nodes.begin(), goal->nodes.end());
        RCLCPP_INFO(get_logger(), "Received goal request, move %zu motors", nodes.size());
        if (nodes.empty() || nodes.size() != goal->goal_positions.size()) {
            RCLCPP_WARN(get_logger(), "Rejected goal: nodes and goal_positions need the same, non-zero length");
            return rclcpp_action::GoalResponse::REJECT;
        }
        for (std::size_t i = 0; i < nodes.size(); ++i){
            if (!isKnownNode(nodes[i]) || std::count(nodes.begin(), nodes.end(), nodes[i]) != 1) {
                RCLCPP_WARN(get_logger(), "Rejected goal: node %i is unknown or listed twice", nodes[i]);
                return rclcpp_action::GoalResponse::REJECT;
            }
            if (!withinLimits(goal->goal_positions[i])) {
                RCLCPP_WARN(get_logger(), "Rejected goal: node %i target %.4f rad is outside +-25 deg",
                    nodes[i], goal->goal_positions[i]);
                return rclcpp_action::GoalResponse::REJECT;
            }
        }
        if (!claimNodes(nodes)) {
            RCLCPP_WARN(get_logger(), "Rejected goal: a node is already moving");
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

rclcpp_action::CancelResponse Epos2Gateway::handle_cancel_move_motors(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle){
        RCLCPP_INFO(get_logger(), "Received request to cancel move of motors");
        (void) goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

void Epos2Gateway::handle_accepted_move_motors(const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle){
        std::thread{[this, goal_handle]() {moveMotors(goal_handle);}}.detach();
    }



} //namespace cpp_motor_thread
