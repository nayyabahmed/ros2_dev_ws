// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_msgs__msg__VehicleCommand __attribute__((deprecated))
#else
# define DEPRECATED__abds_msgs__msg__VehicleCommand __declspec(deprecated)
#endif

namespace abds_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleCommand_
{
  using Type = VehicleCommand_<ContainerAllocator>;

  explicit VehicleCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->long_accel = 0.0f;
      this->velocity_modifier = 0.0f;
      this->front_wheel_angle = 0.0f;
      this->rear_wheel_angle = 0.0f;
    }
  }

  explicit VehicleCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->long_accel = 0.0f;
      this->velocity_modifier = 0.0f;
      this->front_wheel_angle = 0.0f;
      this->rear_wheel_angle = 0.0f;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _long_accel_type =
    float;
  _long_accel_type long_accel;
  using _velocity_modifier_type =
    float;
  _velocity_modifier_type velocity_modifier;
  using _front_wheel_angle_type =
    float;
  _front_wheel_angle_type front_wheel_angle;
  using _rear_wheel_angle_type =
    float;
  _rear_wheel_angle_type rear_wheel_angle;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__long_accel(
    const float & _arg)
  {
    this->long_accel = _arg;
    return *this;
  }
  Type & set__velocity_modifier(
    const float & _arg)
  {
    this->velocity_modifier = _arg;
    return *this;
  }
  Type & set__front_wheel_angle(
    const float & _arg)
  {
    this->front_wheel_angle = _arg;
    return *this;
  }
  Type & set__rear_wheel_angle(
    const float & _arg)
  {
    this->rear_wheel_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_msgs::msg::VehicleCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_msgs::msg::VehicleCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::VehicleCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::VehicleCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_msgs__msg__VehicleCommand
    std::shared_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_msgs__msg__VehicleCommand
    std::shared_ptr<abds_msgs::msg::VehicleCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleCommand_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->long_accel != other.long_accel) {
      return false;
    }
    if (this->velocity_modifier != other.velocity_modifier) {
      return false;
    }
    if (this->front_wheel_angle != other.front_wheel_angle) {
      return false;
    }
    if (this->rear_wheel_angle != other.rear_wheel_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleCommand_

// alias to use template instance with default allocator
using VehicleCommand =
  abds_msgs::msg::VehicleCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_HPP_
