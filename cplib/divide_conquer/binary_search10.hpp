#ifndef CPLIB_BINARY_SEARCH10_HPP
#define CPLIB_BINARY_SEARCH10_HPP

#include <algorithm>
#include <cassert>
#include <iterator>

namespace cplib
{
using namespace std;
template <typename InputIt,
          typename UnaryFunction,
          typename T = typename iterator_traits<InputIt>::value_type>
InputIt binary_search10(InputIt first, InputIt last, UnaryFunction p)
{
    auto it = lower_bound(
        first, last, T(), [p](T x, [[maybe_unused]] T val) { return p(x); });
    return (it == first ? last : --it);
}
} // namespace cplib

#endif // CPLIB_BINARY_SEARCH10_HPP
