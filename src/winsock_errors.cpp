#include "winsock_errors.hpp"
#include <winsock2.h>


const char *winsock_errors::name() const noexcept {
    return "winsock";
}

std::string winsock_errors::message(int ev) const {

    switch (ev)
    {
        case WSANOTINITIALISED:
            return "WSAStartup never called";
        case WSAENETDOWN:
            return "Network is down (Network stack, interface or local network)";
        case WSAEADDRINUSE:
            return "Trying to use an already locked adress/port pair";
        case WSAEINPROGRESS:
            return "Socket already locked by another blocking operation";
        case WSAEINVAL:
            return "Invalid argument";
        case WSAEISCONN:
            return "Socket already connected";
        case WSAEACCES:
            return "Permission denied";
        case WSAEADDRNOTAVAIL:
            return "Cannot assign requested address";
        case WSAEFAULT:
            return "Bad address, invalid pointer or invalid given size";
        case WSAENOBUFS:
            return "No buffer space (this is bad lad)";
        case WSAENOTSOCK:
            return "This is not a socket (art thou drunk?)";
        case WSAEINTR:
            return "Interrupted";
        case WSAEALREADY:
            return "Operation in progress (chill pls)";
        case WSAEAFNOSUPPORT:
            return "Address family not supported by protocol family";
        case WSAECONNREFUSED:
            return "Connection refused";
        case WSAENETUNREACH:
            return "Network is unreachable (probably a L3 problem)";
        case WSAEHOSTUNREACH:
            return "No route to host (who needs a map anyway)";
        case WSAETIMEDOUT:
            return "Connection timed out";
        case WSAEWOULDBLOCK:
            return "Resource temporarily unavailable (not fatal)";
        case WSAEOPNOTSUPP:
            return "Operation not supported";
        case WSAESHUTDOWN:
            return "Request on shutdowned socket";
        case WSAEMSGSIZE:
            return "Message to long";
        case WSAECONNABORTED:
            return "Software-side connection abord";
        case WSAECONNRESET:
            return "Connection reset by peer";
        default:
            return "Unknown error";
    }
}
