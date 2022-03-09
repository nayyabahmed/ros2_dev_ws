// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__TRAITS_HPP_

#include "tutorial_interfaces/msg/detail/mp_status__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tutorial_interfaces::msg::MpStatus>()
{
  return "tutorial_interfaces::msg::MpStatus";
}

template<>
inline const char * name<tutorial_interfaces::msg::MpStatus>()
{
  return "tutorial_interfaces/msg/MpStatus";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::MpStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::MpStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tutorial_interfaces::msg::MpStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__TRAITS_HPP_
