// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_motor_thread:action/MoveProfilePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_motor_thread/action/move_profile_position.hpp"


#ifndef CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__BUILDER_HPP_
#define CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cpp_motor_thread/action/detail/move_profile_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_Goal_goal_position
{
public:
  explicit Init_MoveProfilePosition_Goal_goal_position(::cpp_motor_thread::action::MoveProfilePosition_Goal & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_Goal goal_position(::cpp_motor_thread::action::MoveProfilePosition_Goal::_goal_position_type arg)
  {
    msg_.goal_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_Goal msg_;
};

class Init_MoveProfilePosition_Goal_node
{
public:
  Init_MoveProfilePosition_Goal_node()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_Goal_goal_position node(::cpp_motor_thread::action::MoveProfilePosition_Goal::_node_type arg)
  {
    msg_.node = std::move(arg);
    return Init_MoveProfilePosition_Goal_goal_position(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_Goal>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_Goal_node();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_Result_end_position
{
public:
  Init_MoveProfilePosition_Result_end_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_Result end_position(::cpp_motor_thread::action::MoveProfilePosition_Result::_end_position_type arg)
  {
    msg_.end_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_Result>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_Result_end_position();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_Feedback_current_position
{
public:
  Init_MoveProfilePosition_Feedback_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_Feedback current_position(::cpp_motor_thread::action::MoveProfilePosition_Feedback::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_Feedback>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_Feedback_current_position();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_SendGoal_Request_goal
{
public:
  explicit Init_MoveProfilePosition_SendGoal_Request_goal(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request goal(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request msg_;
};

class Init_MoveProfilePosition_SendGoal_Request_goal_id
{
public:
  Init_MoveProfilePosition_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_SendGoal_Request_goal goal_id(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveProfilePosition_SendGoal_Request_goal(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Request>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_SendGoal_Request_goal_id();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_SendGoal_Response_stamp
{
public:
  explicit Init_MoveProfilePosition_SendGoal_Response_stamp(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response stamp(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response msg_;
};

class Init_MoveProfilePosition_SendGoal_Response_accepted
{
public:
  Init_MoveProfilePosition_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_SendGoal_Response_stamp accepted(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveProfilePosition_SendGoal_Response_stamp(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Response>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_SendGoal_Response_accepted();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_SendGoal_Event_response
{
public:
  explicit Init_MoveProfilePosition_SendGoal_Event_response(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event response(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event msg_;
};

class Init_MoveProfilePosition_SendGoal_Event_request
{
public:
  explicit Init_MoveProfilePosition_SendGoal_Event_request(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_MoveProfilePosition_SendGoal_Event_response request(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveProfilePosition_SendGoal_Event_response(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event msg_;
};

class Init_MoveProfilePosition_SendGoal_Event_info
{
public:
  Init_MoveProfilePosition_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_SendGoal_Event_request info(::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveProfilePosition_SendGoal_Event_request(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_SendGoal_Event>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_SendGoal_Event_info();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_GetResult_Request_goal_id
{
public:
  Init_MoveProfilePosition_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Request goal_id(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_GetResult_Request>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_GetResult_Request_goal_id();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_GetResult_Response_result
{
public:
  explicit Init_MoveProfilePosition_GetResult_Response_result(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response result(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response msg_;
};

class Init_MoveProfilePosition_GetResult_Response_status
{
public:
  Init_MoveProfilePosition_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_GetResult_Response_result status(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveProfilePosition_GetResult_Response_result(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_GetResult_Response>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_GetResult_Response_status();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_GetResult_Event_response
{
public:
  explicit Init_MoveProfilePosition_GetResult_Event_response(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event response(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event msg_;
};

class Init_MoveProfilePosition_GetResult_Event_request
{
public:
  explicit Init_MoveProfilePosition_GetResult_Event_request(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_MoveProfilePosition_GetResult_Event_response request(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveProfilePosition_GetResult_Event_response(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event msg_;
};

class Init_MoveProfilePosition_GetResult_Event_info
{
public:
  Init_MoveProfilePosition_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_GetResult_Event_request info(::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveProfilePosition_GetResult_Event_request(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_GetResult_Event>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_GetResult_Event_info();
}

}  // namespace cpp_motor_thread


namespace cpp_motor_thread
{

namespace action
{

namespace builder
{

class Init_MoveProfilePosition_FeedbackMessage_feedback
{
public:
  explicit Init_MoveProfilePosition_FeedbackMessage_feedback(::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage feedback(::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage msg_;
};

class Init_MoveProfilePosition_FeedbackMessage_goal_id
{
public:
  Init_MoveProfilePosition_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveProfilePosition_FeedbackMessage_feedback goal_id(::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveProfilePosition_FeedbackMessage_feedback(msg_);
  }

private:
  ::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_motor_thread::action::MoveProfilePosition_FeedbackMessage>()
{
  return cpp_motor_thread::action::builder::Init_MoveProfilePosition_FeedbackMessage_goal_id();
}

}  // namespace cpp_motor_thread

#endif  // CPP_MOTOR_THREAD__ACTION__DETAIL__MOVE_PROFILE_POSITION__BUILDER_HPP_
