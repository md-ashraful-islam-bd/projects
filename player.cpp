#include "player.hpp"

Player::Player(int x, int y) : x(x), y(y), player_size(10), color(250, 120, 60), velX(0), velY(0),
                                left_pressed(false), right_pressed(false), up_pressed(false),
                                down_pressed(false), speed(4) {
    rect = sf::RectangleShape(sf::Vector2f(player_size, player_size));
    rect.setPosition(x, y);
    rect.setFillColor(color);
}

void Player::get_current_cell(int x, int y, std::vector<Cell>& gridCells) {
    // Implementation
}

void Player::check_move(int tile, std::vector<Cell>& gridCells, int thickness) {
    // Implementation
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(rect);
}

void Player::update() {
    // Implementation
}
