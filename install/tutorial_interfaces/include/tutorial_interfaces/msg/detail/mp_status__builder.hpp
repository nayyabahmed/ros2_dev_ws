// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/MpStatus.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__BUILDER_HPP_

#include "tutorial_interfaces/msg/detail/mp_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_MpStatus_yaw_angle
{
public:
  explicit Init_MpStatus_yaw_angle(::tutorial_interfaces::msg::MpStatus & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::msg::MpStatus yaw_angle(::tutorial_interfaces::msg::MpStatus::_yaw_angle_type arg)
  {
    msg_.yaw_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::MpStatus msg_;
};

class Init_MpStatus_mp_bearing
{
public:
  explicit Init_MpStatus_mp_bearing(::tutorial_interfaces::msg::MpStatus & msg)
  : msg_(msg)
  {}
  Init_MpStatus_yaw_angle mp_bearing(::tutorial_interfaces::msg::MpStatus::_mp_bearing_type arg)
  {
    msg_.mp_bearing = std::move(arg);
    return Init_MpStatus_yaw_angle(msg_);
  }

private:
  ::tutorial_interfaces::msg::MpStatus msg_;
};

class Init_MpStatus_mp_longt
{
public:
  explicit Init_MpStatus_mp_longt(::tutorial_interfaces::msg::MpStatus & msg)
  : msg_(msg)
  {}
  Init_MpStatus_mp_bearing mp_longt(::tutorial_interfaces::msg::MpStatus::_mp_longt_type arg)
  {
    msg_.mp_longt = std::move(arg);
    return Init_MpStatus_mp_bearing(msg_);
  }

private:
  ::tutorial_interfaces::msg::MpStatus msg_;
};

class Init_MpStatus_mp_lat
{
public:
  explicit Init_MpStatus_mp_lat(::tutorial_interfaces::msg::MpStatus & msg)
  : msg_(msg)
  {}
  Init_MpStatus_mp_longt mp_lat(::tutorial_interfaces::msg::MpStatus::_mp_lat_type arg)
  {
    msg_.mp_lat = std::move(arg);
    return Init_MpStatus_mp_longt(msg_);
  }

private:
  ::tutorial_interfaces::msg::MpStatus msg_;
};

class Init_MpStatus_mp_time
{
public:
  Init_MpStatus_mp_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MpStatus_mp_lat mp_time(::tutorial_interfaces::msg::MpStatus::_mp_time_type arg)
  {
    msg_.mp_time = std::move(arg);
    return Init_MpStatus_mp_lat(msg_);
  }

private:
  ::tutorial_interfaces::msg::MpStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::MpStatus>()
{
  return tutorial_interfaces::msg::builder::Init_MpStatus_mp_time();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__MP_STATUS__BUILDER_HPP_
