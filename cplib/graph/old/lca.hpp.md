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
  bundledCode: "#line 1 \"cplib/graph/old/lca.hpp\"\n\n\n\n#include <cmath>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\nstruct LCA\n{\n    using\
    \ Tree = vector<vector<int>>;\n\n    Tree                g;\n    vector<vector<int>>\
    \ up;\n    vector<int>         tin, tout;\n\n    LCA(int n) : g(n), up(n, vector<int>(log2(n)\
    \ + 2)), tin(n), tout(n) {}\n\n    void operator()(void)\n    {\n        int timer\
    \ = 0;\n        preprocess(0, 0, timer);\n    }\n\n    void add_edge(int u, int\
    \ v) { g[u].push_back(v), g[v].push_back(u); }\n\n    void preprocess(int u, int\
    \ p, int &timer)\n    {\n        tin[u]   = ++timer;\n        up[u][0] = p;\n\
    \        for (int i = 1, height = up[0].size(); i < height; ++i)\n           \
    \ up[u][i] = up[up[u][i - 1]][i - 1];\n\n        for (int v : g[u])\n        \
    \    if (v != p)\n                preprocess(v, u, timer);\n\n        tout[u]\
    \ = ++timer;\n    }\n\n    bool is_ancestor(int u, int v) const\n    {\n     \
    \   return tin[u] <= tin[v] and tout[u] >= tout[v];\n    }\n\n    int ancestor(int\
    \ u, int k) const\n    {\n        int i;\n        while (k)\n        {\n     \
    \       i = 8 * sizeof(k) - __builtin_clz(k) - 1;\n            u = up[u][i];\n\
    \            k ^= 1LL << i;\n        }\n        if (u == 0)\n            return\
    \ -1;\n        return u;\n    }\n\n    int lca(int u, int v) const\n    {\n  \
    \      if (is_ancestor(u, v))\n            return u;\n        if (is_ancestor(v,\
    \ u))\n            return v;\n        for (int i = up[0].size() - 1; i >= 0; --i)\n\
    \            if (!is_ancestor(up[u][i], v))\n                u = up[u][i];\n \
    \       return up[u][0];\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_LCA_HPP\n#define CPLIB_LCA_HPP\n\n#include <cmath>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\nstruct LCA\n{\n    using\
    \ Tree = vector<vector<int>>;\n\n    Tree                g;\n    vector<vector<int>>\
    \ up;\n    vector<int>         tin, tout;\n\n    LCA(int n) : g(n), up(n, vector<int>(log2(n)\
    \ + 2)), tin(n), tout(n) {}\n\n    void operator()(void)\n    {\n        int timer\
    \ = 0;\n        preprocess(0, 0, timer);\n    }\n\n    void add_edge(int u, int\
    \ v) { g[u].push_back(v), g[v].push_back(u); }\n\n    void preprocess(int u, int\
    \ p, int &timer)\n    {\n        tin[u]   = ++timer;\n        up[u][0] = p;\n\
    \        for (int i = 1, height = up[0].size(); i < height; ++i)\n           \
    \ up[u][i] = up[up[u][i - 1]][i - 1];\n\n        for (int v : g[u])\n        \
    \    if (v != p)\n                preprocess(v, u, timer);\n\n        tout[u]\
    \ = ++timer;\n    }\n\n    bool is_ancestor(int u, int v) const\n    {\n     \
    \   return tin[u] <= tin[v] and tout[u] >= tout[v];\n    }\n\n    int ancestor(int\
    \ u, int k) const\n    {\n        int i;\n        while (k)\n        {\n     \
    \       i = 8 * sizeof(k) - __builtin_clz(k) - 1;\n            u = up[u][i];\n\
    \            k ^= 1LL << i;\n        }\n        if (u == 0)\n            return\
    \ -1;\n        return u;\n    }\n\n    int lca(int u, int v) const\n    {\n  \
    \      if (is_ancestor(u, v))\n            return u;\n        if (is_ancestor(v,\
    \ u))\n            return v;\n        for (int i = up[0].size() - 1; i >= 0; --i)\n\
    \            if (!is_ancestor(up[u][i], v))\n                u = up[u][i];\n \
    \       return up[u][0];\n    }\n};\n} // namespace cplib\n\n#endif // CPLIB_LCA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/old/lca.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/old/lca.hpp
layout: document
redirect_from:
- /library/cplib/graph/old/lca.hpp
- /library/cplib/graph/old/lca.hpp.html
title: cplib/graph/old/lca.hpp
---
