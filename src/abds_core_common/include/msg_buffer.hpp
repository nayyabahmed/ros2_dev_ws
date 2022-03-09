#ifndef ABDS_CORE__MSG_BUFFER
#define ABDS_CORE__MSG_BUFFER
#include <queue>
#include <rclcpp/rclcpp.hpp>
#include <stdexcept>
namespace abds_core
{
template<typename MsgT>
class MsgBuffer
{
public:
    MsgBuffer(std::shared_ptr<rclcpp::Clock> clk, std::uint32_t time_tol_ms, std::size_t buffer_capacity)
    : m_clock(m_clock),
      m_time_tol(time_tol_ms*1000),
      m_buffer(),
      m_capacity(buffer_capacity)
    {}
    void add(MsgT msg)
    {
        add(msg,m_clock->now());
    }
    void add(MsgT msg, rclcpp::Time time)
    {
        // this could probably be an if; just being cautious
        while (m_buffer.size() >=  m_capacity)
        {
            (void) m_buffer.pop();
        }
        
        m_buffer.push(std::make_pair(time,msg));
    }
    MsgT get_at_time(rclcpp::Time time)
    {
        auto oldest = m_buffer.front();
        auto diff = time - oldest.first;
        while (std::abs(diff) > m_time_tol || m_buffer.size() )
        {
            if (diff < 0)
            {
                throw std::runtime_error("MsgBuffer: all messages are newer than tolerance, consider increasing buffer capacity");
            }
            (void)m_buffer.pop();
            oldest = m_buffer.first();
            diff = time - oldest.first;
        }
        if (m_buffer.size() > 0)
        {
            (void)m_buffer.pop();
            return oldest;
        }
        throw std::runtime_error("MsgBuffer: No messages within tolerance, consider loosening time tolerance");
    }
private:
    std::queue<std::pair<rclcpp::Time,MsgT>> m_buffer;
    std::shared_ptr<rclcpp::Clock> m_clock;
    rclcpp::Duration m_time_tol;
    size_t m_capacity;
};
}
#endif // ABDS_CORE__MSG_BUFFER