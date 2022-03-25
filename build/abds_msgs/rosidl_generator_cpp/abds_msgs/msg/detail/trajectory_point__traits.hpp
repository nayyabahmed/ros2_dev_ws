// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_
#define ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_

#include "abds_msgs/msg/detail/trajectory_point__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'time_from_start'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_msgs::msg::TrajectoryPoint>()
{
  return "abds_msgs::msg::TrajectoryPoint";
}

template<>
inline const char * name<abds_msgs::msg::TrajectoryPoint>()
{
  return "abds_msgs/msg/TrajectoryPoint";
}

template<>
struct has_fixed_size<abds_msgs::msg::TrajectoryPoint>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Duration>::value && has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<abds_msgs::msg::TrajectoryPoint>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Duration>::value && has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<abds_msgs::msg::TrajectoryPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_
