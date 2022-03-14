// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ether_follow_interfaces:msg/EtherMessage.idl
// generated code does not contain a copyright notice

#ifndef ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_HPP_
#define ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ether_follow_interfaces__msg__EtherMessage __attribute__((deprecated))
#else
# define DEPRECATED__ether_follow_interfaces__msg__EtherMessage __declspec(deprecated)
#endif

namespace ether_follow_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EtherMessage_
{
  using Type = EtherMessage_<ContainerAllocator>;

  explicit EtherMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ip_address = "";
      this->version = 0;
      this->steering_cmd = 0.0;
      this->brake_cmd = 0.0;
      this->accel_cmd = 0.0;
      this->gear_cmd = 0;
    }
  }

  explicit EtherMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ip_address(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ip_address = "";
      this->version = 0;
      this->steering_cmd = 0.0;
      this->brake_cmd = 0.0;
      this->accel_cmd = 0.0;
      this->gear_cmd = 0;
    }
  }

  // field types and members
  using _ip_address_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _ip_address_type ip_address;
  using _version_type =
    uint8_t;
  _version_type version;
  using _steering_cmd_type =
    double;
  _steering_cmd_type steering_cmd;
  using _brake_cmd_type =
    double;
  _brake_cmd_type brake_cmd;
  using _accel_cmd_type =
    double;
  _accel_cmd_type accel_cmd;
  using _gear_cmd_type =
    int8_t;
  _gear_cmd_type gear_cmd;

  // setters for named parameter idiom
  Type & set__ip_address(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->ip_address = _arg;
    return *this;
  }
  Type & set__version(
    const uint8_t & _arg)
  {
    this->version = _arg;
    return *this;
  }
  Type & set__steering_cmd(
    const double & _arg)
  {
    this->steering_cmd = _arg;
    return *this;
  }
  Type & set__brake_cmd(
    const double & _arg)
  {
    this->brake_cmd = _arg;
    return *this;
  }
  Type & set__accel_cmd(
    const double & _arg)
  {
    this->accel_cmd = _arg;
    return *this;
  }
  Type & set__gear_cmd(
    const int8_t & _arg)
  {
    this->gear_cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ether_follow_interfaces__msg__EtherMessage
    std::shared_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ether_follow_interfaces__msg__EtherMessage
    std::shared_ptr<ether_follow_interfaces::msg::EtherMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EtherMessage_ & other) const
  {
    if (this->ip_address != other.ip_address) {
      return false;
    }
    if (this->version != other.version) {
      return false;
    }
    if (this->steering_cmd != other.steering_cmd) {
      return false;
    }
    if (this->brake_cmd != other.brake_cmd) {
      return false;
    }
    if (this->accel_cmd != other.accel_cmd) {
      return false;
    }
    if (this->gear_cmd != other.gear_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const EtherMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EtherMessage_

// alias to use template instance with default allocator
using EtherMessage =
  ether_follow_interfaces::msg::EtherMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ether_follow_interfaces

#endif  // ETHER_FOLLOW_INTERFACES__MSG__DETAIL__ETHER_MESSAGE__STRUCT_HPP_
