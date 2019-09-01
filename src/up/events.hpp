#pragma once

#include "event_queue.hpp"
#include "entity.hpp"
#include "geometry.hpp"

struct EntityCreate {
    Entity entity;
};

struct EntityMove {
    Entity entity;
    Point position;
};

struct StartNewGame {};
struct GameStarted {};

inline EventQueue coreEvents;
