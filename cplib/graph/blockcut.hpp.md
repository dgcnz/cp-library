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
    links:
    - https://codeforces.com/blog/entry/50428?#comment-343460
  bundledCode: "#line 1 \"cplib/graph/blockcut.hpp\"\n\n\n// Source: https://codeforces.com/blog/entry/50428?#comment-343460\n\
    #include <cplib/graph/graph>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace\
    \ std;\n\ntemplate <typename W>\nstruct BlockCut\n{\n\n    vector<int>       \
    \  id, cut;\n    vector<vector<int>> comps;\n    Graph<W>            tree;\n\n\
    \    BlockCut(Graph<W> const &g) : id(g.size()), cut(g.size())\n    {\n      \
    \  int         t, n = g.size();\n        vector<int> tin(n, 0), low(n, 0), stk;\n\
    \n        function<void(int, int)> dfs = [&](int u, int p = -1)\n        {\n \
    \           int children = 0;\n            tin[u] = low[u] = ++t;\n          \
    \  stk.push_back(u);\n\n            for (auto vw : g[u])\n            {\n    \
    \            int v = g.vertex(vw);\n                if (v == p)\n            \
    \        continue;\n\n                if (!tin[v]) // not visited\n          \
    \      {\n                    dfs(v, u);\n                    low[u] = min(low[u],\
    \ low[v]);\n\n                    if (low[v] >= tin[u])\n                    {\n\
    \                        cut[u] = (tin[u] > 1 || tin[v] > 2);\n\n            \
    \            comps.push_back({u});\n                        while (comps.back().back()\
    \ != v)\n                            comps.back().push_back(stk.back()), stk.pop_back();\n\
    \                    }\n                    children++;\n                }\n \
    \               else\n                    low[u] = min(low[u], tin[v]);\n    \
    \        }\n            if (p == -1 and children == 0)\n            {\n      \
    \          stk.pop_back();\n                comps.push_back({u});\n          \
    \  }\n        };\n\n        for (int u = 0; u < n; ++u)\n            if (!tin[u])\n\
    \                t = 0, dfs(u, -1);\n\n        for (int u = 0; u < n; ++u)\n \
    \           if (cut[u])\n                id[u] = tree.add_node();\n\n        for\
    \ (auto &comp : comps)\n        {\n            int v = tree.add_node();\n    \
    \        for (int u : comp)\n            {\n                if (!cut[u])\n   \
    \                 id[u] = v;\n                else\n                    tree.add_undirected_edge(v,\
    \ id[u]);\n            }\n        }\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_BLOCKCUT_HPP\n#define CPLIB_BLOCKCUT_HPP\n// Source: https://codeforces.com/blog/entry/50428?#comment-343460\n\
    #include <cplib/graph/graph>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace\
    \ std;\n\ntemplate <typename W>\nstruct BlockCut\n{\n\n    vector<int>       \
    \  id, cut;\n    vector<vector<int>> comps;\n    Graph<W>            tree;\n\n\
    \    BlockCut(Graph<W> const &g) : id(g.size()), cut(g.size())\n    {\n      \
    \  int         t, n = g.size();\n        vector<int> tin(n, 0), low(n, 0), stk;\n\
    \n        function<void(int, int)> dfs = [&](int u, int p = -1)\n        {\n \
    \           int children = 0;\n            tin[u] = low[u] = ++t;\n          \
    \  stk.push_back(u);\n\n            for (auto vw : g[u])\n            {\n    \
    \            int v = g.vertex(vw);\n                if (v == p)\n            \
    \        continue;\n\n                if (!tin[v]) // not visited\n          \
    \      {\n                    dfs(v, u);\n                    low[u] = min(low[u],\
    \ low[v]);\n\n                    if (low[v] >= tin[u])\n                    {\n\
    \                        cut[u] = (tin[u] > 1 || tin[v] > 2);\n\n            \
    \            comps.push_back({u});\n                        while (comps.back().back()\
    \ != v)\n                            comps.back().push_back(stk.back()), stk.pop_back();\n\
    \                    }\n                    children++;\n                }\n \
    \               else\n                    low[u] = min(low[u], tin[v]);\n    \
    \        }\n            if (p == -1 and children == 0)\n            {\n      \
    \          stk.pop_back();\n                comps.push_back({u});\n          \
    \  }\n        };\n\n        for (int u = 0; u < n; ++u)\n            if (!tin[u])\n\
    \                t = 0, dfs(u, -1);\n\n        for (int u = 0; u < n; ++u)\n \
    \           if (cut[u])\n                id[u] = tree.add_node();\n\n        for\
    \ (auto &comp : comps)\n        {\n            int v = tree.add_node();\n    \
    \        for (int u : comp)\n            {\n                if (!cut[u])\n   \
    \                 id[u] = v;\n                else\n                    tree.add_undirected_edge(v,\
    \ id[u]);\n            }\n        }\n    }\n};\n} // namespace cplib\n\n#endif\
    \ // CPLIB_BLOCKCUT_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  isVerificationFile: false
  path: cplib/graph/blockcut.hpp
  requiredBy: []
  timestamp: '2021-10-21 16:39:26-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/blockcut.hpp
layout: document
redirect_from:
- /library/cplib/graph/blockcut.hpp
- /library/cplib/graph/blockcut.hpp.html
title: cplib/graph/blockcut.hpp
---
