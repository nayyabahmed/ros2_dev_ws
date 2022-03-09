// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:srv/LuminarDiscoverSensors.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_DISCOVER_SENSORS__BUILDER_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_DISCOVER_SENSORS__BUILDER_HPP_

#include "abds_core_common/srv/detail/luminar_discover_sensors__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarDiscoverSensors_Request>()
{
  return ::abds_core_common::srv::LuminarDiscoverSensors_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace abds_core_common


namespace abds_core_common
{

namespace srv
{

namespace builder
{

class Init_LuminarDiscoverSensors_Response_sensors_found
{
public:
  Init_LuminarDiscoverSensors_Response_sensors_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::abds_core_common::srv::LuminarDiscoverSensors_Response sensors_found(::abds_core_common::srv::LuminarDiscoverSensors_Response::_sensors_found_type arg)
  {
    msg_.sensors_found = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::srv::LuminarDiscoverSensors_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::srv::LuminarDiscoverSensors_Response>()
{
  return abds_core_common::srv::builder::Init_LuminarDiscoverSensors_Response_sensors_found();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_DISCOVER_SENSORS__BUILDER_HPP_
