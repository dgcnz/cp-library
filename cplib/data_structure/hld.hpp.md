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
  bundledCode: "#line 1 \"cplib/data_structure/hld.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <template\
    \ <class S, S (*op)(S, S), S (*e)()> class segtree,\n          class S,\n    \
    \      S (*op)(S, S),\n          S (*e)()>\nstruct HLD\n{\n    using Tree    \
    \    = vector<vector<int>>;\n    using SegmentTree = segtree<S, op, e>;\n\n  \
    \  Tree        g;\n    SegmentTree st;\n\n    vector<int> parent, depth, heavy,\
    \ head, pos;\n\n    HLD(int n)\n        : g(n), st(n), parent(n, 0), depth(n,\
    \ 0), heavy(n, -1), head(n, 0),\n          pos(n, 0)\n    {\n    }\n    HLD(Tree\
    \ _g) : HLD(_g.size()) { copy(begin(_g), end(_g), begin(g)); }\n    void add_edge(int\
    \ u, int v) { g[u].push_back(v), g[v].push_back(u); }\n\n    void operator()(void)\n\
    \    {\n        int hld_pos = 0;\n        dfs(0);\n        decompose(0, 0, hld_pos);\n\
    \    }\n\n    int dfs(int u)\n    {\n        /*\n         * Build depth and heavy\
    \ array.\n         *\n         * u_sz: size of u's subtree\n         * v_sz: size\
    \ of v's subtree\n         */\n\n        int u_sz = 1, mx_v_sz = 0, v_sz;\n\n\
    \        for (int v : g[u])\n        {\n            if (v != parent[u])\n    \
    \        {\n                parent[v] = u;\n                depth[v]  = depth[u]\
    \ + 1;\n                v_sz      = dfs(v);\n                u_sz += v_sz;\n\n\
    \                if (v_sz > mx_v_sz)\n                {\n                    mx_v_sz\
    \  = v_sz;\n                    heavy[u] = v;\n                }\n           \
    \ }\n        }\n        return u_sz;\n    }\n\n    // u: node, h: head of node\n\
    \    void decompose(int u, int h, int &hld_pos)\n    {\n        /*\n         *\
    \ Decompose tree\n         *\n         * u: current node\n         * h: head of\
    \ node\n         */\n        head[u] = h;\n        pos[u]  = hld_pos++;\n\n  \
    \      // If u is not a leaf, first decompose its heavy path with head = u's\n\
    \        // head. This will guarantee that heavy paths are contiguous in pos[]\n\
    \        // array Later this will help to maintain the tree with only one segment\n\
    \        // tree\n        if (heavy[u] != -1)\n            decompose(heavy[u],\
    \ h, hld_pos);\n        for (int v : g[u])\n            if (v != parent[u] and\
    \ v != heavy[u])\n                decompose(v, v, hld_pos); // New heavy path\
    \ with v as start\n    }\n\n    // The path from a to b can be decomposed to a\
    \ -> lca(a, b) + b -> lca(a,\n    // b). This query implementation will force\
    \ the deepest node to climb up\n    // until both of them are on the same chain,\
    \ computing partial answers as\n    // they go. Once there one query will do the\
    \ job.\n\n    S query(int a, int b)\n    {\n        /*\n         * Query path\
    \ a to b\n         *\n         * The path from a to b can be decomposed to a ->\
    \ lca(a, b) + b ->\n         * lca(a, b). This query implementation will force\
    \ the deepest node to\n         * climb up until both of them are on the same\
    \ chain, computing partial\n         * answers as they go. Once there one query\
    \ will do the job.\n         */\n\n        S ans = e();\n\n        // This loop\
    \ will allow the deeper node to climb chains until it gets to\n        // a and\
    \ b's lca. It will compute the partial answers on each chain.\n        while (head[a]\
    \ != head[b]) // While a and b are on different chains\n        {\n          \
    \  // We need to find a and b's lca. The node whose chain is furthest\n      \
    \      // down has to climb up. We will refer as b to that node. Note that\n \
    \           // it can stop referring to the same node if the the node that's\n\
    \            // climbing becomes less deeper than the other.\n            if (depth[head[a]]\
    \ > depth[head[b]])\n                swap(a, b);\n            ans = op(ans, st.prod(pos[head[b]],\
    \ pos[b] + 1));\n            b   = parent[head[b]];\n        }\n        // Now\
    \ both a and b are on the same chain, same trick as before, b will\n        //\
    \ refer to the deeper node (the one that appears last in the segment\n       \
    \ // tree).\n        if (depth[a] > depth[b])\n            swap(a, b);\n     \
    \   return op(ans, st.prod(pos[a], pos[b] + 1));\n    }\n\n    void set(int u,\
    \ S new_value) { st.set(pos[u], new_value); }\n    S    get(int u) { return st.get(pos[u]);\
    \ }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_HLD_HPP\n#define CPLIB_HLD_HPP\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <template <class\
    \ S, S (*op)(S, S), S (*e)()> class segtree,\n          class S,\n          S\
    \ (*op)(S, S),\n          S (*e)()>\nstruct HLD\n{\n    using Tree        = vector<vector<int>>;\n\
    \    using SegmentTree = segtree<S, op, e>;\n\n    Tree        g;\n    SegmentTree\
    \ st;\n\n    vector<int> parent, depth, heavy, head, pos;\n\n    HLD(int n)\n\
    \        : g(n), st(n), parent(n, 0), depth(n, 0), heavy(n, -1), head(n, 0),\n\
    \          pos(n, 0)\n    {\n    }\n    HLD(Tree _g) : HLD(_g.size()) { copy(begin(_g),\
    \ end(_g), begin(g)); }\n    void add_edge(int u, int v) { g[u].push_back(v),\
    \ g[v].push_back(u); }\n\n    void operator()(void)\n    {\n        int hld_pos\
    \ = 0;\n        dfs(0);\n        decompose(0, 0, hld_pos);\n    }\n\n    int dfs(int\
    \ u)\n    {\n        /*\n         * Build depth and heavy array.\n         *\n\
    \         * u_sz: size of u's subtree\n         * v_sz: size of v's subtree\n\
    \         */\n\n        int u_sz = 1, mx_v_sz = 0, v_sz;\n\n        for (int v\
    \ : g[u])\n        {\n            if (v != parent[u])\n            {\n       \
    \         parent[v] = u;\n                depth[v]  = depth[u] + 1;\n        \
    \        v_sz      = dfs(v);\n                u_sz += v_sz;\n\n              \
    \  if (v_sz > mx_v_sz)\n                {\n                    mx_v_sz  = v_sz;\n\
    \                    heavy[u] = v;\n                }\n            }\n       \
    \ }\n        return u_sz;\n    }\n\n    // u: node, h: head of node\n    void\
    \ decompose(int u, int h, int &hld_pos)\n    {\n        /*\n         * Decompose\
    \ tree\n         *\n         * u: current node\n         * h: head of node\n \
    \        */\n        head[u] = h;\n        pos[u]  = hld_pos++;\n\n        //\
    \ If u is not a leaf, first decompose its heavy path with head = u's\n       \
    \ // head. This will guarantee that heavy paths are contiguous in pos[]\n    \
    \    // array Later this will help to maintain the tree with only one segment\n\
    \        // tree\n        if (heavy[u] != -1)\n            decompose(heavy[u],\
    \ h, hld_pos);\n        for (int v : g[u])\n            if (v != parent[u] and\
    \ v != heavy[u])\n                decompose(v, v, hld_pos); // New heavy path\
    \ with v as start\n    }\n\n    // The path from a to b can be decomposed to a\
    \ -> lca(a, b) + b -> lca(a,\n    // b). This query implementation will force\
    \ the deepest node to climb up\n    // until both of them are on the same chain,\
    \ computing partial answers as\n    // they go. Once there one query will do the\
    \ job.\n\n    S query(int a, int b)\n    {\n        /*\n         * Query path\
    \ a to b\n         *\n         * The path from a to b can be decomposed to a ->\
    \ lca(a, b) + b ->\n         * lca(a, b). This query implementation will force\
    \ the deepest node to\n         * climb up until both of them are on the same\
    \ chain, computing partial\n         * answers as they go. Once there one query\
    \ will do the job.\n         */\n\n        S ans = e();\n\n        // This loop\
    \ will allow the deeper node to climb chains until it gets to\n        // a and\
    \ b's lca. It will compute the partial answers on each chain.\n        while (head[a]\
    \ != head[b]) // While a and b are on different chains\n        {\n          \
    \  // We need to find a and b's lca. The node whose chain is furthest\n      \
    \      // down has to climb up. We will refer as b to that node. Note that\n \
    \           // it can stop referring to the same node if the the node that's\n\
    \            // climbing becomes less deeper than the other.\n            if (depth[head[a]]\
    \ > depth[head[b]])\n                swap(a, b);\n            ans = op(ans, st.prod(pos[head[b]],\
    \ pos[b] + 1));\n            b   = parent[head[b]];\n        }\n        // Now\
    \ both a and b are on the same chain, same trick as before, b will\n        //\
    \ refer to the deeper node (the one that appears last in the segment\n       \
    \ // tree).\n        if (depth[a] > depth[b])\n            swap(a, b);\n     \
    \   return op(ans, st.prod(pos[a], pos[b] + 1));\n    }\n\n    void set(int u,\
    \ S new_value) { st.set(pos[u], new_value); }\n    S    get(int u) { return st.get(pos[u]);\
    \ }\n};\n} // namespace cplib\n\n#endif // CPLIB_HLD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/hld.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/hld.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/hld.hpp
- /library/cplib/data_structure/hld.hpp.html
title: cplib/data_structure/hld.hpp
---
