---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp
  bundledCode: "#line 1 \"cplib/data_structure/persistent_segtree.hpp\"\n#include\
    \ <vector>\n\n// source: https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp\n\
    \nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename S, S (*op)(S,\
    \ S), S (*e)()>\nstruct PersistentSegmentTree\n{\n    struct Node\n    {\n   \
    \     S     data;\n        Node *l, *r;\n\n        Node(const S &data) : data(data),\
    \ l(nullptr), r(nullptr) {}\n    };\n\n    int n;\n\n    PersistentSegmentTree()\
    \ {}\n\n    Node *build(vector<S> &v)\n    {\n        n = (int)v.size();\n   \
    \     return build(0, (int)v.size(), v);\n    }\n\n    Node *merge(Node *l, Node\
    \ *r)\n    {\n        auto t = new Node(op(l->data, r->data));\n        t->l \
    \  = l;\n        t->r   = r;\n        return t;\n    }\n\n    Node *build(int\
    \ l, int r, vector<S> &v)\n    {\n        if (l + 1 >= r)\n            return\
    \ new Node(v[l]);\n        return merge(build(l, (l + r) >> 1, v), build((l +\
    \ r) >> 1, r, v));\n    }\n\n    Node *update(int a, const S &x, Node *k, int\
    \ l, int r)\n    {\n        if (r <= a || a + 1 <= l)\n            return k;\n\
    \        else if (a <= l && r <= a + 1)\n            return new Node(x);\n   \
    \     else\n            return merge(update(a, x, k->l, l, (l + r) >> 1),\n  \
    \                       update(a, x, k->r, (l + r) >> 1, r));\n    }\n\n    Node\
    \ *update(Node *t, int k, const S &x) { return update(k, x, t, 0, n); }\n\n  \
    \  S query(int a, int b, Node *k, int l, int r)\n    {\n        if (r <= a ||\
    \ b <= l)\n            return e();\n        else if (a <= l && r <= b)\n     \
    \       return k->data;\n        else\n            return op(query(a, b, k->l,\
    \ l, (l + r) >> 1),\n                      query(a, b, k->r, (l + r) >> 1, r));\n\
    \    }\n\n    S query(Node *t, int a, int b) { return query(a, b, t, 0, n); }\n\
    };\n} // namespace cplib\n"
  code: "#include <vector>\n\n// source: https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp\n\
    \nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename S, S (*op)(S,\
    \ S), S (*e)()>\nstruct PersistentSegmentTree\n{\n    struct Node\n    {\n   \
    \     S     data;\n        Node *l, *r;\n\n        Node(const S &data) : data(data),\
    \ l(nullptr), r(nullptr) {}\n    };\n\n    int n;\n\n    PersistentSegmentTree()\
    \ {}\n\n    Node *build(vector<S> &v)\n    {\n        n = (int)v.size();\n   \
    \     return build(0, (int)v.size(), v);\n    }\n\n    Node *merge(Node *l, Node\
    \ *r)\n    {\n        auto t = new Node(op(l->data, r->data));\n        t->l \
    \  = l;\n        t->r   = r;\n        return t;\n    }\n\n    Node *build(int\
    \ l, int r, vector<S> &v)\n    {\n        if (l + 1 >= r)\n            return\
    \ new Node(v[l]);\n        return merge(build(l, (l + r) >> 1, v), build((l +\
    \ r) >> 1, r, v));\n    }\n\n    Node *update(int a, const S &x, Node *k, int\
    \ l, int r)\n    {\n        if (r <= a || a + 1 <= l)\n            return k;\n\
    \        else if (a <= l && r <= a + 1)\n            return new Node(x);\n   \
    \     else\n            return merge(update(a, x, k->l, l, (l + r) >> 1),\n  \
    \                       update(a, x, k->r, (l + r) >> 1, r));\n    }\n\n    Node\
    \ *update(Node *t, int k, const S &x) { return update(k, x, t, 0, n); }\n\n  \
    \  S query(int a, int b, Node *k, int l, int r)\n    {\n        if (r <= a ||\
    \ b <= l)\n            return e();\n        else if (a <= l && r <= b)\n     \
    \       return k->data;\n        else\n            return op(query(a, b, k->l,\
    \ l, (l + r) >> 1),\n                      query(a, b, k->r, (l + r) >> 1, r));\n\
    \    }\n\n    S query(Node *t, int a, int b) { return query(a, b, t, 0, n); }\n\
    };\n} // namespace cplib\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/persistent_segtree.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/persistent_segtree.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/persistent_segtree.hpp
- /library/cplib/data_structure/persistent_segtree.hpp.html
title: cplib/data_structure/persistent_segtree.hpp
---
