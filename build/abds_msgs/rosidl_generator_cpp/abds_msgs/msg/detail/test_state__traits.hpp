// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_msgs:msg/TestState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TEST_STATE__TRAITS_HPP_
#define ABDS_MSGS__MSG__DETAIL__TEST_STATE__TRAITS_HPP_

#include "abds_msgs/msg/detail/test_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_msgs::msg::TestState>()
{
  return "abds_msgs::msg::TestState";
}

template<>
inline const char * name<abds_msgs::msg::TestState>()
{
  return "abds_msgs/msg/TestState";
}

template<>
struct has_fixed_size<abds_msgs::msg::TestState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<abds_msgs::msg::TestState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<abds_msgs::msg::TestState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_MSGS__MSG__DETAIL__TEST_STATE__TRAITS_HPP_
