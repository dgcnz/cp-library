---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Computes the primality of integers in [0, SIZE - 1].
    links: []
  bundledCode: "#line 1 \"cplib/math/sieve.hpp\"\n\n\n\n#include <bitset>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    /*\n * @brief Computes the primality of integers in [0, SIZE - 1].\n * @tparam\
    \ SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct IsPrimeSieve\n{\n    bitset<SIZE>\
    \ is_prime;\n\n    IsPrimeSieve()\n    {\n        is_prime.set();\n        is_prime[0]\
    \ = is_prime[1] = 0;\n        for (int i = 4; i < SIZE; i += 2)\n            is_prime[i]\
    \ = 0;\n        for (int i = 3; i * i < SIZE; i += 2)\n            if (is_prime[i])\n\
    \                for (int j = i * i; j < SIZE; j += i * 2)\n                 \
    \   is_prime[j] = 0;\n    }\n\n    vector<int> primes() const\n    {\n       \
    \ vector<int> p;\n        for (int i = 2; i < SIZE; ++i)\n            if (is_prime[i])\n\
    \                p.push_back(i);\n        return p;\n    }\n};\n\n/*\n * @brief\
    \ Computes the smallest prime divisor of integers in [0, SIZE - 1].\n * @tparam\
    \ SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct SmallestPrimeSieve\n{\n\
    \    vector<int> sp, v;\n    SmallestPrimeSieve() : sp(SIZE, 1), v(SIZE, false)\n\
    \    {\n        for (int i = 2; i < SIZE; i += 2)\n            sp[i] = 2;\n  \
    \      for (int i = 3; i < SIZE; i += 2)\n        {\n            if (!v[i])\n\
    \            {\n                sp[i] = i;\n                for (long long j =\
    \ i; (j * i) < SIZE; j += 2)\n                    if (!v[j * i])\n           \
    \             v[j * i] = true, sp[j * i] = i;\n            }\n        }\n    }\n\
    \    vector<int> primes() const\n    {\n        vector<int> p;\n        for (int\
    \ x = 2; x < SIZE; ++x)\n            if (sp[x] == x)\n                p.push_back(x);\n\
    \        return p;\n    }\n};\n\n/*\n * @brief Computes the largest prime divisor\
    \ of integers in [0, SIZE - 1].\n * @tparam SIZE Size of sieve.\n */\ntemplate\
    \ <int SIZE>\nstruct LargestPrimeSieve\n{\n    vector<int> lp;\n    LargestPrimeSieve()\
    \ : lp(SIZE)\n    {\n        lp[0] = lp[1] = 1;\n        for (int i = 1; i < SIZE;\
    \ ++i)\n            if (lp[i] == 1)\n                for (int j = i; j < SIZE;\
    \ j += i)\n                    lp[j] = i;\n    }\n    vector<int> primes() const\n\
    \    {\n        vector<int> p;\n        for (int x = 2; x < SIZE; ++x)\n     \
    \       if (lp[x] == x)\n                p.push_back(x);\n        return p;\n\
    \    }\n};\n\n/*\n * @brief Computes the number of divisors of integers in [0,\
    \ SIZE - 1].\n * @tparam SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct\
    \ DivisorCountSieve\n{\n    vector<int> cnt;\n    DivisorCountSieve() : cnt(SIZE,\
    \ 0)\n    {\n        for (int i = 1; i < SIZE; i++)\n            for (int j =\
    \ i; j < SIZE; j += i)\n                cnt[j]++;\n    }\n};\n\n/*\n * @brief\
    \ Computes the Euler phi function for integers in [0, SIZE - 1]. phi[n]\n * is\
    \ the count of positive numbers coprime to n in [1, n].\n * @tparam SIZE Size\
    \ of sieve.\n */\ntemplate <int SIZE>\nstruct EulerTotientSieve\n{\n    vector<int>\
    \ phi;\n    EulerTotientSieve() : phi(SIZE, 0)\n    {\n        phi[0] = 0;\n \
    \       phi[1] = 1;\n        for (int i = 2; i < SIZE; i++)\n            phi[i]\
    \ = i;\n\n        for (int i = 2; i < SIZE; i++)\n        {\n            if (phi[i]\
    \ == i)\n                for (int j = i; j < SIZE; j += i)\n                 \
    \   phi[j] -= phi[j] / i;\n        }\n    }\n};\n\n/*\n * @brief Computes the\
    \ sum of positive divisors for integers in [0, SIZE - 1].\n * @tparam SIZE Size\
    \ of sieve.\n */\ntemplate <int SIZE>\nstruct SumDivisorSieve\n{\n    vector<long\
    \ long> sd;\n    SumDivisorSieve() : sd(SIZE, 0)\n    {\n        for (int i =\
    \ 1; i < SIZE; ++i)\n            for (int j = i; j < SIZE; j += i)\n         \
    \       sd[j] += i;\n    }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_SIEVE_HPP\n#define CPLIB_SIEVE_HPP\n\n#include <bitset>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    /*\n * @brief Computes the primality of integers in [0, SIZE - 1].\n * @tparam\
    \ SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct IsPrimeSieve\n{\n    bitset<SIZE>\
    \ is_prime;\n\n    IsPrimeSieve()\n    {\n        is_prime.set();\n        is_prime[0]\
    \ = is_prime[1] = 0;\n        for (int i = 4; i < SIZE; i += 2)\n            is_prime[i]\
    \ = 0;\n        for (int i = 3; i * i < SIZE; i += 2)\n            if (is_prime[i])\n\
    \                for (int j = i * i; j < SIZE; j += i * 2)\n                 \
    \   is_prime[j] = 0;\n    }\n\n    vector<int> primes() const\n    {\n       \
    \ vector<int> p;\n        for (int i = 2; i < SIZE; ++i)\n            if (is_prime[i])\n\
    \                p.push_back(i);\n        return p;\n    }\n};\n\n/*\n * @brief\
    \ Computes the smallest prime divisor of integers in [0, SIZE - 1].\n * @tparam\
    \ SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct SmallestPrimeSieve\n{\n\
    \    vector<int> sp, v;\n    SmallestPrimeSieve() : sp(SIZE, 1), v(SIZE, false)\n\
    \    {\n        for (int i = 2; i < SIZE; i += 2)\n            sp[i] = 2;\n  \
    \      for (int i = 3; i < SIZE; i += 2)\n        {\n            if (!v[i])\n\
    \            {\n                sp[i] = i;\n                for (long long j =\
    \ i; (j * i) < SIZE; j += 2)\n                    if (!v[j * i])\n           \
    \             v[j * i] = true, sp[j * i] = i;\n            }\n        }\n    }\n\
    \    vector<int> primes() const\n    {\n        vector<int> p;\n        for (int\
    \ x = 2; x < SIZE; ++x)\n            if (sp[x] == x)\n                p.push_back(x);\n\
    \        return p;\n    }\n};\n\n/*\n * @brief Computes the largest prime divisor\
    \ of integers in [0, SIZE - 1].\n * @tparam SIZE Size of sieve.\n */\ntemplate\
    \ <int SIZE>\nstruct LargestPrimeSieve\n{\n    vector<int> lp;\n    LargestPrimeSieve()\
    \ : lp(SIZE)\n    {\n        lp[0] = lp[1] = 1;\n        for (int i = 1; i < SIZE;\
    \ ++i)\n            if (lp[i] == 1)\n                for (int j = i; j < SIZE;\
    \ j += i)\n                    lp[j] = i;\n    }\n    vector<int> primes() const\n\
    \    {\n        vector<int> p;\n        for (int x = 2; x < SIZE; ++x)\n     \
    \       if (lp[x] == x)\n                p.push_back(x);\n        return p;\n\
    \    }\n};\n\n/*\n * @brief Computes the number of divisors of integers in [0,\
    \ SIZE - 1].\n * @tparam SIZE Size of sieve.\n */\ntemplate <int SIZE>\nstruct\
    \ DivisorCountSieve\n{\n    vector<int> cnt;\n    DivisorCountSieve() : cnt(SIZE,\
    \ 0)\n    {\n        for (int i = 1; i < SIZE; i++)\n            for (int j =\
    \ i; j < SIZE; j += i)\n                cnt[j]++;\n    }\n};\n\n/*\n * @brief\
    \ Computes the Euler phi function for integers in [0, SIZE - 1]. phi[n]\n * is\
    \ the count of positive numbers coprime to n in [1, n].\n * @tparam SIZE Size\
    \ of sieve.\n */\ntemplate <int SIZE>\nstruct EulerTotientSieve\n{\n    vector<int>\
    \ phi;\n    EulerTotientSieve() : phi(SIZE, 0)\n    {\n        phi[0] = 0;\n \
    \       phi[1] = 1;\n        for (int i = 2; i < SIZE; i++)\n            phi[i]\
    \ = i;\n\n        for (int i = 2; i < SIZE; i++)\n        {\n            if (phi[i]\
    \ == i)\n                for (int j = i; j < SIZE; j += i)\n                 \
    \   phi[j] -= phi[j] / i;\n        }\n    }\n};\n\n/*\n * @brief Computes the\
    \ sum of positive divisors for integers in [0, SIZE - 1].\n * @tparam SIZE Size\
    \ of sieve.\n */\ntemplate <int SIZE>\nstruct SumDivisorSieve\n{\n    vector<long\
    \ long> sd;\n    SumDivisorSieve() : sd(SIZE, 0)\n    {\n        for (int i =\
    \ 1; i < SIZE; ++i)\n            for (int j = i; j < SIZE; j += i)\n         \
    \       sd[j] += i;\n    }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_SIEVE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/sieve.hpp
  requiredBy: []
  timestamp: '2021-12-25 20:18:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/sieve.hpp
layout: document
redirect_from:
- /library/cplib/math/sieve.hpp
- /library/cplib/math/sieve.hpp.html
title: Computes the primality of integers in [0, SIZE - 1].
---
