#pragma once

#include "widget.hpp"

#include <SFML/Graphics.hpp>

class Ui {
public:
    void processInputEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);

    template <class T>
    T& addWidget()
    {
        static_assert(std::is_base_of<Widget, T>());

        _widgets.push_back(std::make_unique<T>());
        return *static_cast<T*>(_widgets.back().get());
    }

private:
    Widget* widgetAtPosition(int x, int y);

    std::vector<std::unique_ptr<Widget>> _widgets;
    Widget* _focusedWidget = nullptr;
    Widget* _pressedWidget = nullptr;
};
