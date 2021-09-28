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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cplib/graphs/base_graph.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef CPLIB_WEIGHTED_GRAPH_HPP\n#define CPLIB_WEIGHTED_GRAPH_HPP\n#include\
    \ \"cplib/graphs/base_graph.hpp\"\n#include <functional>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    template <typename... EdgeContents>\nstruct WeightedGraph : protected BaseGraph<tuple<int,\
    \ EdgeContents...>>\n{\n    using self     = WeightedGraph<EdgeContents...>;\n\
    \    using EdgeType = tuple<int, EdgeContents...>;\n    using BaseType = BaseGraph<EdgeType>;\n\
    \n    using BaseType::add_edge;\n    using BaseType::add_edges;\n    using BaseType::g;\n\
    \    using BaseType::size;\n    using BaseType::operator[];\n    using BaseType::begin;\n\
    \    using BaseType::end;\n\n    WeightedGraph(int n) : BaseType(n) {}\n\n   \
    \ template <typename Visitor>\n    void dfs(int src, Visitor &vis)\n    {\n  \
    \      // 0 unvisited, 1 visiting, 2 visited\n        int         n = g.size();\n\
    \        vector<int> color(n, 0);\n\n        for (int u = 0, n = g.size(); u <\
    \ n; ++u)\n            vis.initialize_vertex(src);\n\n        function<void(int)>\
    \ traverse = [&](int u) {\n            color[u] = 1;\n            vis.discover_vertex(u);\n\
    \            for (auto e : g[u])\n            {\n                int  v    = get<0>(e);\n\
    \                auto edge = tuple_cat(make_tuple(u), e);\n                apply([&vis](int\
    \ u,\n                             auto &&...args) { vis.examine_edge(u, args...);\
    \ },\n                      edge);\n\n                if (color[v] == 0)\n   \
    \             {\n                    apply(\n                        [&vis](int\
    \ u, auto &&...args) {\n                            vis.on_tree_edge(u, args...);\n\
    \                        },\n                        edge);\n                \
    \    traverse(v);\n                    apply(\n                        [&vis](int\
    \ u, auto &&...args) {\n                            vis.off_tree_edge(u, args...);\n\
    \                        },\n                        edge);\n                }\n\
    \                else if (color[v] == 1)\n                    apply([&vis](int\
    \ u,\n                                 auto &&...args) { vis.back_edge(u, args...);\
    \ },\n                          edge);\n                else\n               \
    \     apply(\n                        [&vis](int u, auto &&...args) {\n      \
    \                      vis.cross_edge(u, args...);\n                        },\n\
    \                        edge);\n                apply([&vis](int u,\n       \
    \                      auto &&...args) { vis.finish_edge(u, args...); },\n   \
    \                   edge);\n            }\n            color[u] = 2;\n       \
    \     vis.finish_vertex(u);\n        };\n\n        vis.start_search(src), traverse(src),\
    \ vis.end_search(src);\n        for (int u = 0; u < n; ++u)\n            if (color[u]\
    \ == 0)\n                vis.start_search(u), traverse(u), vis.end_search(u);\n\
    \    }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_WEIGHTED_GRAPH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/weighted_graph.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/weighted_graph.hpp
layout: document
redirect_from:
- /library/cplib/experimental/weighted_graph.hpp
- /library/cplib/experimental/weighted_graph.hpp.html
title: cplib/experimental/weighted_graph.hpp
---
