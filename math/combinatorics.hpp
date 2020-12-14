#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include "modint.hpp"
#include <cassert>
#include <vector>

template <int MOD>
std::vector<ModInt<MOD>> factorials(int len)
{
    assert(len > 0);
    std::vector<ModInt<MOD>> ans(len);
    ans[0] = 1;
    for (int i = 1; i < len; i++)
        ans[i] = ans[i - 1] * i;
    return ans;
}

template <int MOD>
std::vector<ModInt<MOD>> inverse_factorials(int len)
{
    using mint = ModInt<MOD>;
    assert(len > 0);

    mint::precompute_inverses(len);
    std::vector<mint> inv_fact(len);

    inv_fact[0] = 1;
    for (int i = 1; i < len; i++)
        inv_fact[i] = inv_fact[i - 1] * mint::inverse(i);
    return inv_fact;
}

template <int NMAX, int MOD>
struct Combinations
{
    using mint = ModInt<MOD>;
    std::vector<mint> fact, inv_fact;

    Combinations(void)
    {
        fact     = factorials<MOD>(NMAX + 1);
        inv_fact = inverse_factorials<MOD>(NMAX + 1);
    }

    mint C(int n, int k) const
    {
        assert(n < NMAX);
        if (k > n or k < 0)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    mint factorial(int n)
    {
        assert(fact.size() > n);
        return fact[n];
    }

    mint inverse_factorial(int n)
    {
        assert(inv_fact.size() > n);
        return inv_fact[n];
    }
};

#endif
