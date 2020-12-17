#ifndef CPLIB_BINARY_SEARCH10_HPP
#define CPLIB_BINARY_SEARCH10_HPP

#include <algorithm>
#include <cassert>
#include <iterator>

template <typename InputIt,
          typename UnaryFunction,
          typename T = typename std::iterator_traits<InputIt>::value_type>
InputIt binary_search10(InputIt first, InputIt last, UnaryFunction p)
{
    auto it = std::lower_bound(
        first, last, 0, [p](T x, T val) { return p(x) && (val == val); });
    return (it == first ? last : --it);
}

#endif // CPLIB_BINARY_SEARCH10_HPP
