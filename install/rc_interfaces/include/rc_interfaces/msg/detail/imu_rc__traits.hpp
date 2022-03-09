// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__IMU_RC__TRAITS_HPP_
#define RC_INTERFACES__MSG__DETAIL__IMU_RC__TRAITS_HPP_

#include "rc_interfaces/msg/detail/imu_rc__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"
// Member 'accel'
#include "geometry_msgs/msg/detail/accel__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rc_interfaces::msg::ImuRc>()
{
  return "rc_interfaces::msg::ImuRc";
}

template<>
inline const char * name<rc_interfaces::msg::ImuRc>()
{
  return "rc_interfaces/msg/ImuRc";
}

template<>
struct has_fixed_size<rc_interfaces::msg::ImuRc>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rc_interfaces::msg::ImuRc>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rc_interfaces::msg::ImuRc>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RC_INTERFACES__MSG__DETAIL__IMU_RC__TRAITS_HPP_
