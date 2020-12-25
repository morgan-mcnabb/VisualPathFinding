#include "cell.h"

Cell::Cell()
{
  visited = false;;
  best_path = false;
  obstacle = false;
  starting_cell = false;
  goal = false;
}

Cell::Cell(int x_pos, int y_pos, int side_length)
{
  square.x = x_pos;
  square.y = y_pos;
  square.w = side_length;
  square.h = side_length;
  visited = false; 
  best_path = 0;
}

void Cell::create_cell(int x_pos, int y_pos, int side_length)
{
  square.x = x_pos;
  square.y = y_pos;
  square.w = side_length;
  square.h = side_length;
}
