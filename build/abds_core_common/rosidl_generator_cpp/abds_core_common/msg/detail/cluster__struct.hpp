// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_core_common:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point32__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_core_common__msg__Cluster __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__msg__Cluster __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Cluster_
{
  using Type = Cluster_<ContainerAllocator>;

  explicit Cluster_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Cluster_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _points_type =
    std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point32_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point32_<ContainerAllocator>>::other> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::msg::Cluster_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::msg::Cluster_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::msg::Cluster_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::msg::Cluster_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::Cluster_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::Cluster_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::Cluster_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::Cluster_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::msg::Cluster_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::msg::Cluster_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__msg__Cluster
    std::shared_ptr<abds_core_common::msg::Cluster_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__msg__Cluster
    std::shared_ptr<abds_core_common::msg::Cluster_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cluster_ & other) const
  {
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cluster_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cluster_

// alias to use template instance with default allocator
using Cluster =
  abds_core_common::msg::Cluster_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__STRUCT_HPP_
