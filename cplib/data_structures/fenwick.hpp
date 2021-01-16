#ifndef CPLIB_FENWICK_HPP
#define CPLIB_FENWICK_HPP
#include <iterator>
#include <vector>

template <typename T>
struct FenwickTree
{
    int            n;
    std::vector<T> bit;

    FenwickTree(int n) : n(n + 1) { bit.assign(n + 1, 0); }

    template <typename InputIt>
    FenwickTree(InputIt first, InputIt last)
        : FenwickTree(distance(first, last) + 1)
    {
        for (int i = 0; first != last; ++first, ++i)
            add(i, first);
    }

    T sum(int i)
    {
        T ret = 0;
        for (++i; i > 0; i -= i & -i)
            ret += bit[i];
        return ret;
    }

    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int i, T delta)
    {
        for (++i; i < n; i += i & -i)
            bit[i] += delta;
    }
};

#endif // CPLIB_FENWICK_HPP
