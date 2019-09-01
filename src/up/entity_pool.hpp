#pragma once

#include "entity.hpp"

#include <deque>

class EntityPool {
public:
    Entity createEntity();
    void killEntity(Entity entity);

private:
    std::deque<Entity> _freeEntities;
    Entity::ValueType _nextEntity = 0;
};
