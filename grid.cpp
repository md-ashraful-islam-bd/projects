#include <iostream>
#include <cstdlib>
#include <unordered_map>

class Cell {
public:
    Cell(int x, int y, int thickness) : x(x), y(y), thickness(thickness), visited(false) {
        walls["top"] = true;
        walls["right"] = true;
        walls["bottom"] = true;
        walls["left"] = true;
    }

private:
    int x, y;
    int thickness;
    std::unordered_map<std::string, bool> walls;
    bool visited;
};
