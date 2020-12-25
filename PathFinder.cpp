#include "PathFinder.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;

PathFinder::PathFinder(int r, int c) : rows(r), columns(c), goal_set(false)
{
  cells = new Cell*[rows];

  for(int i = 0; i < rows; i++)
  {
    cells[i] = new Cell[columns];
  }

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH+rows, SCREEN_HEIGHT+columns, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

  // set background to white
  SDL_SetRenderDrawColor(renderer,160,160,160, 255);
  SDL_RenderClear(renderer);

  populate_cells();
}

void PathFinder::populate_cells()
{
  int obstacle_count = 0;
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
    {
      cells[i][j].create_cell(i*(CELL_SIZE+1), j*(CELL_SIZE+1), CELL_SIZE);
      if(i == 0 && j == 0)
      {
        cells[i][j].starting_cell = true;
        SDL_SetRenderDrawColor(renderer, 97, 187, 215, 255);
      }
      else if(rand() % 1000 + 1 <= 3 && !goal_set)
      {
        goal_set = true;
        cells[i][j].goal = true;
        SDL_SetRenderDrawColor(renderer, 204, 204, 0, 255);
      }
      else if(rand() % 1000 + 1 <= 50 && obstacle_count < MAX_OBSTACLES)
      {
        obstacle_count++;
        cells[i][j].obstacle = true;
        SDL_SetRenderDrawColor(renderer, 64,64,64,255);
      }
      else if(cells[i][j].visited)
      {
        if(!cells[i][j].best_path)
          SDL_SetRenderDrawColor(renderer,206, 129, 129, 255); 
        else
          SDL_SetRenderDrawColor(renderer, 116, 215, 97, 255);
      }
      else
        SDL_SetRenderDrawColor(renderer,255 ,255, 255, 255);

      SDL_RenderFillRect(renderer, &cells[i][j].square);
    }

  if(!goal_set)
  {
    goal_set = true;
    cells[rows - 1][columns - 1].goal = true;
    cells[rows - 1][columns - 1].obstacle = false;
    SDL_SetRenderDrawColor(renderer, 204, 204, 0, 255);

    SDL_RenderFillRect(renderer, &cells[rows - 1][columns - 1].square);
  }
}

void PathFinder::begin_simulation()
{
  SDL_RenderPresent(renderer);
  while(1)
  {
    if(SDL_PollEvent(&event) && event.type == SDL_QUIT)
      break;

    traverse();
  }
  SDL_Delay(5000);
  SDL_DestroyRenderer(renderer);

  SDL_DestroyWindow(window);

  SDL_Quit();
}

void PathFinder::traverse()
{
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
    {
      if(!cells[i][j].obstacle && !cells[i][j].starting_cell)
      {
        if(check_cell(cells[i][j]))
          return;
        SDL_Delay(100);    
      }
    }

}

bool PathFinder::check_cell(Cell cell)
{
  if(cell.goal)
  {
    SDL_SetRenderDrawColor(renderer, 0, 204, 204, 255);
    SDL_RenderFillRect(renderer, &cell.square);
  }
  else
  {
    cell.visited = true;
    SDL_SetRenderDrawColor(renderer,206, 129, 129, 255);
    SDL_RenderFillRect(renderer, &cell.square);
  }
  SDL_RenderPresent(renderer);
  return cell.goal;
}

void PathFinder::dijkstra()
{
  // 1. Mark all nodes unvisited. create a set of all the unvisited nodes
  //    called the unvisited set

  
  // 2. assign to every node a tentative distance value: set it to zero for our
  //    initial node and to infinity for all other nodes. set the initial node
  //    as current.

  // 3. for the furrent node, consider all of its unvisited neighbors and
  //    calculate their tentative distances through the current node. compare
  //    the newly calculated tentative distance to the current assigned value
  //    and assign the sammler one. for example, if the current node A is
  //    marked with a distance of 6, and the edge connecting it twith
  //    a neighbor B has length 2, then the distance to B through A will be
  //    6 + 2 = 8. if B was previously marked with a greater distance than 8 it
  //    then change it to 8. otherwise, the current value will be kept.

  // 4. when we are done considering all of the unvisited neighbors of the
  //    current node, mark the code as visited and remove it from the unvisited
  //    set. a visited node will never be checked again.
  
  // 5. if the destination node has been marked visited (when plannig a route
  //    between two specidic nodes) or if the smallest tentative distance among
  //    the nodes in the unvisited set is infinity (when plannin a complete
  //    traversal; occurs when there is no conncection between the initial node
  //    and remaining unvisisted nodes), then stop. The algorithm has
  //    finished.

  // 6. otherwise, select the unvisited node that is marked with the smallest
  //    tentative distance, set it as the new "current node" and go back to
  //    step 3.
}
