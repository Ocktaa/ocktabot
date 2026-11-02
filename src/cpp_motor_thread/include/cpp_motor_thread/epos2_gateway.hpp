#ifndef CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP
#define CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP

#include <mutex>
#include <set>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "cpp_motor_thread/visibility_control.hpp"
#include "ocktabot_interfaces/action/move_profile_position.hpp"
#include "ocktabot_interfaces/action/move_motors.hpp"

namespace cpp_motor_thread{

class Epos2Gateway: public rclcpp::Node{
public:
    using MoveProfilePosition = ocktabot_interfaces::action::MoveProfilePosition;
    using MoveMotors = ocktabot_interfaces::action::MoveMotors;

    Epos2Gateway();

    ~Epos2Gateway() override;

    Epos2Gateway(const Epos2Gateway&) = delete;
    Epos2Gateway& operator=(const Epos2Gateway&) = delete;

    //position in encoder quadcounts
    int getPosition(unsigned short node);

    //position of the gearbox output [rad], 0 rad = 0 qc
    double getPositionRad(unsigned short node);

    bool inFault(unsigned short node);

    void haltMovement(unsigned short node);


private:
    void publishJointStates();

    void prepareProfilePosition(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,     
        std::shared_ptr<std_srvs::srv::Trigger::Response> response);

    //absolute move of one node with its own profile (EPOS units: rpm, rpm/s)
    void moveToPosition(unsigned short node, long targetQc, unsigned int velocity,
        unsigned int accel, unsigned int decel);

    bool targetReached(unsigned short node);

    //every node is moved by at most one goal at a time
    bool claimNodes(const std::vector<unsigned short>& nodes);
    void releaseNodes(const std::vector<unsigned short>& nodes);

    //move_profile_position_act: one node
    rclcpp_action::GoalResponse handle_goal_move_profile_position(const rclcpp_action::GoalUUID & uuid,    
        std::shared_ptr<const MoveProfilePosition::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel_move_profile_position(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle);
    
    void handle_accepted_move_profile_position(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle);

    void moveProfilePosition(const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveProfilePosition>> goal_handle);

    //move_motors_act: several nodes, synchronized so they arrive together
    rclcpp_action::GoalResponse handle_goal_move_motors(const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const MoveMotors::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel_move_motors(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle);

    void handle_accepted_move_motors(const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle);

    void moveMotors(const std::shared_ptr<rclcpp_action::ServerGoalHandle<MoveMotors>> goal_handle);

    void * handle_ = nullptr;
    
    //every VCS_ call on handle_ holds this lock
    std::mutex vcs_mutex_;

    std::mutex busy_mutex_;
    std::set<unsigned short> busy_nodes_;
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr motor_position_publisher_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr profile_position_mode_service_;
    rclcpp_action::Server<MoveProfilePosition>::SharedPtr move_profile_position_action_;
    rclcpp_action::Server<MoveMotors>::SharedPtr move_motors_action_;
};

} //namespace cpp_motor_thread

#endif
