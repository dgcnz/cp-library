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

} // namespace cplib

#endif // CPLIB_MATH_UTILS_HPP
