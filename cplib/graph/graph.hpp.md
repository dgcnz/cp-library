---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/graph/bfs01.hpp
    title: cplib/graph/bfs01.hpp
  - icon: ':warning:'
    path: cplib/graph/blockcut.hpp
    title: cplib/graph/blockcut.hpp
  - icon: ':warning:'
    path: cplib/graph/dijkstra.hpp
    title: cplib/graph/dijkstra.hpp
  - icon: ':warning:'
    path: cplib/graph/gridgraph.hpp
    title: cplib/graph/gridgraph.hpp
  - icon: ':warning:'
    path: cplib/graph/lca.hpp
    title: cplib/graph/lca.hpp
  - icon: ':warning:'
    path: cplib/graph/pathqueries.hpp
    title: cplib/graph/pathqueries.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/graph.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing\
    \ namespace std;\n\ntemplate <typename W>\nstruct Graph\n{\n    using adj_list\
    \ = vector<pair<int, W>>;\n    vector<adj_list> g;\n\n    Graph(int n = 0) : g(n)\
    \ {}\n\n    size_t size() const { return g.size(); }\n    int    vertex(pair<int,\
    \ W> e) const { return e.first; }\n    void   add_edge(int u, int v) { g[u].emplace_back(v,\
    \ W()); }\n    void   add_edge(int u, int v, W weights) { g[u].emplace_back(v,\
    \ weights); }\n    void   add_undirected_edge(int u, int v)\n    {\n        g[u].emplace_back(v,\
    \ W());\n        g[v].emplace_back(u, W());\n    }\n    void add_undirected_edge(int\
    \ u, int v, W weights)\n    {\n        g[u].emplace_back(v, weights);\n      \
    \  g[v].emplace_back(u, weights);\n    }\n    int add_node(void)\n    {\n    \
    \    g.push_back({});\n        return g.size() - 1;\n    }\n\n    adj_list &operator[](int\
    \ u) { return g[u]; }\n    adj_list  operator[](int u) const { return g[u]; }\n\
    \n    typename vector<adj_list>::iterator begin() { return g.begin(); };\n   \
    \ typename vector<adj_list>::iterator end() { return g.end(); }\n\n    typename\
    \ vector<adj_list>::const_iterator begin() const\n    {\n        return g.begin();\n\
    \    };\n    typename vector<adj_list>::const_iterator end() const { return g.end();\
    \ }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n    using adj_list = vector<int>;\n\
    \    vector<adj_list> g;\n\n    Graph(int n = 0) : g(n) {}\n\n    size_t size()\
    \ const { return g.size(); }\n    int    vertex(int e) const { return e; }\n \
    \   void   add_edge(int u, int v) { g[u].emplace_back(v); }\n    void   add_undirected_edge(int\
    \ u, int v)\n    {\n        g[u].push_back(v);\n        g[v].push_back(u);\n \
    \   }\n    int add_node(void)\n    {\n        g.push_back({});\n        return\
    \ g.size() - 1;\n    }\n\n    adj_list &operator[](int u) { return g[u]; }\n \
    \   adj_list  operator[](int u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n\n    typename vector<adj_list>::const_iterator begin()\
    \ const\n    {\n        return g.begin();\n    };\n    typename vector<adj_list>::const_iterator\
    \ end() const { return g.end(); }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_GRAPH_HPP\n#define CPLIB_GRAPH_HPP\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <typename W>\nstruct Graph\n{\n    using adj_list\
    \ = vector<pair<int, W>>;\n    vector<adj_list> g;\n\n    Graph(int n = 0) : g(n)\
    \ {}\n\n    size_t size() const { return g.size(); }\n    int    vertex(pair<int,\
    \ W> e) const { return e.first; }\n    void   add_edge(int u, int v) { g[u].emplace_back(v,\
    \ W()); }\n    void   add_edge(int u, int v, W weights) { g[u].emplace_back(v,\
    \ weights); }\n    void   add_undirected_edge(int u, int v)\n    {\n        g[u].emplace_back(v,\
    \ W());\n        g[v].emplace_back(u, W());\n    }\n    void add_undirected_edge(int\
    \ u, int v, W weights)\n    {\n        g[u].emplace_back(v, weights);\n      \
    \  g[v].emplace_back(u, weights);\n    }\n    int add_node(void)\n    {\n    \
    \    g.push_back({});\n        return g.size() - 1;\n    }\n\n    adj_list &operator[](int\
    \ u) { return g[u]; }\n    adj_list  operator[](int u) const { return g[u]; }\n\
    \n    typename vector<adj_list>::iterator begin() { return g.begin(); };\n   \
    \ typename vector<adj_list>::iterator end() { return g.end(); }\n\n    typename\
    \ vector<adj_list>::const_iterator begin() const\n    {\n        return g.begin();\n\
    \    };\n    typename vector<adj_list>::const_iterator end() const { return g.end();\
    \ }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n    using adj_list = vector<int>;\n\
    \    vector<adj_list> g;\n\n    Graph(int n = 0) : g(n) {}\n\n    size_t size()\
    \ const { return g.size(); }\n    int    vertex(int e) const { return e; }\n \
    \   void   add_edge(int u, int v) { g[u].emplace_back(v); }\n    void   add_undirected_edge(int\
    \ u, int v)\n    {\n        g[u].push_back(v);\n        g[v].push_back(u);\n \
    \   }\n    int add_node(void)\n    {\n        g.push_back({});\n        return\
    \ g.size() - 1;\n    }\n\n    adj_list &operator[](int u) { return g[u]; }\n \
    \   adj_list  operator[](int u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator\
    \ begin() { return g.begin(); };\n    typename vector<adj_list>::iterator end()\
    \ { return g.end(); }\n\n    typename vector<adj_list>::const_iterator begin()\
    \ const\n    {\n        return g.begin();\n    };\n    typename vector<adj_list>::const_iterator\
    \ end() const { return g.end(); }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_GRAPH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/graph.hpp
  requiredBy:
  - cplib/graph/pathqueries.hpp
  - cplib/graph/lca.hpp
  - cplib/graph/gridgraph.hpp
  - cplib/graph/bfs01.hpp
  - cplib/graph/dijkstra.hpp
  - cplib/graph/blockcut.hpp
  timestamp: '2021-10-21 16:39:26-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/graph.hpp
layout: document
redirect_from:
- /library/cplib/graph/graph.hpp
- /library/cplib/graph/graph.hpp.html
title: cplib/graph/graph.hpp
---
