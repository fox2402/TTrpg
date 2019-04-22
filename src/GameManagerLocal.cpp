//
// Created by Yuudachi Kai on 4/2/2019.
//
#include "GM/GameManagerLocal.hpp"

#include <iostream>

namespace GM
{
  void GameManagerLocal::init()
  {

    //FIXME the endpoint needs to be assigned from the menu
    asio::ip::tcp::endpoint endpoint;

    asio::error_code code;
//    mainSocket_.connect(endpoint, code);

    if (code)
    {
      std::cerr << "GameManagerLocal: OnSocketConnect: " << code.message();
      return;
      //something happened
    }


  }
}
