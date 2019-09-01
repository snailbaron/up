#include "game.hpp"
#include "events.hpp"

Game::Game()
{
    coreEvents.subscribe<StartNewGame>([this] (const auto&){
        _field.emplace();
        coreEvents.push(GameStarted{});
    });
}

void Game::update(double delta)
{
    if (_field) {
        _field->update(delta);
    }
}
