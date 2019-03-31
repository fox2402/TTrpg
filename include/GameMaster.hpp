//
// Created by Yuudachi Kai on 3/31/2019.
//
#pragma once
#include<variant>


namespace network
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
  protected:

  };
}