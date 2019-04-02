//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once
#include <asio.hpp>
#include "GM/GameManager.hpp"

namespace GM
{
  class GameManagerLocal : public GameManager, public MutableSingleton<GameManagerLocal>
  {
  public:
    ~GameManagerLocal(){};

    void processAction(NetworkAction &p_act);
    void init();

  private:
    asio::ip::tcp::socket mainSocket_;
  };


}