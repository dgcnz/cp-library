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
  bundledCode: "#line 1 \"cplib/graph/bfs01.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cplib/graph/graph>\n#include <deque>\n#include <limits>\n#include <vector>\n\
    \nnamespace cplib\n{\nusing namespace std;\ntemplate <template <typename> class\
    \ G,\n          typename W,\n          W INF = numeric_limits<W>::max()>\nstruct\
    \ BFS01\n{\n    G<W> const &g;\n    int         src;\n    vector<int> p;\n   \
    \ vector<W>   d;\n    BFS01(G<W> const &g) : g(g), p(g.size()), d(g.size()){};\n\
    \    void run(int src = 0)\n    {\n        this->src = src;\n        fill(begin(p),\
    \ end(p), -1);\n        fill(begin(d), end(d), INF);\n\n        deque<int> q;\n\
    \        d[src] = 0;\n        q.push_front(src);\n        while (!q.empty())\n\
    \        {\n            int u = q.front();\n            q.pop_front();\n\n   \
    \         for (auto [v, w] : g[u])\n            {\n                if (d[u] +\
    \ w < d[v])\n                {\n                    d[v] = d[u] + w;\n       \
    \             p[v] = u;\n                    if (w == 1)\n                   \
    \     q.push_back(v);\n                    else\n                        q.push_front(v);\n\
    \                }\n            }\n        }\n    }\n    Graph<W> shortest_path_DAG(void)\
    \ const\n    {\n        int      n = g.size();\n        Graph<W> dag(n);\n   \
    \     for (int v = 0; v < n; ++v)\n            if (auto u = p[v]; u != -1)\n \
    \               dag.add_edge(u, v, d[v] - d[u]);\n        return dag;\n    }\n\
    \n    vector<int> shortest_path(int u) const\n    {\n        if (d[u] == INF)\n\
    \            return {};\n        vector<int> path;\n\n        for (int v = u;\
    \ v != src; v = p[v])\n            path.push_back(v);\n        path.push_back(src);\n\
    \n        reverse(begin(path), end(path));\n        return path;\n    }\n    bool\
    \ is_reachable(int u) { return d[u] != INF; }\n    W    distance(int u) { return\
    \ d[u]; }\n    void operator()(int src = 0) { run(src); }\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_BFS01_HPP\n#define CPLIB_BFS01_HPP\n\n#include <algorithm>\n\
    #include <cplib/graph/graph>\n#include <deque>\n#include <limits>\n#include <vector>\n\
    \nnamespace cplib\n{\nusing namespace std;\ntemplate <template <typename> class\
    \ G,\n          typename W,\n          W INF = numeric_limits<W>::max()>\nstruct\
    \ BFS01\n{\n    G<W> const &g;\n    int         src;\n    vector<int> p;\n   \
    \ vector<W>   d;\n    BFS01(G<W> const &g) : g(g), p(g.size()), d(g.size()){};\n\
    \    void run(int src = 0)\n    {\n        this->src = src;\n        fill(begin(p),\
    \ end(p), -1);\n        fill(begin(d), end(d), INF);\n\n        deque<int> q;\n\
    \        d[src] = 0;\n        q.push_front(src);\n        while (!q.empty())\n\
    \        {\n            int u = q.front();\n            q.pop_front();\n\n   \
    \         for (auto [v, w] : g[u])\n            {\n                if (d[u] +\
    \ w < d[v])\n                {\n                    d[v] = d[u] + w;\n       \
    \             p[v] = u;\n                    if (w == 1)\n                   \
    \     q.push_back(v);\n                    else\n                        q.push_front(v);\n\
    \                }\n            }\n        }\n    }\n    Graph<W> shortest_path_DAG(void)\
    \ const\n    {\n        int      n = g.size();\n        Graph<W> dag(n);\n   \
    \     for (int v = 0; v < n; ++v)\n            if (auto u = p[v]; u != -1)\n \
    \               dag.add_edge(u, v, d[v] - d[u]);\n        return dag;\n    }\n\
    \n    vector<int> shortest_path(int u) const\n    {\n        if (d[u] == INF)\n\
    \            return {};\n        vector<int> path;\n\n        for (int v = u;\
    \ v != src; v = p[v])\n            path.push_back(v);\n        path.push_back(src);\n\
    \n        reverse(begin(path), end(path));\n        return path;\n    }\n    bool\
    \ is_reachable(int u) { return d[u] != INF; }\n    W    distance(int u) { return\
    \ d[u]; }\n    void operator()(int src = 0) { run(src); }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_BFS01_HPPk\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/bfs01.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/bfs01.hpp
layout: document
redirect_from:
- /library/cplib/graph/bfs01.hpp
- /library/cplib/graph/bfs01.hpp.html
title: cplib/graph/bfs01.hpp
---
