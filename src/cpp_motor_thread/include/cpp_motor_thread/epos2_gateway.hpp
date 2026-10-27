#ifndef CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP
#define CPP_MOTOR_THREAD__EPOS2_GATEWAY_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_srvs/srv/trigger.hpp"

namespace cpp_motor_thread{

class Epos2Gateway: public rclcpp::Node{
public:
    Epos2Gateway();

    ~Epos2Gateway() override;

    Epos2Gateway(const Epos2Gateway&) = delete;
    Epos2Gateway& operator=(const Epos2Gateway&) = delete;

    int getPosition(unsigned short node);

    bool inFault(unsigned short node);

    void prepareProfilePosition(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,     
        std::shared_ptr<std_srvs::srv::Trigger::Response> response);

private:
    void publishJointStates();

    void * handle_ = nullptr;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr motor_position_publisher_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr profile_position_mode_service_;
};

} //namespace cpp_motor_thread

#endif