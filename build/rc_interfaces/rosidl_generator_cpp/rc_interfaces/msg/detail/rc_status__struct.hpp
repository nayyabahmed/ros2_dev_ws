// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_HPP_
#define RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rc_interfaces__msg__RcStatus __attribute__((deprecated))
#else
# define DEPRECATED__rc_interfaces__msg__RcStatus __declspec(deprecated)
#endif

namespace rc_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RcStatus_
{
  using Type = RcStatus_<ContainerAllocator>;

  explicit RcStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_index = 0;
      this->test_phase = 0;
      this->mpf_phase = 0l;
      this->path_dist = 0.0f;
      this->desire_speed = 0.0f;
      this->pf_test_true = 0;
      this->max_path_err_left = 0.0f;
      this->max_path_err_right = 0.0f;
      this->current_path_exit_index = 0;
      this->dl_status_1 = 0;
      this->dl_status_2 = 0;
      this->dl_test_procedure_state = 0;
      this->test_in_progress = 0;
      this->ar_control_mode = 0l;
      this->mp_status = 0l;
      this->g_sr_err_1 = 0ul;
      this->br_ar_err_2 = 0ul;
      this->cr_gr_err_3 = 0ul;
      this->sr_mp_err_4 = 0ul;
      this->syn_temp_err_5 = 0ul;
      this->dl_err_1 = 0ul;
      this->dl_err_2 = 0ul;
    }
  }

  explicit RcStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_index = 0;
      this->test_phase = 0;
      this->mpf_phase = 0l;
      this->path_dist = 0.0f;
      this->desire_speed = 0.0f;
      this->pf_test_true = 0;
      this->max_path_err_left = 0.0f;
      this->max_path_err_right = 0.0f;
      this->current_path_exit_index = 0;
      this->dl_status_1 = 0;
      this->dl_status_2 = 0;
      this->dl_test_procedure_state = 0;
      this->test_in_progress = 0;
      this->ar_control_mode = 0l;
      this->mp_status = 0l;
      this->g_sr_err_1 = 0ul;
      this->br_ar_err_2 = 0ul;
      this->cr_gr_err_3 = 0ul;
      this->sr_mp_err_4 = 0ul;
      this->syn_temp_err_5 = 0ul;
      this->dl_err_1 = 0ul;
      this->dl_err_2 = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _test_index_type =
    uint16_t;
  _test_index_type test_index;
  using _test_phase_type =
    int16_t;
  _test_phase_type test_phase;
  using _mpf_phase_type =
    int32_t;
  _mpf_phase_type mpf_phase;
  using _path_dist_type =
    float;
  _path_dist_type path_dist;
  using _desire_speed_type =
    float;
  _desire_speed_type desire_speed;
  using _pf_test_true_type =
    unsigned char;
  _pf_test_true_type pf_test_true;
  using _max_path_err_left_type =
    float;
  _max_path_err_left_type max_path_err_left;
  using _max_path_err_right_type =
    float;
  _max_path_err_right_type max_path_err_right;
  using _current_path_exit_index_type =
    int16_t;
  _current_path_exit_index_type current_path_exit_index;
  using _dl_status_1_type =
    unsigned char;
  _dl_status_1_type dl_status_1;
  using _dl_status_2_type =
    unsigned char;
  _dl_status_2_type dl_status_2;
  using _dl_test_procedure_state_type =
    unsigned char;
  _dl_test_procedure_state_type dl_test_procedure_state;
  using _test_in_progress_type =
    unsigned char;
  _test_in_progress_type test_in_progress;
  using _ar_control_mode_type =
    int32_t;
  _ar_control_mode_type ar_control_mode;
  using _mp_status_type =
    int32_t;
  _mp_status_type mp_status;
  using _g_sr_err_1_type =
    uint32_t;
  _g_sr_err_1_type g_sr_err_1;
  using _br_ar_err_2_type =
    uint32_t;
  _br_ar_err_2_type br_ar_err_2;
  using _cr_gr_err_3_type =
    uint32_t;
  _cr_gr_err_3_type cr_gr_err_3;
  using _sr_mp_err_4_type =
    uint32_t;
  _sr_mp_err_4_type sr_mp_err_4;
  using _syn_temp_err_5_type =
    uint32_t;
  _syn_temp_err_5_type syn_temp_err_5;
  using _dl_err_1_type =
    uint32_t;
  _dl_err_1_type dl_err_1;
  using _dl_err_2_type =
    uint32_t;
  _dl_err_2_type dl_err_2;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__test_index(
    const uint16_t & _arg)
  {
    this->test_index = _arg;
    return *this;
  }
  Type & set__test_phase(
    const int16_t & _arg)
  {
    this->test_phase = _arg;
    return *this;
  }
  Type & set__mpf_phase(
    const int32_t & _arg)
  {
    this->mpf_phase = _arg;
    return *this;
  }
  Type & set__path_dist(
    const float & _arg)
  {
    this->path_dist = _arg;
    return *this;
  }
  Type & set__desire_speed(
    const float & _arg)
  {
    this->desire_speed = _arg;
    return *this;
  }
  Type & set__pf_test_true(
    const unsigned char & _arg)
  {
    this->pf_test_true = _arg;
    return *this;
  }
  Type & set__max_path_err_left(
    const float & _arg)
  {
    this->max_path_err_left = _arg;
    return *this;
  }
  Type & set__max_path_err_right(
    const float & _arg)
  {
    this->max_path_err_right = _arg;
    return *this;
  }
  Type & set__current_path_exit_index(
    const int16_t & _arg)
  {
    this->current_path_exit_index = _arg;
    return *this;
  }
  Type & set__dl_status_1(
    const unsigned char & _arg)
  {
    this->dl_status_1 = _arg;
    return *this;
  }
  Type & set__dl_status_2(
    const unsigned char & _arg)
  {
    this->dl_status_2 = _arg;
    return *this;
  }
  Type & set__dl_test_procedure_state(
    const unsigned char & _arg)
  {
    this->dl_test_procedure_state = _arg;
    return *this;
  }
  Type & set__test_in_progress(
    const unsigned char & _arg)
  {
    this->test_in_progress = _arg;
    return *this;
  }
  Type & set__ar_control_mode(
    const int32_t & _arg)
  {
    this->ar_control_mode = _arg;
    return *this;
  }
  Type & set__mp_status(
    const int32_t & _arg)
  {
    this->mp_status = _arg;
    return *this;
  }
  Type & set__g_sr_err_1(
    const uint32_t & _arg)
  {
    this->g_sr_err_1 = _arg;
    return *this;
  }
  Type & set__br_ar_err_2(
    const uint32_t & _arg)
  {
    this->br_ar_err_2 = _arg;
    return *this;
  }
  Type & set__cr_gr_err_3(
    const uint32_t & _arg)
  {
    this->cr_gr_err_3 = _arg;
    return *this;
  }
  Type & set__sr_mp_err_4(
    const uint32_t & _arg)
  {
    this->sr_mp_err_4 = _arg;
    return *this;
  }
  Type & set__syn_temp_err_5(
    const uint32_t & _arg)
  {
    this->syn_temp_err_5 = _arg;
    return *this;
  }
  Type & set__dl_err_1(
    const uint32_t & _arg)
  {
    this->dl_err_1 = _arg;
    return *this;
  }
  Type & set__dl_err_2(
    const uint32_t & _arg)
  {
    this->dl_err_2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rc_interfaces::msg::RcStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const rc_interfaces::msg::RcStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rc_interfaces::msg::RcStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rc_interfaces::msg::RcStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rc_interfaces__msg__RcStatus
    std::shared_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rc_interfaces__msg__RcStatus
    std::shared_ptr<rc_interfaces::msg::RcStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RcStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->test_index != other.test_index) {
      return false;
    }
    if (this->test_phase != other.test_phase) {
      return false;
    }
    if (this->mpf_phase != other.mpf_phase) {
      return false;
    }
    if (this->path_dist != other.path_dist) {
      return false;
    }
    if (this->desire_speed != other.desire_speed) {
      return false;
    }
    if (this->pf_test_true != other.pf_test_true) {
      return false;
    }
    if (this->max_path_err_left != other.max_path_err_left) {
      return false;
    }
    if (this->max_path_err_right != other.max_path_err_right) {
      return false;
    }
    if (this->current_path_exit_index != other.current_path_exit_index) {
      return false;
    }
    if (this->dl_status_1 != other.dl_status_1) {
      return false;
    }
    if (this->dl_status_2 != other.dl_status_2) {
      return false;
    }
    if (this->dl_test_procedure_state != other.dl_test_procedure_state) {
      return false;
    }
    if (this->test_in_progress != other.test_in_progress) {
      return false;
    }
    if (this->ar_control_mode != other.ar_control_mode) {
      return false;
    }
    if (this->mp_status != other.mp_status) {
      return false;
    }
    if (this->g_sr_err_1 != other.g_sr_err_1) {
      return false;
    }
    if (this->br_ar_err_2 != other.br_ar_err_2) {
      return false;
    }
    if (this->cr_gr_err_3 != other.cr_gr_err_3) {
      return false;
    }
    if (this->sr_mp_err_4 != other.sr_mp_err_4) {
      return false;
    }
    if (this->syn_temp_err_5 != other.syn_temp_err_5) {
      return false;
    }
    if (this->dl_err_1 != other.dl_err_1) {
      return false;
    }
    if (this->dl_err_2 != other.dl_err_2) {
      return false;
    }
    return true;
  }
  bool operator!=(const RcStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RcStatus_

// alias to use template instance with default allocator
using RcStatus =
  rc_interfaces::msg::RcStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rc_interfaces

#endif  // RC_INTERFACES__MSG__DETAIL__RC_STATUS__STRUCT_HPP_
