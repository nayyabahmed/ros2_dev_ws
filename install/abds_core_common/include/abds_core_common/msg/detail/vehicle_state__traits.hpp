// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_core_common:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__TRAITS_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__TRAITS_HPP_

#include "abds_core_common/msg/detail/vehicle_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'state'
#include "abds_core_common/msg/detail/trajectory_point__traits.hpp"
// Member 'delta'
#include "geometry_msgs/msg/detail/transform__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::msg::VehicleState>()
{
  return "abds_core_common::msg::VehicleState";
}

template<>
inline const char * name<abds_core_common::msg::VehicleState>()
{
  return "abds_core_common/msg/VehicleState";
}

template<>
struct has_fixed_size<abds_core_common::msg::VehicleState>
  : std::integral_constant<bool, has_fixed_size<abds_core_common::msg::TrajectoryPoint>::value && has_fixed_size<geometry_msgs::msg::Transform>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<abds_core_common::msg::VehicleState>
  : std::integral_constant<bool, has_bounded_size<abds_core_common::msg::TrajectoryPoint>::value && has_bounded_size<geometry_msgs::msg::Transform>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<abds_core_common::msg::VehicleState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__VEHICLE_STATE__TRAITS_HPP_
