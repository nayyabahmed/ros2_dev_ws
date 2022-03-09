// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rc_interfaces:msg/ImuRc.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__IMU_RC__BUILDER_HPP_
#define RC_INTERFACES__MSG__DETAIL__IMU_RC__BUILDER_HPP_

#include "rc_interfaces/msg/detail/imu_rc__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rc_interfaces
{

namespace msg
{

namespace builder
{

class Init_ImuRc_accel
{
public:
  explicit Init_ImuRc_accel(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  ::rc_interfaces::msg::ImuRc accel(::rc_interfaces::msg::ImuRc::_accel_type arg)
  {
    msg_.accel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_twist
{
public:
  explicit Init_ImuRc_twist(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_accel twist(::rc_interfaces::msg::ImuRc::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return Init_ImuRc_accel(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_pose
{
public:
  explicit Init_ImuRc_pose(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_twist pose(::rc_interfaces::msg::ImuRc::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_ImuRc_twist(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_yaw_angle
{
public:
  explicit Init_ImuRc_yaw_angle(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_pose yaw_angle(::rc_interfaces::msg::ImuRc::_yaw_angle_type arg)
  {
    msg_.yaw_angle = std::move(arg);
    return Init_ImuRc_pose(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_mp_bearing
{
public:
  explicit Init_ImuRc_mp_bearing(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_yaw_angle mp_bearing(::rc_interfaces::msg::ImuRc::_mp_bearing_type arg)
  {
    msg_.mp_bearing = std::move(arg);
    return Init_ImuRc_yaw_angle(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_mp_longt
{
public:
  explicit Init_ImuRc_mp_longt(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_mp_bearing mp_longt(::rc_interfaces::msg::ImuRc::_mp_longt_type arg)
  {
    msg_.mp_longt = std::move(arg);
    return Init_ImuRc_mp_bearing(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_mp_lat
{
public:
  explicit Init_ImuRc_mp_lat(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_mp_longt mp_lat(::rc_interfaces::msg::ImuRc::_mp_lat_type arg)
  {
    msg_.mp_lat = std::move(arg);
    return Init_ImuRc_mp_longt(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_mp_time
{
public:
  explicit Init_ImuRc_mp_time(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_mp_lat mp_time(::rc_interfaces::msg::ImuRc::_mp_time_type arg)
  {
    msg_.mp_time = std::move(arg);
    return Init_ImuRc_mp_lat(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_msg_count
{
public:
  explicit Init_ImuRc_msg_count(::rc_interfaces::msg::ImuRc & msg)
  : msg_(msg)
  {}
  Init_ImuRc_mp_time msg_count(::rc_interfaces::msg::ImuRc::_msg_count_type arg)
  {
    msg_.msg_count = std::move(arg);
    return Init_ImuRc_mp_time(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

class Init_ImuRc_name
{
public:
  Init_ImuRc_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuRc_msg_count name(::rc_interfaces::msg::ImuRc::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ImuRc_msg_count(msg_);
  }

private:
  ::rc_interfaces::msg::ImuRc msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rc_interfaces::msg::ImuRc>()
{
  return rc_interfaces::msg::builder::Init_ImuRc_name();
}

}  // namespace rc_interfaces

#endif  // RC_INTERFACES__MSG__DETAIL__IMU_RC__BUILDER_HPP_
