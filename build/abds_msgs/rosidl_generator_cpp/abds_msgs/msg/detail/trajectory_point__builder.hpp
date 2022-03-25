// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_msgs:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
#define ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_

#include "abds_msgs/msg/detail/trajectory_point__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_msgs
{

namespace msg
{

namespace builder
{

class Init_TrajectoryPoint_instantanious_curvature
{
public:
  explicit Init_TrajectoryPoint_instantanious_curvature(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  ::abds_msgs::msg::TrajectoryPoint instantanious_curvature(::abds_msgs::msg::TrajectoryPoint::_instantanious_curvature_type arg)
  {
    msg_.instantanious_curvature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_heading_rate
{
public:
  explicit Init_TrajectoryPoint_heading_rate(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_instantanious_curvature heading_rate(::abds_msgs::msg::TrajectoryPoint::_heading_rate_type arg)
  {
    msg_.heading_rate = std::move(arg);
    return Init_TrajectoryPoint_instantanious_curvature(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_acceleration
{
public:
  explicit Init_TrajectoryPoint_acceleration(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_heading_rate acceleration(::abds_msgs::msg::TrajectoryPoint::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_TrajectoryPoint_heading_rate(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_lateral_velocity
{
public:
  explicit Init_TrajectoryPoint_lateral_velocity(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_acceleration lateral_velocity(::abds_msgs::msg::TrajectoryPoint::_lateral_velocity_type arg)
  {
    msg_.lateral_velocity = std::move(arg);
    return Init_TrajectoryPoint_acceleration(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_longitudinal_velocity
{
public:
  explicit Init_TrajectoryPoint_longitudinal_velocity(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_lateral_velocity longitudinal_velocity(::abds_msgs::msg::TrajectoryPoint::_longitudinal_velocity_type arg)
  {
    msg_.longitudinal_velocity = std::move(arg);
    return Init_TrajectoryPoint_lateral_velocity(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_dist_along_path
{
public:
  explicit Init_TrajectoryPoint_dist_along_path(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_longitudinal_velocity dist_along_path(::abds_msgs::msg::TrajectoryPoint::_dist_along_path_type arg)
  {
    msg_.dist_along_path = std::move(arg);
    return Init_TrajectoryPoint_longitudinal_velocity(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_pose
{
public:
  explicit Init_TrajectoryPoint_pose(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_dist_along_path pose(::abds_msgs::msg::TrajectoryPoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_TrajectoryPoint_dist_along_path(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_datum_bearing
{
public:
  explicit Init_TrajectoryPoint_datum_bearing(::abds_msgs::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_pose datum_bearing(::abds_msgs::msg::TrajectoryPoint::_datum_bearing_type arg)
  {
    msg_.datum_bearing = std::move(arg);
    return Init_TrajectoryPoint_pose(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_time_from_start
{
public:
  Init_TrajectoryPoint_time_from_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryPoint_datum_bearing time_from_start(::abds_msgs::msg::TrajectoryPoint::_time_from_start_type arg)
  {
    msg_.time_from_start = std::move(arg);
    return Init_TrajectoryPoint_datum_bearing(msg_);
  }

private:
  ::abds_msgs::msg::TrajectoryPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_msgs::msg::TrajectoryPoint>()
{
  return abds_msgs::msg::builder::Init_TrajectoryPoint_time_from_start();
}

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
