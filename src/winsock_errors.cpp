#include "winsock_errors.hpp"
#include <winsock2.h>


const char *winsock_errors::name() const noexcept {
    return "winsock";
}

std::string winsock_errors::message(int ev) const {

    switch (ev)
    {
        case WSANOTINITIALISED:
        case WSAENETDOWN:
        case WSAEADDRINUSE:
        case WSAEINPROGRESS:
        case WSAEINVAL:
        case WSAEISCONN:
        case WSAEACCES:
        case WSAEADDRNOTAVAIL:
        case WSAEFAULT:
        case WSAENOBUFS:
        case WSAENOTSOCK:
        case WSAEINTR:
        case WSAEALREADY:
        case WSAEAFNOSUPPORT:
        case WSAECONNREFUSED:
        case WSAENETUNREACH:
        case WSAEHOSTUNREACH:
        case WSAETIMEDOUT:
        case WSAEWOULDBLOCK:
        case WSAEOPNOTSUPP:
        case WSAESHUTDOWN:
        case WSAEMSGSIZE:
        case WSAECONNABORTED:
        case WSAECONNRESET:
        default:
            return "Unknown error";
    }
}
