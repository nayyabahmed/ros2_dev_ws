// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_
#define ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_

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
// Member 'boxes'
#include "abds_msgs/msg/detail/bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_msgs__msg__BoundingBoxes __attribute__((deprecated))
#else
# define DEPRECATED__abds_msgs__msg__BoundingBoxes __declspec(deprecated)
#endif

namespace abds_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BoundingBoxes_
{
  using Type = BoundingBoxes_<ContainerAllocator>;

  explicit BoundingBoxes_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit BoundingBoxes_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _boxes_type =
    std::vector<abds_msgs::msg::BoundingBox_<ContainerAllocator>, typename ContainerAllocator::template rebind<abds_msgs::msg::BoundingBox_<ContainerAllocator>>::other>;
  _boxes_type boxes;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::vector<abds_msgs::msg::BoundingBox_<ContainerAllocator>, typename ContainerAllocator::template rebind<abds_msgs::msg::BoundingBox_<ContainerAllocator>>::other> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_msgs::msg::BoundingBoxes_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_msgs::msg::BoundingBoxes_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::BoundingBoxes_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::BoundingBoxes_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_msgs__msg__BoundingBoxes
    std::shared_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_msgs__msg__BoundingBoxes
    std::shared_ptr<abds_msgs::msg::BoundingBoxes_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoundingBoxes_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoundingBoxes_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoundingBoxes_

// alias to use template instance with default allocator
using BoundingBoxes =
  abds_msgs::msg::BoundingBoxes_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__STRUCT_HPP_