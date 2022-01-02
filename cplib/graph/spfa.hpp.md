---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/graph/graph.hpp
    title: cplib/graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/spfa.hpp\"\n\n\n\n#line 1 \"cplib/graph/graph.hpp\"\
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
    \n} // namespace cplib\n\n\n#line 5 \"cplib/graph/spfa.hpp\"\n#include <limits>\n\
    #include <queue>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename\
    \ W, W INF = numeric_limits<W>::max()>\nstruct SPFA\n{\n    Graph<W> const &g;\n\
    \    vector<W>       dist;\n    SPFA(Graph<W> const &g) : g(g) {}\n    bool operator()(int\
    \ s)\n    {\n        int n = g.size();\n        dist.assign(n, INF);\n       \
    \ vector<int>  cnt(n, 0);\n        vector<bool> inqueue(n, false);\n        queue<int>\
    \   q;\n\n        dist[s] = 0;\n        q.push(s);\n        inqueue[s] = true;\n\
    \        while (!q.empty())\n        {\n            int v = q.front();\n     \
    \       q.pop();\n            inqueue[v] = false;\n\n            for (auto edge\
    \ : g[v])\n            {\n                int to  = edge.first;\n            \
    \    int len = edge.second;\n\n                if (dist[v] + len < dist[to])\n\
    \                {\n                    dist[to] = dist[v] + len;\n          \
    \          if (!inqueue[to])\n                    {\n                        q.push(to);\n\
    \                        inqueue[to] = true;\n                        cnt[to]++;\n\
    \                        if (cnt[to] > n)\n                            return\
    \ false; // negative cycle\n                    }\n                }\n       \
    \     }\n        }\n        return true;\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_SPFA_HPP\n#define CPLIB_SPFA_HPP\n\n#include \"cplib/graph/graph.hpp\"\
    \n#include <limits>\n#include <queue>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \ntemplate <typename W, W INF = numeric_limits<W>::max()>\nstruct SPFA\n{\n  \
    \  Graph<W> const &g;\n    vector<W>       dist;\n    SPFA(Graph<W> const &g)\
    \ : g(g) {}\n    bool operator()(int s)\n    {\n        int n = g.size();\n  \
    \      dist.assign(n, INF);\n        vector<int>  cnt(n, 0);\n        vector<bool>\
    \ inqueue(n, false);\n        queue<int>   q;\n\n        dist[s] = 0;\n      \
    \  q.push(s);\n        inqueue[s] = true;\n        while (!q.empty())\n      \
    \  {\n            int v = q.front();\n            q.pop();\n            inqueue[v]\
    \ = false;\n\n            for (auto edge : g[v])\n            {\n            \
    \    int to  = edge.first;\n                int len = edge.second;\n\n       \
    \         if (dist[v] + len < dist[to])\n                {\n                 \
    \   dist[to] = dist[v] + len;\n                    if (!inqueue[to])\n       \
    \             {\n                        q.push(to);\n                       \
    \ inqueue[to] = true;\n                        cnt[to]++;\n                  \
    \      if (cnt[to] > n)\n                            return false; // negative\
    \ cycle\n                    }\n                }\n            }\n        }\n\
    \        return true;\n    }\n};\n} // namespace cplib\n\n#endif // CPLIB_SPFA_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/spfa.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/spfa.hpp
layout: document
redirect_from:
- /library/cplib/graph/spfa.hpp
- /library/cplib/graph/spfa.hpp.html
title: cplib/graph/spfa.hpp
---
