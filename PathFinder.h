#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <SDL2/SDL.h>
#include "cell.h"

class PathFinder
{
public:
  PathFinder(int rows, int columns);
  int rows;
  int columns;
  const int CELL_SIZE = 20;
  const int MAX_OBSTACLES = (rows * columns) / 10;
  Cell** cells;
  void begin_simulation();

private:
  void populate_cells();
  bool goal_set;
  SDL_Event event;
  SDL_Renderer* renderer;
  SDL_Window* window;
  bool check_cell(Cell cell);
  void traverse();
};

#endif
