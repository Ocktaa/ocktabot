// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

#ifndef OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ocktabot_kinematics/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize(
  const ocktabot_kinematics::srv::GetJointPosIK_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ocktabot_kinematics::srv::GetJointPosIK_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size(
  const ocktabot_kinematics::srv::GetJointPosIK_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_GetJointPosIK_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Request & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_key_GetJointPosIK_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize(
  const ocktabot_kinematics::srv::GetJointPosIK_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ocktabot_kinematics::srv::GetJointPosIK_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size(
  const ocktabot_kinematics::srv::GetJointPosIK_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_GetJointPosIK_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Response & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_key_GetJointPosIK_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Response)();

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize(
  const ocktabot_kinematics::srv::GetJointPosIK_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ocktabot_kinematics::srv::GetJointPosIK_Event & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size(
  const ocktabot_kinematics::srv::GetJointPosIK_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_GetJointPosIK_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
cdr_serialize_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Event & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
get_serialized_size_key(
  const ocktabot_kinematics::srv::GetJointPosIK_Event & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
max_serialized_size_key_GetJointPosIK_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Event)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ocktabot_kinematics
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK)();

#ifdef __cplusplus
}
#endif

#endif  // OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
