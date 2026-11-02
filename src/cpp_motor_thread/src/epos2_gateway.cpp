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
    constexpr unsigned short kNodes[] = {1};
    constexpr unsigned int kProfileVelocity = 1000;
    constexpr unsigned int kProfileAccel = 500;
    constexpr unsigned int kProfileDecel = 500;
    constexpr double kQcPerMotorRev = 50.0;                    //encoder quadcounts per motor revolution
    constexpr double kGearRatio = 153.0;                       //gearbox 153:1
    constexpr double kQcPerRev = kQcPerMotorRev * kGearRatio;  //7650 qc per revolution of the gearbox output
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

//wrapper for errortext
std::string errorText(unsigned int code) {
  char info[256] = {};
  VCS_GetErrorInfo(code, info, static_cast<unsigned short> (sizeof(info)));
  char hex[16];
  std::snprintf(hex, sizeof(hex), "0x%08X", code);
  return std::string(hex) + info;  
}

//wrapper for error checking of maxon motor function
void check(int ok, unsigned int errorCode, const std::string& what){
  if (!ok) throw std::runtime_error(what + "failed: " + errorText(errorCode));
}

//wrapper for node label
std::string nodeLabel(const char* action, unsigned short node) {
  return std::string(action) + "node" + std::to_string(node);
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

    move_profile_position_action_ = rclcpp_action::create_server<cpp_motor_thread::action::MoveProfilePosition>(
        this,
        "move_profile_position_act",
        std::bind(&Epos2Gateway::handle_goal_move_profile_position, this, _1, _2),
        std::bind(&Epos2Gateway::handle_cancel_move_profile_position, this, _1),
        std::bind(&Epos2Gateway::handle_accepted_move_profile_position, this, _1)
    );
}

Epos2Gateway::~Epos2Gateway(){
    unsigned int err = 0;
    for (auto node : kNodes) VCS_SetDisableState(handle_, node, &err);
    VCS_CloseDevice(handle_, &err);
    std::cout << "Drives disable, device closed" << std::endl;    
}

int Epos2Gateway::getPosition(unsigned short node){
    int pos = 0;
    unsigned int err = 0;
    check(VCS_GetPositionIs(handle_, node, &pos, &err), err, nodeLabel("GetPositionIs", node));
    return pos;
}

double Epos2Gateway::getPositionRad(unsigned short node){
    return qcToRad(getPosition(node));
}

bool Epos2Gateway::inFault(unsigned short node){
    int fault = 0;
    unsigned int err = 0;
    check(VCS_GetFaultState(handle_, node, &fault, &err), err, nodeLabel("GetFaultState", node));
    return fault != 0;    
}

void Epos2Gateway::haltMovement(unsigned short node){
    unsigned int err = 0;
    std::lock_guard<std::mutex> lock(vcs_mutex_);
    VCS_HaltPositionMovement(handle_, node, &err);
}


void Epos2Gateway::prepareProfilePosition(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
    std::shared_ptr<std_srvs::srv::Trigger::Response> response){
    unsigned int err = 0;
    for (auto node : kNodes){
        check(VCS_ClearFault(handle_, node, &err), err, nodeLabel("ClearFault", node));
        check(VCS_SetEnableState(handle_, node, &err), err, nodeLabel("SetEnableState", node));
        check(VCS_ActivateProfilePositionMode(handle_, node, &err), err, 
                nodeLabel("ActivateProfilePositionMode", node));
        check(VCS_SetPositionProfile(handle_, node, kProfileVelocity, kProfileAccel, kProfileDecel, &err), 
                err, nodeLabel("SetProfilePosition", node));
    }
    response->success = 1;
    response->message = "Successfully entered profile position mode";
}

void Epos2Gateway::publishJointStates(){
    sensor_msgs::msg::JointState message;
    message.header.stamp = now();
    for (auto node : kNodes){
        message.name.push_back("motor" + std::to_string(node));
        message.position.push_back(getPositionRad(node));
        RCLCPP_INFO_THROTTLE(
            get_logger(), *get_clock(), 1000, "%s position %.4f rad",
            message.name.back().c_str(), message.position.back()
        );
    }
    motor_position_publisher_->publish(message);
}

void Epos2Gateway::moveProfilePosition(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle){

    unsigned int err = 0;
    RCLCPP_INFO(get_logger(), "Executing goal");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<cpp_motor_thread::action::MoveProfilePosition::Feedback>();
    auto result = std::make_shared<cpp_motor_thread::action::MoveProfilePosition::Result>();

    
    try {
        {
        std::lock_guard<std::mutex> lock(vcs_mutex_);
        check(VCS_MoveToPosition(handle_, goal->node, radToQc(goal->goal_position), goal->absolute ? 1 : 0, 1, &err), err, nodeLabel("MoveToPosition", goal->node));
        }
        const auto deadline = std::chrono::steady_clock::now() + kMoveTimeout;

    
        while (true) {
            if (!rclcpp::ok()) {
                haltMovement(goal->node);
                return;
            }
            if (goal_handle->is_canceling()){
                haltMovement(goal->node);
                result->end_position = getPositionRad(goal->node);
                goal_handle->canceled(result);
                RCLCPP_INFO(get_logger(), "Goal Canceled");
                return;
            }

            feedback->current_position = getPositionRad(goal->node);
            goal_handle->publish_feedback(feedback);

            RCLCPP_INFO(get_logger(), "Pubslish feedback");

            int targetReached = 0;
            {
                std::lock_guard<std::mutex> lock(vcs_mutex_);
                check(VCS_GetMovementState(handle_, goal->node, &targetReached, &err), err,
                    nodeLabel("GetMovementState", goal->node));
            }
            if (targetReached) break;

            if (std::chrono::steady_clock::now() > deadline) {
                haltMovement(goal->node);
                throw std::runtime_error(nodeLabel("Move timed out on ", goal->node));
            
            }
            std::this_thread::sleep_for(kPollPeriod);
        }

        result->end_position = getPositionRad(goal->node);
        goal_handle->succeed(result);
        RCLCPP_INFO(get_logger(), "Goal Succeeded");
    } catch(const std::exception& e){
        RCLCPP_ERROR(get_logger(), "Move failed: %s", e.what());
        if (rclcpp::ok()) goal_handle->abort(result);
    }   

}

rclcpp_action::GoalResponse Epos2Gateway::handle_goal_move_profile_position(const rclcpp_action::GoalUUID & uuid,    
    std::shared_ptr<const cpp_motor_thread::action::MoveProfilePosition::Goal> goal){
        RCLCPP_INFO(get_logger(), "Received goal request, move node: %i, to %s position: %.4f rad",
            goal->node, goal->absolute ? "absolute" : "relative", goal->goal_position);
        (void)uuid;
        if (!std::isfinite(goal->goal_position)) {
            RCLCPP_WARN(get_logger(), "Rejected goal: goal_position is not finite");
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

rclcpp_action::CancelResponse Epos2Gateway::handle_cancel_move_profile_position(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle){
        RCLCPP_INFO(get_logger(), "Received request to cancel goal");
        (void) goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

void Epos2Gateway::handle_accepted_move_profile_position(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle){
        std::thread{[this, goal_handle]() {moveProfilePosition(goal_handle);}}.detach();
    }



} //namespace cpp_motor_thread