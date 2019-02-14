//
// Created by Hiryuu on 2/14/2019.
//

#include <system_error>

class winsock_errors : public std::error_category
{
    const char* name() const noexcept override;
    std::string message(int ev) const override;
};