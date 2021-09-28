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
  bundledCode: "#line 1 \"cplib/old/hld.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing vi = vector<int>;\n\nconst int NMAX = 1e5;\n\
    \n// parent[i]: parent of node i\n// depth[i]: depth of node i\n// heavy[i]: next\
    \ heavy node from node i\n// head[i]: node at the top of chain in which i lies\n\
    // pos[i]: position of node i in the segment tree that maintains the hld\n\nvi\
    \  g[NMAX];\nint parent[NMAX], depth[NMAX], heavy[NMAX], head[NMAX], pos[NMAX];\n\
    \nint segment_tree_query(int ql, int qr) { return 0; }\n\n// DFS's Purpose:\n\
    // - Build depth and heavy array.\nint dfs(int u)\n{\n    // u_sz: size of u's\
    \ subtree, v_sz: size of v's subtree\n    int u_sz = 1, mx_v_sz = 0, v_sz;\n\n\
    \    for (int v : g[u])\n    {\n        if (v != parent[u])\n        {\n     \
    \       parent[v] = u;\n            depth[v]  = depth[u] + 1;\n            v_sz\
    \      = dfs(v);\n            u_sz += v_sz;\n\n            if (v_sz > mx_v_sz)\n\
    \            {\n                mx_v_sz  = v_sz;\n                heavy[u] = v;\n\
    \            }\n        }\n    }\n    return u_sz;\n}\n\n// u: node, h: head of\
    \ node\nvoid decompose(int u, int h, int &hld_pos)\n{\n    head[u] = h;\n    pos[u]\
    \  = hld_pos++;\n\n    // If u is not a leaf, first decompose its heavy path with\
    \ head = u's head.\n    // This will guarantee that heavy paths are contiguous\
    \ in pos[] array\n    // Later this will help to maintain the tree with only one\
    \ segment tree\n    if (heavy[u] != -1)\n        decompose(heavy[u], h, hld_pos);\n\
    \    for (int v : g[u])\n    {\n        if (v != parent[u] and v != heavy[u])\n\
    \            decompose(v, v, hld_pos); // Form a new heavy path with v as start\n\
    \    }\n}\n\nvoid init(void)\n{\n    int hld_pos = 0;\n\n    memset(heavy, -1,\
    \ sizeof(*heavy) * NMAX);\n    dfs(0);\n    decompose(0, 0, hld_pos);\n}\n\n//\
    \ The path from a to b can be decomposed to a -> lca(a, b) + b -> lca(a, b).\n\
    // This query implementation will force the deepest node to climb up until both\n\
    // of them are on the same chain, computing partial answers as they go.\n// Once\
    \ there one query will do the job.\nint query(int a, int b)\n{\n    int ans =\
    \ 0;\n\n    // This loop will allow the deeper node to climb chains until it gets\
    \ to a\n    // and b's lca. It will compute the partial answers on each chain.\n\
    \    while (head[a] != head[b]) // While a and b are on different chains\n   \
    \ {\n        // We need to find a and b's lca. The node whose chain is furthest\
    \ down\n        // has to climb up. We will refer as b to that node.\n       \
    \ // Note that it can stop referring to the same node if the the node\n      \
    \  // that's climbing becomes less deeper than the other.\n        if (depth[head[a]]\
    \ > depth[head[b]])\n            swap(a, b);\n        int cur_heavy_path_max =\
    \ segment_tree_query(pos[head[b]], pos[b]);\n        ans                    =\
    \ max(ans, cur_heavy_path_max);\n        b                      = parent[head[b]];\n\
    \    }\n    // Now both a and b are on the same chain, same trick as before, b\
    \ will\n    // refer to the deeper node (the one that appears last in the segment\
    \ tree).\n    if (depth[a] > depth[b])\n        swap(a, b);\n    int last_heavy_path_max\
    \ = segment_tree_query(pos[a], pos[b]);\n    ans                     = max(ans,\
    \ last_heavy_path_max);\n    return ans;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\nusing ll = long long;\n\
    using vi = vector<int>;\n\nconst int NMAX = 1e5;\n\n// parent[i]: parent of node\
    \ i\n// depth[i]: depth of node i\n// heavy[i]: next heavy node from node i\n\
    // head[i]: node at the top of chain in which i lies\n// pos[i]: position of node\
    \ i in the segment tree that maintains the hld\n\nvi  g[NMAX];\nint parent[NMAX],\
    \ depth[NMAX], heavy[NMAX], head[NMAX], pos[NMAX];\n\nint segment_tree_query(int\
    \ ql, int qr) { return 0; }\n\n// DFS's Purpose:\n// - Build depth and heavy array.\n\
    int dfs(int u)\n{\n    // u_sz: size of u's subtree, v_sz: size of v's subtree\n\
    \    int u_sz = 1, mx_v_sz = 0, v_sz;\n\n    for (int v : g[u])\n    {\n     \
    \   if (v != parent[u])\n        {\n            parent[v] = u;\n            depth[v]\
    \  = depth[u] + 1;\n            v_sz      = dfs(v);\n            u_sz += v_sz;\n\
    \n            if (v_sz > mx_v_sz)\n            {\n                mx_v_sz  = v_sz;\n\
    \                heavy[u] = v;\n            }\n        }\n    }\n    return u_sz;\n\
    }\n\n// u: node, h: head of node\nvoid decompose(int u, int h, int &hld_pos)\n\
    {\n    head[u] = h;\n    pos[u]  = hld_pos++;\n\n    // If u is not a leaf, first\
    \ decompose its heavy path with head = u's head.\n    // This will guarantee that\
    \ heavy paths are contiguous in pos[] array\n    // Later this will help to maintain\
    \ the tree with only one segment tree\n    if (heavy[u] != -1)\n        decompose(heavy[u],\
    \ h, hld_pos);\n    for (int v : g[u])\n    {\n        if (v != parent[u] and\
    \ v != heavy[u])\n            decompose(v, v, hld_pos); // Form a new heavy path\
    \ with v as start\n    }\n}\n\nvoid init(void)\n{\n    int hld_pos = 0;\n\n  \
    \  memset(heavy, -1, sizeof(*heavy) * NMAX);\n    dfs(0);\n    decompose(0, 0,\
    \ hld_pos);\n}\n\n// The path from a to b can be decomposed to a -> lca(a, b)\
    \ + b -> lca(a, b).\n// This query implementation will force the deepest node\
    \ to climb up until both\n// of them are on the same chain, computing partial\
    \ answers as they go.\n// Once there one query will do the job.\nint query(int\
    \ a, int b)\n{\n    int ans = 0;\n\n    // This loop will allow the deeper node\
    \ to climb chains until it gets to a\n    // and b's lca. It will compute the\
    \ partial answers on each chain.\n    while (head[a] != head[b]) // While a and\
    \ b are on different chains\n    {\n        // We need to find a and b's lca.\
    \ The node whose chain is furthest down\n        // has to climb up. We will refer\
    \ as b to that node.\n        // Note that it can stop referring to the same node\
    \ if the the node\n        // that's climbing becomes less deeper than the other.\n\
    \        if (depth[head[a]] > depth[head[b]])\n            swap(a, b);\n     \
    \   int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);\n     \
    \   ans                    = max(ans, cur_heavy_path_max);\n        b        \
    \              = parent[head[b]];\n    }\n    // Now both a and b are on the same\
    \ chain, same trick as before, b will\n    // refer to the deeper node (the one\
    \ that appears last in the segment tree).\n    if (depth[a] > depth[b])\n    \
    \    swap(a, b);\n    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);\n\
    \    ans                     = max(ans, last_heavy_path_max);\n    return ans;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/old/hld.cpp
  requiredBy: []
  timestamp: '2021-01-31 10:07:00-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/hld.cpp
layout: document
redirect_from:
- /library/cplib/old/hld.cpp
- /library/cplib/old/hld.cpp.html
title: cplib/old/hld.cpp
---
