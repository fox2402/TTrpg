#include <cassert>
#include <stdexcept>

#include "grid.hpp"

Grid::Grid(idx_t width, idx_t height, Cell default_fill)
  : width_{width}, height_{height}, grid_{width * height, default_fill}
{}

Grid::coords_t::coords_t(std::initializer_list<idx_t> lst)
{
  assert(lst.size() == 2);
  row = *lst.begin();
  col = *(lst.begin() + 1);
}

const Cell& Grid::operator[](coords_t coords) const { return at(coords.row, coords.col); }
Cell& Grid::operator[](coords_t coords)             { return at(coords.row, coords.col); }

const Cell& Grid::at(coords_t coords) const { return at(coords.row, coords.col); }
Cell& Grid::at(coords_t coords)             { return at(coords.row, coords.col); }

const Cell& Grid::at(idx_t row, idx_t col) const
{
  int row_oob = row < height_ ? 0 : (1 << 0);
  int col_oob = col < width_  ? 0 : (1 << 1);
  if (row_oob != 0 or col_oob != 0) {
    constexpr const char* msg[4] = {
      "this message should never appear",            // [0] i.e 00 (neither)
      "row index is out of grid",                    // [1] i.e 01 (row_oob)
      "column index is out of grid",                 // [2] i.e 10 (col_oob)
      "row and column indices are both out of grid"  // [3] i.e 11 (both)
    };
    throw std::out_of_range(msg[row_oob | col_oob]);
  }
  return grid_[row * width_ + col];
}
Cell& Grid::at(idx_t row, idx_t col)
{
  return const_cast<Cell&>(static_cast<const Grid&>(*this).at(row, col));
}
