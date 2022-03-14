// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rc_interfaces:msg/RcStatus.idl
// generated code does not contain a copyright notice

#ifndef RC_INTERFACES__MSG__DETAIL__RC_STATUS__BUILDER_HPP_
#define RC_INTERFACES__MSG__DETAIL__RC_STATUS__BUILDER_HPP_

#include "rc_interfaces/msg/detail/rc_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rc_interfaces
{

namespace msg
{

namespace builder
{

class Init_RcStatus_dl_err_2
{
public:
  explicit Init_RcStatus_dl_err_2(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  ::rc_interfaces::msg::RcStatus dl_err_2(::rc_interfaces::msg::RcStatus::_dl_err_2_type arg)
  {
    msg_.dl_err_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_dl_err_1
{
public:
  explicit Init_RcStatus_dl_err_1(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_dl_err_2 dl_err_1(::rc_interfaces::msg::RcStatus::_dl_err_1_type arg)
  {
    msg_.dl_err_1 = std::move(arg);
    return Init_RcStatus_dl_err_2(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_syn_temp_err_5
{
public:
  explicit Init_RcStatus_syn_temp_err_5(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_dl_err_1 syn_temp_err_5(::rc_interfaces::msg::RcStatus::_syn_temp_err_5_type arg)
  {
    msg_.syn_temp_err_5 = std::move(arg);
    return Init_RcStatus_dl_err_1(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_sr_mp_err_4
{
public:
  explicit Init_RcStatus_sr_mp_err_4(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_syn_temp_err_5 sr_mp_err_4(::rc_interfaces::msg::RcStatus::_sr_mp_err_4_type arg)
  {
    msg_.sr_mp_err_4 = std::move(arg);
    return Init_RcStatus_syn_temp_err_5(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_cr_gr_err_3
{
public:
  explicit Init_RcStatus_cr_gr_err_3(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_sr_mp_err_4 cr_gr_err_3(::rc_interfaces::msg::RcStatus::_cr_gr_err_3_type arg)
  {
    msg_.cr_gr_err_3 = std::move(arg);
    return Init_RcStatus_sr_mp_err_4(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_br_ar_err_2
{
public:
  explicit Init_RcStatus_br_ar_err_2(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_cr_gr_err_3 br_ar_err_2(::rc_interfaces::msg::RcStatus::_br_ar_err_2_type arg)
  {
    msg_.br_ar_err_2 = std::move(arg);
    return Init_RcStatus_cr_gr_err_3(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_g_sr_err_1
{
public:
  explicit Init_RcStatus_g_sr_err_1(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_br_ar_err_2 g_sr_err_1(::rc_interfaces::msg::RcStatus::_g_sr_err_1_type arg)
  {
    msg_.g_sr_err_1 = std::move(arg);
    return Init_RcStatus_br_ar_err_2(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_mp_status
{
public:
  explicit Init_RcStatus_mp_status(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_g_sr_err_1 mp_status(::rc_interfaces::msg::RcStatus::_mp_status_type arg)
  {
    msg_.mp_status = std::move(arg);
    return Init_RcStatus_g_sr_err_1(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_ar_control_mode
{
public:
  explicit Init_RcStatus_ar_control_mode(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_mp_status ar_control_mode(::rc_interfaces::msg::RcStatus::_ar_control_mode_type arg)
  {
    msg_.ar_control_mode = std::move(arg);
    return Init_RcStatus_mp_status(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_test_in_progress
{
public:
  explicit Init_RcStatus_test_in_progress(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_ar_control_mode test_in_progress(::rc_interfaces::msg::RcStatus::_test_in_progress_type arg)
  {
    msg_.test_in_progress = std::move(arg);
    return Init_RcStatus_ar_control_mode(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_dl_test_procedure_state
{
public:
  explicit Init_RcStatus_dl_test_procedure_state(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_test_in_progress dl_test_procedure_state(::rc_interfaces::msg::RcStatus::_dl_test_procedure_state_type arg)
  {
    msg_.dl_test_procedure_state = std::move(arg);
    return Init_RcStatus_test_in_progress(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_dl_status_2
{
public:
  explicit Init_RcStatus_dl_status_2(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_dl_test_procedure_state dl_status_2(::rc_interfaces::msg::RcStatus::_dl_status_2_type arg)
  {
    msg_.dl_status_2 = std::move(arg);
    return Init_RcStatus_dl_test_procedure_state(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_dl_status_1
{
public:
  explicit Init_RcStatus_dl_status_1(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_dl_status_2 dl_status_1(::rc_interfaces::msg::RcStatus::_dl_status_1_type arg)
  {
    msg_.dl_status_1 = std::move(arg);
    return Init_RcStatus_dl_status_2(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_current_path_exit_index
{
public:
  explicit Init_RcStatus_current_path_exit_index(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_dl_status_1 current_path_exit_index(::rc_interfaces::msg::RcStatus::_current_path_exit_index_type arg)
  {
    msg_.current_path_exit_index = std::move(arg);
    return Init_RcStatus_dl_status_1(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_max_path_err_right
{
public:
  explicit Init_RcStatus_max_path_err_right(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_current_path_exit_index max_path_err_right(::rc_interfaces::msg::RcStatus::_max_path_err_right_type arg)
  {
    msg_.max_path_err_right = std::move(arg);
    return Init_RcStatus_current_path_exit_index(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_max_path_err_left
{
public:
  explicit Init_RcStatus_max_path_err_left(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_max_path_err_right max_path_err_left(::rc_interfaces::msg::RcStatus::_max_path_err_left_type arg)
  {
    msg_.max_path_err_left = std::move(arg);
    return Init_RcStatus_max_path_err_right(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_pf_test_true
{
public:
  explicit Init_RcStatus_pf_test_true(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_max_path_err_left pf_test_true(::rc_interfaces::msg::RcStatus::_pf_test_true_type arg)
  {
    msg_.pf_test_true = std::move(arg);
    return Init_RcStatus_max_path_err_left(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_desire_speed
{
public:
  explicit Init_RcStatus_desire_speed(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_pf_test_true desire_speed(::rc_interfaces::msg::RcStatus::_desire_speed_type arg)
  {
    msg_.desire_speed = std::move(arg);
    return Init_RcStatus_pf_test_true(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_path_dist
{
public:
  explicit Init_RcStatus_path_dist(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_desire_speed path_dist(::rc_interfaces::msg::RcStatus::_path_dist_type arg)
  {
    msg_.path_dist = std::move(arg);
    return Init_RcStatus_desire_speed(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_mpf_phase
{
public:
  explicit Init_RcStatus_mpf_phase(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_path_dist mpf_phase(::rc_interfaces::msg::RcStatus::_mpf_phase_type arg)
  {
    msg_.mpf_phase = std::move(arg);
    return Init_RcStatus_path_dist(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_test_phase
{
public:
  explicit Init_RcStatus_test_phase(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_mpf_phase test_phase(::rc_interfaces::msg::RcStatus::_test_phase_type arg)
  {
    msg_.test_phase = std::move(arg);
    return Init_RcStatus_mpf_phase(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_test_index
{
public:
  explicit Init_RcStatus_test_index(::rc_interfaces::msg::RcStatus & msg)
  : msg_(msg)
  {}
  Init_RcStatus_test_phase test_index(::rc_interfaces::msg::RcStatus::_test_index_type arg)
  {
    msg_.test_index = std::move(arg);
    return Init_RcStatus_test_phase(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

class Init_RcStatus_header
{
public:
  Init_RcStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RcStatus_test_index header(::rc_interfaces::msg::RcStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RcStatus_test_index(msg_);
  }

private:
  ::rc_interfaces::msg::RcStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rc_interfaces::msg::RcStatus>()
{
  return rc_interfaces::msg::builder::Init_RcStatus_header();
}

}  // namespace rc_interfaces

#endif  // RC_INTERFACES__MSG__DETAIL__RC_STATUS__BUILDER_HPP_
