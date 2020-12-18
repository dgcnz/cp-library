#ifndef CPLIB_REV_RANGE_HPP
#define CPLIB_REV_RANGE_HPP

#include <cassert>
#include <cplib/utils/reverse_number_iterator.hpp>

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

#endif // CPLIB_REV_RANGE_HPP
