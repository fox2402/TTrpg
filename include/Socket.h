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
#pragma comment(lib, "ws2_32.lib")
#endif

#include <unistd.h>
#include <fcntl.h>


namespace network
{
    class Socket
    {

    public:
#ifdef _WIN32
        static void windsoc_startup();
        static void windsoc_cleanup();
#endif
        Socket();
    private:

#ifdef __linux__
        int socket;
#endif

#ifdef _WIN32
        static WSADATA data;
        static bool wsinit {false};
        SOCKET socket;
#endif
    };
}