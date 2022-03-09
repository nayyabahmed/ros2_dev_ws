// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:srv/LuminarSetFov.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__BUILDER_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__BUILDER_HPP_

#include "abds_core_common/srv/detail/luminar_set_fov__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarSetFov_Request_fov_center
{
public:
  explicit Init_LuminarSetFov_Request_fov_center(::abds_core_common::srv::LuminarSetFov_Request & msg)
  : msg_(msg)
  {}
  ::abds_core_common::srv::LuminarSetFov_Request fov_center(::abds_core_common::srv::LuminarSetFov_Request::_fov_center_type arg)
  {
    msg_.fov_center = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarSetFov_Request msg_;
};

class Init_LuminarSetFov_Request_fov
{
public:
  Init_LuminarSetFov_Request_fov()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LuminarSetFov_Request_fov_center fov(::abds_core_common::srv::LuminarSetFov_Request::_fov_type arg)
  {
    msg_.fov = std::move(arg);
    return Init_LuminarSetFov_Request_fov_center(msg_);
  }

private:
  ::abds_core_common::srv::LuminarSetFov_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarSetFov_Request>()
{
  return abds_core_common::srv::builder::Init_LuminarSetFov_Request_fov();
}

}  // namespace abds_core_common


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarSetFov_Response_result
{
public:
  Init_LuminarSetFov_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarSetFov_Response result(::abds_core_common::srv::LuminarSetFov_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarSetFov_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarSetFov_Response>()
{
  return abds_core_common::srv::builder::Init_LuminarSetFov_Response_result();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_SET_FOV__BUILDER_HPP_
