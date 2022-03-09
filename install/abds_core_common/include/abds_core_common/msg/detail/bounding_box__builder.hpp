// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/BoundingBox.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_

#include "abds_core_common/msg/detail/bounding_box__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_BoundingBox_class_likelihood
{
public:
  explicit Init_BoundingBox_class_likelihood(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  ::abds_core_common::msg::BoundingBox class_likelihood(::abds_core_common::msg::BoundingBox::_class_likelihood_type arg)
  {
    msg_.class_likelihood = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_vehicle_label
{
public:
  explicit Init_BoundingBox_vehicle_label(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_class_likelihood vehicle_label(::abds_core_common::msg::BoundingBox::_vehicle_label_type arg)
  {
    msg_.vehicle_label = std::move(arg);
    return Init_BoundingBox_class_likelihood(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_variance
{
public:
  explicit Init_BoundingBox_variance(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_vehicle_label variance(::abds_core_common::msg::BoundingBox::_variance_type arg)
  {
    msg_.variance = std::move(arg);
    return Init_BoundingBox_vehicle_label(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_corners
{
public:
  explicit Init_BoundingBox_corners(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_variance corners(::abds_core_common::msg::BoundingBox::_corners_type arg)
  {
    msg_.corners = std::move(arg);
    return Init_BoundingBox_variance(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_heading_rate
{
public:
  explicit Init_BoundingBox_heading_rate(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_corners heading_rate(::abds_core_common::msg::BoundingBox::_heading_rate_type arg)
  {
    msg_.heading_rate = std::move(arg);
    return Init_BoundingBox_corners(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_heading
{
public:
  explicit Init_BoundingBox_heading(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_heading_rate heading(::abds_core_common::msg::BoundingBox::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_BoundingBox_heading_rate(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_velocity
{
public:
  explicit Init_BoundingBox_velocity(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_heading velocity(::abds_core_common::msg::BoundingBox::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_BoundingBox_heading(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_orientation
{
public:
  explicit Init_BoundingBox_orientation(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_velocity orientation(::abds_core_common::msg::BoundingBox::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_BoundingBox_velocity(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_size
{
public:
  explicit Init_BoundingBox_size(::abds_core_common::msg::BoundingBox & msg)
  : msg_(msg)
  {}
  Init_BoundingBox_orientation size(::abds_core_common::msg::BoundingBox::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_BoundingBox_orientation(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

class Init_BoundingBox_centroid
{
public:
  Init_BoundingBox_centroid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBox_size centroid(::abds_core_common::msg::BoundingBox::_centroid_type arg)
  {
    msg_.centroid = std::move(arg);
    return Init_BoundingBox_size(msg_);
  }

private:
  ::abds_core_common::msg::BoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::BoundingBox>()
{
  return abds_core_common::msg::builder::Init_BoundingBox_centroid();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__BOUNDING_BOX__BUILDER_HPP_
