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
    document_title: Computes one iteration of the dfs in a topological sorting.
    links: []
  bundledCode: "#line 1 \"cplib/graph/toposort.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cplib/graph/graph>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ cplib\n{\nusing namespace std;\n\n/*\n * @brief Computes one iteration of the\
    \ dfs in a topological sorting.\n * @param g Graph\n * @param u Source node\n\
    \ * @param order Reverse ordering\n * @param color n-sized vector where 0:unvisited,\
    \ 1:visiting, 2:visited\n * @note O(n + m)\n */\ntemplate <typename T>\nbool toposort_dfs(Graph<T>\
    \ const &g,\n                  int             u,\n                  vector<int>\
    \    &order,\n                  vector<int>    &color)\n{\n    if (color[u] ==\
    \ 1) // Cycle\n        return false;\n    if (color[u] == 2) // Intersection\n\
    \        return true;\n\n    color[u] = 1;\n    for (auto edge : g[u])\n     \
    \   if (not toposort_dfs(g, g.vertex(edge), order, color))\n            return\
    \ false;\n    color[u] = 2;\n    order.push_back(u);\n    return true;\n}\n\n\
    /*\n * @brief Computes the topological sorting of Graph g.\n * @param g Graph\n\
    \ * @note O(n + m)\n */\ntemplate <typename T>\nvector<int> toposort(Graph<T>\
    \ const &g)\n{\n    int         n = g.size();\n    vector<int> order, color(n,\
    \ false);\n    for (int u = 0; u < n; ++u)\n        if (not color[u] and not toposort_dfs(g,\
    \ u, order, color))\n            return {};\n    reverse(order.begin(), order.end());\n\
    \    return order;\n}\n\n/*\n * @brief Computes the topological sorting of the\
    \ nodes reachable from src.\n * @param g Graph\n * @param src Source node\n *\
    \ @note O(n + m)\n */\ntemplate <typename T>\nvector<int> toposort(Graph<T> const\
    \ &g, int src)\n{\n    int         n = g.size();\n    vector<int> order, color(n,\
    \ false);\n    if (not toposort_dfs(g, src, order, color))\n        return {};\n\
    \    reverse(order.begin(), order.end());\n    return order;\n}\n\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_TOPOSORT_HPP\n#define CPLIB_TOPOSORT_HPP\n\n#include <algorithm>\n\
    #include <cplib/graph/graph>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ cplib\n{\nusing namespace std;\n\n/*\n * @brief Computes one iteration of the\
    \ dfs in a topological sorting.\n * @param g Graph\n * @param u Source node\n\
    \ * @param order Reverse ordering\n * @param color n-sized vector where 0:unvisited,\
    \ 1:visiting, 2:visited\n * @note O(n + m)\n */\ntemplate <typename T>\nbool toposort_dfs(Graph<T>\
    \ const &g,\n                  int             u,\n                  vector<int>\
    \    &order,\n                  vector<int>    &color)\n{\n    if (color[u] ==\
    \ 1) // Cycle\n        return false;\n    if (color[u] == 2) // Intersection\n\
    \        return true;\n\n    color[u] = 1;\n    for (auto edge : g[u])\n     \
    \   if (not toposort_dfs(g, g.vertex(edge), order, color))\n            return\
    \ false;\n    color[u] = 2;\n    order.push_back(u);\n    return true;\n}\n\n\
    /*\n * @brief Computes the topological sorting of Graph g.\n * @param g Graph\n\
    \ * @note O(n + m)\n */\ntemplate <typename T>\nvector<int> toposort(Graph<T>\
    \ const &g)\n{\n    int         n = g.size();\n    vector<int> order, color(n,\
    \ false);\n    for (int u = 0; u < n; ++u)\n        if (not color[u] and not toposort_dfs(g,\
    \ u, order, color))\n            return {};\n    reverse(order.begin(), order.end());\n\
    \    return order;\n}\n\n/*\n * @brief Computes the topological sorting of the\
    \ nodes reachable from src.\n * @param g Graph\n * @param src Source node\n *\
    \ @note O(n + m)\n */\ntemplate <typename T>\nvector<int> toposort(Graph<T> const\
    \ &g, int src)\n{\n    int         n = g.size();\n    vector<int> order, color(n,\
    \ false);\n    if (not toposort_dfs(g, src, order, color))\n        return {};\n\
    \    reverse(order.begin(), order.end());\n    return order;\n}\n\n} // namespace\
    \ cplib\n\n#endif // CPLIB_TOPOSORT_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/toposort.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/toposort.hpp
layout: document
redirect_from:
- /library/cplib/graph/toposort.hpp
- /library/cplib/graph/toposort.hpp.html
title: Computes one iteration of the dfs in a topological sorting.
---
