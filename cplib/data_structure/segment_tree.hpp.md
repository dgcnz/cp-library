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
  bundledCode: "#line 1 \"cplib/data_structure/segment_tree.hpp\"\n\n\n\n#include\
    \ <functional>\n#include <vector>\n\ntemplate <typename T>\nstruct SegmentTree\n\
    {\n    using BinaryOperator = std::function<T(T, T)>;\n\n    T              id;\n\
    \    BinaryOperator op;\n\n    int            n;\n    std::vector<T> t;\n\n  \
    \  template <class InputIterator>\n    explicit SegmentTree(InputIterator  first,\n\
    \                         InputIterator  last,\n                         T   \
    \           id,\n                         BinaryOperator op)\n        : id(id),\
    \ op(op), n(distance(first, last))\n    {\n        t.resize(4 * n);\n        build(first,\
    \ last, 1, 0, n - 1);\n    }\n\n    template <class InputIterator>\n    void build(InputIterator\
    \ first, InputIterator last, int v, int tl, int tr)\n    {\n        if (tl ==\
    \ tr)\n            t[v] = T(*(first + tl));\n        else\n        {\n       \
    \     int tm = (tl + tr) / 2;\n            build(first, last, v << 1, tl, tm);\n\
    \            build(first, last, (v << 1) + 1, tm + 1, tr);\n            t[v] =\
    \ op(t[v << 1], t[(v << 1) + 1]);\n        }\n    }\n\n    T query(int l, int\
    \ r) const { return query(1, 0, n - 1, l, r); }\n    T query(int v, int tl, int\
    \ tr, int l, int r) const\n    {\n        if (l > r)\n            return id;\n\
    \        if (l == tl and r == tr)\n            return t[v];\n        int tm =\
    \ (tl + tr) >> 1;\n\n        // min(r, tm), when we split we only care about the\
    \ left part, but if\n        // the range exceeds the queried range, then the\
    \ remaining is\n        // unnecessary, so pick r.\n        return op(query(v\
    \ << 1, tl, tm, l, std::min(r, tm)),\n                  query((v << 1) + 1, tm\
    \ + 1, tr, std::max(l, tm + 1), r));\n    }\n\n    void update(int pos, T val)\
    \ { return update(1, 0, n - 1, pos, val); }\n    void update(int v, int tl, int\
    \ tr, int pos, T val)\n    {\n        if (tl == tr)\n            t[v] = val;\n\
    \        else\n        {\n            int tm = (tl + tr) >> 1;\n\n           \
    \ if (pos <= tm)\n                update(v << 1, tl, tm, pos, val);\n        \
    \    else\n                update((v << 1) + 1, tm + 1, tr, pos, val);\n     \
    \       t[v] = op(t[v << 1], t[(v << 1) + 1]);\n        }\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_SEGMENT_TREE_HPP\n#define CPLIB_SEGMENT_TREE_HPP\n\n#include\
    \ <functional>\n#include <vector>\n\ntemplate <typename T>\nstruct SegmentTree\n\
    {\n    using BinaryOperator = std::function<T(T, T)>;\n\n    T              id;\n\
    \    BinaryOperator op;\n\n    int            n;\n    std::vector<T> t;\n\n  \
    \  template <class InputIterator>\n    explicit SegmentTree(InputIterator  first,\n\
    \                         InputIterator  last,\n                         T   \
    \           id,\n                         BinaryOperator op)\n        : id(id),\
    \ op(op), n(distance(first, last))\n    {\n        t.resize(4 * n);\n        build(first,\
    \ last, 1, 0, n - 1);\n    }\n\n    template <class InputIterator>\n    void build(InputIterator\
    \ first, InputIterator last, int v, int tl, int tr)\n    {\n        if (tl ==\
    \ tr)\n            t[v] = T(*(first + tl));\n        else\n        {\n       \
    \     int tm = (tl + tr) / 2;\n            build(first, last, v << 1, tl, tm);\n\
    \            build(first, last, (v << 1) + 1, tm + 1, tr);\n            t[v] =\
    \ op(t[v << 1], t[(v << 1) + 1]);\n        }\n    }\n\n    T query(int l, int\
    \ r) const { return query(1, 0, n - 1, l, r); }\n    T query(int v, int tl, int\
    \ tr, int l, int r) const\n    {\n        if (l > r)\n            return id;\n\
    \        if (l == tl and r == tr)\n            return t[v];\n        int tm =\
    \ (tl + tr) >> 1;\n\n        // min(r, tm), when we split we only care about the\
    \ left part, but if\n        // the range exceeds the queried range, then the\
    \ remaining is\n        // unnecessary, so pick r.\n        return op(query(v\
    \ << 1, tl, tm, l, std::min(r, tm)),\n                  query((v << 1) + 1, tm\
    \ + 1, tr, std::max(l, tm + 1), r));\n    }\n\n    void update(int pos, T val)\
    \ { return update(1, 0, n - 1, pos, val); }\n    void update(int v, int tl, int\
    \ tr, int pos, T val)\n    {\n        if (tl == tr)\n            t[v] = val;\n\
    \        else\n        {\n            int tm = (tl + tr) >> 1;\n\n           \
    \ if (pos <= tm)\n                update(v << 1, tl, tm, pos, val);\n        \
    \    else\n                update((v << 1) + 1, tm + 1, tr, pos, val);\n     \
    \       t[v] = op(t[v << 1], t[(v << 1) + 1]);\n        }\n    }\n};\n\n#endif\
    \ // CPLIB_SEGMENT_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/segment_tree.hpp
- /library/cplib/data_structure/segment_tree.hpp.html
title: cplib/data_structure/segment_tree.hpp
---
