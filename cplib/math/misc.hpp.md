---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Computes the exponent of the largest power of a prime p that divides
    links: []
  bundledCode: "#line 1 \"cplib/math/misc.hpp\"\n\n\n#include <cassert>\n#include\
    \ <cstdio>\n#include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ cplib\n{\nusing namespace std;\n/*\n * @brief Computes the exponent of the largest\
    \ power of a prime p that divides\n * the factorial n!\n * @param n number\n *\
    \ @param p prime\n */\nlong long legendre_formula(long long n, long long p)\n\
    {\n    long long e = 0;\n    while (n)\n    {\n        e += n / p;\n        n\
    \ /= p;\n    }\n    return e;\n}\n\n/*\n * @brief Tests if a positive number is\
    \ a power of two.\n * @param n non-negative number\n */\ninline bool is_power_two(long\
    \ long n)\n{\n    return n <= 0 ? 0 : (n & (n - 1)) == 0;\n}\n\n/*\n * @brief\
    \ Computes the exponent of the largest power of two that divides n.\n * @param\
    \ n number\n */\ninline int largest_power_two_exp(long long n) { return __builtin_ctzll(n);\
    \ }\n\n/*\n * @brief Counts how many numbers in [0, n] have a reminder of r modulo\
    \ m.\n * @param n end of range\n * @param m modulo\n * @param r remainder\n */\n\
    long long prefix_remainder_count(long long n, long long m, long long r)\n{\n \
    \   assert(0LL <= n and r < m);\n    return (n + m - r - 1) / m;\n}\n\n/*\n *\
    \ @brief Counts how many numbers in [min, max] have a reminder of r modulo m.\n\
    \ * @param min start of range\n * @param max end of range\n * @param m modulo\n\
    \ * @param r remainder\n */\nlong long\nrange_remainder_count(long long min, long\
    \ long max, long long m, long long r)\n{\n    assert(min >= 0LL and min <= max);\n\
    \    return prefix_remainder_count(max + 1, m, r) -\n           prefix_remainder_count(min,\
    \ m, r);\n}\n\n/*\n * @brief Counts how many numbers in [0, n] have the k-th bit\
    \ set.\n * @param n range end\n * @param k index of bit\n */\nlong long prefix_set_bit_count(long\
    \ long n, int k)\n{\n    assert(0LL <= n);\n    n += 1;\n    long long ans = (n\
    \ >> (k + 1)) << k;\n    if ((n >> k) & 1)\n        ans += n & ((1LL << k) - 1);\n\
    \    return ans;\n}\n\n/*\n * @brief Computes the greatest common divisor of a\
    \ and b and finds the\n * solutions (x, y) of the equation: a * x + b * y = gcd(a,\
    \ b)\n * @param a Number\n * @param b Number\n * @param x Solution to a\n * @param\
    \ y Solution to b\n */\ntemplate <typename T>\nT extended_gcd(T a, T b, T &x,\
    \ T &y)\n{\n    x = 1, y = 0;\n    T x1 = 0, y1 = 1, a1 = a, b1 = b;\n    while\
    \ (b1)\n    {\n        T q         = a1 / b1;\n        tie(x, x1)  = make_tuple(x1,\
    \ x - q * x1);\n        tie(y, y1)  = make_tuple(y1, y - q * y1);\n        tie(a1,\
    \ b1) = make_tuple(b1, a1 - q * b1);\n    }\n    return a1;\n}\n\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_MATH_UTILS_HPP\n#define CPLIB_MATH_UTILS_HPP\n#include <cassert>\n\
    #include <cstdio>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    namespace cplib\n{\nusing namespace std;\n/*\n * @brief Computes the exponent\
    \ of the largest power of a prime p that divides\n * the factorial n!\n * @param\
    \ n number\n * @param p prime\n */\nlong long legendre_formula(long long n, long\
    \ long p)\n{\n    long long e = 0;\n    while (n)\n    {\n        e += n / p;\n\
    \        n /= p;\n    }\n    return e;\n}\n\n/*\n * @brief Tests if a positive\
    \ number is a power of two.\n * @param n non-negative number\n */\ninline bool\
    \ is_power_two(long long n)\n{\n    return n <= 0 ? 0 : (n & (n - 1)) == 0;\n\
    }\n\n/*\n * @brief Computes the exponent of the largest power of two that divides\
    \ n.\n * @param n number\n */\ninline int largest_power_two_exp(long long n) {\
    \ return __builtin_ctzll(n); }\n\n/*\n * @brief Counts how many numbers in [0,\
    \ n] have a reminder of r modulo m.\n * @param n end of range\n * @param m modulo\n\
    \ * @param r remainder\n */\nlong long prefix_remainder_count(long long n, long\
    \ long m, long long r)\n{\n    assert(0LL <= n and r < m);\n    return (n + m\
    \ - r - 1) / m;\n}\n\n/*\n * @brief Counts how many numbers in [min, max] have\
    \ a reminder of r modulo m.\n * @param min start of range\n * @param max end of\
    \ range\n * @param m modulo\n * @param r remainder\n */\nlong long\nrange_remainder_count(long\
    \ long min, long long max, long long m, long long r)\n{\n    assert(min >= 0LL\
    \ and min <= max);\n    return prefix_remainder_count(max + 1, m, r) -\n     \
    \      prefix_remainder_count(min, m, r);\n}\n\n/*\n * @brief Counts how many\
    \ numbers in [0, n] have the k-th bit set.\n * @param n range end\n * @param k\
    \ index of bit\n */\nlong long prefix_set_bit_count(long long n, int k)\n{\n \
    \   assert(0LL <= n);\n    n += 1;\n    long long ans = (n >> (k + 1)) << k;\n\
    \    if ((n >> k) & 1)\n        ans += n & ((1LL << k) - 1);\n    return ans;\n\
    }\n\n/*\n * @brief Computes the greatest common divisor of a and b and finds the\n\
    \ * solutions (x, y) of the equation: a * x + b * y = gcd(a, b)\n * @param a Number\n\
    \ * @param b Number\n * @param x Solution to a\n * @param y Solution to b\n */\n\
    template <typename T>\nT extended_gcd(T a, T b, T &x, T &y)\n{\n    x = 1, y =\
    \ 0;\n    T x1 = 0, y1 = 1, a1 = a, b1 = b;\n    while (b1)\n    {\n        T\
    \ q         = a1 / b1;\n        tie(x, x1)  = make_tuple(x1, x - q * x1);\n  \
    \      tie(y, y1)  = make_tuple(y1, y - q * y1);\n        tie(a1, b1) = make_tuple(b1,\
    \ a1 - q * b1);\n    }\n    return a1;\n}\n\n} // namespace cplib\n\n#endif //\
    \ CPLIB_MATH_UTILS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/misc.hpp
  requiredBy: []
  timestamp: '2021-12-25 20:18:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/misc.hpp
layout: document
title: Miscelaneous Math Functions
---

# Miscelaneous Math Functions


