//
// Created by Hiryuu on 2/8/2019.
//
#include "Socket.hpp"

#include <system_error>


namespace network
{
#ifdef _WIN32
    bool& Socket::getInit()
    {
        static bool wsinit = false;
        return wsinit;
    }
    void Socket::windsoc_startup()
    {
        bool& wsinit = getInit();
        if (!wsinit) {
            WSADATA data;
            WSAStartup(MAKEWORD(2, 0), &data);
            wsinit = true;
        }
    }
    void Socket::windsoc_cleanup()
    {
        bool& wsinit = getInit();
        if (wsinit) {
            WSACleanup();
            wsinit = false;
        }
    }
    Socket::Socket()
    {
        if (!getInit())
            windsoc_startup();
        sock = socket(AF_INET,SOCK_STREAM,0);
        status = sock_status::OPENED;
    }

    void Socket::bind_and_listen(int port, int backlog)
    {
        sin.sin_addr.s_addr	= inet_addr("127.0.0.1");
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        if ((bind(sock, (SOCKADDR *)&sin, sizeof(sin))) == -1)
            throw std::system_error(errno, std::system_category(), "Failed to Bind the socket");
        status = sock_status::BINDED;
        if ((listen(sock, backlog)) == -1)
            throw std::system_error(errno, std::system_category(), "Failed to listen on the socket");
        status = sock_status::LISTENING;
    }

    void Socket::connect_to_addr(std::string addr, int port)
    {
        sin.sin_addr.s_addr	= inet_addr(addr.c_str());
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        if ((connect(sock, (SOCKADDR *)&sin, sizeof(sin))) == -1)
            throw std::system_error(errno, std::system_category(), "Failed to Bind the socket");
        status = sock_status::CONNECTED;
    }

    int Socket::send(void *buf, int len, int flags)
    {
        int i = ::send(sock, static_cast<const char*>(buf), len, flags);
        if (i == -1)
            throw std::system_error(errno, std::system_category(), "Failed to send");
        return i;

    }

    template<>
    SOCKET Socket::getUnderlyingSocket()
    {
        return sock;
    }


#endif

#ifdef __linux__
    void Socket::windsoc_startup(){}
    void Socket::windsoc_startup(){}
#endif
}