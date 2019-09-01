#include "field.hpp"
#include "ticker.hpp"
#include "events.hpp"

#include <iostream>

Field::Field()
    : _randomPoint(-10.f, 10.f, -10.f, 10.f)
{
    _taskPool.add([this] (double delta) {
        static auto ticker = Ticker{1.0};
        if (ticker(delta)) {
            auto e = _entities.createEntity();
            auto& movement = _entities.component<MovementComponent>(e);
            movement.position = _randomPoint();
            movement.velocity.y = -1.f;

            coreEvents.push(EntityCreate{e});
            coreEvents.push(EntityMove{e, movement.position});
        }
        return TaskState::Running;
    });
}

void Field::update(double delta)
{
    _taskPool.update(delta);

    for (auto& [entity, movement] :
            _entities.entitiesWithComponent<MovementComponent>()) {
        movement.position += movement.velocity;
        coreEvents.push(EntityMove{entity, movement.position});
    }
}
