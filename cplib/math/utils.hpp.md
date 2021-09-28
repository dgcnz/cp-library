---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/math/utils.hpp\"\n\n\n#include <cstdio>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\nlong\
    \ long legendre_formula(long long n, long long p)\n{\n    /*\n     * Returns the\
    \ exponent of the largest power of a prime p that divides the\n     * factorial\
    \ n!\n     */\n    long long e = 0;\n    while (n)\n    {\n        e += n / p;\n\
    \        n /= p;\n    }\n    return e;\n}\n\nbool is_power_two(long long n) {\
    \ return n == 0 ? 0 : (n & (n - 1)) == 0; }\n\ninline int max_power_two_exp(long\
    \ long n) { return __builtin_ctzll(n); }\n\ntemplate <class T>\nT prefix_remainder_count(T\
    \ n, T m, T r)\n{\n    assert(0 <= n and r < m);\n    return (n + m - r - 1) /\
    \ m;\n}\n\ntemplate <class T>\nT range_remainder_count(T min, T max, T m, T r)\n\
    {\n    assert(min >= 0 and min <= max);\n    return prefix_remainder_count(max\
    \ + 1, m, r) -\n           prefix_remainder_count(min, m, r);\n}\n\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_MATH_UTILS_HPP\n#define CPLIB_MATH_UTILS_HPP\n#include <cstdio>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    long long legendre_formula(long long n, long long p)\n{\n    /*\n     * Returns\
    \ the exponent of the largest power of a prime p that divides the\n     * factorial\
    \ n!\n     */\n    long long e = 0;\n    while (n)\n    {\n        e += n / p;\n\
    \        n /= p;\n    }\n    return e;\n}\n\nbool is_power_two(long long n) {\
    \ return n == 0 ? 0 : (n & (n - 1)) == 0; }\n\ninline int max_power_two_exp(long\
    \ long n) { return __builtin_ctzll(n); }\n\ntemplate <class T>\nT prefix_remainder_count(T\
    \ n, T m, T r)\n{\n    assert(0 <= n and r < m);\n    return (n + m - r - 1) /\
    \ m;\n}\n\ntemplate <class T>\nT range_remainder_count(T min, T max, T m, T r)\n\
    {\n    assert(min >= 0 and min <= max);\n    return prefix_remainder_count(max\
    \ + 1, m, r) -\n           prefix_remainder_count(min, m, r);\n}\n\n} // namespace\
    \ cplib\n\n#endif // CPLIB_MATH_UTILS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/utils.hpp
  requiredBy: []
  timestamp: '2021-09-28 10:47:46-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/utils.hpp
layout: document
redirect_from:
- /library/cplib/math/utils.hpp
- /library/cplib/math/utils.hpp.html
title: cplib/math/utils.hpp
---
