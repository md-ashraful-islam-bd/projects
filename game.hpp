#pragma once

#include <SFML/Graphics.hpp>
#include "cell.hpp" // Assuming you have a cell class

class Game {
public:
    Game(Cell goalCell, int tile);
    void addGoalPoint(sf::RenderWindow& window);
    sf::Text message();
    bool isGameOver(Player& player);

private:
    sf::Font font;
    sf::Color messageColor;
    Cell goalCell;
    int tile;
};
