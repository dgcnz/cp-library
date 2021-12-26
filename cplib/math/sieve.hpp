#ifndef CPLIB_SIEVE_HPP
#define CPLIB_SIEVE_HPP

#include <bitset>
#include <cassert>
#include <vector>

namespace cplib
{
using namespace std;

/*
 * @brief Computes the primality of integers in [0, SIZE - 1].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct IsPrimeSieve
{
    bitset<SIZE> is_prime;

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

    vector<int> primes() const
    {
        vector<int> p;
        for (int i = 2; i < SIZE; ++i)
            if (is_prime[i])
                p.push_back(i);
        return p;
    }
};

/*
 * @brief Computes the smallest prime divisor of integers in [0, SIZE - 1].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct SmallestPrimeSieve
{
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
    vector<int> primes() const
    {
        vector<int> p;
        for (int x = 2; x < SIZE; ++x)
            if (sp[x] == x)
                p.push_back(x);
        return p;
    }
};

/*
 * @brief Computes the largest prime divisor of integers in [0, SIZE - 1].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct LargestPrimeSieve
{
    vector<int> lp;
    LargestPrimeSieve() : lp(SIZE)
    {
        lp[0] = lp[1] = 1;
        for (int i = 1; i < SIZE; ++i)
            if (lp[i] == 1)
                for (int j = i; j < SIZE; j += i)
                    lp[j] = i;
    }
    vector<int> primes() const
    {
        vector<int> p;
        for (int x = 2; x < SIZE; ++x)
            if (lp[x] == x)
                p.push_back(x);
        return p;
    }
};

/*
 * @brief Computes the number of divisors of integers in [0, SIZE - 1].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct DivisorCountSieve
{
    vector<int> cnt;
    DivisorCountSieve() : cnt(SIZE, 0)
    {
        for (int i = 1; i < SIZE; i++)
            for (int j = i; j < SIZE; j += i)
                cnt[j]++;
    }
};

/*
 * @brief Computes the Euler phi function for integers in [0, SIZE - 1]. phi[n]
 * is the count of positive numbers coprime to n in [1, n].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct EulerTotientSieve
{
    vector<int> phi;
    EulerTotientSieve() : phi(SIZE, 0)
    {
        phi[0] = 0;
        phi[1] = 1;
        for (int i = 2; i < SIZE; i++)
            phi[i] = i;

        for (int i = 2; i < SIZE; i++)
        {
            if (phi[i] == i)
                for (int j = i; j < SIZE; j += i)
                    phi[j] -= phi[j] / i;
        }
    }
};

/*
 * @brief Computes the sum of positive divisors for integers in [0, SIZE - 1].
 * @tparam SIZE Size of sieve.
 */
template <int SIZE>
struct SumDivisorSieve
{
    vector<long long> sd;
    SumDivisorSieve() : sd(SIZE, 0)
    {
        for (int i = 1; i < SIZE; ++i)
            for (int j = i; j < SIZE; j += i)
                sd[j] += i;
    }
};

} // namespace cplib

#endif // CPLIB_SIEVE_HPP
