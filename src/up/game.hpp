#pragma once

#include "field.hpp"

#include <optional>

class Game {
public:
    Game();

    void update(double delta);

private:
    std::optional<Field> _field;
};
