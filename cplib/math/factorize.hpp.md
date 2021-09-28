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
  bundledCode: "#line 1 \"cplib/math/factorize.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    namespace smallest_prime\n{\nvector<pair<int, int>> factorize(vector<int> const\
    \ &sp, int x)\n{\n    /*\n     * Prime factorization in O(log n) using smallest\
    \ prime array\n     */\n    assert(0 <= x and x < (int)sp.size());\n    vector<pair<int,\
    \ int>> factors;\n    while (x > 1)\n    {\n        int y = sp[x], e = 0;\n  \
    \      while (x % y == 0)\n            e++, x /= y;\n        if (e > 0)\n    \
    \        factors.emplace_back(y, e);\n    }\n    return factors;\n}\n} // namespace\
    \ smallest_prime\n\nnamespace prime\n{\nvector<pair<long long, int>> factorize(vector<int>\
    \ const &primes, long long n)\n{\n    /*\n     * Prime factorization in O(sqrt\
    \ n) using array of primes\n     */\n    vector<pair<long long, int>> factors;\n\
    \    for (long long p : primes)\n    {\n        int e = 0;\n        if (p * p\
    \ > n)\n            break;\n        while (n % p == 0)\n            n /= p, ++e;\n\
    \        if (e)\n            factors.emplace_back(p, e);\n    }\n    if (n > 1)\n\
    \        factors.emplace_back(n, 1);\n    return factors;\n}\n} // namespace prime\n\
    \n}; // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_FACTORIZE_HPP\n#define CPLIB_FACTORIZE_HPP\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \nnamespace smallest_prime\n{\nvector<pair<int, int>> factorize(vector<int> const\
    \ &sp, int x)\n{\n    /*\n     * Prime factorization in O(log n) using smallest\
    \ prime array\n     */\n    assert(0 <= x and x < (int)sp.size());\n    vector<pair<int,\
    \ int>> factors;\n    while (x > 1)\n    {\n        int y = sp[x], e = 0;\n  \
    \      while (x % y == 0)\n            e++, x /= y;\n        if (e > 0)\n    \
    \        factors.emplace_back(y, e);\n    }\n    return factors;\n}\n} // namespace\
    \ smallest_prime\n\nnamespace prime\n{\nvector<pair<long long, int>> factorize(vector<int>\
    \ const &primes, long long n)\n{\n    /*\n     * Prime factorization in O(sqrt\
    \ n) using array of primes\n     */\n    vector<pair<long long, int>> factors;\n\
    \    for (long long p : primes)\n    {\n        int e = 0;\n        if (p * p\
    \ > n)\n            break;\n        while (n % p == 0)\n            n /= p, ++e;\n\
    \        if (e)\n            factors.emplace_back(p, e);\n    }\n    if (n > 1)\n\
    \        factors.emplace_back(n, 1);\n    return factors;\n}\n} // namespace prime\n\
    \n}; // namespace cplib\n\n#endif // CPLIB_FACTORIZE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/factorize.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/factorize.hpp
layout: document
redirect_from:
- /library/cplib/math/factorize.hpp
- /library/cplib/math/factorize.hpp.html
title: cplib/math/factorize.hpp
---
