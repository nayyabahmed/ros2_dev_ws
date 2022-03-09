#ifndef ABDS_CORE__TIME_UTILS
#define ABDS_CORE__TIME_UTILS
#include <chrono>
#include <std_msgs/msg/header.hpp>
#include <rclcpp/rclcpp.hpp>
namespace abds_core
{
namespace time_utils
{
std::chrono::nanoseconds from_duration(rclcpp::Duration dt) noexcept
{
  const auto ns = std::chrono::nanoseconds{dt.nanoseconds()};
  return std::chrono::duration_cast<std::chrono::nanoseconds>(ns);
} 
std::chrono::system_clock::time_point from_header(std_msgs::msg::Header header) noexcept
{
  auto t = header.stamp;
  const auto dt_ns = std::chrono::seconds(t.sec) + std::chrono::nanoseconds(t.nanosec);
  const auto dt = std::chrono::duration_cast<std::chrono::nanoseconds>(dt_ns);
  return std::chrono::system_clock::time_point{} + dt;
}
}
}
#endif // ABDS_CORE__TIME_UTILS