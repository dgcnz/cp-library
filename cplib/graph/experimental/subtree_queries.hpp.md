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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cplib/graphs/dfs_visitor.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef CPLIB_SUBTREE_QUERIES_HPP\n#define CPLIB_SUBTREE_QUERIES_HPP\n\n\
    #include \"cplib/graphs/dfs_visitor.hpp\"\n#include \"cplib/graphs/unweighted_tree.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace cplib\n{\ntemplate <template\
    \ <class S, S (*op)(S, S), S (*e)()> class segtree,\n          class S,\n    \
    \      S (*op)(S, S),\n          S (*e)()>\nstruct SubtreeQueries\n{\n    using\
    \ SegmentTree = segtree<S, op, e>;\n    using Tree        = UnweightedTree;\n\n\
    \    int         n;\n    SegmentTree st;\n    vector<S>   values;\n    vector<int>\
    \ id, sz;\n\n    SubtreeQueries(const Tree &g, int root, vector<S> values)\n \
    \       : n(g.size()), st(n), id(n), sz(n)\n    {\n        struct Visitor : public\
    \ virtual DFSVisitor<Tree>\n        {\n            int          timer = 0;\n \
    \           vector<int> &id, &sz;\n            Visitor(const Tree &g, vector<int>\
    \ &id, vector<int> &sz)\n                : DFSVisitor<Tree>(g), id(id), sz(sz){};\n\
    \            void discover_vertex(int u) { id[u] = timer++, sz[id[u]] = 1; }\n\
    \            void off_tree_edge(int u, int v) { sz[id[u]] += sz[id[v]]; }\n  \
    \      } vis(g, id, sz);\n\n        g.dfs(root, vis);\n        for (int u = 0;\
    \ u < n; ++u)\n            st.set(id[u], values[u]);\n    }\n\n    S query(int\
    \ u)\n    {\n        assert(0 <= u and u < n);\n        return st.prod(id[u],\
    \ id[u] + sz[id[u]]);\n    }\n\n    void set(int u, S x)\n    {\n        assert(0\
    \ <= u and u < n);\n        st.set(id[u], x);\n    }\n};\n} // namespace cplib\n\
    \n#endif // CPLIB_SUBTREE_QUERIES_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/experimental/subtree_queries.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/experimental/subtree_queries.hpp
layout: document
redirect_from:
- /library/cplib/graph/experimental/subtree_queries.hpp
- /library/cplib/graph/experimental/subtree_queries.hpp.html
title: cplib/graph/experimental/subtree_queries.hpp
---
