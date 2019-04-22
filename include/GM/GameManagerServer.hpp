//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once

#include <asio.hpp>
#include <vector>
#include "GM/GameManagerSingleton.hpp"

namespace GM
{
  class GameManagerServer : public GameManagerSingleton
  {
    SINGLETON_CLASS(GameManagerServer, GameManagerSingleton)

  public:
    SINGLETON_DEFAULT_CTOR_DECL(GameManagerServer)
      : SINGLETON_DEFAULT_CTOR_INIT(), mainSocket_(service_)
    {}

    ~GameManagerServer(){};
    void processAction(NetworkAction &p_act);
    void init(bool p_online);

  private:
    asio::ip::tcp::socket mainSocket_;
    std::vector<asio::ip::tcp::socket> clients_;

    asio::io_service service_;

  };
}
