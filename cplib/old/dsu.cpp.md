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
  bundledCode: "#line 1 \"cplib/old/dsu.cpp\"\n#include <algorithm>\n\n#define NMAX\
    \ 10000\n\nusing namespace std;\n\nint parent[NMAX];\nint ssize[NMAX];\n\nvoid\
    \ make_set(int v)\n{\n    parent[v] = v;\n    ssize[v]  = 1;\n}\n\nint find_set(int\
    \ v)\n{\n    if (v == parent[v])\n        return v;\n    return (parent[v] = find_set(parent[v]));\
    \ // path compression\n}\n\nvoid union_sets(int a, int b)\n{\n    a = find_set(a);\n\
    \    b = find_set(b);\n    if (a != b)\n    {\n        if (ssize[a] < ssize[b])\
    \ // union by size\n            swap(a, b);\n        parent[b] = a;\n        ssize[a]\
    \ += ssize[b];\n    }\n}\n"
  code: "#include <algorithm>\n\n#define NMAX 10000\n\nusing namespace std;\n\nint\
    \ parent[NMAX];\nint ssize[NMAX];\n\nvoid make_set(int v)\n{\n    parent[v] =\
    \ v;\n    ssize[v]  = 1;\n}\n\nint find_set(int v)\n{\n    if (v == parent[v])\n\
    \        return v;\n    return (parent[v] = find_set(parent[v])); // path compression\n\
    }\n\nvoid union_sets(int a, int b)\n{\n    a = find_set(a);\n    b = find_set(b);\n\
    \    if (a != b)\n    {\n        if (ssize[a] < ssize[b]) // union by size\n \
    \           swap(a, b);\n        parent[b] = a;\n        ssize[a] += ssize[b];\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/old/dsu.cpp
  requiredBy: []
  timestamp: '2021-01-31 10:07:00-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/dsu.cpp
layout: document
redirect_from:
- /library/cplib/old/dsu.cpp
- /library/cplib/old/dsu.cpp.html
title: cplib/old/dsu.cpp
---
