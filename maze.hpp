// maze.hpp
#pragma once

#include "cell.hpp"

class Maze {
public:
    Maze(int cols, int rows);
    void removeWalls(Cell* current, Cell* next);
    void generateMaze();

private:
    int cols;
    int rows;
    int thickness;
    std::vector<Cell> gridCells;
};
