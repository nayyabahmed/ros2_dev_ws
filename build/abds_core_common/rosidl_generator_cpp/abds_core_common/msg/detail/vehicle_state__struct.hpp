// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_core_common:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__STRUCT_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'state'
#include "abds_core_common/msg/detail/trajectory_point__struct.hpp"
// Member 'delta'
#include "geometry_msgs/msg/detail/transform__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_core_common__msg__VehicleState __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__msg__VehicleState __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleState_
{
  using Type = VehicleState_<ContainerAllocator>;

  explicit VehicleState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    state(_init),
    delta(_init)
  {
    (void)_init;
  }

  explicit VehicleState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    state(_alloc, _init),
    delta(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _state_type =
    abds_core_common::msg::TrajectoryPoint_<ContainerAllocator>;
  _state_type state;
  using _delta_type =
    geometry_msgs::msg::Transform_<ContainerAllocator>;
  _delta_type delta;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__state(
    const abds_core_common::msg::TrajectoryPoint_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__delta(
    const geometry_msgs::msg::Transform_<ContainerAllocator> & _arg)
  {
    this->delta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::msg::VehicleState_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::msg::VehicleState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::VehicleState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::VehicleState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__msg__VehicleState
    std::shared_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__msg__VehicleState
    std::shared_ptr<abds_core_common::msg::VehicleState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->delta != other.delta) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleState_

// alias to use template instance with default allocator
using VehicleState =
  abds_core_common::msg::VehicleState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__STRUCT_HPP_
