# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target cpp_motor_thread::cpp_motor_thread
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${cpp_motor_thread_TARGETS}.
if(cpp_motor_thread_TARGETS AND NOT TARGET cpp_motor_thread::cpp_motor_thread)
  add_library(cpp_motor_thread::cpp_motor_thread INTERFACE IMPORTED)
  set_target_properties(cpp_motor_thread::cpp_motor_thread PROPERTIES
    INTERFACE_LINK_LIBRARIES "${cpp_motor_thread_TARGETS}")
endif()
