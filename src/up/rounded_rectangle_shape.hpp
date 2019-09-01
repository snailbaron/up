#pragma once

#include <SFML/Graphics.hpp>

#include <cstddef>

sf::Transform power(const sf::Transform transform, unsigned p)
{
    if (p == 0) {
        return sf::Transform::Identity;
    }
    if (p == 1) {
        return transform;
    }

    auto half = power(transform, p / 2);
    auto result = half * half;
    if (p % 2) {
        result *= transform;
    }
    return result;
}

class RoundedRectangleShape : public sf::Shape {
public:
    RoundedRectangleShape(sf::Vector2f size)
    {
        _rotation.rotate(90 / (anglePointCount - 1));
        setSize(size);
        update();
    }

    sf::Vector2f getSize() const
    {
        return 2.f * (_innerRadius + _outerRadius);
    }

    void setSize(const sf::Vector2f& size)
    {
        auto cornerRadius = std::min(size.x, size.y) * angleFraction;
        _outerRadius = {cornerRadius, cornerRadius};
        _innerRadius = size / 2.f - _outerRadius;
        update();
    }

    std::size_t getPointCount() const override
    {
        return anglePointCount * 4;
    }

    sf::Vector2f getPoint(std::size_t index) const override
    {
        auto quadrant = index / anglePointCount;
        auto direction =
            power(_rotation, index - quadrant) * sf::Vector2f{1.f, 0.f};
        int xsign = !!(quadrant & 1) == !!(quadrant & 2) ? 1 : -1;
        int ysign = !(quadrant & 2) ? 1 : -1;
        return {
            (1 + direction.x) * _outerRadius.x + (1 + xsign) * _innerRadius.x,
            (1 + direction.y) * _outerRadius.y + (1 + ysign) * _innerRadius.y};
    }

private:
    static constexpr auto anglePointCount = 6;
    static constexpr auto angleFraction = 0.2f;

    sf::Vector2f _innerRadius;
    sf::Vector2f _outerRadius;
    sf::Transform _rotation;
};
