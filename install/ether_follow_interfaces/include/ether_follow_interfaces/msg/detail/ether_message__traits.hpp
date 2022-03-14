// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice

#ifndef ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__TRAITS_HPP_
#define ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__TRAITS_HPP_

#include "ether_follow_interfaces/msg/detail/ether_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ether_follow_interfaces::msg::EtherMessage>()
{
  return "ether_follow_interfaces::msg::EtherMessage";
}

template<>
inline const char * name<ether_follow_interfaces::msg::EtherMessage>()
{
  return "ether_follow_interfaces/msg/EtherMessage";
}

template<>
struct has_fixed_size<ether_follow_interfaces::msg::EtherMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ether_follow_interfaces::msg::EtherMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ether_follow_interfaces::msg::EtherMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__TRAITS_HPP_
