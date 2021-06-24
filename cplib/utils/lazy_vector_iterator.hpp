#ifndef CPLIB_LAZY_VECTOR_ITERATOR_HPP
#define CPLIB_LAZY_VECTOR_ITERATOR_HPP
#include <cplib/utils/lazy_vector.hpp>
#include <exception>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace cplib
{
using namespace std;

template <class S, typename T>
struct lazy_vector;

template <class S, typename T>
struct lazy_vector_iterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T *;
    using reference         = T &;

    lazy_vector<S, T> &v;
    int                ix;
    bool               is_end;
    lazy_vector_iterator(lazy_vector<S, T> &v, int ix, bool is_end)
        : v(v), ix(ix), is_end(is_end)
    {
    }

    T operator*() { return v[ix]; }

    lazy_vector_iterator &operator++()
    {
        v.cache_next();
        ++ix;
        if (ix >= (int)v.cached_size())
            is_end = true;
        return *this;
    }
    inline bool operator==(lazy_vector_iterator const &other) const
    {
        if (is_end or other.is_end)
            return is_end == other.is_end;
        return ix == other.ix;
    }
    inline bool operator!=(lazy_vector_iterator const &other) const
    {
        return !(operator==(other));
    }
};
} // namespace cplib

#endif // CPLIB_LAZY_VECTOR_ITERATOR_HPP
