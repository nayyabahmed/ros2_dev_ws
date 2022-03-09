// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__TRAITS_HPP_
#define RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__TRAITS_HPP_

#include "rc_interfaces/msg/detail/target_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rc_interfaces::msg::TargetCoordinates>()
{
  return "rc_interfaces::msg::TargetCoordinates";
}

template<>
inline const char * name<rc_interfaces::msg::TargetCoordinates>()
{
  return "rc_interfaces/msg/TargetCoordinates";
}

template<>
struct has_fixed_size<rc_interfaces::msg::TargetCoordinates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rc_interfaces::msg::TargetCoordinates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rc_interfaces::msg::TargetCoordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__TRAITS_HPP_
