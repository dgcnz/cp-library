---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Computes the prime factorization of n using smallest primes
    links: []
  bundledCode: "#line 1 \"cplib/math/factorize.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    /*\n * @brief Computes the prime factorization of n using smallest primes\n *\
    \ @tparam Integral type\n * @param sp Smallest Prime vector\n * @param n Number\
    \ to be factorized\n */\ntemplate <typename T>\nvector<pair<T, int>> smallest_prime_factorize(vector<int>\
    \ const &sp, T n)\n{\n    /*\n     * Prime factorization in O(log n) using smallest\
    \ prime array\n     */\n    assert(0 <= n and n < (int)sp.size());\n    vector<pair<T,\
    \ int>> factors;\n    while (n > 1)\n    {\n        int y = sp[n], e = 0;\n  \
    \      while (n % y == 0)\n            e++, n /= y;\n        if (e > 0)\n    \
    \        factors.emplace_back(y, e);\n    }\n    return factors;\n}\n\n/*\n *\
    \ @brief Computes the integer factorization of n.\n * @tparam Integral type\n\
    \ * @param n Number to be factorized\n */\ntemplate <typename T>\nvector<T> factorize(T\
    \ n)\n{\n    vector<T> factors;\n    for (long long x = 1; x * x <= n; ++x)\n\
    \    {\n        if (n % x == 0)\n        {\n            long long y = n / x;\n\
    \            factors.push_back(x);\n            if (x != y)\n                factors.push_back(y);\n\
    \        }\n    }\n    return factors;\n}\n\n/*\n * @brief Computes the prime\
    \ factorization of n using list of primes\n * @tparam Integral type\n * @param\
    \ primes List of primes\n * @param n Number to be factorized\n */\ntemplate <typename\
    \ T>\nvector<pair<T, int>> prime_factorize(vector<int> const &primes, T n)\n{\n\
    \    /*\n     * Prime factorization in O(sqrt n) using array of primes\n     */\n\
    \    vector<pair<T, int>> factors;\n    for (long long p : primes)\n    {\n  \
    \      int e = 0;\n        if (p * p > n)\n            break;\n        while (n\
    \ % p == 0)\n            n /= p, ++e;\n        if (e)\n            factors.emplace_back(p,\
    \ e);\n    }\n    if (n > 1)\n        factors.emplace_back(n, 1);\n    return\
    \ factors;\n}\n\n}; // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_FACTORIZE_HPP\n#define CPLIB_FACTORIZE_HPP\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \n/*\n * @brief Computes the prime factorization of n using smallest primes\n\
    \ * @tparam Integral type\n * @param sp Smallest Prime vector\n * @param n Number\
    \ to be factorized\n */\ntemplate <typename T>\nvector<pair<T, int>> smallest_prime_factorize(vector<int>\
    \ const &sp, T n)\n{\n    /*\n     * Prime factorization in O(log n) using smallest\
    \ prime array\n     */\n    assert(0 <= n and n < (int)sp.size());\n    vector<pair<T,\
    \ int>> factors;\n    while (n > 1)\n    {\n        int y = sp[n], e = 0;\n  \
    \      while (n % y == 0)\n            e++, n /= y;\n        if (e > 0)\n    \
    \        factors.emplace_back(y, e);\n    }\n    return factors;\n}\n\n/*\n *\
    \ @brief Computes the integer factorization of n.\n * @tparam Integral type\n\
    \ * @param n Number to be factorized\n */\ntemplate <typename T>\nvector<T> factorize(T\
    \ n)\n{\n    vector<T> factors;\n    for (long long x = 1; x * x <= n; ++x)\n\
    \    {\n        if (n % x == 0)\n        {\n            long long y = n / x;\n\
    \            factors.push_back(x);\n            if (x != y)\n                factors.push_back(y);\n\
    \        }\n    }\n    return factors;\n}\n\n/*\n * @brief Computes the prime\
    \ factorization of n using list of primes\n * @tparam Integral type\n * @param\
    \ primes List of primes\n * @param n Number to be factorized\n */\ntemplate <typename\
    \ T>\nvector<pair<T, int>> prime_factorize(vector<int> const &primes, T n)\n{\n\
    \    /*\n     * Prime factorization in O(sqrt n) using array of primes\n     */\n\
    \    vector<pair<T, int>> factors;\n    for (long long p : primes)\n    {\n  \
    \      int e = 0;\n        if (p * p > n)\n            break;\n        while (n\
    \ % p == 0)\n            n /= p, ++e;\n        if (e)\n            factors.emplace_back(p,\
    \ e);\n    }\n    if (n > 1)\n        factors.emplace_back(n, 1);\n    return\
    \ factors;\n}\n\n}; // namespace cplib\n\n#endif // CPLIB_FACTORIZE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/factorize.hpp
  requiredBy: []
  timestamp: '2021-12-25 20:18:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/factorize.hpp
layout: document
redirect_from:
- /library/cplib/math/factorize.hpp
- /library/cplib/math/factorize.hpp.html
title: Computes the prime factorization of n using smallest primes
---
