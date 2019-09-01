#pragma once

#include "ui.hpp"
#include "widget.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <type_traits>
#include <vector>

class View {
public:
    View();

    void processInputEvents();
    void update(double delta);
    void draw();

    bool isAlive() const;

private:
    void createMainMenu();

    sf::RenderWindow _window;
    Ui _ui;
};
