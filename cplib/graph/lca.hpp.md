---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/graph/graph.hpp
    title: cplib/graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/graph/pathqueries.hpp
    title: cplib/graph/pathqueries.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/lca.hpp\"\n\n\n\n#line 1 \"cplib/graph/graph.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename W>\n\
    struct Graph\n{\n    using adj_list = vector<pair<int, W>>;\n    vector<adj_list>\
    \ g;\n\n    Graph(int n = 0) : g(n) {}\n\n    size_t size() const { return g.size();\
    \ }\n    int    vertex(pair<int, W> e) const { return e.first; }\n    void   add_edge(int\
    \ u, int v) { g[u].emplace_back(v, W()); }\n    void   add_edge(int u, int v,\
    \ W weights) { g[u].emplace_back(v, weights); }\n    void   add_undirected_edge(int\
    \ u, int v)\n    {\n        g[u].emplace_back(v, W());\n        g[v].emplace_back(u,\
    \ W());\n    }\n    void add_undirected_edge(int u, int v, W weights)\n    {\n\
    \        g[u].emplace_back(v, weights);\n        g[v].emplace_back(u, weights);\n\
    \    }\n    int add_node(void)\n    {\n        g.push_back({});\n        return\
    \ g.size() - 1;\n    }\n\n    adj_list &operator[](int u) { return g[u]; }\n \
    \   adj_list  operator[](int u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n\n    typename vector<adj_list>::const_iterator begin()\
    \ const\n    {\n        return g.begin();\n    };\n    typename vector<adj_list>::const_iterator\
    \ end() const { return g.end(); }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n\
    \    using adj_list = vector<int>;\n    vector<adj_list> g;\n\n    Graph(int n\
    \ = 0) : g(n) {}\n\n    size_t size() const { return g.size(); }\n    int    vertex(int\
    \ e) const { return e; }\n    void   add_edge(int u, int v) { g[u].emplace_back(v);\
    \ }\n    void   add_undirected_edge(int u, int v)\n    {\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    int add_node(void)\n    {\n        g.push_back({});\n\
    \        return g.size() - 1;\n    }\n\n    adj_list &operator[](int u) { return\
    \ g[u]; }\n    adj_list  operator[](int u) const { return g[u]; }\n\n    typename\
    \ vector<adj_list>::iterator begin() { return g.begin(); };\n    typename vector<adj_list>::iterator\
    \ end() { return g.end(); }\n\n    typename vector<adj_list>::const_iterator begin()\
    \ const\n    {\n        return g.begin();\n    };\n    typename vector<adj_list>::const_iterator\
    \ end() const { return g.end(); }\n};\n\nusing UndirectedGraph = Graph<void>;\n\
    \n} // namespace cplib\n\n\n#line 5 \"cplib/graph/lca.hpp\"\n#include <cmath>\n\
    #include <functional>\n#line 8 \"cplib/graph/lca.hpp\"\n\nnamespace cplib\n{\n\
    using namespace std;\n\ntemplate <typename W>\nstruct LCA\n{\n    Graph<W> const\
    \ &    g;\n    vector<vector<int>> up;\n    vector<int>         tin, tout;\n\n\
    \    LCA(Graph<W> const &g)\n        : g(g), up(g.size(), vector<int>(log2(g.size())\
    \ + 2)), tin(g.size()),\n          tout(g.size())\n    {\n        int        \
    \              timer = 0, n = g.size();\n        function<void(int, int)> dfs\
    \ = [&](int u, int p)\n        {\n            tin[u]   = ++timer;\n          \
    \  up[u][0] = p;\n            for (int i = 1, height = up[0].size(); i < height;\
    \ ++i)\n                up[u][i] = up[up[u][i - 1]][i - 1];\n\n            for\
    \ (auto vw : g[u])\n                if (g.vertex(vw) != p)\n                 \
    \   dfs(g.vertex(vw), u);\n\n            tout[u] = ++timer;\n        };\n\n  \
    \      for (int u = 0; u < n; ++u)\n            if (tin[u] == 0)\n           \
    \     dfs(u, u);\n    }\n\n    bool is_ancestor(int u, int v) const\n    {\n \
    \       return tin[u] <= tin[v] and tout[u] >= tout[v];\n    }\n\n    int ancestor(int\
    \ u, int k) const\n    {\n        int i;\n        while (k)\n        {\n     \
    \       i = 8 * sizeof(k) - __builtin_clz(k) - 1;\n            u = up[u][i];\n\
    \            k ^= 1LL << i;\n        }\n        if (up[u][0] == u)\n         \
    \   return -1;\n        return u;\n    }\n\n    int lca(int u, int v) const\n\
    \    {\n        if (is_ancestor(u, v))\n            return u;\n        if (is_ancestor(v,\
    \ u))\n            return v;\n        for (int i = up[0].size() - 1; i >= 0; --i)\n\
    \            if (!is_ancestor(up[u][i], v))\n                u = up[u][i];\n \
    \       return up[u][0];\n    }\n\n    int operator()(int u, int v) const { return\
    \ lca(u, v); }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_LCA_HPP\n#define CPLIB_LCA_HPP\n\n#include \"cplib/graph/graph.hpp\"\
    \n#include <cmath>\n#include <functional>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <typename W>\nstruct LCA\n{\n    Graph<W>\
    \ const &    g;\n    vector<vector<int>> up;\n    vector<int>         tin, tout;\n\
    \n    LCA(Graph<W> const &g)\n        : g(g), up(g.size(), vector<int>(log2(g.size())\
    \ + 2)), tin(g.size()),\n          tout(g.size())\n    {\n        int        \
    \              timer = 0, n = g.size();\n        function<void(int, int)> dfs\
    \ = [&](int u, int p)\n        {\n            tin[u]   = ++timer;\n          \
    \  up[u][0] = p;\n            for (int i = 1, height = up[0].size(); i < height;\
    \ ++i)\n                up[u][i] = up[up[u][i - 1]][i - 1];\n\n            for\
    \ (auto vw : g[u])\n                if (g.vertex(vw) != p)\n                 \
    \   dfs(g.vertex(vw), u);\n\n            tout[u] = ++timer;\n        };\n\n  \
    \      for (int u = 0; u < n; ++u)\n            if (tin[u] == 0)\n           \
    \     dfs(u, u);\n    }\n\n    bool is_ancestor(int u, int v) const\n    {\n \
    \       return tin[u] <= tin[v] and tout[u] >= tout[v];\n    }\n\n    int ancestor(int\
    \ u, int k) const\n    {\n        int i;\n        while (k)\n        {\n     \
    \       i = 8 * sizeof(k) - __builtin_clz(k) - 1;\n            u = up[u][i];\n\
    \            k ^= 1LL << i;\n        }\n        if (up[u][0] == u)\n         \
    \   return -1;\n        return u;\n    }\n\n    int lca(int u, int v) const\n\
    \    {\n        if (is_ancestor(u, v))\n            return u;\n        if (is_ancestor(v,\
    \ u))\n            return v;\n        for (int i = up[0].size() - 1; i >= 0; --i)\n\
    \            if (!is_ancestor(up[u][i], v))\n                u = up[u][i];\n \
    \       return up[u][0];\n    }\n\n    int operator()(int u, int v) const { return\
    \ lca(u, v); }\n};\n} // namespace cplib\n\n#endif // CPLIB_LCA_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/lca.hpp
  requiredBy:
  - cplib/graph/pathqueries.hpp
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/lca.hpp
layout: document
redirect_from:
- /library/cplib/graph/lca.hpp
- /library/cplib/graph/lca.hpp.html
title: cplib/graph/lca.hpp
---
