---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/math/binary_exponentiation.hpp
    title: cplib/math/binary_exponentiation.hpp
  - icon: ':warning:'
    path: cplib/utils/misc.hpp
    title: cplib/utils/misc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/math/pfint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cplib/math/binary_exponentiation>\n#include <cplib/utils/misc>\n#include <utility>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\nstruct pfint\n\
    {\n    vector<pair<int, int>> pf;\n    bool                   zero;\n\n    pfint()\
    \ : zero(true) {}\n    pfint(vector<pair<int, int>> pf, bool zero = false) : pf(pf),\
    \ zero(zero) {}\n\n    template <typename T>\n    T val() const\n    {\n     \
    \   T ans = 1;\n        for (auto [p, e] : pf)\n            ans *= binpow(T(p),\
    \ e);\n        return ans;\n    }\n    static pfint    e() { return {{}, true};\
    \ }\n    size_t          size() const { return pf.size(); }\n    pair<int, int>\
    \ &operator[](int i)\n    {\n        assert(0 <= i and i < (int)pf.size());\n\
    \        return pf[i];\n    }\n\n    const pair<int, int> &operator[](int i) const\n\
    \    {\n        assert(0 <= i and i < (int)pf.size());\n        return pf[i];\n\
    \    }\n\n    pfint operator*(pfint a) const\n    {\n        /*\n         * Takes\
    \ the union/aggrefation of prime factors of both numbers\n         */\n      \
    \  if (zero or a.zero)\n            return this->e();\n        return map_union(pf,\
    \ a.pf);\n    }\n    friend pfint gcd(pfint a, pfint b)\n    {\n        /*\n \
    \        * Takes the intersection of prime factors of both numbers\n         */\n\
    \        if (a.zero)\n            return b;\n        if (b.zero)\n           \
    \ return a;\n        return map_intersection(a.pf, b.pf);\n    };\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_PFINT_HPP\n#define CPLIB_PFINT_HPP\n\n#include <cassert>\n\
    #include <cplib/math/binary_exponentiation>\n#include <cplib/utils/misc>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\nstruct\
    \ pfint\n{\n    vector<pair<int, int>> pf;\n    bool                   zero;\n\
    \n    pfint() : zero(true) {}\n    pfint(vector<pair<int, int>> pf, bool zero\
    \ = false) : pf(pf), zero(zero) {}\n\n    template <typename T>\n    T val() const\n\
    \    {\n        T ans = 1;\n        for (auto [p, e] : pf)\n            ans *=\
    \ binpow(T(p), e);\n        return ans;\n    }\n    static pfint    e() { return\
    \ {{}, true}; }\n    size_t          size() const { return pf.size(); }\n    pair<int,\
    \ int> &operator[](int i)\n    {\n        assert(0 <= i and i < (int)pf.size());\n\
    \        return pf[i];\n    }\n\n    const pair<int, int> &operator[](int i) const\n\
    \    {\n        assert(0 <= i and i < (int)pf.size());\n        return pf[i];\n\
    \    }\n\n    pfint operator*(pfint a) const\n    {\n        /*\n         * Takes\
    \ the union/aggrefation of prime factors of both numbers\n         */\n      \
    \  if (zero or a.zero)\n            return this->e();\n        return map_union(pf,\
    \ a.pf);\n    }\n    friend pfint gcd(pfint a, pfint b)\n    {\n        /*\n \
    \        * Takes the intersection of prime factors of both numbers\n         */\n\
    \        if (a.zero)\n            return b;\n        if (b.zero)\n           \
    \ return a;\n        return map_intersection(a.pf, b.pf);\n    };\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_PFINT_HPP\n"
  dependsOn:
  - cplib/math/binary_exponentiation.hpp
  - cplib/utils/misc.hpp
  isVerificationFile: false
  path: cplib/math/pfint.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/pfint.hpp
layout: document
redirect_from:
- /library/cplib/math/pfint.hpp
- /library/cplib/math/pfint.hpp.html
title: cplib/math/pfint.hpp
---
