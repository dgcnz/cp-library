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
  bundledCode: "#line 2 \"cplib/graph/old/toposort.hpp\"\n\n#include <cplib/graphs/graph>\n\
    #include <functional>\n#include <vector>\n\nusing namespace std;\n\nnamespace\
    \ cplib\n{\ntemplate <typename W>\nvector<int> toposort(Graph<W> g)\n{\n    int\
    \         n = g.size();\n    vector<int> visited(n, false), order;\n\n    function<bool(int)>\
    \ dfs = [&](int u) {\n        if (visited[u] == 1)\n            return false;\n\
    \        if (visited[u] == 2)\n            return true;\n\n        visited[u]\
    \ = 1;\n        for (auto v : g.neighbors(u))\n            if (not dfs(v))\n \
    \               return false;\n\n        visited[u] = 2;\n        order.push_back(u);\n\
    \        return true;\n    };\n\n    for (int u = 0; u < n; ++u)\n        if (not\
    \ visited[u] and not dfs(u))\n            return {};\n    reverse(order.begin(),\
    \ order.end());\n    return order;\n}\n} // namespace cplib\n"
  code: "#pragma once\n\n#include <cplib/graphs/graph>\n#include <functional>\n#include\
    \ <vector>\n\nusing namespace std;\n\nnamespace cplib\n{\ntemplate <typename W>\n\
    vector<int> toposort(Graph<W> g)\n{\n    int         n = g.size();\n    vector<int>\
    \ visited(n, false), order;\n\n    function<bool(int)> dfs = [&](int u) {\n  \
    \      if (visited[u] == 1)\n            return false;\n        if (visited[u]\
    \ == 2)\n            return true;\n\n        visited[u] = 1;\n        for (auto\
    \ v : g.neighbors(u))\n            if (not dfs(v))\n                return false;\n\
    \n        visited[u] = 2;\n        order.push_back(u);\n        return true;\n\
    \    };\n\n    for (int u = 0; u < n; ++u)\n        if (not visited[u] and not\
    \ dfs(u))\n            return {};\n    reverse(order.begin(), order.end());\n\
    \    return order;\n}\n} // namespace cplib\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/old/toposort.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/old/toposort.hpp
layout: document
redirect_from:
- /library/cplib/graph/old/toposort.hpp
- /library/cplib/graph/old/toposort.hpp.html
title: cplib/graph/old/toposort.hpp
---
