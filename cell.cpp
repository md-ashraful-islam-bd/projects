// cell.cpp
#include "cell.hpp"
#include <cstdlib> // for rand

Cell::Cell(int x, int y, int thickness) : x(x), y(y), thickness(thickness), visited(false) {
    walls = {{"top", true}, {"right", true}, {"bottom", true}, {"left", true}};
}

void Cell::draw(sf::RenderWindow& window, int tile) {
    // ... (unchanged draw method)
}

Cell* Cell::checkCell(int x, int y, int cols, int rows, std::vector<Cell>& gridCells) {
    auto findIndex = [cols](int x, int y) { return x + y * cols; };

    if (x < 0 || x > cols - 1 || y < 0 || y > rows - 1) {
        return nullptr;
    }

    return &gridCells[findIndex(x, y)];
}

Cell* Cell::checkNeighbors(int cols, int rows, std::vector<Cell>& gridCells) {
    std::vector<Cell*> neighbors;
    Cell* top = checkCell(x, y - 1, cols, rows, gridCells);
    Cell* right = checkCell(x + 1, y, cols, rows, gridCells);
    Cell* bottom = checkCell(x, y + 1, cols, rows, gridCells);
    Cell* left = checkCell(x - 1, y, cols, rows, gridCells);

    if (top && !top->visited) {
        neighbors.push_back(top);
    }
    if (right && !right->visited) {
        neighbors.push_back(right);
    }
    if (bottom && !bottom->visited) {
        neighbors.push_back(bottom);
    }
    if (left && !left->visited) {
        neighbors.push_back(left);
    }

    return neighbors.empty() ? nullptr : neighbors[rand() % neighbors.size()];
}
