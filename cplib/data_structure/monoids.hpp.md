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
  bundledCode: "#line 1 \"cplib/data_structure/monoids.hpp\"\n\nnamespace cplib\n\
    {\n\nnamespace RangeUpdate\n{\nnamespace Sum\n{\nstruct S\n{\n    int       n;\n\
    \    long long sum;\n};\nS op(S a, S b) { return {a.n + b.n, a.sum + b.sum}; }\n\
    S e() { return {0, 0}; }\nusing F = long long;\nS mapping(F f, S x) { return {x.n,\
    \ x.sum + x.n * f}; }\nF composition(F f, F g) { return f + g; }\nF id() { return\
    \ 0LL; }\n} // namespace Sum\n} // namespace RangeUpdate\n\nnamespace PointUpdate\n\
    {\nnamespace Sum\n{\nusing S = long long;\nS op(S a, S b) { return a + b; }\n\
    S e() { return 0; }\n} // namespace Sum\n\nnamespace Min\n{\nusing S = long long;\n\
    S op(S a, S b) { return (a < b ? a : b); }\nS e() { return 1e18; }\n\n} // namespace\
    \ Min\n} // namespace PointUpdate\n\n}; // namespace cplib\n"
  code: "\nnamespace cplib\n{\n\nnamespace RangeUpdate\n{\nnamespace Sum\n{\nstruct\
    \ S\n{\n    int       n;\n    long long sum;\n};\nS op(S a, S b) { return {a.n\
    \ + b.n, a.sum + b.sum}; }\nS e() { return {0, 0}; }\nusing F = long long;\nS\
    \ mapping(F f, S x) { return {x.n, x.sum + x.n * f}; }\nF composition(F f, F g)\
    \ { return f + g; }\nF id() { return 0LL; }\n} // namespace Sum\n} // namespace\
    \ RangeUpdate\n\nnamespace PointUpdate\n{\nnamespace Sum\n{\nusing S = long long;\n\
    S op(S a, S b) { return a + b; }\nS e() { return 0; }\n} // namespace Sum\n\n\
    namespace Min\n{\nusing S = long long;\nS op(S a, S b) { return (a < b ? a : b);\
    \ }\nS e() { return 1e18; }\n\n} // namespace Min\n} // namespace PointUpdate\n\
    \n}; // namespace cplib\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/monoids.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/monoids.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/monoids.hpp
- /library/cplib/data_structure/monoids.hpp.html
title: cplib/data_structure/monoids.hpp
---
