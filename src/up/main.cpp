#include "config.hpp"
#include "event_logger.hpp"
#include "events.hpp"
#include "field.hpp"
#include "frame_timer.hpp"
#include "view.hpp"
#include "game.hpp"

int main()
{
    auto eventLogger = EventLogger{};

    auto game = Game{};
    auto view = View{};

    auto frameTimer = FrameTimer{config().gameFps};
    while (view.isAlive()) {
        view.processInputEvents();

        auto framesPassed = frameTimer();
        for (auto i = framesPassed; i > 0; i--) {
            game.update(frameTimer.delta());
        }

        if (framesPassed > 0) {
            coreEvents.send();
        }

        if (framesPassed > 0) {
            view.update(frameTimer.delta() * framesPassed);
            view.draw();
        }
    }
}
