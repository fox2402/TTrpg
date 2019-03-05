//
// Created by Yuudachi Kai on 3/5/2019.
//

#include "Socket.hpp"


namespace network {

    enum RPC_MSG
    {
        ROOMCHG,

    };

    class Server {
    public:
        Server() = delete;

        Server(Server &) = delete;


        explicit Server(bool local);

        template<typename T>
        int RPCCall(void* data);

        int updatePosition(void* data);

        void fetchUpdates();

    private:
        bool local_;

    };
}
