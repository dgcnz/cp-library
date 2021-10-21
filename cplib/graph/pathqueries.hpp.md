---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/graph/graph.hpp
    title: cplib/graph/graph.hpp
  - icon: ':warning:'
    path: cplib/graph/lca.hpp
    title: cplib/graph/lca.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/pathqueries.hpp\"\n\n\n\n#include <cplib/graph/graph>\n\
    #include <cplib/graph/lca>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ cplib\n{\nusing namespace std;\n\ntemplate <typename W, typename S, S (*op)(S,\
    \ S), S (*inv)(S), S (*e)()>\nstruct PathQueries\n{\n    LCA<W>           lca;\n\
    \    vector<S> const &x;\n    vector<S>        dp;\n    PathQueries(const Graph<W>\
    \ &g, vector<S> const &x) : lca(g), x(x), dp(x)\n    {\n        int          \
    \       n = g.size();\n        vector<bool>        vis(n, false);\n        function<void(int)>\
    \ dfs = [&](int u)\n        {\n            vis[u] = true;\n            for (auto\
    \ v : g[u])\n            {\n                if (vis[v])\n                    continue;\n\
    \n                dp[v] = op(dp[u], x[v]);\n                dfs(v);\n        \
    \    }\n        };\n\n        for (int u = 0; u < n; ++u)\n            if (not\
    \ vis[u])\n                dfs(u);\n    }\n\n    S query(int u, int v) const\n\
    \    {\n        int l   = lca(u, v);\n        S   ans = e();\n        ans    \
    \ = op(ans, dp[u]);\n        ans     = op(ans, dp[v]);\n        ans     = op(ans,\
    \ inv(dp[l]));\n        ans     = op(ans, inv(dp[l]));\n        ans     = op(ans,\
    \ x[l]);\n        return ans;\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_PATHQUERIES_HPP\n#define CPLIB_PATHQUERIES_HPP\n\n#include\
    \ <cplib/graph/graph>\n#include <cplib/graph/lca>\n#include <functional>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename W,\
    \ typename S, S (*op)(S, S), S (*inv)(S), S (*e)()>\nstruct PathQueries\n{\n \
    \   LCA<W>           lca;\n    vector<S> const &x;\n    vector<S>        dp;\n\
    \    PathQueries(const Graph<W> &g, vector<S> const &x) : lca(g), x(x), dp(x)\n\
    \    {\n        int                 n = g.size();\n        vector<bool>      \
    \  vis(n, false);\n        function<void(int)> dfs = [&](int u)\n        {\n \
    \           vis[u] = true;\n            for (auto v : g[u])\n            {\n \
    \               if (vis[v])\n                    continue;\n\n               \
    \ dp[v] = op(dp[u], x[v]);\n                dfs(v);\n            }\n        };\n\
    \n        for (int u = 0; u < n; ++u)\n            if (not vis[u])\n         \
    \       dfs(u);\n    }\n\n    S query(int u, int v) const\n    {\n        int\
    \ l   = lca(u, v);\n        S   ans = e();\n        ans     = op(ans, dp[u]);\n\
    \        ans     = op(ans, dp[v]);\n        ans     = op(ans, inv(dp[l]));\n \
    \       ans     = op(ans, inv(dp[l]));\n        ans     = op(ans, x[l]);\n   \
    \     return ans;\n    }\n};\n} // namespace cplib\n\n#endif // CPLIB_PATHQUERIES_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  - cplib/graph/lca.hpp
  isVerificationFile: false
  path: cplib/graph/pathqueries.hpp
  requiredBy: []
  timestamp: '2021-10-21 16:39:26-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/pathqueries.hpp
layout: document
redirect_from:
- /library/cplib/graph/pathqueries.hpp
- /library/cplib/graph/pathqueries.hpp.html
title: cplib/graph/pathqueries.hpp
---
