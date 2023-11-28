#include "main.hpp"

Main::Main() : window(sf::VideoMode(800, 600), "Maze Game"), maze(20, 15), player(0, 0), tile_size(40) {
    window.setFramerateLimit(60);
}

void Main::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle other events if needed
        }

        player.update();
        player.check_move(tile_size, maze.getGridCells(), maze.getThickness());

        window.clear();
        maze.draw(window);
        player.draw(window);
        sf::Text timerText = timer.display_timer();
        timerText.setPosition(10, 10);
        window.draw(timerText);
        window.display();

        timer.update_timer();
    }
}

int main() {
    Main game;
    game.run();

    return 0;
}
