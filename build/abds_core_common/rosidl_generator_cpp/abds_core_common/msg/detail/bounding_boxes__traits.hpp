// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_core_common:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_

#include "abds_core_common/msg/detail/bounding_boxes__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::msg::BoundingBoxes>()
{
  return "abds_core_common::msg::BoundingBoxes";
}

template<>
inline const char * name<abds_core_common::msg::BoundingBoxes>()
{
  return "abds_core_common/msg/BoundingBoxes";
}

template<>
struct has_fixed_size<abds_core_common::msg::BoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<abds_core_common::msg::BoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<abds_core_common::msg::BoundingBoxes>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOXES__TRAITS_HPP_
