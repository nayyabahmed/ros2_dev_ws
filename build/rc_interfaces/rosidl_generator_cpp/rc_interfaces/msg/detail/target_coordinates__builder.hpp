// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rc_interfaces:msg/TargetCoordinates.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__BUILDER_HPP_
#define RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__BUILDER_HPP_

#include "rc_interfaces/msg/detail/target_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rc_interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetCoordinates_pose
{
public:
  explicit Init_TargetCoordinates_pose(::rc_interfaces::msg::TargetCoordinates & msg)
  : msg_(msg)
  {}
  ::rc_interfaces::msg::TargetCoordinates pose(::rc_interfaces::msg::TargetCoordinates::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rc_interfaces::msg::TargetCoordinates msg_;
};

class Init_TargetCoordinates_name
{
public:
  Init_TargetCoordinates_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetCoordinates_pose name(::rc_interfaces::msg::TargetCoordinates::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_TargetCoordinates_pose(msg_);
  }

private:
  ::rc_interfaces::msg::TargetCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rc_interfaces::msg::TargetCoordinates>()
{
  return rc_interfaces::msg::builder::Init_TargetCoordinates_name();
}

}  // namespace rc_interfaces

#endif  // RC_INTERFACES__MSG__DETAIL__TARGET_COORDINATES__BUILDER_HPP_
