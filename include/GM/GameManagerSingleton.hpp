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

  class GameManagerSingleton : public MutableDynamicSingleton<GameManagerSingleton>
  {
    SINGLETON_CLASS(GameManagerSingleton, MutableDynamicSingleton<GameManagerSingleton>)

  public:
    SINGLETON_DEFAULT_CTOR(GameManagerSingleton)

    virtual ~GameManagerSingleton() = 0;
    virtual void processAction(NetworkAction &p_act) = 0;
  };

  // bring singleton functions directly to the GM namespace for ease of use
  // e.g: GM::instance()

  template <class U, class... Args>
  void initialize_instance(Args&&... args) {
    GameManagerSingleton::initialize_instance<U>(std::forward(args)...);
  }

  auto instance() -> decltype(GameManagerSingleton::instance()) {
    return GameManagerSingleton::instance();
  }

  bool is_instance_initialized() {
    return GameManagerSingleton::is_instance_initialized();
  }
}
