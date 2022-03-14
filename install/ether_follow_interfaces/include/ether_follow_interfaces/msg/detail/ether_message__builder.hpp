// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice

#ifndef ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__BUILDER_HPP_
#define ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__BUILDER_HPP_

#include "ether_follow_interfaces/msg/detail/ether_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ether_follow_interfaces
{

namespace msg
{

namespace builder
{

class Init_EtherMessage_gear_cmd
{
public:
  explicit Init_EtherMessage_gear_cmd(::ether_follow_interfaces::msg::EtherMessage & msg)
  : msg_(msg)
  {}
  ::ether_follow_interfaces::msg::EtherMessage gear_cmd(::ether_follow_interfaces::msg::EtherMessage::_gear_cmd_type arg)
  {
    msg_.gear_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

class Init_EtherMessage_accel_cmd
{
public:
  explicit Init_EtherMessage_accel_cmd(::ether_follow_interfaces::msg::EtherMessage & msg)
  : msg_(msg)
  {}
  Init_EtherMessage_gear_cmd accel_cmd(::ether_follow_interfaces::msg::EtherMessage::_accel_cmd_type arg)
  {
    msg_.accel_cmd = std::move(arg);
    return Init_EtherMessage_gear_cmd(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

class Init_EtherMessage_brake_cmd
{
public:
  explicit Init_EtherMessage_brake_cmd(::ether_follow_interfaces::msg::EtherMessage & msg)
  : msg_(msg)
  {}
  Init_EtherMessage_accel_cmd brake_cmd(::ether_follow_interfaces::msg::EtherMessage::_brake_cmd_type arg)
  {
    msg_.brake_cmd = std::move(arg);
    return Init_EtherMessage_accel_cmd(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

class Init_EtherMessage_steering_cmd
{
public:
  explicit Init_EtherMessage_steering_cmd(::ether_follow_interfaces::msg::EtherMessage & msg)
  : msg_(msg)
  {}
  Init_EtherMessage_brake_cmd steering_cmd(::ether_follow_interfaces::msg::EtherMessage::_steering_cmd_type arg)
  {
    msg_.steering_cmd = std::move(arg);
    return Init_EtherMessage_brake_cmd(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

class Init_EtherMessage_version
{
public:
  explicit Init_EtherMessage_version(::ether_follow_interfaces::msg::EtherMessage & msg)
  : msg_(msg)
  {}
  Init_EtherMessage_steering_cmd version(::ether_follow_interfaces::msg::EtherMessage::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_EtherMessage_steering_cmd(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

class Init_EtherMessage_ip_address
{
public:
  Init_EtherMessage_ip_address()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EtherMessage_version ip_address(::ether_follow_interfaces::msg::EtherMessage::_ip_address_type arg)
  {
    msg_.ip_address = std::move(arg);
    return Init_EtherMessage_version(msg_);
  }

private:
  ::ether_follow_interfaces::msg::EtherMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ether_follow_interfaces::msg::EtherMessage>()
{
  return ether_follow_interfaces::msg::builder::Init_EtherMessage_ip_address();
}

}  // namespace ether_follow_interfaces

#endif  // ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__BUILDER_HPP_
