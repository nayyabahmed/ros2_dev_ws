
#include "udp_client_server.hpp"
#include <string.h>
#include <unistd.h>
#include <exception>
namespace abds_core
{
namespace udp_client_server
{


// ========================= CLIENT =========================

udp_client::udp_client(const std::string& addr, int port)
    : m_port(port)
    , m_addr(addr)
{
    char decimal_port[16];
    snprintf(decimal_port, sizeof(decimal_port), "%d", m_port);
    decimal_port[sizeof(decimal_port) / sizeof(decimal_port[0]) - 1] = '\0';
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    int r(getaddrinfo(addr.c_str(), decimal_port, &hints, &m_addrinfo));
    if(r != 0 || m_addrinfo == NULL)
    {
        throw udp_client_server_runtime_error(("invalid address or port: \"" + addr + ":" + decimal_port + "\"").c_str());
    }
    m_socket = socket(m_addrinfo->ai_family, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
    if(m_socket == -1)
    {
        freeaddrinfo(m_addrinfo);
        throw udp_client_server_runtime_error(("could not create socket for: \"" + addr + ":" + decimal_port + "\"").c_str());
    }
}

udp_client::~udp_client()
{
    freeaddrinfo(m_addrinfo);
    close(m_socket);
}

int udp_client::get_socket() const
{
    return m_socket;
}

int udp_client::get_port() const
{
    return m_port;
}

std::string udp_client::get_addr() const
{
    return m_addr;
}

int udp_client::send(const unsigned char *msg, size_t size)
{
    return sendto(m_socket, msg, size, 0, m_addrinfo->ai_addr, m_addrinfo->ai_addrlen);
}

udp_server::udp_server(const std::string& addr, int port)
    : m_port(port)
    , m_addr(addr)
{
    char decimal_port[16];
    snprintf(decimal_port, sizeof(decimal_port), "%d", m_port);
    decimal_port[sizeof(decimal_port) / sizeof(decimal_port[0]) - 1] = '\0';
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    int r(getaddrinfo(addr.c_str(), decimal_port, &hints, &m_addrinfo));
    if(r != 0 || m_addrinfo == NULL)
    {
        throw udp_client_server_runtime_error(("invalid address or port for UDP socket: \"" + addr + ":" + decimal_port + "\"").c_str());
    }
    m_socket = socket(m_addrinfo->ai_family, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
    if(m_socket == -1)
    {
        freeaddrinfo(m_addrinfo);
        throw udp_client_server_runtime_error(("could not create UDP socket for: \"" + addr + ":" + decimal_port + "\"").c_str());
    }
    r = bind(m_socket, m_addrinfo->ai_addr, m_addrinfo->ai_addrlen);
    if(r != 0)
    {
        freeaddrinfo(m_addrinfo);
        close(m_socket);
        throw udp_client_server_runtime_error(("could not bind UDP socket with: \"" + addr + ":" + decimal_port + "\"").c_str());
    }
}

udp_server::~udp_server()
{
    stop_recv();
    freeaddrinfo(m_addrinfo);
    close(m_socket);
}

int udp_server::get_socket() const
{
    return m_socket;
}

int udp_server::get_port() const
{
    return m_port;
}

std::string udp_server::get_addr() const
{
    return m_addr;
}

int udp_server::recv(unsigned char *msg, size_t max_size)
{
    return ::recv(m_socket, msg, max_size, 0);
}

int udp_server::timed_recv(unsigned char *msg, size_t max_size, int max_wait_ms)
{
    fd_set s;
    FD_ZERO(&s);
    FD_SET(m_socket, &s);
    struct timeval timeout;
    timeout.tv_sec = max_wait_ms / 1000;
    timeout.tv_usec = (max_wait_ms % 1000) * 1000;
    int retval = select(m_socket + 1, &s, &s, &s, &timeout);
    if(retval == -1)
    {
        // select() set errno accordingly
        return -1;
    }
    if(retval > 0)
    {
        // our socket has data
        return ::recv(m_socket, msg, max_size, 0);
    }

    // our socket has no data
    errno = EAGAIN;
    return -1;
}

int udp_server::async_recv(size_t max_size, std::function<void(unsigned char*,size_t)> callback)
{
    if(m_running_async)
    {
        throw std::runtime_error("udp_socket already receiving async packets");
    }
    
    m_running_async = true;
    m_async_recv_thread = new std::thread([this](size_t max_size, std::function<void(unsigned char*,size_t)> callback){
        while (m_running_async)
        {
            unsigned char msg[max_size];
            if(timed_recv(msg,max_size,10) > 0)
            {
                callback(msg,max_size);
            }
        }
    }, max_size, callback
    );
}

int udp_server::stop_recv()
{
    m_running_async = false;
    delete m_async_recv_thread;
}

} // namespace udp_client_server
} // namespace abds_core
