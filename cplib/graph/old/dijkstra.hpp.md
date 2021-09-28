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
  bundledCode: "#line 1 \"cplib/graph/old/dijkstra.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cmath>\n#include <limits>\n#include <set>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename T>\n\
    struct Dijkstra\n{\n    using Graph = vector<vector<pair<int, T>>>;\n    T INF\
    \       = numeric_limits<T>::max();\n\n    Graph       g;\n    int         src;\n\
    \    vector<int> p;\n    vector<T>   d;\n\n    Dijkstra(int n) : g(n), p(n), d(n){};\n\
    \    void add_edge(int u, int v, T w = 1) { g[u].emplace_back(v, w); }\n\n   \
    \ void run(int src = 0)\n    {\n        clear(src);\n\n        set<pair<T, int>>\
    \ q;\n        d[src] = 0;\n        q.emplace(d[src], src);\n        while (!q.empty())\n\
    \        {\n            int u = q.begin()->second;\n            q.erase(q.begin());\n\
    \n            for (auto [v, w] : g[u])\n            {\n                if (d[u]\
    \ + w < d[v])\n                {\n                    q.erase({d[v], v});\n  \
    \                  d[v] = d[u] + w;\n                    p[v] = u;\n         \
    \           q.emplace(d[v], v);\n                }\n            }\n        }\n\
    \    }\n\n    vector<vector<pair<int, T>>> shortest_path_DAG(void) const\n   \
    \ {\n        int                          n = g.size();\n        vector<vector<pair<int,\
    \ T>>> dag(n);\n        for (int v = 0; v < n; ++v)\n            if (auto u =\
    \ p[v]; u != -1)\n                dag[u].emplace_back(v, d[v] - d[u]);\n     \
    \   return dag;\n    }\n\n    vector<int> shortest_path(int u) const\n    {\n\
    \        if (d[u] == INF)\n            return {};\n        vector<int> path;\n\
    \n        for (int v = u; v != src; v = p[v])\n            path.push_back(v);\n\
    \        path.push_back(src);\n\n        reverse(begin(path), end(path));\n  \
    \      return path;\n    }\n    void clear(int src)\n    {\n        this->src\
    \ = src;\n        fill(begin(p), end(p), -1);\n        fill(begin(d), end(d),\
    \ INF);\n    }\n    bool is_reachable(int u) { return d[u] != INF; }\n    T  \
    \  distance(int u) { return d[u]; }\n    void operator()(int src = 0) { run(src);\
    \ }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_DIJKSTRA_HPP\n#define CPLIB_DIJKSTRA_HPP\n\n#include <algorithm>\n\
    #include <cmath>\n#include <limits>\n#include <set>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename T>\n\
    struct Dijkstra\n{\n    using Graph = vector<vector<pair<int, T>>>;\n    T INF\
    \       = numeric_limits<T>::max();\n\n    Graph       g;\n    int         src;\n\
    \    vector<int> p;\n    vector<T>   d;\n\n    Dijkstra(int n) : g(n), p(n), d(n){};\n\
    \    void add_edge(int u, int v, T w = 1) { g[u].emplace_back(v, w); }\n\n   \
    \ void run(int src = 0)\n    {\n        clear(src);\n\n        set<pair<T, int>>\
    \ q;\n        d[src] = 0;\n        q.emplace(d[src], src);\n        while (!q.empty())\n\
    \        {\n            int u = q.begin()->second;\n            q.erase(q.begin());\n\
    \n            for (auto [v, w] : g[u])\n            {\n                if (d[u]\
    \ + w < d[v])\n                {\n                    q.erase({d[v], v});\n  \
    \                  d[v] = d[u] + w;\n                    p[v] = u;\n         \
    \           q.emplace(d[v], v);\n                }\n            }\n        }\n\
    \    }\n\n    vector<vector<pair<int, T>>> shortest_path_DAG(void) const\n   \
    \ {\n        int                          n = g.size();\n        vector<vector<pair<int,\
    \ T>>> dag(n);\n        for (int v = 0; v < n; ++v)\n            if (auto u =\
    \ p[v]; u != -1)\n                dag[u].emplace_back(v, d[v] - d[u]);\n     \
    \   return dag;\n    }\n\n    vector<int> shortest_path(int u) const\n    {\n\
    \        if (d[u] == INF)\n            return {};\n        vector<int> path;\n\
    \n        for (int v = u; v != src; v = p[v])\n            path.push_back(v);\n\
    \        path.push_back(src);\n\n        reverse(begin(path), end(path));\n  \
    \      return path;\n    }\n    void clear(int src)\n    {\n        this->src\
    \ = src;\n        fill(begin(p), end(p), -1);\n        fill(begin(d), end(d),\
    \ INF);\n    }\n    bool is_reachable(int u) { return d[u] != INF; }\n    T  \
    \  distance(int u) { return d[u]; }\n    void operator()(int src = 0) { run(src);\
    \ }\n};\n} // namespace cplib\n\n#endif // CPLIB_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/old/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/old/dijkstra.hpp
layout: document
redirect_from:
- /library/cplib/graph/old/dijkstra.hpp
- /library/cplib/graph/old/dijkstra.hpp.html
title: cplib/graph/old/dijkstra.hpp
---
