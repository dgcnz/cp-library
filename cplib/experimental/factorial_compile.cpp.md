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
  bundledCode: "#line 1 \"cplib/experimental/factorial_compile.cpp\"\n//  #include\
    \ \"modint.hpp\"\n#include <iostream>\n\ntemplate <int N, int MOD>\nstruct Factorial\n\
    {\n    constexpr Factorial() : fact()\n    {\n        fact[0] = 1;\n        for\
    \ (auto i = 1; i <= N; ++i)\n            fact[i] = (fact[i - 1] * i) % MOD;\n\
    \    }\n    long long fact[N + 1];\n};\n\nint main()\n{\n    int const      NMAX\
    \ = 1e5;\n    int const      MOD  = 1e9 + 7;\n    constexpr auto f    = Factorial<NMAX,\
    \ MOD>();\n    for (auto x : f.fact)\n        std::cout << x << '\\n';\n}\n"
  code: "//  #include \"modint.hpp\"\n#include <iostream>\n\ntemplate <int N, int\
    \ MOD>\nstruct Factorial\n{\n    constexpr Factorial() : fact()\n    {\n     \
    \   fact[0] = 1;\n        for (auto i = 1; i <= N; ++i)\n            fact[i] =\
    \ (fact[i - 1] * i) % MOD;\n    }\n    long long fact[N + 1];\n};\n\nint main()\n\
    {\n    int const      NMAX = 1e5;\n    int const      MOD  = 1e9 + 7;\n    constexpr\
    \ auto f    = Factorial<NMAX, MOD>();\n    for (auto x : f.fact)\n        std::cout\
    \ << x << '\\n';\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/factorial_compile.cpp
  requiredBy: []
  timestamp: '2021-01-16 15:57:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/factorial_compile.cpp
layout: document
redirect_from:
- /library/cplib/experimental/factorial_compile.cpp
- /library/cplib/experimental/factorial_compile.cpp.html
title: cplib/experimental/factorial_compile.cpp
---
