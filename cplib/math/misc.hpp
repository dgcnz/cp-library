#ifndef CPLIB_MATH_UTILS_HPP
#define CPLIB_MATH_UTILS_HPP
#include <cassert>
#include <cstdio>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;
/*
 * @brief Computes the exponent of the largest power of a prime p that divides
 * the factorial n!
 * @param n number
 * @param p prime
 */
long long legendre_formula(long long n, long long p)
{
    long long e = 0;
    while (n)
    {
        e += n / p;
        n /= p;
    }
    return e;
}

/*
 * @brief Tests if a positive number is a power of two.
 * @param n non-negative number
 */
inline bool is_power_two(long long n)
{
    return n <= 0 ? 0 : (n & (n - 1)) == 0;
}

/*
 * @brief Computes the exponent of the largest power of two that divides n.
 * @param n number
 */
inline int largest_power_two_exp(long long n) { return __builtin_ctzll(n); }

/*
 * @brief Counts how many numbers in [0, n] have a reminder of r modulo m.
 * @param n end of range
 * @param m modulo
 * @param r remainder
 */
long long prefix_remainder_count(long long n, long long m, long long r)
{
    assert(0LL <= n and r < m);
    return (n + m - r - 1) / m;
}

/*
 * @brief Counts how many numbers in [min, max] have a reminder of r modulo m.
 * @param min start of range
 * @param max end of range
 * @param m modulo
 * @param r remainder
 */
long long
range_remainder_count(long long min, long long max, long long m, long long r)
{
    assert(min >= 0LL and min <= max);
    return prefix_remainder_count(max + 1, m, r) -
           prefix_remainder_count(min, m, r);
}

/*
 * @brief Counts how many numbers in [0, n] have the k-th bit set.
 * @param n range end
 * @param k index of bit
 */
long long prefix_set_bit_count(long long n, int k)
{
    assert(0LL <= n);
    n += 1;
    long long ans = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        ans += n & ((1LL << k) - 1);
    return ans;
}

/*
 * @brief Computes the greatest common divisor of a and b and finds the
 * solutions (x, y) of the equation: a * x + b * y = gcd(a, b)
 * @param a Number
 * @param b Number
 * @param x Solution to a
 * @param y Solution to b
 */
template <typename T>
T extended_gcd(T a, T b, T &x, T &y)
{
    x = 1, y = 0;
    T x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        T q         = a1 / b1;
        tie(x, x1)  = make_tuple(x1, x - q * x1);
        tie(y, y1)  = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

} // namespace cplib

#endif // CPLIB_MATH_UTILS_HPP
