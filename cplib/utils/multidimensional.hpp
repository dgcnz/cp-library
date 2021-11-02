#ifndef CPLIB_MULTIDIMENSIONAL_HPP
#define CPLIB_MULTIDIMENSIONAL_HPP
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

namespace cplib
{

template <typename T, size_t dims>
struct multidimensional_vector
{
    typedef std::vector<typename multidimensional_vector<T, dims - 1>::type>
        type;
};

template <typename T>
struct multidimensional_vector<T, 0>
{
    typedef T type;
};

template <class... Args>
auto create_multidimensional(size_t n, Args &&...args)
{
    if constexpr (sizeof...(args) == 1)
        return std::vector(n, args...);
    else
        return std::vector(n, create_multidimensional(args...));
}

template <typename T, size_t N, class... Args>
void resize(typename multidimensional_vector<T, N>::type &v,
            size_t                                        n,
            Args &&...args)
{
    v.resize(n);
    if constexpr (sizeof...(args) > 0)
        for (auto &x : v)
            resize<T, N - 1>(x, args...);
}

template <typename T, size_t N, class... Args>
void assign(typename multidimensional_vector<T, N>::type &v,
            T                                             val,
            size_t                                        n,
            Args &&...args)
{
    if constexpr (sizeof...(args) > 0)
    {
        v.resize(n);
        for (auto &x : v)
            assign<T, N - 1>(x, val, args...);
    }
    else
        v.assign(n, val);
}

template <typename T, size_t N, typename InputIterator>
void fill(InputIterator first, InputIterator last, T val)
{
    if constexpr (N > 1)
        for (; first != last; ++first)
            fill<T, N - 1>(begin(*first), end(*first), val);
    else
        fill(first, last, val);
}

template <size_t N, typename InputIterator, typename UnaryFunction>
void for_each(InputIterator first, InputIterator last, UnaryFunction f)
{
    if constexpr (N > 1)
        for (; first != last; ++first)
            for_each<N - 1>(std::begin(*first), std::end(*first), f);
    else
        std::for_each(first, last, f);
}

template <size_t N,
          typename InputIterator,
          typename T,
          typename BinaryOperation>
T accumulate(InputIterator   first,
             InputIterator   last,
             T               init,
             BinaryOperation op)
{
    if constexpr (N > 1)
        for (; first != last; ++first)
            init = accumulate<N - 1>(
                std::begin(*first), std::end(*first), init, op);
    else
        init = std::accumulate(first, last, init, op);
    return init;
}
} // namespace cplib

#endif // CPLIB_MULTIDIMENSIONAL_HPP
