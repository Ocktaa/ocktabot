// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__rosidl_typesupport_introspection_c.h"
#include "ocktabot_kinematics/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ocktabot_kinematics__srv__GetJointPosIK_Request__init(message_memory);
}

void ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_fini_function(void * message_memory)
{
  ocktabot_kinematics__srv__GetJointPosIK_Request__fini(message_memory);
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Request__target(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Request__target(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Request__target(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Request__target(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Request__target(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Request__target(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Request__target(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_member_array[1] = {
  {
    "target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Request, target),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Request__target,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Request__target,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Request__target,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Request__target,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Request__target,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_members = {
  "ocktabot_kinematics__srv",  // message namespace
  "GetJointPosIK_Request",  // message name
  1,  // number of fields
  sizeof(ocktabot_kinematics__srv__GetJointPosIK_Request),
  false,  // has_any_key_member_
  ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_member_array,  // message members
  ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle = {
  0,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_members,
  get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ocktabot_kinematics
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Request)() {
  if (!ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle.typesupport_identifier) {
    ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.h"


// Include directives for member types
// Member `message`
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ocktabot_kinematics__srv__GetJointPosIK_Response__init(message_memory);
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_fini_function(void * message_memory)
{
  ocktabot_kinematics__srv__GetJointPosIK_Response__fini(message_memory);
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__name(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__name(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__name(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__name(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__name(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Response__name(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__motor_positions(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__motor_positions(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__motor_positions(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__motor_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__motor_positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__motor_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__motor_positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__pose(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__pose(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__pose(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__pose(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__pose(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_member_array[5] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Response, name),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__name,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__name,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__name,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__name,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__name,  // assign(index, value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Response__name  // resize(index) function pointer
  },
  {
    "motor_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Response, motor_positions),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__motor_positions,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__motor_positions,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__motor_positions,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__motor_positions,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__motor_positions,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Response, pose),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Response__pose,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Response__pose,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Response__pose,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Response__pose,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Response__pose,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_members = {
  "ocktabot_kinematics__srv",  // message namespace
  "GetJointPosIK_Response",  // message name
  5,  // number of fields
  sizeof(ocktabot_kinematics__srv__GetJointPosIK_Response),
  false,  // has_any_key_member_
  ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_member_array,  // message members
  ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle = {
  0,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_members,
  get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ocktabot_kinematics
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Response)() {
  if (!ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle.typesupport_identifier) {
    ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "ocktabot_kinematics/srv/get_joint_pos_ik.h"
// Member `request`
// Member `response`
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ocktabot_kinematics__srv__GetJointPosIK_Event__init(message_memory);
}

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_fini_function(void * message_memory)
{
  ocktabot_kinematics__srv__GetJointPosIK_Event__fini(message_memory);
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Event__request(
  const void * untyped_member)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * member =
    (const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__request(
  const void * untyped_member, size_t index)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * member =
    (const ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__request(
  void * untyped_member, size_t index)
{
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * member =
    (ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Request * item =
    ((const ocktabot_kinematics__srv__GetJointPosIK_Request *)
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__request(untyped_member, index));
  ocktabot_kinematics__srv__GetJointPosIK_Request * value =
    (ocktabot_kinematics__srv__GetJointPosIK_Request *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ocktabot_kinematics__srv__GetJointPosIK_Request * item =
    ((ocktabot_kinematics__srv__GetJointPosIK_Request *)
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__request(untyped_member, index));
  const ocktabot_kinematics__srv__GetJointPosIK_Request * value =
    (const ocktabot_kinematics__srv__GetJointPosIK_Request *)(untyped_value);
  *item = *value;
}

bool ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Event__request(
  void * untyped_member, size_t size)
{
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence * member =
    (ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence *)(untyped_member);
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__fini(member);
  return ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence__init(member, size);
}

size_t ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Event__response(
  const void * untyped_member)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * member =
    (const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__response(
  const void * untyped_member, size_t index)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * member =
    (const ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__response(
  void * untyped_member, size_t index)
{
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * member =
    (ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ocktabot_kinematics__srv__GetJointPosIK_Response * item =
    ((const ocktabot_kinematics__srv__GetJointPosIK_Response *)
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__response(untyped_member, index));
  ocktabot_kinematics__srv__GetJointPosIK_Response * value =
    (ocktabot_kinematics__srv__GetJointPosIK_Response *)(untyped_value);
  *value = *item;
}

void ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ocktabot_kinematics__srv__GetJointPosIK_Response * item =
    ((ocktabot_kinematics__srv__GetJointPosIK_Response *)
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__response(untyped_member, index));
  const ocktabot_kinematics__srv__GetJointPosIK_Response * value =
    (const ocktabot_kinematics__srv__GetJointPosIK_Response *)(untyped_value);
  *item = *value;
}

bool ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Event__response(
  void * untyped_member, size_t size)
{
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence * member =
    (ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence *)(untyped_member);
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__fini(member);
  return ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Event, request),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Event__request,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__request,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__request,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Event__request,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Event__request,  // assign(index, value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ocktabot_kinematics__srv__GetJointPosIK_Event, response),  // bytes offset in struct
    NULL,  // default value
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__size_function__GetJointPosIK_Event__response,  // size() function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_const_function__GetJointPosIK_Event__response,  // get_const(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__get_function__GetJointPosIK_Event__response,  // get(index) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__fetch_function__GetJointPosIK_Event__response,  // fetch(index, &value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__assign_function__GetJointPosIK_Event__response,  // assign(index, value) function pointer
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__resize_function__GetJointPosIK_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_members = {
  "ocktabot_kinematics__srv",  // message namespace
  "GetJointPosIK_Event",  // message name
  3,  // number of fields
  sizeof(ocktabot_kinematics__srv__GetJointPosIK_Event),
  false,  // has_any_key_member_
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_member_array,  // message members
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_type_support_handle = {
  0,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_members,
  get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ocktabot_kinematics
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Event)() {
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Request)();
  ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Response)();
  if (!ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_type_support_handle.typesupport_identifier) {
    ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ocktabot_kinematics/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_members = {
  "ocktabot_kinematics__srv",  // service namespace
  "GetJointPosIK",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle,
  NULL,  // response message
  // ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle
  NULL  // event_message
  // ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle
};


static rosidl_service_type_support_t ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_type_support_handle = {
  0,
  &ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_members,
  get_service_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__rosidl_typesupport_introspection_c__GetJointPosIK_Request_message_type_support_handle,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__rosidl_typesupport_introspection_c__GetJointPosIK_Response_message_type_support_handle,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__rosidl_typesupport_introspection_c__GetJointPosIK_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ocktabot_kinematics,
    srv,
    GetJointPosIK
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ocktabot_kinematics,
    srv,
    GetJointPosIK
  ),
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ocktabot_kinematics
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK)(void) {
  if (!ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_type_support_handle.typesupport_identifier) {
    ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ocktabot_kinematics, srv, GetJointPosIK_Event)()->data;
  }

  return &ocktabot_kinematics__srv__detail__get_joint_pos_ik__rosidl_typesupport_introspection_c__GetJointPosIK_service_type_support_handle;
}
