#ifndef CPLIB_BINARY_SEARCH01_HPP
#define CPLIB_BINARY_SEARCH01_HPP

#include <algorithm>
#include <cassert>
#include <iterator>

namespace cplib
{
using namespace std;
template <typename InputIt,
          typename UnaryFunction,
          typename T = typename iterator_traits<InputIt>::value_type>
InputIt binary_search01(InputIt first, InputIt last, UnaryFunction p)
{
    return lower_bound(
        first, last, T(), [&p](T x, [[maybe_unused]] T val) { return !p(x); });
}
} // namespace cplib

#endif // CPLIB_BINARY_SEARCH01_HPP
