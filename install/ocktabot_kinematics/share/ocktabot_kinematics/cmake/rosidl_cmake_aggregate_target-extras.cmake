# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ocktabot_kinematics::ocktabot_kinematics
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ocktabot_kinematics_TARGETS}.
if(ocktabot_kinematics_TARGETS AND NOT TARGET ocktabot_kinematics::ocktabot_kinematics)
  add_library(ocktabot_kinematics::ocktabot_kinematics INTERFACE IMPORTED)
  set_target_properties(ocktabot_kinematics::ocktabot_kinematics PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ocktabot_kinematics_TARGETS}")
endif()
