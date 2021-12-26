#ifndef CPLIB_FACTORIZE_HPP
#define CPLIB_FACTORIZE_HPP

#include <cassert>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

/*
 * @brief Computes the prime factorization of n using smallest primes
 * @tparam Integral type
 * @param sp Smallest Prime vector
 * @param n Number to be factorized
 */
template <typename T>
vector<pair<T, int>> smallest_prime_factorize(vector<int> const &sp, T n)
{
    /*
     * Prime factorization in O(log n) using smallest prime array
     */
    assert(0 <= n and n < (int)sp.size());
    vector<pair<T, int>> factors;
    while (n > 1)
    {
        int y = sp[n], e = 0;
        while (n % y == 0)
            e++, n /= y;
        if (e > 0)
            factors.emplace_back(y, e);
    }
    return factors;
}

/*
 * @brief Computes the integer factorization of n.
 * @tparam Integral type
 * @param n Number to be factorized
 */
template <typename T>
vector<T> factorize(T n)
{
    vector<T> factors;
    for (long long x = 1; x * x <= n; ++x)
    {
        if (n % x == 0)
        {
            long long y = n / x;
            factors.push_back(x);
            if (x != y)
                factors.push_back(y);
        }
    }
    return factors;
}

/*
 * @brief Computes the prime factorization of n using list of primes
 * @tparam Integral type
 * @param primes List of primes
 * @param n Number to be factorized
 */
template <typename T>
vector<pair<T, int>> prime_factorize(vector<int> const &primes, T n)
{
    /*
     * Prime factorization in O(sqrt n) using array of primes
     */
    vector<pair<T, int>> factors;
    for (long long p : primes)
    {
        int e = 0;
        if (p * p > n)
            break;
        while (n % p == 0)
            n /= p, ++e;
        if (e)
            factors.emplace_back(p, e);
    }
    if (n > 1)
        factors.emplace_back(n, 1);
    return factors;
}

}; // namespace cplib

#endif // CPLIB_FACTORIZE_HPP
