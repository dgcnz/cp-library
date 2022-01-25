---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/math/modint.hpp
    title: cplib/math/modint.hpp
  - icon: ':warning:'
    path: cplib/math/pfint.hpp
    title: cplib/math/pfint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/math/binary_exponentiation.hpp\"\n\n\n\ntemplate <typename\
    \ T1, typename T2>\nT1 binpow(T1 base, T2 exp)\n{\n    T1 ans = 1;\n    while\
    \ (exp > 0)\n    {\n        if (exp & 1)\n            ans *= base;\n        base\
    \ *= base;\n        exp >>= 1;\n    }\n    return ans;\n}\n\n\n"
  code: "#ifndef CPLIB_BINARY_EXPONENTIATION_HPP\n#define CPLIB_BINARY_EXPONENTIATION_HPP\n\
    \ntemplate <typename T1, typename T2>\nT1 binpow(T1 base, T2 exp)\n{\n    T1 ans\
    \ = 1;\n    while (exp > 0)\n    {\n        if (exp & 1)\n            ans *= base;\n\
    \        base *= base;\n        exp >>= 1;\n    }\n    return ans;\n}\n\n#endif\
    \ // CPLIB_BINARY_EXPONENTIATION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/binary_exponentiation.hpp
  requiredBy:
  - cplib/math/modint.hpp
  - cplib/math/pfint.hpp
  timestamp: '2020-12-17 19:42:35-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/binary_exponentiation.hpp
layout: document
redirect_from:
- /library/cplib/math/binary_exponentiation.hpp
- /library/cplib/math/binary_exponentiation.hpp.html
title: cplib/math/binary_exponentiation.hpp
---
