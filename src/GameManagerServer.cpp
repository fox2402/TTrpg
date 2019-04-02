//
// Created by Yuudachi Kai on 4/2/2019.
//

#include "GM/GameManagerServer.hpp"

#include <iostream>

namespace GM
{
  void GameManagerServer::init(bool p_online)
  {
    if (p_online)
    {
      //FIXME the endpoint needs to be assigned from the menu
      asio::ip::tcp::endpoint endpoint;
      asio::ip::tcp::acceptor acceptor{service_, endpoint};
      asio::ip::tcp::socket& newClient = clients_.emplace_back(service_);
      (void) newClient;
      asio::error_code code;
      mainSocket_.connect(endpoint, code);

      if (code)
      {
        std::cerr << "GameManagerLocal: OnSocketConnect: " << code.message();
        return;
        //something happened
      }

    }
    else
    {

    }
  }
  GameManagerServer::GameManagerServer(SingletonBase<GameManagerServer>::SingletonExclusiveConstructor ctor)
  : GameManager()
  , MutableSingleton<GameManagerServer>(ctor)
  , mainSocket_(service_)
  {

  }
}