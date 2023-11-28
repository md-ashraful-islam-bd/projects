#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game(Cell goalCell, int tile) : goalCell(goalCell), tile(tile) {
    font.loadFromFile("arial.ttf"); // Replace "arial.ttf" with the correct path to your font file
    messageColor = sf::Color::Yellow;
}

void Game::addGoalPoint(sf::RenderWindow& window) {
    // Adding gate for the goal point
    sf::Texture texture;
    if (texture.loadFromFile("gate.png")) { // Replace "img/gate.png" with the correct path to your image
        sf::Sprite sprite(texture);
        sprite.setScale(static_cast<float>(tile) / texture.getSize().x, static_cast<float>(tile) / texture.getSize().y);
        sprite.setPosition(goalCell.getX() * tile, goalCell.getY() * tile);
        window.draw(sprite);
    }
}

sf::Text Game::message() {
    sf::Text msg;
    msg.setFont(font);
    msg.setString("You Win!!");
    msg.setCharacterSize(35);
    msg.setFillColor(messageColor);
    return msg;
}

bool Game::isGameOver(Player& player) {
    int goalCellAbsX = goalCell.getX() * tile;
    int goalCellAbsY = goalCell.getY() * tile;
    return player.getX() >= goalCellAbsX && player.getY() >= goalCellAbsY;
}
