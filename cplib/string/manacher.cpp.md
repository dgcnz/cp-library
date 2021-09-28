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
  bundledCode: "#line 1 \"cplib/string/manacher.cpp\"\n\n\n#include <string>\n#include\
    \ <utility>\n#include <algorithm>\n#include <vector>\n\nnamespace cplib\n{\n\n\
    using namespace std;\n\npair<vector<int>, vector<int>> manacher(string const &s)\n\
    {\n    int         n = s.size();\n    vector<int> d1(n), d2(n);\n    for (int\
    \ i = 0, l = 0, r = -1; i < n; ++i)\n    {\n        int j = l + r - i;\n     \
    \   int k = (i > r) ? 1 : min(d1[j], j - l + 1);\n        while (0 <= i - k and\
    \ i + k < n and s[i - k] == s[i + k])\n            ++k;\n        d1[i] = k--;\n\
    \        if (i + k > r)\n        {\n            l = i - k;\n            r = i\
    \ + k;\n        }\n    }\n\n    for (int i = 0, l = 0, r = -1; i < n; ++i)\n \
    \   {\n        int j = l + r - i;\n        int k = (i > r) ? 0 : min(d2[j + 1],\
    \ j - l + 1);\n        while (0 <= i - k - 1 and i + k < n and s[i - k - 1] ==\
    \ s[i + k])\n            ++k;\n        d2[i] = k--;\n        if (i + k > r)\n\
    \        {\n            l = i - k - 1;\n            r = i + k;\n        }\n  \
    \  }\n    return {d1, d2};\n}\n}; // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_MANACHER_HPP\n#define CPLIB_MANACHER_HPP\n#include <string>\n\
    #include <utility>\n#include <algorithm>\n#include <vector>\n\nnamespace cplib\n\
    {\n\nusing namespace std;\n\npair<vector<int>, vector<int>> manacher(string const\
    \ &s)\n{\n    int         n = s.size();\n    vector<int> d1(n), d2(n);\n    for\
    \ (int i = 0, l = 0, r = -1; i < n; ++i)\n    {\n        int j = l + r - i;\n\
    \        int k = (i > r) ? 1 : min(d1[j], j - l + 1);\n        while (0 <= i -\
    \ k and i + k < n and s[i - k] == s[i + k])\n            ++k;\n        d1[i] =\
    \ k--;\n        if (i + k > r)\n        {\n            l = i - k;\n          \
    \  r = i + k;\n        }\n    }\n\n    for (int i = 0, l = 0, r = -1; i < n; ++i)\n\
    \    {\n        int j = l + r - i;\n        int k = (i > r) ? 0 : min(d2[j + 1],\
    \ j - l + 1);\n        while (0 <= i - k - 1 and i + k < n and s[i - k - 1] ==\
    \ s[i + k])\n            ++k;\n        d2[i] = k--;\n        if (i + k > r)\n\
    \        {\n            l = i - k - 1;\n            r = i + k;\n        }\n  \
    \  }\n    return {d1, d2};\n}\n}; // namespace cplib\n\n#endif // CPLIB_MANACHER_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/manacher.cpp
  requiredBy: []
  timestamp: '2021-09-28 18:27:50-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/manacher.cpp
layout: document
redirect_from:
- /library/cplib/string/manacher.cpp
- /library/cplib/string/manacher.cpp.html
title: cplib/string/manacher.cpp
---
