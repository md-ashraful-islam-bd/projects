#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.hpp" // Include the header for Cell class

class Player {
public:
    Player(int x, int y);
    void get_current_cell(int x, int y, std::vector<Cell>& gridCells);
    void check_move(int tile, std::vector<Cell>& gridCells, int thickness);
    void draw(sf::RenderWindow& window);
    void update();

private:
    int x;
    int y;
    int player_size;
    sf::RectangleShape rect;
    sf::Color color;
    float velX;
    float velY;
    bool left_pressed;
    bool right_pressed;
    bool up_pressed;
    bool down_pressed;
    float speed;
};
