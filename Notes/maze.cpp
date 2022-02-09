#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char me = 'Z';
char wall = ' ';
char goal = '$';

int load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
  return i;
}

void print_maze(std::string maze[],int lines){
  for(int i = 0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
}

void solve(std::string maze[], int lines, int row, int col){
  if(maze[row][col] == wall){
    return;
  }
  else if(maze[row][col] == me){
    return;
  }
  else if(maze[row][col] == goal){
    std::cout << "solved\n"; 
    exit(1);
  }
  //record where you are when moving the maze
  maze[row][col] = me;
  print_maze(maze, lines);
  solve(maze, lines, row, col+1);
  solve(maze, lines, row, col-1);
  solve(maze, lines, row+1, col);
  solve(maze, lines, row-1, col);
}

int main()
{
  std::string maze[27];
  int lines;
  lines = load_maze("maze.dat",maze);
  //std::cout << lines << "\n";
  print_maze(maze,lines);
  solve(maze,lines,2,2);
  return 0;
}
