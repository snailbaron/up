#pragma once

#include "task_pool.hpp"
#include "geometry.hpp"
#include "entity_manager.hpp"
#include "random.hpp"

struct MovementComponent {
    Point position;
    Vector velocity;
};

class Field {
public:
    Field();

    void update(double delta);

private:
    TaskPool _taskPool;
    EntityManager _entities;
    RandomPointBuilder _randomPoint;
};
