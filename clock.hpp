#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SFML/Graphics.hpp>

class Clock {
public:
    Clock();
    void start_timer();
    void update_timer();
    sf::Text display_timer();
    void stop_timer();

private:
    std::chrono::steady_clock::time_point start_time;
    int elapsed_time;
    sf::Font font;
    sf::Color message_color;
};

#endif // CLOCK_HPP
