#pragma once

enum class CellType {
  Empty,
  Grass // temporary, just for testing
};

class Cell {
public:
  explicit Cell(CellType type = CellType::Empty) : type_{type} {}
private:
  CellType type_;
  // todo: vector of pointers to entities on the cell and/or components/elements/statuses
};
