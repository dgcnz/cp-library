---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/old/sieve_eratosthenes.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll  = long long;\nusing vi  = vector<int>;\nusing\
    \ mii = map<int, int>;\n\nconst int PMAX = 1e7 + 11; // okay for range <= INT_MAX\n\
    \nbitset<PMAX> is_prime; // is_prime[i], true if number i is prime, else false\n\
    vector<int>  primes;   // primes[i], prime at pos i\n\nvi prime_factors(ll n)\n\
    {\n    // mii factors;\n    vi factors;\n    ll i = 0, pf = primes[i];\n\n   \
    \ while (pf * pf <= n)\n    {\n        while (n % pf == 0)\n        {\n      \
    \      factors.push_back(pf);\n            // ++factors[pf];\n            n =\
    \ n / pf;\n        }\n        pf = primes[++i];\n    }\n\n    if (n != 1) // If\
    \ n is prime then it will stay the same, add n.\n        factors.push_back(n);\
    \ // ++factors[n];\n    return factors;\n}\n\n// Note it's only necessary to sieve\
    \ until sqrt(upperbound), why?\n//\n// (1) All smaller numbers that are multiples\
    \ of i necessary also have a prime\n// factor which is less than i, so all of\
    \ them were already sifted earlier.\n\nvoid sieve(void) // fi primes until upperbound\
    \ inclusive\n{\n    is_prime.set(); // set all bits to true\n    is_prime[0] =\
    \ is_prime[1] = 0;\n\n    for (ll i = 2; i < PMAX; i++)\n        if (is_prime[i])\n\
    \        {\n            for (ll j = i * i; j < PMAX; j += i)\n               \
    \ is_prime[j] = 0;\n            primes.push_back(i);\n        }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll  = long long;\n\
    using vi  = vector<int>;\nusing mii = map<int, int>;\n\nconst int PMAX = 1e7 +\
    \ 11; // okay for range <= INT_MAX\n\nbitset<PMAX> is_prime; // is_prime[i], true\
    \ if number i is prime, else false\nvector<int>  primes;   // primes[i], prime\
    \ at pos i\n\nvi prime_factors(ll n)\n{\n    // mii factors;\n    vi factors;\n\
    \    ll i = 0, pf = primes[i];\n\n    while (pf * pf <= n)\n    {\n        while\
    \ (n % pf == 0)\n        {\n            factors.push_back(pf);\n            //\
    \ ++factors[pf];\n            n = n / pf;\n        }\n        pf = primes[++i];\n\
    \    }\n\n    if (n != 1) // If n is prime then it will stay the same, add n.\n\
    \        factors.push_back(n); // ++factors[n];\n    return factors;\n}\n\n//\
    \ Note it's only necessary to sieve until sqrt(upperbound), why?\n//\n// (1) All\
    \ smaller numbers that are multiples of i necessary also have a prime\n// factor\
    \ which is less than i, so all of them were already sifted earlier.\n\nvoid sieve(void)\
    \ // fi primes until upperbound inclusive\n{\n    is_prime.set(); // set all bits\
    \ to true\n    is_prime[0] = is_prime[1] = 0;\n\n    for (ll i = 2; i < PMAX;\
    \ i++)\n        if (is_prime[i])\n        {\n            for (ll j = i * i; j\
    \ < PMAX; j += i)\n                is_prime[j] = 0;\n            primes.push_back(i);\n\
    \        }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/old/sieve_eratosthenes.cpp
  requiredBy: []
  timestamp: '2021-01-31 11:22:21-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/sieve_eratosthenes.cpp
layout: document
redirect_from:
- /library/cplib/old/sieve_eratosthenes.cpp
- /library/cplib/old/sieve_eratosthenes.cpp.html
title: cplib/old/sieve_eratosthenes.cpp
---
