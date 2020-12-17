#ifndef CPLIB_BINARY_SEARCH01_HPP
#define CPLIB_BINARY_SEARCH01_HPP

#include <algorithm>
#include <cassert>
#include <iterator>

template <typename InputIt,
          typename UnaryFunction,
          typename T = typename std::iterator_traits<InputIt>::value_type>
InputIt binary_search01(InputIt first, InputIt last, UnaryFunction p)
{
    return std::lower_bound(
        first, last, 0, [p](T x, T val) { return !p(x) && (val == val); });
}

#endif // CPLIB_BINARY_SEARCH01_HPP
