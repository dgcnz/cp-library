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
  bundledCode: "#line 1 \"cplib/experimental/base_graph.hpp\"\n\n\n\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \n// TODO: allocator template -> Create class ordered_base_graph\n// TODO: undirected\
    \ edges\ntemplate <typename T>\nstruct BaseGraph\n{\n    using self       = BaseGraph<T>;\n\
    \    using value_type = vector<T>;\n\n  protected:\n    vector<vector<T>> g;\n\
    \    BaseGraph(int n) : g(n) {}\n\n    template <bool DIRECTED = true, typename...\
    \ Types>\n    void add_edges(vector<tuple<int, int, Types...>> edges)\n    {\n\
    \        auto f = [this](int u, int v, auto &&...args) {\n            add_edge(u,\
    \ v, args...);\n        };\n        auto g = [this](int u, int v, auto &&...args)\
    \ {\n            add_edge(v, u, args...);\n        };\n        for (auto e : edges)\n\
    \        {\n            apply(f, e);\n            if (!DIRECTED)\n           \
    \     apply(g, e);\n        }\n    }\n\n    template <bool DIRECTED=true, typename...\
    \ Types>\n    void add_edge(int u, int v, Types... t)\n    {\n        g[u].emplace_back(v,\
    \ t...);\n        if (!DIRECTED)\n            g[v].emplace_back(u, t...);\n  \
    \  }\n\n    size_t     size() const { return g.size(); }\n    vector<T> &operator[](int\
    \ u) { return g[u]; }\n    vector<T>  operator[](int u) const { return g[u]; }\n\
    \n    typename vector<vector<T>>::iterator begin() { return g.begin(); };\n  \
    \  typename vector<vector<T>>::iterator end() { return g.end(); }\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_BASE_GRAPH_HPP\n#define CPLIB_BASE_GRAPH_HPP\n\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \n// TODO: allocator template -> Create class ordered_base_graph\n// TODO: undirected\
    \ edges\ntemplate <typename T>\nstruct BaseGraph\n{\n    using self       = BaseGraph<T>;\n\
    \    using value_type = vector<T>;\n\n  protected:\n    vector<vector<T>> g;\n\
    \    BaseGraph(int n) : g(n) {}\n\n    template <bool DIRECTED = true, typename...\
    \ Types>\n    void add_edges(vector<tuple<int, int, Types...>> edges)\n    {\n\
    \        auto f = [this](int u, int v, auto &&...args) {\n            add_edge(u,\
    \ v, args...);\n        };\n        auto g = [this](int u, int v, auto &&...args)\
    \ {\n            add_edge(v, u, args...);\n        };\n        for (auto e : edges)\n\
    \        {\n            apply(f, e);\n            if (!DIRECTED)\n           \
    \     apply(g, e);\n        }\n    }\n\n    template <bool DIRECTED=true, typename...\
    \ Types>\n    void add_edge(int u, int v, Types... t)\n    {\n        g[u].emplace_back(v,\
    \ t...);\n        if (!DIRECTED)\n            g[v].emplace_back(u, t...);\n  \
    \  }\n\n    size_t     size() const { return g.size(); }\n    vector<T> &operator[](int\
    \ u) { return g[u]; }\n    vector<T>  operator[](int u) const { return g[u]; }\n\
    \n    typename vector<vector<T>>::iterator begin() { return g.begin(); };\n  \
    \  typename vector<vector<T>>::iterator end() { return g.end(); }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_BASE_GRAPH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/base_graph.hpp
  requiredBy: []
  timestamp: '2021-09-28 18:42:31-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/base_graph.hpp
layout: document
redirect_from:
- /library/cplib/experimental/base_graph.hpp
- /library/cplib/experimental/base_graph.hpp.html
title: cplib/experimental/base_graph.hpp
---
