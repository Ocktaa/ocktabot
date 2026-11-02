// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ocktabot_kinematics:srv/GetJointPosIK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ocktabot_kinematics/srv/get_joint_pos_ik.hpp"


#ifndef OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_HPP_
#define OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Request __attribute__((deprecated))
#else
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Request __declspec(deprecated)
#endif

namespace ocktabot_kinematics
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetJointPosIK_Request_
{
  using Type = GetJointPosIK_Request_<ContainerAllocator>;

  explicit GetJointPosIK_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->target.begin(), this->target.end(), 0.0);
    }
  }

  explicit GetJointPosIK_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->target.begin(), this->target.end(), 0.0);
    }
  }

  // field types and members
  using _target_type =
    std::array<double, 6>;
  _target_type target;

  // setters for named parameter idiom
  Type & set__target(
    const std::array<double, 6> & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Request
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Request
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetJointPosIK_Request_ & other) const
  {
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetJointPosIK_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetJointPosIK_Request_

// alias to use template instance with default allocator
using GetJointPosIK_Request =
  ocktabot_kinematics::srv::GetJointPosIK_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ocktabot_kinematics


#ifndef _WIN32
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Response __attribute__((deprecated))
#else
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Response __declspec(deprecated)
#endif

namespace ocktabot_kinematics
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetJointPosIK_Response_
{
  using Type = GetJointPosIK_Response_<ContainerAllocator>;

  explicit GetJointPosIK_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->motor_positions.begin(), this->motor_positions.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->pose.begin(), this->pose.end(), 0.0);
    }
  }

  explicit GetJointPosIK_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    motor_positions(_alloc),
    pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      std::fill<typename std::array<double, 3>::iterator, double>(this->motor_positions.begin(), this->motor_positions.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->pose.begin(), this->pose.end(), 0.0);
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _name_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _name_type name;
  using _motor_positions_type =
    std::array<double, 3>;
  _motor_positions_type motor_positions;
  using _pose_type =
    std::array<double, 6>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__name(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__motor_positions(
    const std::array<double, 3> & _arg)
  {
    this->motor_positions = _arg;
    return *this;
  }
  Type & set__pose(
    const std::array<double, 6> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Response
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Response
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetJointPosIK_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->motor_positions != other.motor_positions) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetJointPosIK_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetJointPosIK_Response_

// alias to use template instance with default allocator
using GetJointPosIK_Response =
  ocktabot_kinematics::srv::GetJointPosIK_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ocktabot_kinematics


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Event __attribute__((deprecated))
#else
# define DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Event __declspec(deprecated)
#endif

namespace ocktabot_kinematics
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetJointPosIK_Event_
{
  using Type = GetJointPosIK_Event_<ContainerAllocator>;

  explicit GetJointPosIK_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetJointPosIK_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ocktabot_kinematics::srv::GetJointPosIK_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ocktabot_kinematics::srv::GetJointPosIK_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Event
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ocktabot_kinematics__srv__GetJointPosIK_Event
    std::shared_ptr<ocktabot_kinematics::srv::GetJointPosIK_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetJointPosIK_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetJointPosIK_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetJointPosIK_Event_

// alias to use template instance with default allocator
using GetJointPosIK_Event =
  ocktabot_kinematics::srv::GetJointPosIK_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ocktabot_kinematics

namespace ocktabot_kinematics
{

namespace srv
{

struct GetJointPosIK
{
  using Request = ocktabot_kinematics::srv::GetJointPosIK_Request;
  using Response = ocktabot_kinematics::srv::GetJointPosIK_Response;
  using Event = ocktabot_kinematics::srv::GetJointPosIK_Event;
};

}  // namespace srv

}  // namespace ocktabot_kinematics

#endif  // OCKTABOT_KINEMATICS__SRV__DETAIL__GET_JOINT_POS_IK__STRUCT_HPP_
