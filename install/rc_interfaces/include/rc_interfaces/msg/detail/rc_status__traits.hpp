// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__RC_STATUS__TRAITS_HPP_
#define RC_INTERFACES__MSG__DETAIL__RC_STATUS__TRAITS_HPP_

#include "rc_interfaces/msg/detail/rc_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rc_interfaces::msg::RcStatus>()
{
  return "rc_interfaces::msg::RcStatus";
}

template<>
inline const char * name<rc_interfaces::msg::RcStatus>()
{
  return "rc_interfaces/msg/RcStatus";
}

template<>
struct has_fixed_size<rc_interfaces::msg::RcStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rc_interfaces::msg::RcStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rc_interfaces::msg::RcStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RC_INTERFACES__MSG__DETAIL__RC_STATUS__TRAITS_HPP_
