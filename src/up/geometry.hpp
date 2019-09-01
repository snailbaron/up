#pragma once

#include <ostream>

struct Vector {
    Vector() : x(), y() {}
    Vector(float x, float y) : x(x), y(y) {}

    float x;
    float y;
};

struct Point {
    Point() : x(), y() {}
    Point(float x, float y) : x(x), y(y) {}

    Point& operator+=(const Vector& vector)
    {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    Point& operator-=(const Vector& vector)
    {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    float x;
    float y;
};

inline std::ostream& operator<<(std::ostream& output, const Point& point)
{
    return output << "(" << point.x << ", " << point.y << ")";
}
