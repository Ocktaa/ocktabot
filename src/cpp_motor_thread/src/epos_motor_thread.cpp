#include <memory>
#include <iostream>
#include <exception>

#include "rclcpp/rclcpp.hpp"
#include "cpp_motor_thread/epos2_gateway.hpp"


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  int exitCode = 0;
  try {
    auto node = std::make_shared<cpp_motor_thread::Epos2Gateway>();
    rclcpp::spin(node);
  } catch(const std::exception & e){
    std::cerr << "Erorr: " << e.what() <<std::endl;
    exitCode = 1;
  }
  rclcpp::shutdown();
  return exitCode;
}