#pragma once

#include <SFML/Graphics.hpp>

class Widget {
public:
    virtual ~Widget() {}
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual bool contains(int x, int y) const = 0;

    virtual void onGetFocus() {}
    virtual void onLoseFocus() {}
    virtual void onPress() {}
    virtual void onRelease() {}
    virtual void onActivate() {}
};
