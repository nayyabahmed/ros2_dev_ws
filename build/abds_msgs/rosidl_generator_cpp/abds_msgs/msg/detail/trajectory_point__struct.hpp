// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_
#define ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'time_from_start'
#include "builtin_interfaces/msg/detail/duration__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__abds_msgs__msg__TrajectoryPoint __attribute__((deprecated))
#else
# define DEPRECATED__abds_msgs__msg__TrajectoryPoint __declspec(deprecated)
#endif

namespace abds_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrajectoryPoint_
{
  using Type = TrajectoryPoint_<ContainerAllocator>;

  explicit TrajectoryPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_from_start(_init),
    pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->datum_bearing = 0.0f;
      this->dist_along_path = 0.0f;
      this->longitudinal_velocity = 0.0f;
      this->lateral_velocity = 0.0f;
      this->acceleration = 0.0f;
      this->heading_rate = 0.0f;
      this->instantanious_curvature = 0.0f;
    }
  }

  explicit TrajectoryPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : time_from_start(_alloc, _init),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->datum_bearing = 0.0f;
      this->dist_along_path = 0.0f;
      this->longitudinal_velocity = 0.0f;
      this->lateral_velocity = 0.0f;
      this->acceleration = 0.0f;
      this->heading_rate = 0.0f;
      this->instantanious_curvature = 0.0f;
    }
  }

  // field types and members
  using _time_from_start_type =
    builtin_interfaces::msg::Duration_<ContainerAllocator>;
  _time_from_start_type time_from_start;
  using _datum_bearing_type =
    float;
  _datum_bearing_type datum_bearing;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _dist_along_path_type =
    float;
  _dist_along_path_type dist_along_path;
  using _longitudinal_velocity_type =
    float;
  _longitudinal_velocity_type longitudinal_velocity;
  using _lateral_velocity_type =
    float;
  _lateral_velocity_type lateral_velocity;
  using _acceleration_type =
    float;
  _acceleration_type acceleration;
  using _heading_rate_type =
    float;
  _heading_rate_type heading_rate;
  using _instantanious_curvature_type =
    float;
  _instantanious_curvature_type instantanious_curvature;

  // setters for named parameter idiom
  Type & set__time_from_start(
    const builtin_interfaces::msg::Duration_<ContainerAllocator> & _arg)
  {
    this->time_from_start = _arg;
    return *this;
  }
  Type & set__datum_bearing(
    const float & _arg)
  {
    this->datum_bearing = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__dist_along_path(
    const float & _arg)
  {
    this->dist_along_path = _arg;
    return *this;
  }
  Type & set__longitudinal_velocity(
    const float & _arg)
  {
    this->longitudinal_velocity = _arg;
    return *this;
  }
  Type & set__lateral_velocity(
    const float & _arg)
  {
    this->lateral_velocity = _arg;
    return *this;
  }
  Type & set__acceleration(
    const float & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__heading_rate(
    const float & _arg)
  {
    this->heading_rate = _arg;
    return *this;
  }
  Type & set__instantanious_curvature(
    const float & _arg)
  {
    this->instantanious_curvature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_msgs__msg__TrajectoryPoint
    std::shared_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_msgs__msg__TrajectoryPoint
    std::shared_ptr<abds_msgs::msg::TrajectoryPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryPoint_ & other) const
  {
    if (this->time_from_start != other.time_from_start) {
      return false;
    }
    if (this->datum_bearing != other.datum_bearing) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->dist_along_path != other.dist_along_path) {
      return false;
    }
    if (this->longitudinal_velocity != other.longitudinal_velocity) {
      return false;
    }
    if (this->lateral_velocity != other.lateral_velocity) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->heading_rate != other.heading_rate) {
      return false;
    }
    if (this->instantanious_curvature != other.instantanious_curvature) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryPoint_

// alias to use template instance with default allocator
using TrajectoryPoint =
  abds_msgs::msg::TrajectoryPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_
