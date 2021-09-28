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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: cplib/graphs/unweighted_graph.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef CPLIB_UNWEIGHTED_TREE_HPP\n#define CPLIB_UNWEIGHTED_TREE_HPP\n#include\
    \ \"cplib/graphs/unweighted_graph.hpp\"\n#include <functional>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace cplib\n{\nstruct UnweightedTree\
    \ : public UnweightedGraph\n{\n    using BaseType = UnweightedGraph;\n    using\
    \ BaseType::add_edge;\n    using BaseType::add_edges;\n    using BaseType::g;\n\
    \    using BaseType::size;\n    using BaseType::operator[];\n    using BaseType::begin;\n\
    \    using BaseType::dfs;\n    using BaseType::end;\n\n    UnweightedTree(int\
    \ n) : UnweightedGraph(n){};\n};\n\n} // namespace cplib\n\n#endif // CPLIB_UNWEIGHTED_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/unweighted_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/unweighted_tree.hpp
layout: document
redirect_from:
- /library/cplib/experimental/unweighted_tree.hpp
- /library/cplib/experimental/unweighted_tree.hpp.html
title: cplib/experimental/unweighted_tree.hpp
---
