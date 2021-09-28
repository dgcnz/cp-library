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
  bundledCode: "#line 1 \"cplib/old/gcd.cpp\"\n\n// Euclides' algorithm\n//\n// Key\
    \ insight to remember:\n//\n// Euclides' algorithm is based on two observations:\n\
    //\n// 1. if b divides a, then gcd(a, b) = b\n// 2. a = bd + r, gcd(a, b) = gcd(b,\
    \ r)\n\ntemplate <typename T>\nT gcd(T a, T b)\n{\n    return (b == 0 ? a : gcd(b,\
    \ a % b));\n}\n\n// Observations\n// 1. lcm(a, b) >= max(a, b);\n// 2. lcm(a,\
    \ b) <= a * b\n\ntemplate <typename T>\nT lcm(T a, T b)\n{\n    return ((a * b)\
    \ / gcd(a, b));\n}\n"
  code: "\n// Euclides' algorithm\n//\n// Key insight to remember:\n//\n// Euclides'\
    \ algorithm is based on two observations:\n//\n// 1. if b divides a, then gcd(a,\
    \ b) = b\n// 2. a = bd + r, gcd(a, b) = gcd(b, r)\n\ntemplate <typename T>\nT\
    \ gcd(T a, T b)\n{\n    return (b == 0 ? a : gcd(b, a % b));\n}\n\n// Observations\n\
    // 1. lcm(a, b) >= max(a, b);\n// 2. lcm(a, b) <= a * b\n\ntemplate <typename\
    \ T>\nT lcm(T a, T b)\n{\n    return ((a * b) / gcd(a, b));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/old/gcd.cpp
  requiredBy: []
  timestamp: '2021-01-31 11:22:21-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/gcd.cpp
layout: document
redirect_from:
- /library/cplib/old/gcd.cpp
- /library/cplib/old/gcd.cpp.html
title: cplib/old/gcd.cpp
---
