#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include "maze.hpp"
#include "player.hpp"
#include "clock.hpp"

class Main {
public:
    Main();
    void run();

private:
    sf::RenderWindow window;
    Maze maze;
    Player player;
    Clock timer;
    int tile_size;
};

#endif // MAIN_HPP
