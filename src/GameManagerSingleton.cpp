#include "GM/GameManagerSingleton.hpp"

namespace GM {
  auto instance() -> decltype(GameManagerSingleton::instance()) {
    return GameManagerSingleton::instance();
  }

  bool is_instance_initialized() {
    return GameManagerSingleton::is_instance_initialized();
  }
}
