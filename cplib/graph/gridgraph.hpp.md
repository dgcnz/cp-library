---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/graph/graph.hpp
    title: cplib/graph/graph.hpp
  - icon: ':warning:'
    path: cplib/utils/grid.hpp
    title: cplib/utils/grid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/gridgraph.hpp\"\n\n\n\n#include <cplib/graph/graph>\n\
    #include <cplib/utils/grid>\n#include <functional>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename W>\n\
    struct GridGraph\n{\n    using ii       = pair<int, int>;\n    using adj_list\
    \ = vector<pair<int, W>>;\n\n    vector<string> const &table;\n    int       \
    \            n, m;\n    Graph<W>              g;\n    function<bool(ii)>    valid;\n\
    \    function<W(ii, ii)>   cost;\n\n    GridGraph(vector<string> const &table,\n\
    \              function<bool(ii)>    valid,\n              function<W(ii, ii)>\
    \   cost)\n        : table(table), n(table.size()), m(table[0].size()), g(n *\
    \ m),\n          valid(valid), cost(cost)\n    {\n        build();\n    }\n  \
    \  adj_list   &operator[](int u) { return g[u]; }\n    adj_list    operator[](int\
    \ u) const { return g[u]; }\n    vector<int> neighbors(int u) const\n    {\n \
    \       vector<int> ans(g[u].size());\n        transform(\n            all(g[u]),\
    \ begin(ans), [](pair<int, W> p) { return p.first; });\n        return ans;\n\
    \    }\n    size_t     size() const { return g.size(); }\n    inline ii  rid(int\
    \ u) { return {u / m, u % m}; }\n    inline int id(int r, int c) { return r *\
    \ m + c; }\n    inline int id(ii pos) { return pos.first * m + pos.second; }\n\
    \    void       build()\n    {\n        for (int r = 0; r < n; ++r)\n        {\n\
    \            for (int c = 0; c < m; ++c)\n            {\n                int u\
    \ = id(r, c);\n                if (r > 0 and valid({r - 1, c}))\n            \
    \    {\n                    int v = id(r - 1, c);\n                    g.add_edge(u,\
    \ v, cost({r, c}, {r - 1, c}));\n                }\n                if (r < n\
    \ - 1 and valid({r + 1, c}))\n                {\n                    int v = id(r\
    \ + 1, c);\n                    g.add_edge(u, v, cost({r, c}, {r + 1, c}));\n\
    \                }\n                if (c > 0 and valid({r, c - 1}))\n       \
    \         {\n                    int v = id(r, c - 1);\n                    g.add_edge(u,\
    \ v, cost({r, c}, {r, c - 1}));\n                }\n                if (c < m\
    \ - 1 and valid({r, c + 1}))\n                {\n                    int v = id(r,\
    \ c + 1);\n                    g.add_edge(u, v, cost({r, c}, {r, c + 1}));\n \
    \               }\n            }\n        }\n    }\n};\n\ntemplate <typename W>\n\
    struct ImplicitGridGraph\n{\n    using self     = ImplicitGridGraph<W>;\n    using\
    \ ii       = pair<int, int>;\n    using edge_t   = pair<int, W>;\n    using adj_list\
    \ = vector<edge_t>;\n    vector<string> const     &grid;\n    int            \
    \           n, m, sz;\n    function<bool(ii)> const  valid;\n    function<W(ii,\
    \ ii)> const cost;\n\n    ImplicitGridGraph(vector<string> const     &_grid,\n\
    \                      function<bool(ii)> const  _valid,\n                   \
    \   function<W(ii, ii)> const _cost)\n        : grid(_grid), n(_grid.size()),\
    \ m(_grid[0].size()), sz(n * m),\n          valid(_valid), cost(_cost)\n    {\n\
    \    }\n    size_t      size() const { return sz; }\n    inline ii   rid(int u)\
    \ const { return make_pair(u / m, u % m); }\n    inline int  id(int r, int c)\
    \ const { return r * m + c; }\n    inline int  id(ii rc) const { return rc.first\
    \ * m + rc.second; }\n    inline bool in_range(int r, int c) const\n    {\n  \
    \      return 0 <= r and r < n and 0 <= c and c < m;\n    }\n\n    inline bool\
    \ in_range(ii rc) const\n    {\n        return 0 <= rc.first and rc.first < n\
    \ and 0 <= rc.second and\n               rc.second < m;\n    }\n    inline int\
    \ vertex(pair<int, W> vw) const { return get<0>(vw); }\n    auto       operator[](int\
    \ u) const { return neighbor_view(u, 0, *this); }\n    struct neighbor_view\n\
    \    {\n        int                         n, m, u, i;\n        ii          \
    \                u_rc, v_rc;\n        ImplicitGridGraph<W> const &g;\n       \
    \ neighbor_view(int _u, int _i, ImplicitGridGraph<W> const &_g)\n            :\
    \ u(_u), i(_i), g(_g)\n        {\n            if ((i = min(i, 4)) == 4)\n    \
    \            return;\n            u_rc = g.rid(u);\n            v_rc = u_rc +\
    \ cardinal_directions[i];\n            while (i < 4 and not(g.in_range(v_rc) and\
    \ g.valid(v_rc)))\n            {\n                ++i;\n                if (i\
    \ < 4)\n                    v_rc = u_rc + cardinal_directions[i];\n          \
    \  }\n        }\n\n        pair<int, W> operator*() const\n        {\n       \
    \     if (i == 4)\n                throw out_of_range(\"Trying to derefernce end.\"\
    );\n            return make_pair(g.id(v_rc), g.cost(u_rc, v_rc));\n        }\n\
    \        neighbor_view &operator++()\n        {\n            ++i;\n          \
    \  if ((i = min(i, 4)) == 4)\n                return *this;\n            v_rc\
    \ = u_rc + cardinal_directions[i];\n            while (i < 4 and not(g.in_range(v_rc)\
    \ and g.valid(v_rc)))\n            {\n                ++i;\n                if\
    \ (i < 4)\n                    v_rc = u_rc + cardinal_directions[i];\n       \
    \     }\n            return *this;\n        }\n        inline bool operator==(neighbor_view\
    \ const &other) const\n        {\n            return i == other.i;\n        }\n\
    \        inline bool operator!=(neighbor_view const &other) const\n        {\n\
    \            return i != other.i;\n        }\n        neighbor_view begin() const\
    \ { return neighbor_view(u, 0, g); }\n        neighbor_view end() const { return\
    \ neighbor_view(u, 4, g); }\n    };\n\n    vector<int> neighbors(int u) const\n\
    \    {\n        // todo wrong\n        vector<int> neighbors;\n        auto [r,\
    \ c] = rid(u);\n        if (r > 0 and valid({r - 1, c}))\n            neighbors.emplace(id(r\
    \ - 1, c));\n        if (r < n - 1 and valid({r + 1, c}))\n            neighbors.emplace(id(r\
    \ + 1, c));\n        if (c > 0 and valid({r, c - 1}))\n            neighbors.emplace(id(r,\
    \ c - 1));\n        if (c < m - 1 and valid({r, c + 1}))\n            neighbors.emplace(id(r,\
    \ c + 1));\n        return neighbors;\n    }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_GRIDGRAPH_HPP\n#define CPLIB_GRIDGRAPH_HPP\n\n#include <cplib/graph/graph>\n\
    #include <cplib/utils/grid>\n#include <functional>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename W>\n\
    struct GridGraph\n{\n    using ii       = pair<int, int>;\n    using adj_list\
    \ = vector<pair<int, W>>;\n\n    vector<string> const &table;\n    int       \
    \            n, m;\n    Graph<W>              g;\n    function<bool(ii)>    valid;\n\
    \    function<W(ii, ii)>   cost;\n\n    GridGraph(vector<string> const &table,\n\
    \              function<bool(ii)>    valid,\n              function<W(ii, ii)>\
    \   cost)\n        : table(table), n(table.size()), m(table[0].size()), g(n *\
    \ m),\n          valid(valid), cost(cost)\n    {\n        build();\n    }\n  \
    \  adj_list   &operator[](int u) { return g[u]; }\n    adj_list    operator[](int\
    \ u) const { return g[u]; }\n    vector<int> neighbors(int u) const\n    {\n \
    \       vector<int> ans(g[u].size());\n        transform(\n            all(g[u]),\
    \ begin(ans), [](pair<int, W> p) { return p.first; });\n        return ans;\n\
    \    }\n    size_t     size() const { return g.size(); }\n    inline ii  rid(int\
    \ u) { return {u / m, u % m}; }\n    inline int id(int r, int c) { return r *\
    \ m + c; }\n    inline int id(ii pos) { return pos.first * m + pos.second; }\n\
    \    void       build()\n    {\n        for (int r = 0; r < n; ++r)\n        {\n\
    \            for (int c = 0; c < m; ++c)\n            {\n                int u\
    \ = id(r, c);\n                if (r > 0 and valid({r - 1, c}))\n            \
    \    {\n                    int v = id(r - 1, c);\n                    g.add_edge(u,\
    \ v, cost({r, c}, {r - 1, c}));\n                }\n                if (r < n\
    \ - 1 and valid({r + 1, c}))\n                {\n                    int v = id(r\
    \ + 1, c);\n                    g.add_edge(u, v, cost({r, c}, {r + 1, c}));\n\
    \                }\n                if (c > 0 and valid({r, c - 1}))\n       \
    \         {\n                    int v = id(r, c - 1);\n                    g.add_edge(u,\
    \ v, cost({r, c}, {r, c - 1}));\n                }\n                if (c < m\
    \ - 1 and valid({r, c + 1}))\n                {\n                    int v = id(r,\
    \ c + 1);\n                    g.add_edge(u, v, cost({r, c}, {r, c + 1}));\n \
    \               }\n            }\n        }\n    }\n};\n\ntemplate <typename W>\n\
    struct ImplicitGridGraph\n{\n    using self     = ImplicitGridGraph<W>;\n    using\
    \ ii       = pair<int, int>;\n    using edge_t   = pair<int, W>;\n    using adj_list\
    \ = vector<edge_t>;\n    vector<string> const     &grid;\n    int            \
    \           n, m, sz;\n    function<bool(ii)> const  valid;\n    function<W(ii,\
    \ ii)> const cost;\n\n    ImplicitGridGraph(vector<string> const     &_grid,\n\
    \                      function<bool(ii)> const  _valid,\n                   \
    \   function<W(ii, ii)> const _cost)\n        : grid(_grid), n(_grid.size()),\
    \ m(_grid[0].size()), sz(n * m),\n          valid(_valid), cost(_cost)\n    {\n\
    \    }\n    size_t      size() const { return sz; }\n    inline ii   rid(int u)\
    \ const { return make_pair(u / m, u % m); }\n    inline int  id(int r, int c)\
    \ const { return r * m + c; }\n    inline int  id(ii rc) const { return rc.first\
    \ * m + rc.second; }\n    inline bool in_range(int r, int c) const\n    {\n  \
    \      return 0 <= r and r < n and 0 <= c and c < m;\n    }\n\n    inline bool\
    \ in_range(ii rc) const\n    {\n        return 0 <= rc.first and rc.first < n\
    \ and 0 <= rc.second and\n               rc.second < m;\n    }\n    inline int\
    \ vertex(pair<int, W> vw) const { return get<0>(vw); }\n    auto       operator[](int\
    \ u) const { return neighbor_view(u, 0, *this); }\n    struct neighbor_view\n\
    \    {\n        int                         n, m, u, i;\n        ii          \
    \                u_rc, v_rc;\n        ImplicitGridGraph<W> const &g;\n       \
    \ neighbor_view(int _u, int _i, ImplicitGridGraph<W> const &_g)\n            :\
    \ u(_u), i(_i), g(_g)\n        {\n            if ((i = min(i, 4)) == 4)\n    \
    \            return;\n            u_rc = g.rid(u);\n            v_rc = u_rc +\
    \ cardinal_directions[i];\n            while (i < 4 and not(g.in_range(v_rc) and\
    \ g.valid(v_rc)))\n            {\n                ++i;\n                if (i\
    \ < 4)\n                    v_rc = u_rc + cardinal_directions[i];\n          \
    \  }\n        }\n\n        pair<int, W> operator*() const\n        {\n       \
    \     if (i == 4)\n                throw out_of_range(\"Trying to derefernce end.\"\
    );\n            return make_pair(g.id(v_rc), g.cost(u_rc, v_rc));\n        }\n\
    \        neighbor_view &operator++()\n        {\n            ++i;\n          \
    \  if ((i = min(i, 4)) == 4)\n                return *this;\n            v_rc\
    \ = u_rc + cardinal_directions[i];\n            while (i < 4 and not(g.in_range(v_rc)\
    \ and g.valid(v_rc)))\n            {\n                ++i;\n                if\
    \ (i < 4)\n                    v_rc = u_rc + cardinal_directions[i];\n       \
    \     }\n            return *this;\n        }\n        inline bool operator==(neighbor_view\
    \ const &other) const\n        {\n            return i == other.i;\n        }\n\
    \        inline bool operator!=(neighbor_view const &other) const\n        {\n\
    \            return i != other.i;\n        }\n        neighbor_view begin() const\
    \ { return neighbor_view(u, 0, g); }\n        neighbor_view end() const { return\
    \ neighbor_view(u, 4, g); }\n    };\n\n    vector<int> neighbors(int u) const\n\
    \    {\n        // todo wrong\n        vector<int> neighbors;\n        auto [r,\
    \ c] = rid(u);\n        if (r > 0 and valid({r - 1, c}))\n            neighbors.emplace(id(r\
    \ - 1, c));\n        if (r < n - 1 and valid({r + 1, c}))\n            neighbors.emplace(id(r\
    \ + 1, c));\n        if (c > 0 and valid({r, c - 1}))\n            neighbors.emplace(id(r,\
    \ c - 1));\n        if (c < m - 1 and valid({r, c + 1}))\n            neighbors.emplace(id(r,\
    \ c + 1));\n        return neighbors;\n    }\n};\n\n} // namespace cplib\n\n#endif\
    \ // CPLIB_GRIDGRAPH_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  - cplib/utils/grid.hpp
  isVerificationFile: false
  path: cplib/graph/gridgraph.hpp
  requiredBy: []
  timestamp: '2022-01-25 16:37:41-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/gridgraph.hpp
layout: document
redirect_from:
- /library/cplib/graph/gridgraph.hpp
- /library/cplib/graph/gridgraph.hpp.html
title: cplib/graph/gridgraph.hpp
---
