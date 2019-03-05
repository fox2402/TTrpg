//
// Created by Yuudachi Kai on 3/5/2019.
//

#include "server.hpp"
namespace network
{
    template<>
    int Server::RPCCall<RPC_MSG::ROOMCHG>(void *data)
    {
        (void)data;
        return 0;
    }

}