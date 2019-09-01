#pragma once

#include <SFML/Window.hpp>

struct Config {
    struct Controls {
        sf::Keyboard::Key moveRight = sf::Keyboard::D;
        sf::Keyboard::Key moveLeft = sf::Keyboard::A;
        sf::Keyboard::Key moveUp = sf::Keyboard::W;
        sf::Keyboard::Key moveDown = sf::Keyboard::S;
    };

    Controls controls;
    bool enableVerticalSync = true;
    int gameFps = 60;
};

inline Config& config()
{
    static Config config;
    return config;
}
