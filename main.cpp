#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "cell.h"
#include "PathFinder.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;
const int CELL_SIZE = 20;


int main(int argc, char* args[])
{
  srand(time(NULL)); 
  PathFinder test(SCREEN_WIDTH/CELL_SIZE, SCREEN_HEIGHT/CELL_SIZE);
  test.begin_simulation();
  
  return 0;
}
