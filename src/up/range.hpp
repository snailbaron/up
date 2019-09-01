#pragma once

#include "map_iterators.hpp"

#include <utility>

template <class I>
class Range {
public:
    Range(I begin, I end)
        : _begin(std::move(begin))
        , _end(std::move(end))
    { }

    auto begin() const
    {
        return _begin;
    }

    auto end() const
    {
        return _end;
    }

private:
    const I _begin;
    const I _end;
};

template <class Map>
auto keyRange(const Map& map)
{
    return Range{KeyConstIterator{map.begin()}, KeyConstIterator{map.end()}};
}

template <class Map>
auto constValueRange(const Map& map)
{
    return Range{
        ValueConstIterator{map.begin()}, ValueConstIterator{map.end()}};
}

template <class Map>
auto valueRange(Map& map)
{
    return Range{ValueIterator{map.begin()}, ValueIterator{map.end()}};
}
