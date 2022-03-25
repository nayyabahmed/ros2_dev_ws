// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_msgs:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_

#include "abds_msgs/msg/detail/vehicle_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleState_delta
{
public:
  explicit Init_VehicleState_delta(::abds_msgs::msg::VehicleState & msg)
  : msg_(msg)
  {}
  ::abds_msgs::msg::VehicleState delta(::abds_msgs::msg::VehicleState::_delta_type arg)
  {
    msg_.delta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_msgs::msg::VehicleState msg_;
};

class Init_VehicleState_state
{
public:
  explicit Init_VehicleState_state(::abds_msgs::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_delta state(::abds_msgs::msg::VehicleState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_VehicleState_delta(msg_);
  }

private:
  ::abds_msgs::msg::VehicleState msg_;
};

class Init_VehicleState_header
{
public:
  Init_VehicleState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleState_state header(::abds_msgs::msg::VehicleState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleState_state(msg_);
  }

private:
  ::abds_msgs::msg::VehicleState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_msgs::msg::VehicleState>()
{
  return abds_msgs::msg::builder::Init_VehicleState_header();
}

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
