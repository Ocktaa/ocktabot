// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ocktabot_kinematics/srv/get_joint_pos_ik.h"


#ifndef OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_H_
#define OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetJointPosIK in the package ocktabot_kinematics.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Request
{
  double target[6];
} ocktabot_kinematics__srv__GetJointPosIK_Request;

// Struct for a sequence of ocktabot_kinematics__srv__GetJointPosIK_Request.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence
{
  ocktabot_kinematics__srv__GetJointPosIK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetJointPosIK in the package ocktabot_kinematics.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Response
{
  bool success;
  rosidl_runtime_c__String message;
  /// motor names, same order as /motor_jointstate
  rosidl_runtime_c__String__Sequence name;
  /// in the units of /motor_jointstate
  double motor_positions[3];
  /// full end-effector pose reached at that solution
  double pose[6];
} ocktabot_kinematics__srv__GetJointPosIK_Response;

// Struct for a sequence of ocktabot_kinematics__srv__GetJointPosIK_Response.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence
{
  ocktabot_kinematics__srv__GetJointPosIK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ocktabot_kinematics__srv__GetJointPosIK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ocktabot_kinematics__srv__GetJointPosIK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetJointPosIK in the package ocktabot_kinematics.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ocktabot_kinematics__srv__GetJointPosIK_Request__Sequence request;
  ocktabot_kinematics__srv__GetJointPosIK_Response__Sequence response;
} ocktabot_kinematics__srv__GetJointPosIK_Event;

// Struct for a sequence of ocktabot_kinematics__srv__GetJointPosIK_Event.
typedef struct ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence
{
  ocktabot_kinematics__srv__GetJointPosIK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ocktabot_kinematics__srv__GetJointPosIK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_H_
