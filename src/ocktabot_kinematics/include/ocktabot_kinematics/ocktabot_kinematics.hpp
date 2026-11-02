#ifndef OCKTABOT_KINEMATICS__OCKTABOT_KINEMATICS_HPP
#define OCKTABOT_KINEMATICS__OCKTABOT_KINEMATICS_HPP

#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "ocktabot_interfaces/srv/get_joint_pos_ik.hpp"
#include "ocktabot_kinematics/simulation.hpp"

namespace ocktabot_kinematics{

// Subscribes to motor_jointstate, publishes the end-effector pose on
// endeffector_pos for every reading (forward kinematics), and serves
// get_jointpos_ik (inverse kinematics).
//
// Motor reading (gearbox output [rad], 0 = links straight up) -> base link
// angle phi_in [rad], measured up from the plate toward the centroid:
//   phi_in[j] = motor_scale[j] * position[j] + motor_offset[j]
// motor_offset = pi/2 (straight up), motor_scale = +1 if a positive motor
// angle tilts the link outward (away from the centroid), -1 if inward.
class OcktabotKinematics: public rclcpp::Node{
public:
    OcktabotKinematics();

private:
    void onMotorJointState(const sensor_msgs::msg::JointState::SharedPtr msg);

    void getJointPosIK(const std::shared_ptr<ocktabot_interfaces::srv::GetJointPosIK::Request> request,
        std::shared_ptr<ocktabot_interfaces::srv::GetJointPosIK::Response> response);

    // Base link angles from a JointState, matched by motor_names_.
    // Returns false (and a reason) if a motor is missing.
    bool readMotorAngles(const sensor_msgs::msg::JointState& msg, stewart::Vec3& phi, std::string& reason) const;

    stewart::Simulation sim_;

    std::vector<std::string> motor_names_;
    std::vector<double> motor_scale_;
    std::vector<double> motor_offset_;
    stewart::PoseMask ik_spec_{};
    std::string frame_id_;

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr motor_jointstate_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr endeffector_pos_publisher_;
    rclcpp::Service<ocktabot_interfaces::srv::GetJointPosIK>::SharedPtr get_jointpos_ik_service_;
};

} //namespace ocktabot_kinematics

#endif
