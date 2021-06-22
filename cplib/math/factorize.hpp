#ifndef CPLIB_FACTORIZE_HPP
#define CPLIB_FACTORIZE_HPP

#include <cassert>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

namespace smallest_prime
{
vector<pair<int, int>> factorize(vector<int> const &sp, int x)
{
    /*
     * Prime factorization in O(log n) using smallest prime array
     */
    assert(0 <= x and x < (int)sp.size());
    vector<pair<int, int>> factors;
    while (x > 1)
    {
        int y = sp[x], e = 0;
        while (x % y == 0)
            e++, x /= y;
        if (e > 0)
            factors.emplace_back(y, e);
    }
    return factors;
}
} // namespace smallest_prime

namespace prime
{
vector<pair<long long, int>> factorize(vector<int> const &primes, long long n)
{
    /*
     * Prime factorization in O(sqrt n) using array of primes
     */
    vector<pair<long long, int>> factors;
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
} // namespace prime

}; // namespace cplib

#endif // CPLIB_FACTORIZE_HPP
