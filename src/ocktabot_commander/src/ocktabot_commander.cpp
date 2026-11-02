//Implementation of ocktabot_commander::OcktabotCommander (declared in ocktabot_commander.hpp)

#include "ocktabot_commander/ocktabot_commander.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <thread>

using namespace std::chrono_literals;

namespace{
    constexpr double kDeg = M_PI / 180.0;
    constexpr auto kServerWait = 1s;          //how long to wait for a server to appear
    constexpr auto kPollPeriod = 20ms;

std::chrono::milliseconds seconds(double s){
    return std::chrono::milliseconds(static_cast<int64_t>(s * 1000.0));
}

//quaternion -> (roll, pitch, yaw) with rotation = Rz(yaw) * Ry(pitch) * Rx(roll), same as ocktabot_kinematics
std::array<double, 3> rollPitchYaw(const geometry_msgs::msg::Quaternion& q){
    const double sinp = std::clamp(2.0 * (q.w * q.y - q.z * q.x), -1.0, 1.0);
    return {std::atan2(2.0 * (q.w * q.x + q.y * q.z), 1.0 - 2.0 * (q.x * q.x + q.y * q.y)),
            std::asin(sinp),
            std::atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z))};
}

} //namespace

namespace ocktabot_commander{

OcktabotCommander::OcktabotCommander() : Node("ocktabot_commander"){

    using namespace std::placeholders;

    const auto nodes = declare_parameter<std::vector<int64_t>>("motor_nodes", {1, 2, 3});
    max_motor_angle_ = declare_parameter<double>("max_motor_angle_deg", 25.0) * kDeg;
    ready_position_ = declare_parameter<double>("ready_position", 0.05);
    ik_timeout_ = seconds(declare_parameter<double>("ik_timeout_s", 5.0));
    move_timeout_ = seconds(declare_parameter<double>("move_timeout_s", 20.0));
    pose_timeout_ = seconds(declare_parameter<double>("pose_timeout_s", 2.0));

    if (nodes.size() != 3) throw std::invalid_argument("parameter motor_nodes needs exactly 3 values");
    for (auto node : nodes){
        motor_nodes_.push_back(static_cast<uint16_t>(node));
        motor_names_.push_back("motor" + std::to_string(node));
    }
    if (!(max_motor_angle_ > 0.0)) throw std::invalid_argument("parameter max_motor_angle_deg must be > 0");
    if (ready_position_ == 0.0 || std::abs(ready_position_) > max_motor_angle_) {
        throw std::invalid_argument("parameter ready_position must be non-zero and within max_motor_angle_deg");
    }

    motor_jointstate_subscriber_ = create_subscription<sensor_msgs::msg::JointState>("motor_jointstate", 10,
        [this](const sensor_msgs::msg::JointState::SharedPtr msg){onMotorJointState(msg);});
    endeffector_pos_subscriber_ = create_subscription<geometry_msgs::msg::PoseStamped>("endeffector_pos", 10,
        [this](const geometry_msgs::msg::PoseStamped::SharedPtr msg){onEndEffectorPos(msg);});

    get_jointpos_ik_client_ = create_client<GetJointPosIK>("get_jointpos_ik");
    move_motors_client_ = rclcpp_action::create_client<MoveMotors>(this, "move_motors_act");

    move_to_pose_action_ = rclcpp_action::create_server<MoveToPose>(
        this,
        "move_to_pose_act",
        std::bind(&OcktabotCommander::handle_goal_move_to_pose, this, _1, _2),
        std::bind(&OcktabotCommander::handle_cancel_move_to_pose, this, _1),
        std::bind(&OcktabotCommander::handle_accepted_move_to_pose, this, _1)
    );
}

void OcktabotCommander::onMotorJointState(const sensor_msgs::msg::JointState::SharedPtr msg){
    std::lock_guard<std::mutex> lock(state_mutex_);
    for (std::size_t i = 0; i < msg->name.size() && i < msg->position.size(); ++i){
        motor_positions_[msg->name[i]] = msg->position[i];
    }
}

void OcktabotCommander::onEndEffectorPos(const geometry_msgs::msg::PoseStamped::SharedPtr msg){
    const auto rpy = rollPitchYaw(msg->pose.orientation);
    std::lock_guard<std::mutex> lock(state_mutex_);
    pose_ = {msg->pose.position.x, msg->pose.position.y, msg->pose.position.z, rpy[0], rpy[1], rpy[2]};
    pose_stamp_ns_ = rclcpp::Time(msg->header.stamp).nanoseconds();
}

OcktabotCommander::Pose OcktabotCommander::latestPose(){
    std::lock_guard<std::mutex> lock(state_mutex_);
    return pose_;
}

bool OcktabotCommander::nearHome(){
    std::lock_guard<std::mutex> lock(state_mutex_);
    for (const auto& name : motor_names_){
        const auto it = motor_positions_.find(name);
        if (it == motor_positions_.end() || std::abs(it->second) >= std::abs(ready_position_)) return false;
    }
    return true;
}

rclcpp_action::GoalResponse OcktabotCommander::handle_goal_move_to_pose(const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const MoveToPose::Goal> goal){
        (void)uuid;
        RCLCPP_INFO(get_logger(), "Received goal request, target x %.3f y %.3f z %.3f roll %.2f pitch %.2f yaw %.2f deg",
            goal->target[0], goal->target[1], goal->target[2],
            goal->target[3] / kDeg, goal->target[4] / kDeg, goal->target[5] / kDeg);
        if (!std::all_of(goal->target.begin(), goal->target.end(), [](double v){return std::isfinite(v);})) {
            RCLCPP_WARN(get_logger(), "Rejected goal: target is not finite");
            return rclcpp_action::GoalResponse::REJECT;
        }
        //one move at a time; cancel the running goal first
        if (busy_.exchange(true)) {
            RCLCPP_WARN(get_logger(), "Rejected goal: another move is running");
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

rclcpp_action::CancelResponse OcktabotCommander::handle_cancel_move_to_pose(
    const std::shared_ptr<GoalHandleMoveToPose> goal_handle){
        RCLCPP_INFO(get_logger(), "Received request to cancel goal");
        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

void OcktabotCommander::handle_accepted_move_to_pose(const std::shared_ptr<GoalHandleMoveToPose> goal_handle){
        //runs in its own thread: it waits for the IK and the motors, whose answers
        //are delivered by the executor
        std::thread{[this, goal_handle]() {moveToPose(goal_handle);}}.detach();
    }

void OcktabotCommander::moveToPose(const std::shared_ptr<GoalHandleMoveToPose> goal_handle){
    const auto goal = goal_handle->get_goal();
    auto result = std::make_shared<MoveToPose::Result>();

    try {
        auto ik = callIK(goal->target);
        if (!ik->success && nearHome()) {
            //at full extension the IK is singular: step off it, then try again
            RCLCPP_INFO(get_logger(), "IK failed at full extension (%s), moving to ready_position %.4f rad first",
                ik->message.c_str(), ready_position_);
            const std::vector<double> ready(motor_nodes_.size(), ready_position_);
            if (moveMotors(ready, goal_handle) == MoveOutcome::Canceled) {
                result->success = false;
                result->message = "canceled";
                result->pose = latestPose();
                goal_handle->canceled(result);
                busy_ = false;
                return;
            }
            waitForPoseAfter(now().nanoseconds());
            if (nearHome()) {
                throw std::runtime_error("the move to ready_position did not move the motors off full extension");
            }
            ik = callIK(goal->target);
        }
        if (!ik->success) throw std::runtime_error("IK failed: " + ik->message);

        const std::vector<double> motorPositions(ik->motor_positions.begin(), ik->motor_positions.end());
        checkLimits(motorPositions);

        if (moveMotors(motorPositions, goal_handle) == MoveOutcome::Canceled) {
            result->success = false;
            result->message = "canceled";
            result->pose = latestPose();
            goal_handle->canceled(result);
            RCLCPP_INFO(get_logger(), "Goal Canceled");
        } else {
            //measured pose, from a motor reading taken after the motors stopped
            result->pose = waitForPoseAfter(now().nanoseconds());
            double err = 0.0;
            for (int i = 0; i < 3; ++i) err += std::pow(result->pose[i] - ik->pose[i], 2);
            char text[128];
            std::snprintf(text, sizeof(text), "target reached, %.4f from the IK position", std::sqrt(err));
            result->success = true;
            result->message = text;
            goal_handle->succeed(result);
            RCLCPP_INFO(get_logger(), "Goal Succeeded: %s", text);
        }
    } catch(const std::exception& e){
        RCLCPP_ERROR(get_logger(), "Move to pose failed: %s", e.what());
        result->success = false;
        result->message = e.what();
        result->pose = latestPose();
        if (rclcpp::ok()) goal_handle->abort(result);
    }
    busy_ = false;
}

OcktabotCommander::GetJointPosIK::Response::SharedPtr OcktabotCommander::callIK(const Pose& target){
    if (!get_jointpos_ik_client_->wait_for_service(kServerWait)) {
        throw std::runtime_error("service get_jointpos_ik is not available");
    }
    auto request = std::make_shared<GetJointPosIK::Request>();
    request->target = target;
    auto future = get_jointpos_ik_client_->async_send_request(request);
    if (future.wait_for(ik_timeout_) != std::future_status::ready) {
        get_jointpos_ik_client_->remove_pending_request(future);
        throw std::runtime_error("get_jointpos_ik did not answer in time");
    }
    auto response = future.get();
    //IK answers in the kinematics' motor order; it must be the order of motor_nodes
    if (response->success && response->name != motor_names_) {
        throw std::runtime_error("get_jointpos_ik motor names do not match motor_nodes");
    }
    return response;
}

void OcktabotCommander::checkLimits(const std::vector<double>& motorPositions) const{
    for (std::size_t i = 0; i < motorPositions.size(); ++i){
        if (!std::isfinite(motorPositions[i]) || std::abs(motorPositions[i]) > max_motor_angle_) {
            char text[160];
            std::snprintf(text, sizeof(text), "%s would move to %.2f deg, outside the +-%.1f deg limit",
                motor_names_[i].c_str(), motorPositions[i] / kDeg, max_motor_angle_ / kDeg);
            throw std::runtime_error(text);
        }
    }
}

OcktabotCommander::MoveOutcome OcktabotCommander::moveMotors(const std::vector<double>& motorPositions,
    const std::shared_ptr<GoalHandleMoveToPose>& goal_handle){
    if (!move_motors_client_->wait_for_action_server(kServerWait)) {
        throw std::runtime_error("action move_motors_act is not available");
    }

    MoveMotors::Goal goal;
    goal.nodes = motor_nodes_;
    goal.goal_positions = motorPositions;

    //forward the motor feedback, together with the latest end-effector pose
    rclcpp_action::Client<MoveMotors>::SendGoalOptions options;
    options.feedback_callback = [this, goal_handle](rclcpp_action::ClientGoalHandle<MoveMotors>::SharedPtr,
        const std::shared_ptr<const MoveMotors::Feedback> motorFeedback){
            auto feedback = std::make_shared<MoveToPose::Feedback>();
            const std::size_t n = std::min(feedback->motor_positions.size(), motorFeedback->current_positions.size());
            std::copy_n(motorFeedback->current_positions.begin(), n, feedback->motor_positions.begin());
            feedback->pose = latestPose();
            goal_handle->publish_feedback(feedback);
        };

    auto goalFuture = move_motors_client_->async_send_goal(goal, options);
    if (goalFuture.wait_for(kServerWait) != std::future_status::ready) {
        throw std::runtime_error("move_motors_act did not answer the goal");
    }
    const auto motorGoal = goalFuture.get();
    if (!motorGoal) throw std::runtime_error("move_motors_act rejected the goal (limits or motors busy)");

    auto resultFuture = move_motors_client_->async_get_result(motorGoal);
    const auto deadline = std::chrono::steady_clock::now() + move_timeout_;
    while (resultFuture.wait_for(kPollPeriod) != std::future_status::ready) {
        if (goal_handle->is_canceling()) {
            move_motors_client_->async_cancel_goal(motorGoal);
            resultFuture.wait_for(move_timeout_);
            return MoveOutcome::Canceled;
        }
        if (std::chrono::steady_clock::now() > deadline) {
            move_motors_client_->async_cancel_goal(motorGoal);
            throw std::runtime_error("move_motors_act timed out");
        }
    }

    const auto wrapped = resultFuture.get();
    const std::string message = wrapped.result ? wrapped.result->message : "no result";
    if (wrapped.code == rclcpp_action::ResultCode::SUCCEEDED && wrapped.result && wrapped.result->success) {
        return MoveOutcome::Succeeded;
    }
    throw std::runtime_error("motor move failed: " + message);
}

OcktabotCommander::Pose OcktabotCommander::waitForPoseAfter(int64_t stampNs){
    //endeffector_pos carries the stamp of the motor reading it was computed from
    const auto deadline = std::chrono::steady_clock::now() + pose_timeout_;
    while (std::chrono::steady_clock::now() < deadline) {
        {
            std::lock_guard<std::mutex> lock(state_mutex_);
            if (pose_stamp_ns_ > stampNs) return pose_;
        }
        std::this_thread::sleep_for(kPollPeriod);
    }
    throw std::runtime_error("no endeffector_pos received after the move (is ocktabot_kinematics running?)");
}

} //namespace ocktabot_commander

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  int exitCode = 0;
  try {
    auto node = std::make_shared<ocktabot_commander::OcktabotCommander>();
    rclcpp::spin(node);
  } catch(const std::exception & e){
    std::cerr << "Error: " << e.what() << std::endl;
    exitCode = 1;
  }
  rclcpp::shutdown();
  return exitCode;
}
