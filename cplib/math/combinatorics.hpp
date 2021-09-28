#ifndef CPLIB_COMBINATORICS_HPP
#define CPLIB_COMBINATORICS_HPP

#include <cassert>
#include <vector>

namespace cplib
{
using namespace std;

template <typename MOD_T>
struct Combinatorics
{
    vector<MOD_T> fact, inv_fact;

    Combinatorics(int n)
    {
        assert(0 <= n and n <= 1e8);
        precompute(n);
    }

    void precompute(int n)
    {
        if (n <= (int)fact.size())
            return;

        fact.resize(n), inv_fact.resize(n);
        inv_fact[0] = fact[0] = 1;
        for (int i = 1; i < n; i++)
        {
            inv_fact[i] = inv_fact[i - 1] / i;
            fact[i]     = fact[i - 1] * i;
        }
    }

    MOD_T C(int n, int k) const
    {
        assert(int(fact.size()) > n);
        if (k > n or k < 0)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    MOD_T factorial(int n)
    {
        assert(int(fact.size()) > n);
        return fact[n];
    }

    MOD_T inverse_factorial(int n)
    {
        assert(int(fact.size()) > n);
        return inv_fact[n];
    }
    MOD_T operator()(int n, int k) const { return C(n, k); }
};
} // namespace cplib

#endif // CPLIB_COMBINATORICS_HPP
