// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_core_common:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_

#include "abds_core_common/msg/detail/bounding_box__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'centroid'
// Member 'size'
// Member 'corners'
#include "geometry_msgs/msg/detail/point32__traits.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::msg::BoundingBox>()
{
  return "abds_core_common::msg::BoundingBox";
}

template<>
inline const char * name<abds_core_common::msg::BoundingBox>()
{
  return "abds_core_common/msg/BoundingBox";
}

template<>
struct has_fixed_size<abds_core_common::msg::BoundingBox>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value && has_fixed_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct has_bounded_size<abds_core_common::msg::BoundingBox>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value && has_bounded_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct is_message<abds_core_common::msg::BoundingBox>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__TRAITS_HPP_
