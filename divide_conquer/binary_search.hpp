#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>

template <typename InputIt,
          typename UnaryFunction,
          typename T = typename std::iterator_traits<InputIt>::value_type>
InputIt binary_search01(InputIt first, InputIt last, UnaryFunction p)
{
    return lower_bound(
        first, last, 0, [p](T x, T val) { return !p(x) && (val == val); });
}

template <typename InputIt,
          typename UnaryFunction,
          typename T = typename std::iterator_traits<InputIt>::value_type>
InputIt binary_search10(InputIt first, InputIt last, UnaryFunction p)
{
    auto it = lower_bound(
        first, last, 0, [p](T x, T val) { return p(x) && (val == val); });
    return (it == first ? last : --it);
}

template <typename T>
T binary_search(T lo, T hi, std::function<bool(T)> p)
{
    assert(lo <= hi);
    while (lo < hi)
    {
        T mid = lo + (hi - lo) / 2;
        if (p(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (p(lo) == false)
        return -1; // p(x) is false for all x
    return lo;
}

#endif
