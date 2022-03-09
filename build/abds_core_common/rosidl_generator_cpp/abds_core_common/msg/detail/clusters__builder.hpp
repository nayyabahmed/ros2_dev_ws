// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/Clusters.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__BUILDER_HPP_

#include "abds_core_common/msg/detail/clusters__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_Clusters_clusters
{
public:
  explicit Init_Clusters_clusters(::abds_core_common::msg::Clusters & msg)
  : msg_(msg)
  {}
  ::abds_core_common::msg::Clusters clusters(::abds_core_common::msg::Clusters::_clusters_type arg)
  {
    msg_.clusters = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::Clusters msg_;
};

class Init_Clusters_header
{
public:
  Init_Clusters_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Clusters_clusters header(::abds_core_common::msg::Clusters::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Clusters_clusters(msg_);
  }

private:
  ::abds_core_common::msg::Clusters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::Clusters>()
{
  return abds_core_common::msg::builder::Init_Clusters_header();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__CLUSTERS__BUILDER_HPP_
