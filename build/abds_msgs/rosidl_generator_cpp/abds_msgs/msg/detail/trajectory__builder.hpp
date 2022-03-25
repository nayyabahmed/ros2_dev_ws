// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define ABDS_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include "abds_msgs/msg/detail/trajectory__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_points
{
public:
  explicit Init_Trajectory_points(::abds_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::abds_msgs::msg::Trajectory points(::abds_msgs::msg::Trajectory::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_header
{
public:
  Init_Trajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_points header(::abds_msgs::msg::Trajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Trajectory_points(msg_);
  }

private:
  ::abds_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_msgs::msg::Trajectory>()
{
  return abds_msgs::msg::builder::Init_Trajectory_header();
}

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
