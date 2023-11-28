// maze.cpp
#include "maze.hpp"

Maze::Maze(int cols, int rows) : cols(cols), rows(rows), thickness(4) {
    gridCells = std::vector<Cell>(cols * rows);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            gridCells[row * cols + col] = Cell(col, row, thickness);
        }
    }
}

void Maze::removeWalls(Cell* current, Cell* next) {
    int dx = current->getX() - next->getX();
    if (dx == 1) {
        current->setWall("left", false);
        next->setWall("right", false);
    } else if (dx == -1) {
        current->setWall("right", false);
        next->setWall("left", false);
    }

    int dy = current->getY() - next->getY();
    if (dy == 1) {
        current->setWall("top", false);
        next->setWall("bottom", false);
    } else if (dy == -1) {
        current->setWall("bottom", false);
        next->setWall("top", false);
    }
}

void Maze::generateMaze() {
    // Implement your maze generation algorithm here
    // You can use the gridCells vector and Cell class
    // Don't forget to update the visited status and call removeWalls
}
