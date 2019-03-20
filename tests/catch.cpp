#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

/* Note:
   Custom main can be written like that instead:

#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

int main(int argc, char *argv[]) {
  // custom stuff
  int result = Catch::Session().run(argc, argv);
  // custom stuff
  return result;
};

  More details at:
  https://github.com/catchorg/Catch2/blob/master/docs/own-main.md
*/
