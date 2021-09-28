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
  bundledCode: "#line 1 \"cplib/math/combinatorics.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <typename\
    \ MOD_T>\nstruct Combinatorics\n{\n    vector<MOD_T> fact, inv_fact;\n\n    Combinatorics(int\
    \ n)\n    {\n        assert(0 <= n and n <= 1e8);\n        precompute(n);\n  \
    \  }\n\n    void precompute(int n)\n    {\n        if (n <= (int)fact.size())\n\
    \            return;\n\n        fact.resize(n), inv_fact.resize(n);\n        inv_fact[0]\
    \ = fact[0] = 1;\n        for (int i = 1; i < n; i++)\n        {\n           \
    \ inv_fact[i] = inv_fact[i - 1] / i;\n            fact[i]     = fact[i - 1] *\
    \ i;\n        }\n    }\n\n    MOD_T C(int n, int k) const\n    {\n        assert(int(fact.size())\
    \ > n);\n        if (k > n or k < 0)\n            return 0;\n        return fact[n]\
    \ * inv_fact[k] * inv_fact[n - k];\n    }\n\n    MOD_T factorial(int n)\n    {\n\
    \        assert(int(fact.size()) > n);\n        return fact[n];\n    }\n\n   \
    \ MOD_T inverse_factorial(int n)\n    {\n        assert(int(fact.size()) > n);\n\
    \        return inv_fact[n];\n    }\n    MOD_T operator()(int n, int k) const\
    \ { return C(n, k); }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_COMBINATORICS_HPP\n#define CPLIB_COMBINATORICS_HPP\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    template <typename MOD_T>\nstruct Combinatorics\n{\n    vector<MOD_T> fact, inv_fact;\n\
    \n    Combinatorics(int n)\n    {\n        assert(0 <= n and n <= 1e8);\n    \
    \    precompute(n);\n    }\n\n    void precompute(int n)\n    {\n        if (n\
    \ <= (int)fact.size())\n            return;\n\n        fact.resize(n), inv_fact.resize(n);\n\
    \        inv_fact[0] = fact[0] = 1;\n        for (int i = 1; i < n; i++)\n   \
    \     {\n            inv_fact[i] = inv_fact[i - 1] / i;\n            fact[i] \
    \    = fact[i - 1] * i;\n        }\n    }\n\n    MOD_T C(int n, int k) const\n\
    \    {\n        assert(int(fact.size()) > n);\n        if (k > n or k < 0)\n \
    \           return 0;\n        return fact[n] * inv_fact[k] * inv_fact[n - k];\n\
    \    }\n\n    MOD_T factorial(int n)\n    {\n        assert(int(fact.size()) >\
    \ n);\n        return fact[n];\n    }\n\n    MOD_T inverse_factorial(int n)\n\
    \    {\n        assert(int(fact.size()) > n);\n        return inv_fact[n];\n \
    \   }\n    MOD_T operator()(int n, int k) const { return C(n, k); }\n};\n} //\
    \ namespace cplib\n\n#endif // CPLIB_COMBINATORICS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/combinatorics.hpp
  requiredBy: []
  timestamp: '2021-09-28 13:06:15-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/combinatorics.hpp
layout: document
redirect_from:
- /library/cplib/math/combinatorics.hpp
- /library/cplib/math/combinatorics.hpp.html
title: cplib/math/combinatorics.hpp
---
