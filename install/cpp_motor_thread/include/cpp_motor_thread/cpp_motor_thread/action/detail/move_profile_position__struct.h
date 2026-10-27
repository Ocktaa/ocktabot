// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_motor_thread:action/MoveProfilePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_motor_thread/action/move_profile_position.h"


#ifndef CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__STRUCT_H_
#define CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Goal
{
  uint16_t node;
  int32_t goal_position;
} cpp_motor_thread__action__MoveProfilePosition_Goal;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_Goal.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_Goal__Sequence;

// Constants defined in the message

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Result
{
  int32_t end_position;
} cpp_motor_thread__action__MoveProfilePosition_Result;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_Result.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Result__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Feedback
{
  int32_t current_position;
} cpp_motor_thread__action__MoveProfilePosition_Feedback;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_Feedback.
typedef struct cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "cpp_motor_thread/action/detail/move_profile_position__struct.h"

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  cpp_motor_thread__action__MoveProfilePosition_Goal goal;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Request__Sequence request;
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Response__Sequence response;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event.
typedef struct cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Request;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_GetResult_Request.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__struct.h"

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Response
{
  int8_t status;
  cpp_motor_thread__action__MoveProfilePosition_Result result;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Response;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_GetResult_Response.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Request__Sequence request;
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Response__Sequence response;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Event;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_GetResult_Event.
typedef struct cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "cpp_motor_thread/action/detail/move_profile_position__struct.h"

/// Struct defined in action/MoveProfilePosition in the package cpp_motor_thread.
typedef struct cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  cpp_motor_thread__action__MoveProfilePosition_Feedback feedback;
} cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage;

// Struct for a sequence of cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage.
typedef struct cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence
{
  cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_motor_thread__action__MoveProfilePosition_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__STRUCT_H_
