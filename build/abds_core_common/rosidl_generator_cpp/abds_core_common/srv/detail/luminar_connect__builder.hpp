// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:srv/LuminarConnect.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__BUILDER_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__BUILDER_HPP_

#include "abds_core_common/srv/detail/luminar_connect__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarConnect_Request_sensor_id
{
public:
  Init_LuminarConnect_Request_sensor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarConnect_Request sensor_id(::abds_core_common::srv::LuminarConnect_Request::_sensor_id_type arg)
  {
    msg_.sensor_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarConnect_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarConnect_Request>()
{
  return abds_core_common::srv::builder::Init_LuminarConnect_Request_sensor_id();
}

}  // namespace abds_core_common


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarConnect_Response_result
{
public:
  Init_LuminarConnect_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarConnect_Response result(::abds_core_common::srv::LuminarConnect_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarConnect_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarConnect_Response>()
{
  return abds_core_common::srv::builder::Init_LuminarConnect_Response_result();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__BUILDER_HPP_
