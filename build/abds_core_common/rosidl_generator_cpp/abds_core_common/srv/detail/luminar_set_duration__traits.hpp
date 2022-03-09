// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from abds_core_common:srv/LuminarSetDuration.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__TRAITS_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__TRAITS_HPP_

#include "abds_core_common/srv/detail/luminar_set_duration__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::srv::LuminarSetDuration_Request>()
{
  return "abds_core_common::srv::LuminarSetDuration_Request";
}

template<>
inline const char * name<abds_core_common::srv::LuminarSetDuration_Request>()
{
  return "abds_core_common/srv/LuminarSetDuration_Request";
}

template<>
struct has_fixed_size<abds_core_common::srv::LuminarSetDuration_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<abds_core_common::srv::LuminarSetDuration_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<abds_core_common::srv::LuminarSetDuration_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::srv::LuminarSetDuration_Response>()
{
  return "abds_core_common::srv::LuminarSetDuration_Response";
}

template<>
inline const char * name<abds_core_common::srv::LuminarSetDuration_Response>()
{
  return "abds_core_common/srv/LuminarSetDuration_Response";
}

template<>
struct has_fixed_size<abds_core_common::srv::LuminarSetDuration_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<abds_core_common::srv::LuminarSetDuration_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<abds_core_common::srv::LuminarSetDuration_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<abds_core_common::srv::LuminarSetDuration>()
{
  return "abds_core_common::srv::LuminarSetDuration";
}

template<>
inline const char * name<abds_core_common::srv::LuminarSetDuration>()
{
  return "abds_core_common/srv/LuminarSetDuration";
}

template<>
struct has_fixed_size<abds_core_common::srv::LuminarSetDuration>
  : std::integral_constant<
    bool,
    has_fixed_size<abds_core_common::srv::LuminarSetDuration_Request>::value &&
    has_fixed_size<abds_core_common::srv::LuminarSetDuration_Response>::value
  >
{
};

template<>
struct has_bounded_size<abds_core_common::srv::LuminarSetDuration>
  : std::integral_constant<
    bool,
    has_bounded_size<abds_core_common::srv::LuminarSetDuration_Request>::value &&
    has_bounded_size<abds_core_common::srv::LuminarSetDuration_Response>::value
  >
{
};

template<>
struct is_service<abds_core_common::srv::LuminarSetDuration>
  : std::true_type
{
};

template<>
struct is_service_request<abds_core_common::srv::LuminarSetDuration_Request>
  : std::true_type
{
};

template<>
struct is_service_response<abds_core_common::srv::LuminarSetDuration_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__TRAITS_HPP_
