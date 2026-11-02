cmake_minimum_required(VERSION 3.8)
project(ocktabot_commander)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(ocktabot_interfaces REQUIRED)

# action server move_to_pose_act: IK (get_jointpos_ik) -> limits -> motors (move_motors_act)
add_executable(ocktabot_commander_node
  src/ocktabot_commander.cpp)
target_include_directories(ocktabot_commander_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(ocktabot_commander_node PRIVATE cxx_std_17)
ament_target_dependencies(ocktabot_commander_node
  rclcpp rclcpp_action sensor_msgs geometry_msgs ocktabot_interfaces)

install(TARGETS ocktabot_commander_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
