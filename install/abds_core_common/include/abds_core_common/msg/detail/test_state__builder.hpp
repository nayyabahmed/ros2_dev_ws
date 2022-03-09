// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from abds_core_common:msg/TestState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__BUILDER_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__BUILDER_HPP_

#include "abds_core_common/msg/detail/test_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace abds_core_common
{

namespace msg
{

namespace builder
{

class Init_TestState_desired_speed
{
public:
  explicit Init_TestState_desired_speed(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  ::abds_core_common::msg::TestState desired_speed(::abds_core_common::msg::TestState::_desired_speed_type arg)
  {
    msg_.desired_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_abort_deceleration_rate
{
public:
  explicit Init_TestState_abort_deceleration_rate(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  Init_TestState_desired_speed abort_deceleration_rate(::abds_core_common::msg::TestState::_abort_deceleration_rate_type arg)
  {
    msg_.abort_deceleration_rate = std::move(arg);
    return Init_TestState_desired_speed(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_deceleration_rate
{
public:
  explicit Init_TestState_deceleration_rate(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  Init_TestState_abort_deceleration_rate deceleration_rate(::abds_core_common::msg::TestState::_deceleration_rate_type arg)
  {
    msg_.deceleration_rate = std::move(arg);
    return Init_TestState_abort_deceleration_rate(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_path_distance
{
public:
  explicit Init_TestState_path_distance(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  Init_TestState_deceleration_rate path_distance(::abds_core_common::msg::TestState::_path_distance_type arg)
  {
    msg_.path_distance = std::move(arg);
    return Init_TestState_deceleration_rate(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_test_state
{
public:
  explicit Init_TestState_test_state(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  Init_TestState_path_distance test_state(::abds_core_common::msg::TestState::_test_state_type arg)
  {
    msg_.test_state = std::move(arg);
    return Init_TestState_path_distance(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_test_phase
{
public:
  explicit Init_TestState_test_phase(::abds_core_common::msg::TestState & msg)
  : msg_(msg)
  {}
  Init_TestState_test_state test_phase(::abds_core_common::msg::TestState::_test_phase_type arg)
  {
    msg_.test_phase = std::move(arg);
    return Init_TestState_test_state(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

class Init_TestState_test_id
{
public:
  Init_TestState_test_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TestState_test_phase test_id(::abds_core_common::msg::TestState::_test_id_type arg)
  {
    msg_.test_id = std::move(arg);
    return Init_TestState_test_phase(msg_);
  }

private:
  ::abds_core_common::msg::TestState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::abds_core_common::msg::TestState>()
{
  return abds_core_common::msg::builder::Init_TestState_test_id();
}

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__BUILDER_HPP_
