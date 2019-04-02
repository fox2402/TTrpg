//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once
#include<variant>

#include "utils/singleton.hpp"


namespace GM
{


  enum class ActionType
  {
    MOVE,
    ATK,
    CHARUPDATE,
    LVLCHANGE
  };

  struct NetworkAction
  {
    ActionType type;
    std::variant<int> data;
  };

  class GameManager
  {
  public:
    virtual ~GameManager() = 0;

    virtual void processAction(NetworkAction &p_act) = 0;


  protected:

  };
}
