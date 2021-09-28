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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cplib/graphs/lca.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef CPLIB_PATH_QUERIES_HPP\n#define CPLIB_PATH_QUERIES_HPP\n\n#include\
    \ \"cplib/graphs/lca.hpp\"\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ cplib\n{\ntemplate <template <class S, S (*op)(S, S), S (*e)()> class segtree,\n\
    \          class S,\n          S (*op)(S, S),\n          S (*e)(),\n         \
    \ S (*inv)(S)>\nstruct PathQueries\n{\n    int                 n;\n    vector<vector<int>>\
    \ g;\n    LCA                 lca;\n    segtree<S, op, e>   st;\n    vector<S>\
    \           values;\n    vector<int>         id, sz;\n\n    PathQueries(int n)\
    \ : g(n), lca(n), st(n) {}\n\n    void add_edge(int u, int v)\n    {\n       \
    \ lca.add_edge(u, v);\n        g[u].push_back(v), g[v].push_back(u);\n    }\n\n\
    \    S query(int u) const\n    {\n        assert(0 <= u and u < n);\n        return\
    \ st.prod(id[u], id[u] + sz[id[u]]);\n    }\n\n    void set(int u, S x)\n    {\n\
    \        assert(0 <= u and u < n);\n        st.set(id[u], x);\n    }\n};\n} //\
    \ namespace cplib\n\n#endif // CPLIB_PATH_QUERIES_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/experimental/path_queries.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/experimental/path_queries.hpp
layout: document
redirect_from:
- /library/cplib/graph/experimental/path_queries.hpp
- /library/cplib/graph/experimental/path_queries.hpp.html
title: cplib/graph/experimental/path_queries.hpp
---
