#pragma once

#include <iterator>

template <class It>
class ConstValueIterator {
public:
    explicit ConstValueIterator(It iterator)
        : _iterator(iterator)
    { }

    ConstValueIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    ConstValueIterator operator++(int)
    {
        auto current = *this;
        operator++();
        return current;
    }

    const auto& operator*() const
    {
        return _iterator->second;
    }

    friend bool operator==(
        const ConstValueIterator& lhs, const ConstValueIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(
        const ConstValueIterator& lhs, const ConstValueIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    It _iterator;
};

namespace std {

template <class It>
struct iterator_traits<ConstValueIterator<It>> {
    using difference_type = typename iterator_traits<It>::difference_type;
    using value_type = typename iterator_traits<It>::value_type::second_type;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = forward_iterator_tag;
};

} // namespace std
