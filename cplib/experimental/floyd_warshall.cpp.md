---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/experimental/floyd_warshall.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\ntemplate <typename T>\nusing\
    \ vx = vector<T>;\ntemplate <typename T>\nusing vvx = vector<vx<T>>;\n\nconst\
    \ ll INF = 1e16;\n\nconst vvx<ll> floyd_warshall(int n, const vvx<int> &g)\n{\n\
    \    vvx<ll> dist(n + 1, vx<ll>(n + 1, 0));\n\n    for (int i = 1; i <= n; i++)\n\
    \    {\n        for (int j = 1; j <= n; j++)\n        {\n            if (i ==\
    \ j)\n                dist[i][j] = 0;\n            else if (g[i][j])\n       \
    \         dist[i][j] = g[i][j];\n            else\n                dist[i][j]\
    \ = INF;\n        }\n    }\n\n    for (int k = 1; k <= n; k++)\n    {\n      \
    \  for (int i = 1; i <= n; i++)\n        {\n            for (int j = 1; j <= n;\
    \ j++)\n            {\n                dist[i][j] = min(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\n            }\n        }\n    }\n    return dist;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    template <typename T>\nusing vx = vector<T>;\ntemplate <typename T>\nusing vvx\
    \ = vector<vx<T>>;\n\nconst ll INF = 1e16;\n\nconst vvx<ll> floyd_warshall(int\
    \ n, const vvx<int> &g)\n{\n    vvx<ll> dist(n + 1, vx<ll>(n + 1, 0));\n\n   \
    \ for (int i = 1; i <= n; i++)\n    {\n        for (int j = 1; j <= n; j++)\n\
    \        {\n            if (i == j)\n                dist[i][j] = 0;\n       \
    \     else if (g[i][j])\n                dist[i][j] = g[i][j];\n            else\n\
    \                dist[i][j] = INF;\n        }\n    }\n\n    for (int k = 1; k\
    \ <= n; k++)\n    {\n        for (int i = 1; i <= n; i++)\n        {\n       \
    \     for (int j = 1; j <= n; j++)\n            {\n                dist[i][j]\
    \ = min(dist[i][j], dist[i][k] + dist[k][j]);\n            }\n        }\n    }\n\
    \    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/floyd_warshall.cpp
  requiredBy: []
  timestamp: '2021-09-28 18:42:31-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/floyd_warshall.cpp
layout: document
redirect_from:
- /library/cplib/experimental/floyd_warshall.cpp
- /library/cplib/experimental/floyd_warshall.cpp.html
title: cplib/experimental/floyd_warshall.cpp
---
