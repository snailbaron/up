#include "events.hpp"
#include "button.hpp"
#include "config.hpp"
#include "view.hpp"

#include <utility>

View::View()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(
        sf::VideoMode{1024, 768}, "tower-power", sf::Style::Default, settings);

    _window.setVerticalSyncEnabled(config().enableVerticalSync);

    createMainMenu();

    coreEvents.subscribe<GameStarted>([this] (const auto&) {
    });
}

void View::processInputEvents()
{
    auto event = sf::Event{};
    while (_window.pollEvent(event)) {
        _ui.processInputEvent(event);

        if (event.type == sf::Event::Closed) {
            _window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                _window.close();
            } else if (event.key.code == config().controls.moveRight) {
            } else if (event.key.code == config().controls.moveLeft) {
            } else if (event.key.code == config().controls.moveUp) {
            } else if (event.key.code == config().controls.moveDown) {
            }
        }
    }
}

void View::update(double delta)
{
}

void View::draw()
{
    _window.clear(sf::Color{50, 50, 50});
    _ui.draw(_window);
    _window.display();
}

bool View::isAlive() const
{
    return _window.isOpen();
}

void View::createMainMenu()
{
    _ui.addWidget<Button>()
        .position(600.f, 80.f)
        .size(250.f, 50.f)
        .text("New Game");
    _ui.addWidget<Button>()
        .position(600.f, 150.f)
        .size(250.f, 50.f)
        .text("Exit")
        .action(
            [this] {
                _window.close();
            });
}
