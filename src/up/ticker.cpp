#include "ticker.hpp"

#include <cmath>

int Ticker::operator()(double delta)
{
    _currentTime += delta;
    auto framesPassed = static_cast<int>(_currentTime / _period);
    _currentTime = std::fmod(_currentTime, _period);
    return framesPassed;
}
