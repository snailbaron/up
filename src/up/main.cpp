#include "config.hpp"
#include "frame_timer.hpp"
#include "field.hpp"
#include "event_logger.hpp"
#include "events.hpp"

int main()
{
    auto config = Config{};

    auto field = Field{};
    auto eventLogger = EventLogger{};

    auto frameTimer = FrameTimer{config.gameFps};
    for (;;) {
        auto framesPassed = frameTimer();
        for (auto i = framesPassed; i > 0; i--) {
            field.update(frameTimer.delta());
        }

        if (framesPassed > 0) {
            coreEvents.send();
        }
    }
}
