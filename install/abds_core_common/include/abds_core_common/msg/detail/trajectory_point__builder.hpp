// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_

#include "abds_core_common/msg/detail/trajectory_point__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_TrajectoryPoint_instantenious_curvature
{
public:
  explicit Init_TrajectoryPoint_instantenious_curvature(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  ::abds_core_common::msg::TrajectoryPoint instantenious_curvature(::abds_core_common::msg::TrajectoryPoint::_instantenious_curvature_type arg)
  {
    msg_.instantenious_curvature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_heading_rate
{
public:
  explicit Init_TrajectoryPoint_heading_rate(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_instantenious_curvature heading_rate(::abds_core_common::msg::TrajectoryPoint::_heading_rate_type arg)
  {
    msg_.heading_rate = std::move(arg);
    return Init_TrajectoryPoint_instantenious_curvature(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_acceleration
{
public:
  explicit Init_TrajectoryPoint_acceleration(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_heading_rate acceleration(::abds_core_common::msg::TrajectoryPoint::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_TrajectoryPoint_heading_rate(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_lateral_velocity
{
public:
  explicit Init_TrajectoryPoint_lateral_velocity(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_acceleration lateral_velocity(::abds_core_common::msg::TrajectoryPoint::_lateral_velocity_type arg)
  {
    msg_.lateral_velocity = std::move(arg);
    return Init_TrajectoryPoint_acceleration(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_longitudinal_velocity
{
public:
  explicit Init_TrajectoryPoint_longitudinal_velocity(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_lateral_velocity longitudinal_velocity(::abds_core_common::msg::TrajectoryPoint::_longitudinal_velocity_type arg)
  {
    msg_.longitudinal_velocity = std::move(arg);
    return Init_TrajectoryPoint_lateral_velocity(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_dist_along_path
{
public:
  explicit Init_TrajectoryPoint_dist_along_path(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_longitudinal_velocity dist_along_path(::abds_core_common::msg::TrajectoryPoint::_dist_along_path_type arg)
  {
    msg_.dist_along_path = std::move(arg);
    return Init_TrajectoryPoint_longitudinal_velocity(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_pose
{
public:
  explicit Init_TrajectoryPoint_pose(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_dist_along_path pose(::abds_core_common::msg::TrajectoryPoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_TrajectoryPoint_dist_along_path(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_datum_bearing
{
public:
  explicit Init_TrajectoryPoint_datum_bearing(::abds_core_common::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_pose datum_bearing(::abds_core_common::msg::TrajectoryPoint::_datum_bearing_type arg)
  {
    msg_.datum_bearing = std::move(arg);
    return Init_TrajectoryPoint_pose(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_time_from_start
{
public:
  Init_TrajectoryPoint_time_from_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryPoint_datum_bearing time_from_start(::abds_core_common::msg::TrajectoryPoint::_time_from_start_type arg)
  {
    msg_.time_from_start = std::move(arg);
    return Init_TrajectoryPoint_datum_bearing(msg_);
  }

private:
  ::abds_core_common::msg::TrajectoryPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::TrajectoryPoint>()
{
  return abds_core_common::msg::builder::Init_TrajectoryPoint_time_from_start();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
