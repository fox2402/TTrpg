//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once

#include "GM/GameManager.hpp"

namespace GM
{
  class GameManagerServer : public GameManager, public MutableSingleton<GameManagerServer>
  {
  public:
    ~GameManagerServer()
    {};

    void processAction(NetworkAction &p_act);
  };
}
