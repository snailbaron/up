#pragma once

#include "geometry.hpp"

#include <random>

// This is a very stupid random point builder. It can and should be replaced by
// something more intricate if required.
class RandomPointBuilder {
public:
    RandomPointBuilder(float x0, float x1, float y0, float y1)
        : _generator(std::random_device{}())
        , _x(x0, x1)
        , _y(y0, y1)
    { }

    Point operator()()
    {
        return Point{_x(_generator), _y(_generator)};
    }

private:
    std::minstd_rand _generator;
    std::uniform_real_distribution<float> _x;
    std::uniform_real_distribution<float> _y;
};
