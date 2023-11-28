// cell.hpp
#pragma once

#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class Cell {
public:
    Cell(int x, int y, int thickness);
    void draw(sf::RenderWindow& window, int tile);
    Cell* checkCell(int x, int y, int cols, int rows, std::vector<Cell>& gridCells);
    Cell* checkNeighbors(int cols, int rows, std::vector<Cell>& gridCells);

private:
    int x;
    int y;
    int thickness;
    std::unordered_map<std::string, bool> walls;
    bool visited;
};
