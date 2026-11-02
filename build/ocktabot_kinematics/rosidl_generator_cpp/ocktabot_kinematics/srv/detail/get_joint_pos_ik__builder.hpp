// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ocktabot_kinematics/srv/get_joint_pos_ik.hpp"


#ifndef OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__BUILDER_HPP_
#define OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ocktabot_kinematics/srv/detail/get_joint_pos_ik__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ocktabot_kinematics
{

namespace srv
{

namespace builder
{

class Init_GetJointPosIK_Request_target
{
public:
  Init_GetJointPosIK_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ocktabot_kinematics::srv::GetJointPosIK_Request target(::ocktabot_kinematics::srv::GetJointPosIK_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ocktabot_kinematics::srv::GetJointPosIK_Request>()
{
  return ocktabot_kinematics::srv::builder::Init_GetJointPosIK_Request_target();
}

}  // namespace ocktabot_kinematics


namespace ocktabot_kinematics
{

namespace srv
{

namespace builder
{

class Init_GetJointPosIK_Response_pose
{
public:
  explicit Init_GetJointPosIK_Response_pose(::ocktabot_kinematics::srv::GetJointPosIK_Response & msg)
  : msg_(msg)
  {}
  ::ocktabot_kinematics::srv::GetJointPosIK_Response pose(::ocktabot_kinematics::srv::GetJointPosIK_Response::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Response msg_;
};

class Init_GetJointPosIK_Response_motor_positions
{
public:
  explicit Init_GetJointPosIK_Response_motor_positions(::ocktabot_kinematics::srv::GetJointPosIK_Response & msg)
  : msg_(msg)
  {}
  Init_GetJointPosIK_Response_pose motor_positions(::ocktabot_kinematics::srv::GetJointPosIK_Response::_motor_positions_type arg)
  {
    msg_.motor_positions = std::move(arg);
    return Init_GetJointPosIK_Response_pose(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Response msg_;
};

class Init_GetJointPosIK_Response_name
{
public:
  explicit Init_GetJointPosIK_Response_name(::ocktabot_kinematics::srv::GetJointPosIK_Response & msg)
  : msg_(msg)
  {}
  Init_GetJointPosIK_Response_motor_positions name(::ocktabot_kinematics::srv::GetJointPosIK_Response::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_GetJointPosIK_Response_motor_positions(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Response msg_;
};

class Init_GetJointPosIK_Response_message
{
public:
  explicit Init_GetJointPosIK_Response_message(::ocktabot_kinematics::srv::GetJointPosIK_Response & msg)
  : msg_(msg)
  {}
  Init_GetJointPosIK_Response_name message(::ocktabot_kinematics::srv::GetJointPosIK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetJointPosIK_Response_name(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Response msg_;
};

class Init_GetJointPosIK_Response_success
{
public:
  Init_GetJointPosIK_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetJointPosIK_Response_message success(::ocktabot_kinematics::srv::GetJointPosIK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetJointPosIK_Response_message(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ocktabot_kinematics::srv::GetJointPosIK_Response>()
{
  return ocktabot_kinematics::srv::builder::Init_GetJointPosIK_Response_success();
}

}  // namespace ocktabot_kinematics


namespace ocktabot_kinematics
{

namespace srv
{

namespace builder
{

class Init_GetJointPosIK_Event_response
{
public:
  explicit Init_GetJointPosIK_Event_response(::ocktabot_kinematics::srv::GetJointPosIK_Event & msg)
  : msg_(msg)
  {}
  ::ocktabot_kinematics::srv::GetJointPosIK_Event response(::ocktabot_kinematics::srv::GetJointPosIK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Event msg_;
};

class Init_GetJointPosIK_Event_request
{
public:
  explicit Init_GetJointPosIK_Event_request(::ocktabot_kinematics::srv::GetJointPosIK_Event & msg)
  : msg_(msg)
  {}
  Init_GetJointPosIK_Event_response request(::ocktabot_kinematics::srv::GetJointPosIK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetJointPosIK_Event_response(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Event msg_;
};

class Init_GetJointPosIK_Event_info
{
public:
  Init_GetJointPosIK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetJointPosIK_Event_request info(::ocktabot_kinematics::srv::GetJointPosIK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetJointPosIK_Event_request(msg_);
  }

private:
  ::ocktabot_kinematics::srv::GetJointPosIK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ocktabot_kinematics::srv::GetJointPosIK_Event>()
{
  return ocktabot_kinematics::srv::builder::Init_GetJointPosIK_Event_info();
}

}  // namespace ocktabot_kinematics

#endif  // OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__BUILDER_HPP_
