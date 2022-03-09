// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:srv/LuminarSetDuration.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__BUILDER_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__BUILDER_HPP_

#include "abds_core_common/srv/detail/luminar_set_duration__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarSetDuration_Request_duration
{
public:
  Init_LuminarSetDuration_Request_duration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarSetDuration_Request duration(::abds_core_common::srv::LuminarSetDuration_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarSetDuration_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarSetDuration_Request>()
{
  return abds_core_common::srv::builder::Init_LuminarSetDuration_Request_duration();
}

}  // namespace abds_core_common


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarSetDuration_Response_result
{
public:
  Init_LuminarSetDuration_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarSetDuration_Response result(::abds_core_common::srv::LuminarSetDuration_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarSetDuration_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarSetDuration_Response>()
{
  return abds_core_common::srv::builder::Init_LuminarSetDuration_Response_result();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_DURATION__BUILDER_HPP_
