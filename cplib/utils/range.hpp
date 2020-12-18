#ifndef CPLIB_RANGE_HPP
#define CPLIB_RANGE_HPP

#include <cassert>
#include <cplib/utils/number_iterator.hpp>

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

#endif // CPLIB_RANGE_HPP
