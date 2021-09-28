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
  bundledCode: "#line 1 \"cplib/string/trie.cpp\"\ntemplate <typename T>\nstruct Trie\n\
    {\n    int                 n, nmax;\n    vector<vector<int>> t;\n    vector<T>\
    \           val;\n\n    Trie(int N, int alphasz) : n(0), t(N, vector<int>(alphasz,\
    \ 0)), val(N, T())\n    {\n    }\n    void update(const vector<int> &a, function<void(T\
    \ &)> f)\n    {\n        int cur = 0;\n        for (int i = 0; i < (int)a.size();\
    \ ++i)\n        {\n            if (!t[cur][a[i]])\n                t[cur][a[i]]\
    \ = ++n;\n            cur = t[cur][a[i]];\n            f(val[cur]);\n        }\n\
    \    }\n\n    void traverse(const vector<int> &a, function<void(T &, int)> f)\n\
    \    {\n        int cur = 0;\n        for (int i = 0; i < (int)a.size(); ++i)\n\
    \        {\n\n            if (!t[cur][a[i]])\n                return;\n\n    \
    \        f(val[t[cur][a[i]]], i);\n            cur = t[cur][a[i]];\n        }\n\
    \    }\n};\n"
  code: "template <typename T>\nstruct Trie\n{\n    int                 n, nmax;\n\
    \    vector<vector<int>> t;\n    vector<T>           val;\n\n    Trie(int N, int\
    \ alphasz) : n(0), t(N, vector<int>(alphasz, 0)), val(N, T())\n    {\n    }\n\
    \    void update(const vector<int> &a, function<void(T &)> f)\n    {\n       \
    \ int cur = 0;\n        for (int i = 0; i < (int)a.size(); ++i)\n        {\n \
    \           if (!t[cur][a[i]])\n                t[cur][a[i]] = ++n;\n        \
    \    cur = t[cur][a[i]];\n            f(val[cur]);\n        }\n    }\n\n    void\
    \ traverse(const vector<int> &a, function<void(T &, int)> f)\n    {\n        int\
    \ cur = 0;\n        for (int i = 0; i < (int)a.size(); ++i)\n        {\n\n   \
    \         if (!t[cur][a[i]])\n                return;\n\n            f(val[t[cur][a[i]]],\
    \ i);\n            cur = t[cur][a[i]];\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/trie.cpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/trie.cpp
layout: document
redirect_from:
- /library/cplib/string/trie.cpp
- /library/cplib/string/trie.cpp.html
title: cplib/string/trie.cpp
---
