//
// Created by Hiryuu on 2/8/2019.
//

#include "Socket.h"

namespace network
{
#ifdef _WIN32
    void Socket::windsoc_startup()
    {
        if (!wsinit) {
            WSAStartup(MAKEWORD(2, 0), &Socket::data);
            Socket::wsinit = true;
        }
    }
    void Socket::windsoc_cleanup()
    {
        if (wsinit) {
            WSACleanup();
            Socket::wsinit = false;
        }
    }
#endif
}