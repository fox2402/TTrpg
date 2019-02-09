#include <iostream>

#include "grid.hpp"
#include "Socket.h"

int main() {

  Grid grid(5, 3);
  grid.at({0,0}) = Cell(CellType::Grass);
  grid.at(1, 1) = Cell(CellType::Grass);
  grid[{2, 2}] = Cell(CellType::Grass);
  grid[{3, 2}] = Cell(CellType::Grass);
#ifdef _WIN32

#endif
    return 0;
}
