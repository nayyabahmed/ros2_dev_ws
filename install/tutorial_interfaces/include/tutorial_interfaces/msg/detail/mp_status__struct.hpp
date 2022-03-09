// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__MpStatus __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__MpStatus __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MpStatus_
{
  using Type = MpStatus_<ContainerAllocator>;

  explicit MpStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mp_time = 0.0;
      this->mp_lat = 0.0f;
      this->mp_longt = 0.0f;
      this->mp_bearing = 0.0f;
      this->yaw_angle = 0.0f;
    }
  }

  explicit MpStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mp_time = 0.0;
      this->mp_lat = 0.0f;
      this->mp_longt = 0.0f;
      this->mp_bearing = 0.0f;
      this->yaw_angle = 0.0f;
    }
  }

  // field types and members
  using _mp_time_type =
    double;
  _mp_time_type mp_time;
  using _mp_lat_type =
    float;
  _mp_lat_type mp_lat;
  using _mp_longt_type =
    float;
  _mp_longt_type mp_longt;
  using _mp_bearing_type =
    float;
  _mp_bearing_type mp_bearing;
  using _yaw_angle_type =
    float;
  _yaw_angle_type yaw_angle;

  // setters for named parameter idiom
  Type & set__mp_time(
    const double & _arg)
  {
    this->mp_time = _arg;
    return *this;
  }
  Type & set__mp_lat(
    const float & _arg)
  {
    this->mp_lat = _arg;
    return *this;
  }
  Type & set__mp_longt(
    const float & _arg)
  {
    this->mp_longt = _arg;
    return *this;
  }
  Type & set__mp_bearing(
    const float & _arg)
  {
    this->mp_bearing = _arg;
    return *this;
  }
  Type & set__yaw_angle(
    const float & _arg)
  {
    this->yaw_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::MpStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::MpStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::MpStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::MpStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__MpStatus
    std::shared_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__MpStatus
    std::shared_ptr<tutorial_interfaces::msg::MpStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MpStatus_ & other) const
  {
    if (this->mp_time != other.mp_time) {
      return false;
    }
    if (this->mp_lat != other.mp_lat) {
      return false;
    }
    if (this->mp_longt != other.mp_longt) {
      return false;
    }
    if (this->mp_bearing != other.mp_bearing) {
      return false;
    }
    if (this->yaw_angle != other.yaw_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const MpStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MpStatus_

// alias to use template instance with default allocator
using MpStatus =
  tutorial_interfaces::msg::MpStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__STRUCT_HPP_
