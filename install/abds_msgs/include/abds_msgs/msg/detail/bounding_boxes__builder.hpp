// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_msgs:msg/BoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
#define ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_

#include "abds_msgs/msg/detail/bounding_boxes__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_msgs
{

namespace msg
{

namespace builder
{

class Init_BoundingBoxes_boxes
{
public:
  explicit Init_BoundingBoxes_boxes(::abds_msgs::msg::BoundingBoxes & msg)
  : msg_(msg)
  {}
  ::abds_msgs::msg::BoundingBoxes boxes(::abds_msgs::msg::BoundingBoxes::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_msgs::msg::BoundingBoxes msg_;
};

class Init_BoundingBoxes_header
{
public:
  Init_BoundingBoxes_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoundingBoxes_boxes header(::abds_msgs::msg::BoundingBoxes::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BoundingBoxes_boxes(msg_);
  }

private:
  ::abds_msgs::msg::BoundingBoxes msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_msgs::msg::BoundingBoxes>()
{
  return abds_msgs::msg::builder::Init_BoundingBoxes_header();
}

}  // namespace abds_msgs

#endif  // ABDS_MSGS__MSG__DETAIL__BOUNDING_BOXES__BUILDER_HPP_
