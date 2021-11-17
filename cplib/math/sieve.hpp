#ifndef CPLIB_SIEVE_HPP
#define CPLIB_SIEVE_HPP

#include <bitset>
#include <cassert>
#include <vector>

namespace cplib
{
using namespace std;

template <int SIZE>
struct IsPrimeSieve
{
    static_assert(0 <= SIZE and SIZE < 1e8, "0 <= SIZE < 1e8");
    bitset<SIZE> is_prime;
    vector<int>  primes;

    IsPrimeSieve()
    {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < SIZE; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i < SIZE; i += 2)
            if (is_prime[i])
                for (int j = i * i; j < SIZE; j += i * 2)
                    is_prime[j] = 0;
    }

    vector<int> get_primes() const
    {
        vector<int> p;
        for (int i = 2; i < SIZE; ++i)
            if (is_prime[i])
                p.push_back(i);
        return p;
    }
};

template <int SIZE>
struct SmallestPrimeSieve
{
    static_assert(1 <= SIZE and SIZE < 2e7, "1 <= SIZE < 2e7");
    vector<int> sp, v;
    SmallestPrimeSieve() : sp(SIZE, 1), v(SIZE, false)
    {
        for (int i = 2; i < SIZE; i += 2)
            sp[i] = 2;
        for (int i = 3; i < SIZE; i += 2)
        {
            if (!v[i])
            {
                sp[i] = i;
                for (long long j = i; (j * i) < SIZE; j += 2)
                    if (!v[j * i])
                        v[j * i] = true, sp[j * i] = i;
            }
        }
    }
    vector<int> get_primes() const
    {
        vector<int> p;
        for (int x = 2; x < SIZE; ++x)
            if (sp[x] == x)
                p.push_back(x);
        return p;
    }
};

template <int SIZE>
struct LargestPrimeSieve
{
    static_assert(1 <= SIZE and SIZE < 2e7, "1 <= SIZE < 2e7");
    vector<int> lp;
    LargestPrimeSieve() : lp(SIZE)
    {
        lp[0] = lp[1] = 1;
        for (int i = 1; i < SIZE; ++i)
            if (lp[i] == 1)
                for (int j = i; j < SIZE; j += i)
                    lp[j] = i;
    }
    vector<int> get_primes() const
    {
        vector<int> p;
        for (int x = 2; x < SIZE; ++x)
            if (lp[x] == x)
                p.push_back(x);
        return p;
    }
};

template <int SIZE>
struct DivisorCountSieve
{
    static_assert(1 <= SIZE and SIZE < 2e7, "1 <= SIZE < 2e7");
    vector<int> cnt;
    DivisorCountSieve() : cnt(SIZE, 0)
    {
        for (int i = 1; i <= SIZE; i++)
            for (int j = i; j < SIZE; j += i)
                cnt[j]++;
    }
};

} // namespace cplib

#endif // CPLIB_SIEVE_HPP
