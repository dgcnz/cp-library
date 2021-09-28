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
  bundledCode: "#line 1 \"cplib/utils/compress.cpp\"\ntemplate <typename T>\nmap<T,\
    \ int> compress(vector<T> values)\n{\n    map<T, int> mp;\n    int         cnt\
    \ = 0;\n    for (auto v : values)\n        mp[v];\n    for (auto &[k, v] : mp)\n\
    \        v = cnt++;\n    return mp;\n}\n"
  code: "template <typename T>\nmap<T, int> compress(vector<T> values)\n{\n    map<T,\
    \ int> mp;\n    int         cnt = 0;\n    for (auto v : values)\n        mp[v];\n\
    \    for (auto &[k, v] : mp)\n        v = cnt++;\n    return mp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/compress.cpp
  requiredBy: []
  timestamp: '2021-01-16 15:57:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/compress.cpp
layout: document
redirect_from:
- /library/cplib/utils/compress.cpp
- /library/cplib/utils/compress.cpp.html
title: cplib/utils/compress.cpp
---
