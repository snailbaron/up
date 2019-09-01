#pragma once

#include <iterator>

template <class I>
class KeyConstIterator {
public:
    explicit KeyConstIterator(I iterator)
        : _iterator(iterator)
    { }

    KeyConstIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    KeyConstIterator operator++(int)
    {
        auto current = *this;
        operator++();
        return current;
    }

    const auto& operator*() const
    {
        return _iterator->first;
    }

    friend bool operator==(
        const KeyConstIterator& lhs, const KeyConstIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(
        const KeyConstIterator& lhs, const KeyConstIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    I _iterator;
};

namespace std {

template <class I>
struct iterator_traits<KeyConstIterator<I>> {
    using difference_type = typename iterator_traits<I>::difference_type;
    using value_type = typename iterator_traits<I>::value_type::first_type;
    using pointer = const value_type*;
    using reference = const value_type&;
    using iterator_category = forward_iterator_tag;
};

} // namespace std

template <class I>
class ValueConstIterator {
public:
    explicit ValueConstIterator(I iterator)
        : _iterator(iterator)
    { }

    ValueConstIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    ValueConstIterator operator++(int)
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
        const ValueConstIterator& lhs, const ValueConstIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(
        const ValueConstIterator& lhs, const ValueConstIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    I _iterator;
};

namespace std {

template <class I>
struct iterator_traits<ValueConstIterator<I>> {
    using difference_type = typename iterator_traits<I>::difference_type;
    using value_type = typename iterator_traits<I>::value_type::second_type;
    using pointer = const value_type*;
    using reference = const value_type&;
    using iterator_category = forward_iterator_tag;
};

} // namespace std

template <class I>
class ValueIterator {
public:
    explicit ValueIterator(I iterator)
        : _iterator(iterator)
    { }

    ValueIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    ValueIterator operator++(int)
    {
        auto current = *this;
        operator++();
        return current;
    }

    auto& operator*() const
    {
        return _iterator->second;
    }

    friend bool operator==(
        const ValueIterator& lhs, const ValueIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(
        const ValueIterator& lhs, const ValueIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    I _iterator;
};

namespace std {

template <class I>
struct iterator_traits<ValueIterator<I>> {
    using difference_type = typename iterator_traits<I>::difference_type;
    using value_type = typename iterator_traits<I>::value_type::second_type;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = forward_iterator_tag;
};

} // namespace std
