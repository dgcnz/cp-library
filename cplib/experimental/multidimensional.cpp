#include <algorithm>
#include <array>
#include <dbg.h>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

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
auto create(size_t n, Args &&...args)
{
    if constexpr (sizeof...(args) == 1)
        return std::vector(n, args...);
    else
        return std::vector(n, create(args...));
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

int main(void)
{
    using namespace std;
    multidimensional_vector<int, 2>::type v;

    resize<int, 2>(v, 3, 2);
    fill<int, 2>(begin(v), end(v), 3);
    // or instead: assign<int, 2>(v, 3, 3, 2)

    // Results in 3 x 2 vector filled with 3's:
    // 3 3
    // 3 3
    // 3 3

    for_each<2>(begin(v), end(v), [](int x) { cout << x << " "; }),
        cout << endl;
    // 3 3 3 3 3 3

    cout << accumulate<2>(begin(v), end(v), 0, plus<int>()) << endl;
    // 6

    return 0;
}
