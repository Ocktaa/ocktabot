#ifndef OCKTABOT_COMMANDER__OCKTABOT_COMMANDER_HPP
#define OCKTABOT_COMMANDER__OCKTABOT_COMMANDER_HPP

#include <array>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "ocktabot_interfaces/srv/get_joint_pos_ik.hpp"
#include "ocktabot_interfaces/action/move_motors.hpp"
#include "ocktabot_interfaces/action/move_to_pose.hpp"

namespace ocktabot_commander{

// Action server move_to_pose_act: end-effector pose in, robot moved there.
//   1. get_jointpos_ik         motor positions for the target pose
//      (at full extension the IK is singular: move to ready_position first, retry)
//   2. check the +-max_motor_angle_deg limit
//   3. move_motors_act         all motors together, feedback forwarded
//   4. result                  the measured pose from endeffector_pos after the move
class OcktabotCommander: public rclcpp::Node{
public:
    using GetJointPosIK = ocktabot_interfaces::srv::GetJointPosIK;
    using MoveMotors = ocktabot_interfaces::action::MoveMotors;
    using MoveToPose = ocktabot_interfaces::action::MoveToPose;
    using GoalHandleMoveToPose = rclcpp_action::ServerGoalHandle<MoveToPose>;
    using Pose = std::array<double, 6>;   // x, y, z, roll, pitch, yaw

    OcktabotCommander();

private:
    enum class MoveOutcome { Succeeded, Canceled };

    void onMotorJointState(const sensor_msgs::msg::JointState::SharedPtr msg);
    void onEndEffectorPos(const geometry_msgs::msg::PoseStamped::SharedPtr msg);

    rclcpp_action::GoalResponse handle_goal_move_to_pose(const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const MoveToPose::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel_move_to_pose(const std::shared_ptr<GoalHandleMoveToPose> goal_handle);

    void handle_accepted_move_to_pose(const std::shared_ptr<GoalHandleMoveToPose> goal_handle);

    void moveToPose(const std::shared_ptr<GoalHandleMoveToPose> goal_handle);

    //the steps of moveToPose, each throws std::runtime_error with the reason on failure
    GetJointPosIK::Response::SharedPtr callIK(const Pose& target);
    void checkLimits(const std::vector<double>& motorPositions) const;
    MoveOutcome moveMotors(const std::vector<double>& motorPositions,
        const std::shared_ptr<GoalHandleMoveToPose>& goal_handle);
    Pose waitForPoseAfter(int64_t stampNs);

    //all motors closer to 0 than ready_position (the singular full extension)
    bool nearHome();
    Pose latestPose();

    std::vector<uint16_t> motor_nodes_;
    std::vector<std::string> motor_names_;    //"motor" + node, as published by epos2_gateway
    double max_motor_angle_ = 0.0;            //[rad]
    double ready_position_ = 0.0;             //[rad]
    std::chrono::milliseconds ik_timeout_;
    std::chrono::milliseconds move_timeout_;
    std::chrono::milliseconds pose_timeout_;

    std::mutex state_mutex_;
    std::map<std::string, double> motor_positions_;   //latest motor_jointstate [rad]
    Pose pose_{};                                     //latest endeffector_pos
    int64_t pose_stamp_ns_ = -1;                      //-1: nothing received yet

    std::atomic<bool> busy_{false};

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr motor_jointstate_subscriber_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr endeffector_pos_subscriber_;
    rclcpp::Client<GetJointPosIK>::SharedPtr get_jointpos_ik_client_;
    rclcpp_action::Client<MoveMotors>::SharedPtr move_motors_client_;
    rclcpp_action::Server<MoveToPose>::SharedPtr move_to_pose_action_;
};

} //namespace ocktabot_commander

#endif
