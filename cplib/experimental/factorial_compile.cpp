//  #include "modint.hpp"
#include <iostream>

template <int N, int MOD>
struct Factorial
{
    constexpr Factorial() : fact()
    {
        fact[0] = 1;
        for (auto i = 1; i <= N; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
    }
    long long fact[N + 1];
};

int main()
{
    int const      NMAX = 1e5;
    int const      MOD  = 1e9 + 7;
    constexpr auto f    = Factorial<NMAX, MOD>();
    for (auto x : f.fact)
        std::cout << x << '\n';
}
