#ifndef CPLIB_COMBINATORICS_HPP
#define CPLIB_COMBINATORICS_HPP

#include <atcoder/modint>
#include <cassert>
#include <vector>

template <int NMAX, typename mint>
struct Combinations
{
    std::vector<mint> fact, inv_fact;

    Combinations(void) { precompute(NMAX + 1); }

    void precompute(int len)
    {
        fact.resize(len), inv_fact.resize(len);
        inv_fact[0] = fact[0] = 1;
        for (int i = 1; i < len; i++)
        {
            inv_fact[i] = inv_fact[i - 1] * mint(i).inv();
            fact[i]     = fact[i - 1] * i;
        }
    }

    mint C(int n, int k) const
    {
        assert(int(fact.size()) > n);
        if (k > n or k < 0)
            return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    mint factorial(int n)
    {
        assert(int(fact.size()) > n);
        return fact[n];
    }

    mint inverse_factorial(int n)
    {
        assert(int(fact.size()) > n);
        return inv_fact[n];
    }
    mint operator()(int n, int k) const { return C(n, k); }
};

#endif // CPLIB_COMBINATORICS_HPP
