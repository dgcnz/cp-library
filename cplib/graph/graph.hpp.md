---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/graph/bfs01.hpp
    title: cplib/graph/bfs01.hpp
  - icon: ':warning:'
    path: cplib/graph/dijkstra.hpp
    title: cplib/graph/dijkstra.hpp
  - icon: ':warning:'
    path: cplib/graph/gridgraph.hpp
    title: cplib/graph/gridgraph.hpp
  - icon: ':warning:'
    path: cplib/graph/lca.hpp
    title: cplib/graph/lca.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/graph.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing\
    \ namespace std;\n\ntemplate <typename W>\nstruct Graph\n{\n    using adj_list\
    \ = vector<pair<int, W>>;\n    vector<adj_list> g;\n\n    Graph(int n) : g(n)\
    \ {}\n\n    size_t size() const { return g.size(); }\n    void   add_edge(int\
    \ u, int v) { g[u].emplace_back(v, W()); }\n    void   add_edge(int u, int v,\
    \ W weights) { g[u].emplace_back(v, weights); }\n\n    adj_list &operator[](int\
    \ u) { return g[u]; }\n    adj_list  operator[](int u) const { return g[u]; }\n\
    \n    vector<int> neighbors(int u) const\n    {\n        vector<int> ans(g[u].size());\n\
    \        transform(\n            all(g[u]), begin(ans), [](pair<int, W> p) { return\
    \ p.first; });\n        return ans;\n    }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n    using adj_list\
    \ = vector<int>;\n    vector<adj_list> g;\n\n    Graph(int n) : g(n) {}\n\n  \
    \  size_t size() const { return g.size(); }\n    void   add_edge(int u, int v)\
    \ { g[u].emplace_back(v); }\n\n    adj_list &operator[](int u) { return g[u];\
    \ }\n    adj_list  operator[](int u) const { return g[u]; }\n\n    vector<int>\
    \ neighbors(int u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_GRAPH_HPP\n#define CPLIB_GRAPH_HPP\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <typename W>\nstruct Graph\n{\n    using adj_list\
    \ = vector<pair<int, W>>;\n    vector<adj_list> g;\n\n    Graph(int n) : g(n)\
    \ {}\n\n    size_t size() const { return g.size(); }\n    void   add_edge(int\
    \ u, int v) { g[u].emplace_back(v, W()); }\n    void   add_edge(int u, int v,\
    \ W weights) { g[u].emplace_back(v, weights); }\n\n    adj_list &operator[](int\
    \ u) { return g[u]; }\n    adj_list  operator[](int u) const { return g[u]; }\n\
    \n    vector<int> neighbors(int u) const\n    {\n        vector<int> ans(g[u].size());\n\
    \        transform(\n            all(g[u]), begin(ans), [](pair<int, W> p) { return\
    \ p.first; });\n        return ans;\n    }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n    using adj_list\
    \ = vector<int>;\n    vector<adj_list> g;\n\n    Graph(int n) : g(n) {}\n\n  \
    \  size_t size() const { return g.size(); }\n    void   add_edge(int u, int v)\
    \ { g[u].emplace_back(v); }\n\n    adj_list &operator[](int u) { return g[u];\
    \ }\n    adj_list  operator[](int u) const { return g[u]; }\n\n    vector<int>\
    \ neighbors(int u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_GRAPH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/graph.hpp
  requiredBy:
  - cplib/graph/dijkstra.hpp
  - cplib/graph/bfs01.hpp
  - cplib/graph/lca.hpp
  - cplib/graph/gridgraph.hpp
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/graph.hpp
layout: document
redirect_from:
- /library/cplib/graph/graph.hpp
- /library/cplib/graph/graph.hpp.html
title: cplib/graph/graph.hpp
---
