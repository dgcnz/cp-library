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
  bundledCode: "#line 1 \"cplib/data_structure/lazy_segtree.cpp\"\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\ntemplate <typename T>\nstruct LazySegmentTree\n\
    {\n    using BinaryOperator = std::function<T(T, T)>;\n\n    T              id;\n\
    \    BinaryOperator op;\n\n    int            n;\n    std::vector<T> seg, lazy;\n\
    \n    template <class InputIterator>\n    explicit LazySegmentTree(InputIterator\
    \  first,\n                             InputIterator  last,\n               \
    \              T              id,\n                             BinaryOperator\
    \ op)\n        : id(id), op(op), n(distance(first, last))\n    {\n        seg.resize(4\
    \ * n), lazy.resize(4 * n);\n        build(first, last, 1, 0, n - 1);\n    }\n\
    \n    template <class InputIterator>\n    void build(InputIterator first, InputIterator\
    \ last, int v, int tl, int tr)\n    {\n        if (tl == tr)\n            seg[v]\
    \ = T(*(first + tl));\n        else\n        {\n            int tm = (tl + tr)\
    \ / 2;\n            build(first, last, v << 1, tl, tm);\n            build(first,\
    \ last, (v << 1) + 1, tm + 1, tr);\n            seg[v] = op(seg[v << 1], seg[(v\
    \ << 1) + 1]);\n        }\n    }\n\n    // Computes current node and propagates\
    \ change to lazy subtrees\n    void lazy_propagate(int v, int tl, int tr, T val)\n\
    \    {\n        // TODO: How do we lazy propagate\n        seg[v] += (tr - tl\
    \ + 1) * val; // Apply changes\n        if (tl != tr) // If non-leaf, propagate\
    \ lazily to children\n        {\n            lazy[(v << 1)] += val;\n        \
    \    lazy[(v << 1) + 1] += val;\n        }\n        lazy[v] = 0; // Clear node\n\
    \    }\n\n    // [tl, tr] : tree's range\n    // [ql, qr] : query's range\n\n\
    \    void update(int v, int tl, int tr, int ql, int qr, T x)\n    {\n\n      \
    \  if (lazy[v] != 0) // Pending update. Propagate lazily on children.\n      \
    \      lazy_propagate(v, tl, tr, lazy[v]);\n\n        if (ql > qr) // no overlap\n\
    \            return;\n\n        if (tl == ql and tr == qr) // complete overlap\n\
    \            lazy_propagate(\n                v, tl, tr, x); // Apply x to node,\
    \ lazily propagate to children\n        else                   // partial overlap\n\
    \        {\n            int tm = (tl + tr) / 2;\n            update(v * 2, tl,\
    \ tm, ql, std::min(qr, tm), x);\n            update(v * 2 + 1, tm + 1, tr, std::max(ql,\
    \ tm + 1), qr, x);\n\n            seg[v] = op(seg[v << 1], seg[(v << 1) + 1]);\n\
    \        }\n    }\n\n    T query(int v, int tl, int tr, int ql, int qr)\n    {\n\
    \        if (lazy[v] != 0) // Pending update. Propagate on children.\n       \
    \     lazy_propagate(v, tl, tr, lazy[v]);\n\n        if (ql > qr) // no overlap\n\
    \            return 0;\n        if (tl == ql and tr == qr) // complete overlap\n\
    \            return seg[v];\n        else // partial overlap\n        {\n    \
    \        int tm = (tl + tr) / 2;\n            return op(query(v * 2, tl, tm, ql,\
    \ std::min(qr, tm)),\n                      query(v * 2 + 1, tm + 1, tr, std::max(ql,\
    \ tm + 1), qr));\n        }\n    }\n};\n"
  code: "#include <algorithm>\n#include <functional>\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct LazySegmentTree\n{\n    using BinaryOperator = std::function<T(T,\
    \ T)>;\n\n    T              id;\n    BinaryOperator op;\n\n    int          \
    \  n;\n    std::vector<T> seg, lazy;\n\n    template <class InputIterator>\n \
    \   explicit LazySegmentTree(InputIterator  first,\n                         \
    \    InputIterator  last,\n                             T              id,\n \
    \                            BinaryOperator op)\n        : id(id), op(op), n(distance(first,\
    \ last))\n    {\n        seg.resize(4 * n), lazy.resize(4 * n);\n        build(first,\
    \ last, 1, 0, n - 1);\n    }\n\n    template <class InputIterator>\n    void build(InputIterator\
    \ first, InputIterator last, int v, int tl, int tr)\n    {\n        if (tl ==\
    \ tr)\n            seg[v] = T(*(first + tl));\n        else\n        {\n     \
    \       int tm = (tl + tr) / 2;\n            build(first, last, v << 1, tl, tm);\n\
    \            build(first, last, (v << 1) + 1, tm + 1, tr);\n            seg[v]\
    \ = op(seg[v << 1], seg[(v << 1) + 1]);\n        }\n    }\n\n    // Computes current\
    \ node and propagates change to lazy subtrees\n    void lazy_propagate(int v,\
    \ int tl, int tr, T val)\n    {\n        // TODO: How do we lazy propagate\n \
    \       seg[v] += (tr - tl + 1) * val; // Apply changes\n        if (tl != tr)\
    \ // If non-leaf, propagate lazily to children\n        {\n            lazy[(v\
    \ << 1)] += val;\n            lazy[(v << 1) + 1] += val;\n        }\n        lazy[v]\
    \ = 0; // Clear node\n    }\n\n    // [tl, tr] : tree's range\n    // [ql, qr]\
    \ : query's range\n\n    void update(int v, int tl, int tr, int ql, int qr, T\
    \ x)\n    {\n\n        if (lazy[v] != 0) // Pending update. Propagate lazily on\
    \ children.\n            lazy_propagate(v, tl, tr, lazy[v]);\n\n        if (ql\
    \ > qr) // no overlap\n            return;\n\n        if (tl == ql and tr == qr)\
    \ // complete overlap\n            lazy_propagate(\n                v, tl, tr,\
    \ x); // Apply x to node, lazily propagate to children\n        else         \
    \          // partial overlap\n        {\n            int tm = (tl + tr) / 2;\n\
    \            update(v * 2, tl, tm, ql, std::min(qr, tm), x);\n            update(v\
    \ * 2 + 1, tm + 1, tr, std::max(ql, tm + 1), qr, x);\n\n            seg[v] = op(seg[v\
    \ << 1], seg[(v << 1) + 1]);\n        }\n    }\n\n    T query(int v, int tl, int\
    \ tr, int ql, int qr)\n    {\n        if (lazy[v] != 0) // Pending update. Propagate\
    \ on children.\n            lazy_propagate(v, tl, tr, lazy[v]);\n\n        if\
    \ (ql > qr) // no overlap\n            return 0;\n        if (tl == ql and tr\
    \ == qr) // complete overlap\n            return seg[v];\n        else // partial\
    \ overlap\n        {\n            int tm = (tl + tr) / 2;\n            return\
    \ op(query(v * 2, tl, tm, ql, std::min(qr, tm)),\n                      query(v\
    \ * 2 + 1, tm + 1, tr, std::max(ql, tm + 1), qr));\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/lazy_segtree.cpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/lazy_segtree.cpp
layout: document
redirect_from:
- /library/cplib/data_structure/lazy_segtree.cpp
- /library/cplib/data_structure/lazy_segtree.cpp.html
title: cplib/data_structure/lazy_segtree.cpp
---
