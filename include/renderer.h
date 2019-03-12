#pragma once

// Temporary forward declarations until these classes actually exists
// Scene should contain grid, entities, ... everything that is in the level
// Ui is for contextual elements, menus, also contains display mode for grid ...
class Scene;
class Ui;

class Renderer {
public:
  virtual void render(const Scene& scene, const Ui& ui) = 0;
  virtual void draw()  = 0;
};
