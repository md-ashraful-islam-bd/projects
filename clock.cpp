#include "clock.hpp"
#include <chrono>

Clock::Clock() : start_time(std::chrono::steady_clock::now()), elapsed_time(0) {
    font.loadFromFile("arial.ttf"); // Replace with the path to your font file
    message_color = sf::Color::Yellow;
}

void Clock::start_timer() {
    start_time = std::chrono::steady_clock::now();
}

void Clock::update_timer() {
    if (start_time != std::chrono::steady_clock::time_point()) {
        auto now = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();
    }
}

sf::Text Clock::display_timer() {
    int secs = elapsed_time % 60;
    int mins = elapsed_time / 60;

    sf::Text my_time;
    my_time.setFont(font);
    my_time.setString(sf::String(std::to_string(mins) + ":" + (secs < 10 ? "0" : "") + std::to_string(secs)));
    my_time.setCharacterSize(35);
    my_time.setFillColor(message_color);

    return my_time;
}

void Clock::stop_timer() {
    start_time = std::chrono::steady_clock::time_point();
}
