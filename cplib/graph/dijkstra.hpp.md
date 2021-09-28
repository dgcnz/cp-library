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
  bundledCode: "#line 1 \"cplib/graph/dijkstra.hpp\"\n\n\n\n#line 1 \"cplib/graph/graph.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename W>\n\
    struct Graph\n{\n    using adj_list = vector<pair<int, W>>;\n    vector<adj_list>\
    \ g;\n\n    Graph(int n) : g(n) {}\n\n    size_t size() const { return g.size();\
    \ }\n    void   add_edge(int u, int v) { g[u].emplace_back(v, W()); }\n    void\
    \   add_edge(int u, int v, W weights) { g[u].emplace_back(v, weights); }\n\n \
    \   adj_list &operator[](int u) { return g[u]; }\n    adj_list  operator[](int\
    \ u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator begin()\
    \ { return g.begin(); };\n    typename vector<adj_list>::iterator end() { return\
    \ g.end(); }\n};\n\ntemplate <>\nstruct Graph<void>\n{\n    using adj_list = vector<int>;\n\
    \    vector<adj_list> g;\n\n    Graph(int n) : g(n) {}\n\n    size_t size() const\
    \ { return g.size(); }\n    void   add_edge(int u, int v) { g[u].emplace_back(v);\
    \ }\n\n    adj_list &operator[](int u) { return g[u]; }\n    adj_list  operator[](int\
    \ u) const { return g[u]; }\n\n    typename vector<adj_list>::iterator begin()\
    \ { return g.begin(); };\n    typename vector<adj_list>::iterator end() { return\
    \ g.end(); }\n};\n\n} // namespace cplib\n\n\n#line 6 \"cplib/graph/dijkstra.hpp\"\
    \n#include <cmath>\n#include <limits>\n#include <set>\n#line 11 \"cplib/graph/dijkstra.hpp\"\
    \n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename W, W INF =\
    \ numeric_limits<W>::max()>\nstruct Dijkstra\n{\n    Graph<W> const &g;\n    int\
    \             src;\n    vector<int>     p;\n    vector<W>       d;\n\n    Dijkstra(Graph<W>\
    \ const &g) : g(g), p(g.size()), d(g.size()){};\n    void run(int src = 0)\n \
    \   {\n        this->src = src;\n        fill(begin(p), end(p), -1);\n       \
    \ fill(begin(d), end(d), INF);\n\n        set<pair<W, int>> q;\n        d[src]\
    \ = 0;\n        q.emplace(d[src], src);\n        while (!q.empty())\n        {\n\
    \            int u = q.begin()->second;\n            q.erase(q.begin());\n\n \
    \           for (auto [v, w] : g[u])\n            {\n                if (d[u]\
    \ + w < d[v])\n                {\n                    q.erase({d[v], v});\n  \
    \                  d[v] = d[u] + w;\n                    p[v] = u;\n         \
    \           q.emplace(d[v], v);\n                }\n            }\n        }\n\
    \    }\n\n    Graph<W> shortest_path_DAG(void) const\n    {\n        int     \
    \ n = g.size();\n        Graph<W> dag(n);\n        for (int v = 0; v < n; ++v)\n\
    \            if (auto u = p[v]; u != -1)\n                dag.add_edge(u, v, d[v]\
    \ - d[u]);\n        return dag;\n    }\n\n    vector<int> shortest_path(int u)\
    \ const\n    {\n        if (d[u] == INF)\n            return {};\n        vector<int>\
    \ path;\n\n        for (int v = u; v != src; v = p[v])\n            path.push_back(v);\n\
    \        path.push_back(src);\n\n        reverse(begin(path), end(path));\n  \
    \      return path;\n    }\n    bool is_reachable(int u) { return d[u] != INF;\
    \ }\n    W    distance(int u) { return d[u]; }\n    void operator()(int src =\
    \ 0) { run(src); }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_DIJKSTRA_HPP\n#define CPLIB_DIJKSTRA_HPP\n\n#include \"cplib/graph/graph.hpp\"\
    \n#include <algorithm>\n#include <cmath>\n#include <limits>\n#include <set>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \ntemplate <typename W, W INF = numeric_limits<W>::max()>\nstruct Dijkstra\n{\n\
    \    Graph<W> const &g;\n    int             src;\n    vector<int>     p;\n  \
    \  vector<W>       d;\n\n    Dijkstra(Graph<W> const &g) : g(g), p(g.size()),\
    \ d(g.size()){};\n    void run(int src = 0)\n    {\n        this->src = src;\n\
    \        fill(begin(p), end(p), -1);\n        fill(begin(d), end(d), INF);\n\n\
    \        set<pair<W, int>> q;\n        d[src] = 0;\n        q.emplace(d[src],\
    \ src);\n        while (!q.empty())\n        {\n            int u = q.begin()->second;\n\
    \            q.erase(q.begin());\n\n            for (auto [v, w] : g[u])\n   \
    \         {\n                if (d[u] + w < d[v])\n                {\n       \
    \             q.erase({d[v], v});\n                    d[v] = d[u] + w;\n    \
    \                p[v] = u;\n                    q.emplace(d[v], v);\n        \
    \        }\n            }\n        }\n    }\n\n    Graph<W> shortest_path_DAG(void)\
    \ const\n    {\n        int      n = g.size();\n        Graph<W> dag(n);\n   \
    \     for (int v = 0; v < n; ++v)\n            if (auto u = p[v]; u != -1)\n \
    \               dag.add_edge(u, v, d[v] - d[u]);\n        return dag;\n    }\n\
    \n    vector<int> shortest_path(int u) const\n    {\n        if (d[u] == INF)\n\
    \            return {};\n        vector<int> path;\n\n        for (int v = u;\
    \ v != src; v = p[v])\n            path.push_back(v);\n        path.push_back(src);\n\
    \n        reverse(begin(path), end(path));\n        return path;\n    }\n    bool\
    \ is_reachable(int u) { return d[u] != INF; }\n    W    distance(int u) { return\
    \ d[u]; }\n    void operator()(int src = 0) { run(src); }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_DIJKSTRA_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-09-28 13:06:15-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/cplib/graph/dijkstra.hpp
- /library/cplib/graph/dijkstra.hpp.html
title: cplib/graph/dijkstra.hpp
---
