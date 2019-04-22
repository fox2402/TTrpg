//
// Created by Yuudachi Kai on 3/31/2019.
//

#pragma once
#include <asio.hpp>
#include "GM/GameManagerSingleton.hpp"

namespace GM
{
  class GameManagerLocal : public GameManagerSingleton
  {
    SINGLETON_CLASS(GameManagerLocal, GameManagerSingleton)

  public:
    SINGLETON_DEFAULT_CTOR_DECL(GameManagerLocal)
      : SINGLETON_DEFAULT_CTOR_INIT()
//      , mainSocket_(/* fixme */)
    {}

    ~GameManagerLocal() {}

    void processAction(NetworkAction &p_act);
    void init();

  private:
//    asio::ip::tcp::socket mainSocket_;
  };


}
