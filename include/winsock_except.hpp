#pragma once
#include <exception>
#include <string>


namespace network {
    class winsock_except : public std::exception {
    public:
        winsock_except() = delete;

        winsock_except(winsock_except &e) = delete;

        winsock_except(int error, std::string usermsg);

        const char *what() const noexcept override;

    private:
        std::string emsg;

    };
}
