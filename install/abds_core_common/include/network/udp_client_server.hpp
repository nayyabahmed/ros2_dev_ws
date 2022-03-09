#ifndef ABDS_CORE_CLIENT_SERVER_H
#define ABDS_CORE_CLIENT_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdexcept>
#include <functional>
#include <thread>
namespace abds_core
{
namespace udp_client_server
{

class udp_client_server_runtime_error : public std::runtime_error
{
public:
    udp_client_server_runtime_error(const char *w) : std::runtime_error(w) {}
};


class udp_client
{
public:
    udp_client(const std::string& addr, int port);
    ~udp_client();

    int                 get_socket() const;
    int                 get_port() const;
    std::string         get_addr() const;

    int                 send(const unsigned char *msg, size_t size);

private:
    int                 m_socket;
    int                 m_port;
    std::string         m_addr;
    struct addrinfo *   m_addrinfo;
};


class udp_server
{
public:
    udp_server(const std::string& addr, int port);
    ~udp_server();

    int                 get_socket() const;
    int                 get_port() const;
    std::string         get_addr() const;

    int                 recv(unsigned char *msg, size_t max_size);
    int                 timed_recv(unsigned char *msg, size_t max_size, int max_wait_ms);
    int                 async_recv(size_t max_size, std::function<void(unsigned char*,size_t)> callback);
    int                 stop_recv();

private:
    int                 m_socket;
    int                 m_port;
    std::string         m_addr;
    struct addrinfo *   m_addrinfo;
    std::thread *       m_async_recv_thread;
    bool                m_running_async;
};

} // namespace udp_client_server
} // namespace abds_core
#endif
// ABDS_CORE_CLIENT_SERVER_H