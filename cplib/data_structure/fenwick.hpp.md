---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/data_structure/fenwick.hpp\"\n\n\n#include <iterator>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct FenwickTree\n{\n    int   \
    \         n;\n    std::vector<T> bit;\n\n    FenwickTree(int n) : n(n + 1) { bit.assign(n\
    \ + 1, 0); }\n\n    template <typename InputIt>\n    FenwickTree(InputIt first,\
    \ InputIt last)\n        : FenwickTree(distance(first, last) + 1)\n    {\n   \
    \     for (int i = 0; first != last; ++first, ++i)\n            add(i, first);\n\
    \    }\n\n    T sum(int i)\n    {\n        T ret = 0;\n        for (++i; i > 0;\
    \ i -= i & -i)\n            ret += bit[i];\n        return ret;\n    }\n\n   \
    \ T sum(int l, int r) { return sum(r) - sum(l - 1); }\n\n    void add(int i, T\
    \ delta)\n    {\n        for (++i; i < n; i += i & -i)\n            bit[i] +=\
    \ delta;\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_FENWICK_HPP\n#define CPLIB_FENWICK_HPP\n#include <iterator>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct FenwickTree\n{\n    int   \
    \         n;\n    std::vector<T> bit;\n\n    FenwickTree(int n) : n(n + 1) { bit.assign(n\
    \ + 1, 0); }\n\n    template <typename InputIt>\n    FenwickTree(InputIt first,\
    \ InputIt last)\n        : FenwickTree(distance(first, last) + 1)\n    {\n   \
    \     for (int i = 0; first != last; ++first, ++i)\n            add(i, first);\n\
    \    }\n\n    T sum(int i)\n    {\n        T ret = 0;\n        for (++i; i > 0;\
    \ i -= i & -i)\n            ret += bit[i];\n        return ret;\n    }\n\n   \
    \ T sum(int l, int r) { return sum(r) - sum(l - 1); }\n\n    void add(int i, T\
    \ delta)\n    {\n        for (++i; i < n; i += i & -i)\n            bit[i] +=\
    \ delta;\n    }\n};\n\n#endif // CPLIB_FENWICK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/fenwick.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/fenwick.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/fenwick.hpp
- /library/cplib/data_structure/fenwick.hpp.html
title: cplib/data_structure/fenwick.hpp
---
