#ifndef CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP
#define CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "cpp_motor_thread/visibility_control.hpp"
#include "cpp_motor_thread/action/move_profile_position.hpp"

namespace cpp_motor_thread{

class Epos2Gateway: public rclcpp::Node{
public:
    Epos2Gateway();

    ~Epos2Gateway() override;

    Epos2Gateway(const Epos2Gateway&) = delete;
    Epos2Gateway& operator=(const Epos2Gateway&) = delete;

    int getPosition(unsigned short node);

    bool inFault(unsigned short node);

    void haltMovement(unsigned short node);


private:
    void publishJointStates();

    void prepareProfilePosition(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,     
        std::shared_ptr<std_srvs::srv::Trigger::Response> response);

    rclcpp_action::GoalResponse handle_goal_move_profile_position(const rclcpp_action::GoalUUID & uuid,    
        std::shared_ptr<const cpp_motor_thread::action::MoveProfilePosition::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel_move_profile_position(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle);
    
    void handle_accepted_move_profile_position(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle);

    void moveProfilePosition(const std::shared_ptr<rclcpp_action::ServerGoalHandle<cpp_motor_thread::action::MoveProfilePosition>> goal_handle);

    void * handle_ = nullptr;
    
    std::mutex vcs_mutex_;
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr motor_position_publisher_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr profile_position_mode_service_;
    rclcpp_action::Server<cpp_motor_thread::action::MoveProfilePosition>::SharedPtr move_profile_position_action_;
};

} //namespace cpp_motor_thread

#endif