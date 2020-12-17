#ifndef REV_RANGE_HPP
#define REV_RANGE_HPP

#include "reverse_number_iterator.hpp"
#include <cassert>

template <typename T = int>
class rev_range
{
    T l, r;

  public:
    using iterator         = ReverseNumberIterator<T>;
    using forward_iterator = ReverseNumberIterator<T>;
    // using reverse_iterator = NumberIterator<T>;

    rev_range(T l, T r) : l(l), r(r) { assert(l >= r); }
    iterator begin() { return iterator(l); }
    iterator end() { return iterator(r); }
};

#endif
