//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once

#include <asio.hpp>
#include <vector>
#include "GM/GameManager.hpp"

namespace GM
{
  class GameManagerServer : public GameManager, public MutableSingleton<GameManagerServer>
  {
  public:
    ~GameManagerServer(){};
    void processAction(NetworkAction &p_act);
    void init(bool p_online);


  protected:
    GameManagerServer(SingletonBase<GameManagerServer>::SingletonExclusiveConstructor ctor);
  private:
    asio::ip::tcp::socket mainSocket_;
    std::vector<asio::ip::tcp::socket> clients_;

    asio::io_service service_;

  };
}
