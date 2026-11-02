cmake_minimum_required(VERSION 3.8)
project(ocktabot_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/GetJointPosIK.srv"
  "action/MoveProfilePosition.action"
  "action/MoveMotors.action"
  "action/MoveToPose.action")

ament_export_dependencies(rosidl_default_runtime)
ament_package()
