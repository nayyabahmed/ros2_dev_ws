// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_
#define ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_

#include "abds_msgs/msg/detail/vehicle_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleCommand_rear_wheel_angle
{
public:
  explicit Init_VehicleCommand_rear_wheel_angle(::abds_msgs::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  ::abds_msgs::msg::VehicleCommand rear_wheel_angle(::abds_msgs::msg::VehicleCommand::_rear_wheel_angle_type arg)
  {
    msg_.rear_wheel_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_msgs::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_front_wheel_angle
{
public:
  explicit Init_VehicleCommand_front_wheel_angle(::abds_msgs::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  Init_VehicleCommand_rear_wheel_angle front_wheel_angle(::abds_msgs::msg::VehicleCommand::_front_wheel_angle_type arg)
  {
    msg_.front_wheel_angle = std::move(arg);
    return Init_VehicleCommand_rear_wheel_angle(msg_);
  }

private:
  ::abds_msgs::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_velocity_modifier
{
public:
  explicit Init_VehicleCommand_velocity_modifier(::abds_msgs::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  Init_VehicleCommand_front_wheel_angle velocity_modifier(::abds_msgs::msg::VehicleCommand::_velocity_modifier_type arg)
  {
    msg_.velocity_modifier = std::move(arg);
    return Init_VehicleCommand_front_wheel_angle(msg_);
  }

private:
  ::abds_msgs::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_long_accel
{
public:
  explicit Init_VehicleCommand_long_accel(::abds_msgs::msg::VehicleCommand & msg)
  : msg_(msg)
  {}
  Init_VehicleCommand_velocity_modifier long_accel(::abds_msgs::msg::VehicleCommand::_long_accel_type arg)
  {
    msg_.long_accel = std::move(arg);
    return Init_VehicleCommand_velocity_modifier(msg_);
  }

private:
  ::abds_msgs::msg::VehicleCommand msg_;
};

class Init_VehicleCommand_stamp
{
public:
  Init_VehicleCommand_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleCommand_long_accel stamp(::abds_msgs::msg::VehicleCommand::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_VehicleCommand_long_accel(msg_);
  }

private:
  ::abds_msgs::msg::VehicleCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_msgs::msg::VehicleCommand>()
{
  return abds_msgs::msg::builder::Init_VehicleCommand_stamp();
}

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__VEHICLE_COMMAND__BUILDER_HPP_
