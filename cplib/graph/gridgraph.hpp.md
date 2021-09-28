---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/graph/graph.hpp
    title: cplib/graph/graph.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_state.hpp
    title: cplib/utils/lazy_state.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_view.hpp
    title: cplib/utils/lazy_view.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/gridgraph.hpp\"\n\n\n\n#include <cplib/graph/graph>\n\
    #include <cplib/utils/lazy_view>\n#include <functional>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename W>\n\
    struct GridGraph\n{\n    using ii       = pair<int, int>;\n    using adj_list\
    \ = vector<pair<int, W>>;\n\n    vector<string> const &table;\n    int       \
    \            n, m;\n    Graph<W>              g;\n    function<bool(ii)>    valid;\n\
    \    function<W(ii, ii)>   cost;\n\n    GridGraph(vector<string> const &table,\n\
    \              function<bool(ii)>    valid,\n              function<W(ii, ii)>\
    \   cost)\n        : table(table), n(table.size()), m(table[0].size()), g(n *\
    \ m),\n          valid(valid), cost(cost)\n    {\n        build();\n    }\n  \
    \  adj_list &  operator[](int u) { return g[u]; }\n    adj_list    operator[](int\
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
    \ ii       = pair<int, int>;\n    using adj_list = vector<pair<int, W>>;\n   \
    \ vector<string> const &table;\n    int                   n, m;\n    function<bool(ii)>\
    \    valid;\n    function<W(ii, ii)>   cost;\n    vector<ii> const      dir =\
    \ {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};\n\n    ImplicitGridGraph(vector<string>\
    \ const &table,\n                      function<bool(ii)>    valid,\n        \
    \              function<W(ii, ii)>   cost)\n        : table(table), n(table.size()),\
    \ m(table[0].size()), valid(valid),\n          cost(cost)\n    {\n    }\n    size_t\
    \      size() const { return n * m; }\n    inline ii   rid(int u) const { return\
    \ {u / m, u % m}; }\n    inline int  id(int r, int c) const { return r * m + c;\
    \ }\n    inline int  id(ii pos) const { return pos.first * m + pos.second; }\n\
    \    inline bool in_range(int r, int c) const\n    {\n        return 0 <= r and\
    \ r < n and 0 <= c and c < m;\n    }\n    inline bool in_range(ii rc) const {\
    \ return in_range(rc.first, rc.second); }\n\n    struct neighbor_state : public\
    \ LazyState<ii>\n    {\n        int                         u, ix;\n        ImplicitGridGraph<W>\
    \ const &g;\n        neighbor_state(int u, int ix, ImplicitGridGraph<W> const\
    \ &g)\n            : u(u), ix(ix), g(g)\n        {\n        }\n\n        bool\
    \ is_valid() const\n        {\n            auto [ur, uc] = g.rid(u);\n       \
    \     auto [dr, dc] = g.dir[ix];\n            return g.in_range(ur + dr, uc +\
    \ dc) and\n                   g.valid(ii{ur + dr, uc + dc});\n        }\n\n  \
    \      ii value() const\n        {\n            auto [ur, uc] = g.rid(u);\n  \
    \          auto [dr, dc] = g.dir[ix];\n            auto v        = g.id(ur + dr,\
    \ uc + dc);\n            auto w        = g.cost(ii{ur, uc}, ii{ur + dr, uc + dc});\n\
    \            return ii{v, w};\n        }\n        void next()\n        {\n   \
    \         if (ix < 4)\n                ++ix;\n            while (ix < 4 and not\
    \ is_valid())\n                ++ix;\n        }\n        void init()\n       \
    \ {\n            if (not is_valid())\n                next();\n        };\n  \
    \      bool terminated() const { return ix >= 4; };\n    };\n\n    lazy_view<neighbor_state,\
    \ ii> operator[](int u) const\n    {\n        neighbor_state s{u, 0, *this};\n\
    \        s.init();\n        return lazy_view<neighbor_state, ii>(s, s.terminated());\n\
    \    }\n\n    vector<int> neighbors(int u) const\n    {\n        vector<int> neighbors;\n\
    \        auto [r, c] = rid(u);\n        if (r > 0 and valid({r - 1, c}))\n   \
    \         neighbors.emplace(id(r - 1, c));\n        if (r < n - 1 and valid({r\
    \ + 1, c}))\n            neighbors.emplace(id(r + 1, c));\n        if (c > 0 and\
    \ valid({r, c - 1}))\n            neighbors.emplace(id(r, c - 1));\n        if\
    \ (c < m - 1 and valid({r, c + 1}))\n            neighbors.emplace(id(r, c + 1));\n\
    \        return neighbors;\n    }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_GRIDGRAPH_HPP\n#define CPLIB_GRIDGRAPH_HPP\n\n#include <cplib/graph/graph>\n\
    #include <cplib/utils/lazy_view>\n#include <functional>\n#include <string>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename W>\n\
    struct GridGraph\n{\n    using ii       = pair<int, int>;\n    using adj_list\
    \ = vector<pair<int, W>>;\n\n    vector<string> const &table;\n    int       \
    \            n, m;\n    Graph<W>              g;\n    function<bool(ii)>    valid;\n\
    \    function<W(ii, ii)>   cost;\n\n    GridGraph(vector<string> const &table,\n\
    \              function<bool(ii)>    valid,\n              function<W(ii, ii)>\
    \   cost)\n        : table(table), n(table.size()), m(table[0].size()), g(n *\
    \ m),\n          valid(valid), cost(cost)\n    {\n        build();\n    }\n  \
    \  adj_list &  operator[](int u) { return g[u]; }\n    adj_list    operator[](int\
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
    \ ii       = pair<int, int>;\n    using adj_list = vector<pair<int, W>>;\n   \
    \ vector<string> const &table;\n    int                   n, m;\n    function<bool(ii)>\
    \    valid;\n    function<W(ii, ii)>   cost;\n    vector<ii> const      dir =\
    \ {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};\n\n    ImplicitGridGraph(vector<string>\
    \ const &table,\n                      function<bool(ii)>    valid,\n        \
    \              function<W(ii, ii)>   cost)\n        : table(table), n(table.size()),\
    \ m(table[0].size()), valid(valid),\n          cost(cost)\n    {\n    }\n    size_t\
    \      size() const { return n * m; }\n    inline ii   rid(int u) const { return\
    \ {u / m, u % m}; }\n    inline int  id(int r, int c) const { return r * m + c;\
    \ }\n    inline int  id(ii pos) const { return pos.first * m + pos.second; }\n\
    \    inline bool in_range(int r, int c) const\n    {\n        return 0 <= r and\
    \ r < n and 0 <= c and c < m;\n    }\n    inline bool in_range(ii rc) const {\
    \ return in_range(rc.first, rc.second); }\n\n    struct neighbor_state : public\
    \ LazyState<ii>\n    {\n        int                         u, ix;\n        ImplicitGridGraph<W>\
    \ const &g;\n        neighbor_state(int u, int ix, ImplicitGridGraph<W> const\
    \ &g)\n            : u(u), ix(ix), g(g)\n        {\n        }\n\n        bool\
    \ is_valid() const\n        {\n            auto [ur, uc] = g.rid(u);\n       \
    \     auto [dr, dc] = g.dir[ix];\n            return g.in_range(ur + dr, uc +\
    \ dc) and\n                   g.valid(ii{ur + dr, uc + dc});\n        }\n\n  \
    \      ii value() const\n        {\n            auto [ur, uc] = g.rid(u);\n  \
    \          auto [dr, dc] = g.dir[ix];\n            auto v        = g.id(ur + dr,\
    \ uc + dc);\n            auto w        = g.cost(ii{ur, uc}, ii{ur + dr, uc + dc});\n\
    \            return ii{v, w};\n        }\n        void next()\n        {\n   \
    \         if (ix < 4)\n                ++ix;\n            while (ix < 4 and not\
    \ is_valid())\n                ++ix;\n        }\n        void init()\n       \
    \ {\n            if (not is_valid())\n                next();\n        };\n  \
    \      bool terminated() const { return ix >= 4; };\n    };\n\n    lazy_view<neighbor_state,\
    \ ii> operator[](int u) const\n    {\n        neighbor_state s{u, 0, *this};\n\
    \        s.init();\n        return lazy_view<neighbor_state, ii>(s, s.terminated());\n\
    \    }\n\n    vector<int> neighbors(int u) const\n    {\n        vector<int> neighbors;\n\
    \        auto [r, c] = rid(u);\n        if (r > 0 and valid({r - 1, c}))\n   \
    \         neighbors.emplace(id(r - 1, c));\n        if (r < n - 1 and valid({r\
    \ + 1, c}))\n            neighbors.emplace(id(r + 1, c));\n        if (c > 0 and\
    \ valid({r, c - 1}))\n            neighbors.emplace(id(r, c - 1));\n        if\
    \ (c < m - 1 and valid({r, c + 1}))\n            neighbors.emplace(id(r, c + 1));\n\
    \        return neighbors;\n    }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_GRIDGRAPH_HPP\n"
  dependsOn:
  - cplib/graph/graph.hpp
  - cplib/utils/lazy_view.hpp
  - cplib/utils/lazy_state.hpp
  isVerificationFile: false
  path: cplib/graph/gridgraph.hpp
  requiredBy: []
  timestamp: '2021-08-21 11:37:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/gridgraph.hpp
layout: document
redirect_from:
- /library/cplib/graph/gridgraph.hpp
- /library/cplib/graph/gridgraph.hpp.html
title: cplib/graph/gridgraph.hpp
---
