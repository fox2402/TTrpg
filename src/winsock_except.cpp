#include "winsock_except.hpp"


namespace network
{
    winsock_except::winsock_except(int error, std::string usermsg)
    : exception()
    {
        switch (error)
        {
            default:
                emsg = "Unknown error" + usermsg;
        }
    }

    const char *winsock_except::what() const noexcept {
        return emsg.c_str();
    }
}