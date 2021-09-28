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
  bundledCode: "#line 1 \"cplib/old/bfs.cpp\"\n\nint  n, m, dist[NMAX][NMAX], visited[NMAX][NMAX];\n\
    char board[NMAX][NMAX];\nint  dr[4] = {1, -1, 0, 0};\nint  dc[4] = {0, 0, 1, -1};\n\
    \ninline bool in_bounds(int r, int c)\n{\n    return 0 <= r and r < n and 0 <=\
    \ c and c < m;\n}\n\nvector<ii> neighbors(int r, int c)\n{\n    vector<ii> ans;\n\
    \    for (int i = 0; i < 4; ++i)\n    {\n        if (in_bounds(r + dr[i], c +\
    \ dc[i]))\n        {\n            ans.emplace_back(r + dr[i], c + dc[i]);\n  \
    \      }\n    }\n    return ans;\n}\n\nvoid bfs(vector<ii> sources)\n{\n    queue<ii>\
    \ frontier;\n    memset(visited, false, sizeof(visited));\n    for (auto x : sources)\n\
    \        frontier.push(x);\n\n    while (not frontier.empty())\n    {\n      \
    \  auto [r, c] = frontier.front();\n        frontier.pop();\n\n        for (auto\
    \ [rr, cc] : neighbors(r, c))\n        {\n            if (not visited[rr][cc])\n\
    \            {\n                frontier.emplace(rr, cc);\n                visited[rr][cc]\
    \ = true;\n                dist[rr][cc]    = dist[r][c] + 1;\n            }\n\
    \        }\n    }\n}\n"
  code: "\nint  n, m, dist[NMAX][NMAX], visited[NMAX][NMAX];\nchar board[NMAX][NMAX];\n\
    int  dr[4] = {1, -1, 0, 0};\nint  dc[4] = {0, 0, 1, -1};\n\ninline bool in_bounds(int\
    \ r, int c)\n{\n    return 0 <= r and r < n and 0 <= c and c < m;\n}\n\nvector<ii>\
    \ neighbors(int r, int c)\n{\n    vector<ii> ans;\n    for (int i = 0; i < 4;\
    \ ++i)\n    {\n        if (in_bounds(r + dr[i], c + dc[i]))\n        {\n     \
    \       ans.emplace_back(r + dr[i], c + dc[i]);\n        }\n    }\n    return\
    \ ans;\n}\n\nvoid bfs(vector<ii> sources)\n{\n    queue<ii> frontier;\n    memset(visited,\
    \ false, sizeof(visited));\n    for (auto x : sources)\n        frontier.push(x);\n\
    \n    while (not frontier.empty())\n    {\n        auto [r, c] = frontier.front();\n\
    \        frontier.pop();\n\n        for (auto [rr, cc] : neighbors(r, c))\n  \
    \      {\n            if (not visited[rr][cc])\n            {\n              \
    \  frontier.emplace(rr, cc);\n                visited[rr][cc] = true;\n      \
    \          dist[rr][cc]    = dist[r][c] + 1;\n            }\n        }\n    }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/old/bfs.cpp
  requiredBy: []
  timestamp: '2021-01-31 10:07:00-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/bfs.cpp
layout: document
redirect_from:
- /library/cplib/old/bfs.cpp
- /library/cplib/old/bfs.cpp.html
title: cplib/old/bfs.cpp
---
