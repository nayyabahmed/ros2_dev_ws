// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_

#include "abds_msgs/msg/detail/vehicle_command__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_msgs::msg::VehicleCommand>()
{
  return "abds_msgs::msg::VehicleCommand";
}

template<>
inline const char * name<abds_msgs::msg::VehicleCommand>()
{
  return "abds_msgs/msg/VehicleCommand";
}

template<>
struct has_fixed_size<abds_msgs::msg::VehicleCommand>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<abds_msgs::msg::VehicleCommand>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<abds_msgs::msg::VehicleCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__TRAITS_HPP_
