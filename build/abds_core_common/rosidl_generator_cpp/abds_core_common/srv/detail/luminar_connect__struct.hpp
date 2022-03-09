// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from abds_core_common:srv/LuminarConnect.idl
// generated code does not contain a copyright notice

#ifndef ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__STRUCT_HPP_
#define ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__abds_core_common__srv__LuminarConnect_Request __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__srv__LuminarConnect_Request __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LuminarConnect_Request_
{
  using Type = LuminarConnect_Request_<ContainerAllocator>;

  explicit LuminarConnect_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor_id = 0;
    }
  }

  explicit LuminarConnect_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor_id = 0;
    }
  }

  // field types and members
  using _sensor_id_type =
    int8_t;
  _sensor_id_type sensor_id;

  // setters for named parameter idiom
  Type & set__sensor_id(
    const int8_t & _arg)
  {
    this->sensor_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__srv__LuminarConnect_Request
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__srv__LuminarConnect_Request
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LuminarConnect_Request_ & other) const
  {
    if (this->sensor_id != other.sensor_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const LuminarConnect_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LuminarConnect_Request_

// alias to use template instance with default allocator
using LuminarConnect_Request =
  abds_core_common::srv::LuminarConnect_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace abds_core_common


#ifndef _WIN32
# define DEPRECATED__abds_core_common__srv__LuminarConnect_Response __attribute__((deprecated))
#else
# define DEPRECATED__abds_core_common__srv__LuminarConnect_Response __declspec(deprecated)
#endif

namespace abds_core_common
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LuminarConnect_Response_
{
  using Type = LuminarConnect_Response_<ContainerAllocator>;

  explicit LuminarConnect_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  explicit LuminarConnect_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0;
    }
  }

  // field types and members
  using _result_type =
    int8_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const int8_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__abds_core_common__srv__LuminarConnect_Response
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__abds_core_common__srv__LuminarConnect_Response
    std::shared_ptr<abds_core_common::srv::LuminarConnect_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LuminarConnect_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const LuminarConnect_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LuminarConnect_Response_

// alias to use template instance with default allocator
using LuminarConnect_Response =
  abds_core_common::srv::LuminarConnect_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace abds_core_common

namespace abds_core_common
{

namespace srv
{

struct LuminarConnect
{
  using Request = abds_core_common::srv::LuminarConnect_Request;
  using Response = abds_core_common::srv::LuminarConnect_Response;
};

}  // namespace srv

}  // namespace abds_core_common

#endif  // ABDS_CORE_COMMON__SRV__DETAIL__LUMINAR_CONNECT__STRUCT_HPP_
