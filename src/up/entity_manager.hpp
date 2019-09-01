#pragma once

#include "entity.hpp"
#include "entity_pool.hpp"
#include "range.hpp"

#include <any>
#include <cassert>
#include <map>
#include <typeindex>
#include <tuple>

class EntityManager {
public:
    template <class Component>
    Component& component(Entity entity)
    {
        return entityComponents<Component>()[entity];
    }

    // TODO: remove in favor of entitiesWithComponent?
    template <class Component>
    auto allComponents()
    {
        return valueRange(entityComponents<Component>());
    }

    template <class Component>
    auto& entitiesWithComponent()
    {
        return entityComponents<Component>();
    }

    // TODO: why would this be needed?
    template <class Component>
    auto allEntities() const
    {
        return keyRange(entityComponents<Component>());
    }

    Entity createEntity()
    {
        return _entityPool.createEntity();
    }

    void killEntity(Entity entity)
    {
        return _entityPool.killEntity(entity);
    }

private:
    template <class Component>
    std::map<Entity, Component>& entityComponents()
    {
        using Map = std::map<Entity, Component>;

        auto typeIndex = std::type_index{typeid(Component)};
        auto it = _entityComponents.find(typeIndex);
        if (it == _entityComponents.end()) {
            std::tie(it, std::ignore) =
                _entityComponents.insert({typeIndex, Map{}});
        }
        return std::any_cast<Map&>(it->second);
    }

    EntityPool _entityPool;
    std::map<std::type_index, std::any> _entityComponents;
};
