// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_core_common:msg/TestState.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__STRUCT_HPP_
#define ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__abds_core_common__msg__TestState __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__msg__TestState __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TestState_
{
  using Type = TestState_<ContainerAllocator>;

  explicit TestState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_id = 0l;
      this->test_phase = 0l;
      this->test_state = 0l;
      this->path_distance = 0.0f;
      this->deceleration_rate = 0.0f;
      this->abort_deceleration_rate = 0.0f;
      this->desired_speed = 0.0f;
    }
  }

  explicit TestState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_id = 0l;
      this->test_phase = 0l;
      this->test_state = 0l;
      this->path_distance = 0.0f;
      this->deceleration_rate = 0.0f;
      this->abort_deceleration_rate = 0.0f;
      this->desired_speed = 0.0f;
    }
  }

  // field types and members
  using _test_id_type =
    int32_t;
  _test_id_type test_id;
  using _test_phase_type =
    int32_t;
  _test_phase_type test_phase;
  using _test_state_type =
    int32_t;
  _test_state_type test_state;
  using _path_distance_type =
    float;
  _path_distance_type path_distance;
  using _deceleration_rate_type =
    float;
  _deceleration_rate_type deceleration_rate;
  using _abort_deceleration_rate_type =
    float;
  _abort_deceleration_rate_type abort_deceleration_rate;
  using _desired_speed_type =
    float;
  _desired_speed_type desired_speed;

  // setters for named parameter idiom
  Type & set__test_id(
    const int32_t & _arg)
  {
    this->test_id = _arg;
    return *this;
  }
  Type & set__test_phase(
    const int32_t & _arg)
  {
    this->test_phase = _arg;
    return *this;
  }
  Type & set__test_state(
    const int32_t & _arg)
  {
    this->test_state = _arg;
    return *this;
  }
  Type & set__path_distance(
    const float & _arg)
  {
    this->path_distance = _arg;
    return *this;
  }
  Type & set__deceleration_rate(
    const float & _arg)
  {
    this->deceleration_rate = _arg;
    return *this;
  }
  Type & set__abort_deceleration_rate(
    const float & _arg)
  {
    this->abort_deceleration_rate = _arg;
    return *this;
  }
  Type & set__desired_speed(
    const float & _arg)
  {
    this->desired_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::msg::TestState_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::msg::TestState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::msg::TestState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::msg::TestState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::TestState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::TestState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::msg::TestState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::msg::TestState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::msg::TestState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::msg::TestState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__msg__TestState
    std::shared_ptr<abds_core_common::msg::TestState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__msg__TestState
    std::shared_ptr<abds_core_common::msg::TestState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TestState_ & other) const
  {
    if (this->test_id != other.test_id) {
      return false;
    }
    if (this->test_phase != other.test_phase) {
      return false;
    }
    if (this->test_state != other.test_state) {
      return false;
    }
    if (this->path_distance != other.path_distance) {
      return false;
    }
    if (this->deceleration_rate != other.deceleration_rate) {
      return false;
    }
    if (this->abort_deceleration_rate != other.abort_deceleration_rate) {
      return false;
    }
    if (this->desired_speed != other.desired_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const TestState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TestState_

// alias to use template instance with default allocator
using TestState =
  abds_core_common::msg::TestState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__MSG__DETAIL__TEST_STATE__STRUCT_HPP_
