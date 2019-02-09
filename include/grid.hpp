#pragma once

#include <initializer_list>
#include <vector>

#include "cell.hpp"

class Grid {
  using idx_t = unsigned;

public:
  struct coords_t {
    coords_t(std::initializer_list<idx_t> lst);
    idx_t row;
    idx_t col;
  };

  // Ctors
  Grid(idx_t width, idx_t height, Cell default_fill = Cell());

  // Accessors
  const Cell& operator[](coords_t coords) const;
  Cell& operator[](coords_t coords);

  const Cell& at(coords_t coords) const;
  Cell& at(coords_t coords);

  const Cell& at(idx_t row, idx_t col) const;
  Cell& at(idx_t row, idx_t col);
private:
  idx_t width_;
  idx_t height_;
  std::vector<Cell> grid_;
};
