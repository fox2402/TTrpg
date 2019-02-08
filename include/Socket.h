//
// Created by Hiryuu on 2/8/2019.
//

#pragma once

#ifdef __linux__
#include <netinet/ip.h>
#include <netdb.h>
#endif

#ifdef _WIN32
#include <winsock2.h>
#endif

#include <unistd.h>
#include <fcntl.h>
#include <string>

namespace network
{
    class Socket
    {
    enum sock_status
    {
        CLOSED,
        OPENED,
        BINDED,
        LISTENING,
        CONNECTED
    };
    public:
        static void windsoc_startup();
        static void windsoc_cleanup();
        Socket();
        ~Socket();
        void bind_and_listen(int port, int backlog);
        void connect_to_addr(std::string addr, int port);

    private:
        Socket::sock_status status {sock_status::CLOSED};


#ifdef __linux__
        int socket;
#endif

#ifdef _WIN32
        static bool& getInit();
        SOCKET sock;
        SOCKADDR_IN sin;
#endif
    };
}