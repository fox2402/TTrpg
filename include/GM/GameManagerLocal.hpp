//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once

#include "GM/GameManager.hpp"


class GameManagerClient : public GameManager, public MutableSingleton<GameManagerClient>
{
public:
  ~GameManagerClient(){};

  void processAction(NetworkAction& p_act);

};