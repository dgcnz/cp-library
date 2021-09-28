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
  bundledCode: "#line 1 \"cplib/string/manacher.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nconst int NMAX = 1e5 + 11;\nint       n, d1[NMAX], d2[NMAX];\n\
    \n// odd manacher: for each i compute the number of palindromes centered at i\n\
    // if i is out of the rightmost palindrome, then do trivial algorithm\n// otherwise,\
    \ let j = l + r - i, the mirror of i on rightmost palindrome\n// we have already\
    \ computed the palindromes of j, d[j]\n// however, d[j] borders might exceed the\
    \ rightmost palindrome with ends [l, r]\n// In that, case, just take the minimum\
    \ of them and extend as much as possible\n\nvoid manacher(const string &s)\n{\n\
    \    for (int i = 0, l = 0, r = -1; i < n; ++i)\n    {\n        int j = l + r\
    \ - i;\n        int k = (i > r) ? 1 : min(d1[j], j - l + 1);\n        while (0\
    \ <= i - k and i + k < n and s[i - k] == s[i + k])\n            ++k;\n       \
    \ d1[i] = k--;\n        if (i + k > r)\n        {\n            l = i - k;\n  \
    \          r = i + k;\n        }\n    }\n\n    for (int i = 0, l = 0, r = -1;\
    \ i < n; ++i)\n    {\n        int j = l + r - i;\n        int k = (i > r) ? 0\
    \ : min(d2[j + 1], j - l + 1);\n        while (0 <= i - k - 1 and i + k < n and\
    \ s[i - k - 1] == s[i + k])\n            ++k;\n        d2[i] = k--;\n        if\
    \ (i + k > r)\n        {\n            l = i - k - 1;\n            r = i + k;\n\
    \        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nconst int NMAX = 1e5\
    \ + 11;\nint       n, d1[NMAX], d2[NMAX];\n\n// odd manacher: for each i compute\
    \ the number of palindromes centered at i\n// if i is out of the rightmost palindrome,\
    \ then do trivial algorithm\n// otherwise, let j = l + r - i, the mirror of i\
    \ on rightmost palindrome\n// we have already computed the palindromes of j, d[j]\n\
    // however, d[j] borders might exceed the rightmost palindrome with ends [l, r]\n\
    // In that, case, just take the minimum of them and extend as much as possible\n\
    \nvoid manacher(const string &s)\n{\n    for (int i = 0, l = 0, r = -1; i < n;\
    \ ++i)\n    {\n        int j = l + r - i;\n        int k = (i > r) ? 1 : min(d1[j],\
    \ j - l + 1);\n        while (0 <= i - k and i + k < n and s[i - k] == s[i + k])\n\
    \            ++k;\n        d1[i] = k--;\n        if (i + k > r)\n        {\n \
    \           l = i - k;\n            r = i + k;\n        }\n    }\n\n    for (int\
    \ i = 0, l = 0, r = -1; i < n; ++i)\n    {\n        int j = l + r - i;\n     \
    \   int k = (i > r) ? 0 : min(d2[j + 1], j - l + 1);\n        while (0 <= i -\
    \ k - 1 and i + k < n and s[i - k - 1] == s[i + k])\n            ++k;\n      \
    \  d2[i] = k--;\n        if (i + k > r)\n        {\n            l = i - k - 1;\n\
    \            r = i + k;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/manacher.cpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/manacher.cpp
layout: document
redirect_from:
- /library/cplib/string/manacher.cpp
- /library/cplib/string/manacher.cpp.html
title: cplib/string/manacher.cpp
---
