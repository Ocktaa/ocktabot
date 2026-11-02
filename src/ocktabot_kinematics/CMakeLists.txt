cmake_minimum_required(VERSION 3.8)
project(ocktabot_kinematics)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(ocktabot_interfaces REQUIRED)
find_package(Eigen3 REQUIRED NO_MODULE)

# kinematics (no ROS): forward/inverse kinematics of the stacked stages
add_library(stewart_kinematics STATIC
  src/math_utils.cpp
  src/stage.cpp
  src/direct_kinematics.cpp
  src/forward_chain.cpp
  src/inverse_kinematics.cpp
  src/simulation.cpp)
target_include_directories(stewart_kinematics PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/ocktabot_kinematics)
target_link_libraries(stewart_kinematics PUBLIC Eigen3::Eigen)
target_compile_features(stewart_kinematics PUBLIC cxx_std_17)
set_target_properties(stewart_kinematics PROPERTIES POSITION_INDEPENDENT_CODE ON)

# ros2 node: motor_jointstate -> endeffector_pos, service get_jointpos_ik
add_executable(ocktabot_kinematics_node
  src/ocktabot_kinematics.cpp)
ament_target_dependencies(ocktabot_kinematics_node rclcpp sensor_msgs geometry_msgs ocktabot_interfaces)
target_link_libraries(ocktabot_kinematics_node stewart_kinematics)

install(TARGETS ocktabot_kinematics_node
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

  # kinematics checks, run with: colcon test --packages-select ocktabot_kinematics
  add_executable(stewart_tests src/tests.cpp)
  target_link_libraries(stewart_tests stewart_kinematics)
  add_test(NAME stewart_tests COMMAND stewart_tests)
endif()

ament_package()
