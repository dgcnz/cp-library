---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://hitonanode.github.io/cplib-cpp/other_algorithms/mos_algorithm.hpp
  bundledCode: "#line 1 \"cplib/data_structure/mo.hpp\"\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\n// source:\n// https://hitonanode.github.io/cplib-cpp/other_algorithms/mos_algorithm.hpp\n\
    \nnamespace cplib\n{\nusing namespace std;\n\nclass Mo\n{\n    static const int\
    \ INF = 1 << 30;\n    int              nmin, nmax;\n\n  public:\n    vector<pair<int,\
    \ int>> ranges;\n    Mo() : nmin(INF), nmax(-INF) {}\n\n    void add_range(int\
    \ l, int r)\n    {\n        assert(l <= r);\n        nmin = min(nmin, l);\n  \
    \      nmax = max(nmax, r);\n        ranges.emplace_back(l, r);\n    }\n    template\
    \ <typename F1, typename F2, typename F3, typename F4, typename F5>\n    void\
    \ run(F1 Query, F2 AddLeft, F3 RemoveLeft, F4 AddRight, F5 RemoveRight)\n    {\n\
    \        const int Q = ranges.size();\n        if (!Q)\n            return;\n\
    \        const int   nbbucket = max(1, min<int>(nmax - nmin, sqrt(Q)));\n    \
    \    const int   szbucket = (nmax - nmin + nbbucket - 1) / nbbucket;\n       \
    \ vector<int> qs(Q);\n        iota(qs.begin(), qs.end(), 0);\n        sort(qs.begin(),\n\
    \             qs.end(),\n             [&](int q1, int q2)\n             {\n  \
    \               int b1 = (ranges[q1].first - nmin) / szbucket,\n             \
    \        b2 = (ranges[q2].first - nmin) / szbucket;\n                 if (b1 !=\
    \ b2)\n                     return b1 < b2;\n                 else\n         \
    \            return (b1 & 1) ? (ranges[q1].second > ranges[q2].second)\n     \
    \                                : (ranges[q1].second < ranges[q2].second);\n\
    \             });\n\n        int l = ranges[qs[0]].first, r = l;\n        for\
    \ (auto q : qs)\n        {\n            while (r < ranges[q].second)\n       \
    \         AddRight(r++);\n            while (l > ranges[q].first)\n          \
    \      AddLeft(--l);\n            while (r > ranges[q].second)\n             \
    \   RemoveRight(--r);\n            while (l < ranges[q].first)\n             \
    \   RemoveLeft(l++);\n            assert(l == ranges[q].first and r == ranges[q].second);\n\
    \            Query(q);\n        }\n    }\n    template <typename F1, typename\
    \ F2, typename F3>\n    void run(F1 Query, F2 Add, F3 Remove)\n    {\n       \
    \ run(Query, Add, Remove, Add, Remove);\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_MO_HPP\n#define CPLIB_MO_HPP\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <numeric>\n#include <utility>\n#include\
    \ <vector>\n\n// source:\n// https://hitonanode.github.io/cplib-cpp/other_algorithms/mos_algorithm.hpp\n\
    \nnamespace cplib\n{\nusing namespace std;\n\nclass Mo\n{\n    static const int\
    \ INF = 1 << 30;\n    int              nmin, nmax;\n\n  public:\n    vector<pair<int,\
    \ int>> ranges;\n    Mo() : nmin(INF), nmax(-INF) {}\n\n    void add_range(int\
    \ l, int r)\n    {\n        assert(l <= r);\n        nmin = min(nmin, l);\n  \
    \      nmax = max(nmax, r);\n        ranges.emplace_back(l, r);\n    }\n    template\
    \ <typename F1, typename F2, typename F3, typename F4, typename F5>\n    void\
    \ run(F1 Query, F2 AddLeft, F3 RemoveLeft, F4 AddRight, F5 RemoveRight)\n    {\n\
    \        const int Q = ranges.size();\n        if (!Q)\n            return;\n\
    \        const int   nbbucket = max(1, min<int>(nmax - nmin, sqrt(Q)));\n    \
    \    const int   szbucket = (nmax - nmin + nbbucket - 1) / nbbucket;\n       \
    \ vector<int> qs(Q);\n        iota(qs.begin(), qs.end(), 0);\n        sort(qs.begin(),\n\
    \             qs.end(),\n             [&](int q1, int q2)\n             {\n  \
    \               int b1 = (ranges[q1].first - nmin) / szbucket,\n             \
    \        b2 = (ranges[q2].first - nmin) / szbucket;\n                 if (b1 !=\
    \ b2)\n                     return b1 < b2;\n                 else\n         \
    \            return (b1 & 1) ? (ranges[q1].second > ranges[q2].second)\n     \
    \                                : (ranges[q1].second < ranges[q2].second);\n\
    \             });\n\n        int l = ranges[qs[0]].first, r = l;\n        for\
    \ (auto q : qs)\n        {\n            while (r < ranges[q].second)\n       \
    \         AddRight(r++);\n            while (l > ranges[q].first)\n          \
    \      AddLeft(--l);\n            while (r > ranges[q].second)\n             \
    \   RemoveRight(--r);\n            while (l < ranges[q].first)\n             \
    \   RemoveLeft(l++);\n            assert(l == ranges[q].first and r == ranges[q].second);\n\
    \            Query(q);\n        }\n    }\n    template <typename F1, typename\
    \ F2, typename F3>\n    void run(F1 Query, F2 Add, F3 Remove)\n    {\n       \
    \ run(Query, Add, Remove, Add, Remove);\n    }\n};\n} // namespace cplib\n\n#endif\
    \ // CPLIB_MO_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/mo.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:44:49-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/mo.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/mo.hpp
- /library/cplib/data_structure/mo.hpp.html
title: cplib/data_structure/mo.hpp
---
