// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_core_common:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_

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
// Member 'points'
#include "abds_core_common/msg/detail/trajectory_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_core_common__msg__Trajectory __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__msg__Trajectory __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Trajectory_
{
  using Type = Trajectory_<ContainerAllocator>;

  explicit Trajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Trajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _points_type =
    std::vector<abds_core_common::msg::TrajectoryPoint_<ContainerAllocator>, typename ContainerAllocator::template rebind<abds_core_common::msg::TrajectoryPoint_<ContainerAllocator>>::other>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<abds_core_common::msg::TrajectoryPoint_<ContainerAllocator>, typename ContainerAllocator::template rebind<abds_core_common::msg::TrajectoryPoint_<ContainerAllocator>>::other> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::msg::Trajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::msg::Trajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::Trajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::Trajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__msg__Trajectory
    std::shared_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__msg__Trajectory
    std::shared_ptr<abds_core_common::msg::Trajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trajectory_

// alias to use template instance with default allocator
using Trajectory =
  abds_core_common::msg::Trajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
