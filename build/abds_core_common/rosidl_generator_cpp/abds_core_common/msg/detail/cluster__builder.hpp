// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/Cluster.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__BUILDER_HPP_

#include "abds_core_common/msg/detail/cluster__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_Cluster_points
{
public:
  Init_Cluster_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::msg::Cluster points(::abds_core_common::msg::Cluster::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::Cluster msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::Cluster>()
{
  return abds_core_common::msg::builder::Init_Cluster_points();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__CLUSTER__BUILDER_HPP_
