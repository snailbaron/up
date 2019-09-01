#include "event_logger.hpp"
#include "events.hpp"

#include <iostream>

EventLogger::EventLogger()
{
    coreEvents.subscribe<EntityCreate>([] (const auto& event) {
        std::cout << "entity create: " << event.entity << "\n";
    });

    coreEvents.subscribe<EntityMove>([] (const auto& event) {
        std::cout << "entity move: (" << event.entity << ") -> " <<
            event.position << "\n";
    });
}
