#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>

class Cell
{
public:
  Cell();
  Cell(int x_pos, int y_pos, int size_length);
  bool visited;
  bool best_path;
  bool obstacle;
  bool starting_cell;
  bool goal;
  SDL_Rect square;

  void create_cell(int x_pos, int y_pos, int size_length);
};

#endif
