cmake_minimum_required(VERSION 3.8)
project(cpp_motor_thread)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# maxon EPOS Command Library
file(GLOB EPOS_HINTS /opt/EposCmdLib_*/include)
find_path(EPOS_INCLUDE_DIR Definitions.h
  HINTS ${EPOS_HINTS} $ENV{HOME}/EPOS_Linux_Library/include)
if(NOT EPOS_INCLUDE_DIR)
  message(FATAL_ERROR "Definitions.h not found. Run 'find /opt ~ -name Definitions.h' and add that folder to HINTS.")
endif()
find_library(EPOS_LIB EposCmd REQUIRED)
find_library(FTD2XX_LIB ftd2xx REQUIRED)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
add_executable(epos_motor_thread src/epos_motor_thread.cpp)
target_include_directories(epos_motor_thread PRIVATE ${EPOS_INCLUDE_DIR})
target_link_libraries(epos_motor_thread ${EPOS_LIB} ${FTD2XX_LIB})
ament_target_dependencies(epos_motor_thread rclcpp sensor_msgs)

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

install(TARGETS epos_motor_thread
  DESTINATION lib/${PROJECT_NAME})
  
ament_package()
