#ifndef CPLIB_MATH_UTILS_HPP
#define CPLIB_MATH_UTILS_HPP
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;
long long legendre_formula(long long n, long long p)
{
    /*
     * Returns the exponent of the largest power of a prime p that divides the
     * factorial n!
     */
    long long e = 0;
    while (n)
    {
        e += n / p;
        n /= p;
    }
    return e;
}

bool is_power_two(long long n)
{
    if (n == 0)
        return false;
    return (n & (n - 1)) == 0;
}

template <class T>
T prefix_remainder_count(T n, T m, T r)
{
    assert(0 <= n and r < m);
    return (n + m - r - 1) / m;
}

template <class T>
T range_remainder_count(T min, T max, T m, T r)
{
    assert(min >= 0 and min <= max);
    return prefix_remainder_count(max + 1, m, r) -
           prefix_remainder_count(min, m, r);
}

} // namespace cplib

#endif // CPLIB_MATH_UTILS_HPP
