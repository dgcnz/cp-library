#ifndef RANGE_HPP
#define RANGE_HPP

#include "number_iterator.hpp"
#include <cassert>

template <typename T = int>
class range
{
    T l, r;

  public:
    using iterator         = NumberIterator<T>;
    using forward_iterator = NumberIterator<T>;
    // using reverse_iterator = ReverseNumberIterator<T>;

    range(T l, T r) : l(l), r(r) { assert(r >= l); }
    range(T n) : range(0, n) {}
    iterator begin() { return iterator(l); }
    iterator end() { return iterator(r); }
};

#endif
