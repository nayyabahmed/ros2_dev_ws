// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include "abds_core_common/msg/detail/trajectory__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_Trajectory_points
{
public:
  explicit Init_Trajectory_points(::abds_core_common::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::abds_core_common::msg::Trajectory points(::abds_core_common::msg::Trajectory::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::Trajectory msg_;
};

class Init_Trajectory_header
{
public:
  Init_Trajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_points header(::abds_core_common::msg::Trajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Trajectory_points(msg_);
  }

private:
  ::abds_core_common::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::Trajectory>()
{
  return abds_core_common::msg::builder::Init_Trajectory_header();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
