// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetJointPosIK_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetJointPosIK_Request_type_support_ids_t;

static const _GetJointPosIK_Request_type_support_ids_t _GetJointPosIK_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetJointPosIK_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetJointPosIK_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetJointPosIK_Request_type_support_symbol_names_t _GetJointPosIK_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ocktabot_kinematics, srv, GetJointPosIK_Request)),
  }
};

typedef struct _GetJointPosIK_Request_type_support_data_t
{
  void * data[2];
} _GetJointPosIK_Request_type_support_data_t;

static _GetJointPosIK_Request_type_support_data_t _GetJointPosIK_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetJointPosIK_Request_message_typesupport_map = {
  2,
  "ocktabot_kinematics",
  &_GetJointPosIK_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetJointPosIK_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetJointPosIK_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetJointPosIK_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetJointPosIK_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Request>()
{
  return &::ocktabot_kinematics::srv::rosidl_typesupport_cpp::GetJointPosIK_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ocktabot_kinematics, srv, GetJointPosIK_Request)() {
  return get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetJointPosIK_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetJointPosIK_Response_type_support_ids_t;

static const _GetJointPosIK_Response_type_support_ids_t _GetJointPosIK_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetJointPosIK_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetJointPosIK_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetJointPosIK_Response_type_support_symbol_names_t _GetJointPosIK_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ocktabot_kinematics, srv, GetJointPosIK_Response)),
  }
};

typedef struct _GetJointPosIK_Response_type_support_data_t
{
  void * data[2];
} _GetJointPosIK_Response_type_support_data_t;

static _GetJointPosIK_Response_type_support_data_t _GetJointPosIK_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetJointPosIK_Response_message_typesupport_map = {
  2,
  "ocktabot_kinematics",
  &_GetJointPosIK_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetJointPosIK_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetJointPosIK_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetJointPosIK_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetJointPosIK_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Response>()
{
  return &::ocktabot_kinematics::srv::rosidl_typesupport_cpp::GetJointPosIK_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ocktabot_kinematics, srv, GetJointPosIK_Response)() {
  return get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__functions.h"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetJointPosIK_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetJointPosIK_Event_type_support_ids_t;

static const _GetJointPosIK_Event_type_support_ids_t _GetJointPosIK_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetJointPosIK_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetJointPosIK_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetJointPosIK_Event_type_support_symbol_names_t _GetJointPosIK_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ocktabot_kinematics, srv, GetJointPosIK_Event)),
  }
};

typedef struct _GetJointPosIK_Event_type_support_data_t
{
  void * data[2];
} _GetJointPosIK_Event_type_support_data_t;

static _GetJointPosIK_Event_type_support_data_t _GetJointPosIK_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetJointPosIK_Event_message_typesupport_map = {
  2,
  "ocktabot_kinematics",
  &_GetJointPosIK_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetJointPosIK_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetJointPosIK_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetJointPosIK_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetJointPosIK_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Event>()
{
  return &::ocktabot_kinematics::srv::rosidl_typesupport_cpp::GetJointPosIK_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, ocktabot_kinematics, srv, GetJointPosIK_Event)() {
  return get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ocktabot_kinematics
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetJointPosIK_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetJointPosIK_type_support_ids_t;

static const _GetJointPosIK_type_support_ids_t _GetJointPosIK_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetJointPosIK_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetJointPosIK_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetJointPosIK_type_support_symbol_names_t _GetJointPosIK_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ocktabot_kinematics, srv, GetJointPosIK)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ocktabot_kinematics, srv, GetJointPosIK)),
  }
};

typedef struct _GetJointPosIK_type_support_data_t
{
  void * data[2];
} _GetJointPosIK_type_support_data_t;

static _GetJointPosIK_type_support_data_t _GetJointPosIK_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetJointPosIK_service_typesupport_map = {
  2,
  "ocktabot_kinematics",
  &_GetJointPosIK_service_typesupport_ids.typesupport_identifier[0],
  &_GetJointPosIK_service_typesupport_symbol_names.symbol_name[0],
  &_GetJointPosIK_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetJointPosIK_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetJointPosIK_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<ocktabot_kinematics::srv::GetJointPosIK>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<ocktabot_kinematics::srv::GetJointPosIK>,
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_hash,
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_description,
  &ocktabot_kinematics__srv__GetJointPosIK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace ocktabot_kinematics

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK>()
{
  return &::ocktabot_kinematics::srv::rosidl_typesupport_cpp::GetJointPosIK_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, ocktabot_kinematics, srv, GetJointPosIK)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<ocktabot_kinematics::srv::GetJointPosIK>();
}

#ifdef __cplusplus
}
#endif
