// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_HPP_
#define RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rc_interfaces__msg__ImuRc __attribute__((deprecated))
#else
# define DEPRECATED__rc_interfaces__msg__ImuRc __declspec(deprecated)
#endif

namespace rc_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuRc_
{
  using Type = ImuRc_<ContainerAllocator>;

  explicit ImuRc_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    twist(_init),
    accel(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->msg_count = 0l;
      this->mp_time = 0.0;
      this->mp_lat = 0.0f;
      this->mp_longt = 0.0f;
      this->mp_bearing = 0.0f;
      this->yaw_angle = 0.0f;
    }
  }

  explicit ImuRc_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pose(_alloc, _init),
    twist(_alloc, _init),
    accel(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->msg_count = 0l;
      this->mp_time = 0.0;
      this->mp_lat = 0.0f;
      this->mp_longt = 0.0f;
      this->mp_bearing = 0.0f;
      this->yaw_angle = 0.0f;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _msg_count_type =
    int32_t;
  _msg_count_type msg_count;
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
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _twist_type twist;
  using _accel_type =
    geometry_msgs::msg::Accel_<ContainerAllocator>;
  _accel_type accel;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__msg_count(
    const int32_t & _arg)
  {
    this->msg_count = _arg;
    return *this;
  }
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
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->twist = _arg;
    return *this;
  }
  Type & set__accel(
    const geometry_msgs::msg::Accel_<ContainerAllocator> & _arg)
  {
    this->accel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rc_interfaces::msg::ImuRc_<ContainerAllocator> *;
  using ConstRawPtr =
    const rc_interfaces::msg::ImuRc_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rc_interfaces::msg::ImuRc_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rc_interfaces::msg::ImuRc_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rc_interfaces__msg__ImuRc
    std::shared_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rc_interfaces__msg__ImuRc
    std::shared_ptr<rc_interfaces::msg::ImuRc_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuRc_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->msg_count != other.msg_count) {
      return false;
    }
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
    if (this->pose != other.pose) {
      return false;
    }
    if (this->twist != other.twist) {
      return false;
    }
    if (this->accel != other.accel) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuRc_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuRc_

// alias to use template instance with default allocator
using ImuRc =
  rc_interfaces::msg::ImuRc_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rc_interfaces

#endif  // RC_INTERFACES__MSG__DETAIL__IMU_RC__STRUCT_HPP_
