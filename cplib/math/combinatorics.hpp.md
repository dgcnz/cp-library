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
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <int\
    \ NMAX, typename mint>\nstruct Combinations\n{\n    vector<mint> fact, inv_fact;\n\
    \n    Combinations(void) { precompute(NMAX + 1); }\n\n    void precompute(int\
    \ len)\n    {\n        fact.resize(len), inv_fact.resize(len);\n        inv_fact[0]\
    \ = fact[0] = 1;\n        for (int i = 1; i < len; i++)\n        {\n         \
    \   inv_fact[i] = inv_fact[i - 1] * mint(i).inv();\n            fact[i]     =\
    \ fact[i - 1] * i;\n        }\n    }\n\n    mint C(int n, int k) const\n    {\n\
    \        assert(int(fact.size()) > n);\n        if (k > n or k < 0)\n        \
    \    return 0;\n        return fact[n] * inv_fact[k] * inv_fact[n - k];\n    }\n\
    \n    mint factorial(int n)\n    {\n        assert(int(fact.size()) > n);\n  \
    \      return fact[n];\n    }\n\n    mint inverse_factorial(int n)\n    {\n  \
    \      assert(int(fact.size()) > n);\n        return inv_fact[n];\n    }\n   \
    \ mint operator()(int n, int k) const { return C(n, k); }\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_COMBINATORICS_HPP\n#define CPLIB_COMBINATORICS_HPP\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    template <int NMAX, typename mint>\nstruct Combinations\n{\n    vector<mint> fact,\
    \ inv_fact;\n\n    Combinations(void) { precompute(NMAX + 1); }\n\n    void precompute(int\
    \ len)\n    {\n        fact.resize(len), inv_fact.resize(len);\n        inv_fact[0]\
    \ = fact[0] = 1;\n        for (int i = 1; i < len; i++)\n        {\n         \
    \   inv_fact[i] = inv_fact[i - 1] * mint(i).inv();\n            fact[i]     =\
    \ fact[i - 1] * i;\n        }\n    }\n\n    mint C(int n, int k) const\n    {\n\
    \        assert(int(fact.size()) > n);\n        if (k > n or k < 0)\n        \
    \    return 0;\n        return fact[n] * inv_fact[k] * inv_fact[n - k];\n    }\n\
    \n    mint factorial(int n)\n    {\n        assert(int(fact.size()) > n);\n  \
    \      return fact[n];\n    }\n\n    mint inverse_factorial(int n)\n    {\n  \
    \      assert(int(fact.size()) > n);\n        return inv_fact[n];\n    }\n   \
    \ mint operator()(int n, int k) const { return C(n, k); }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_COMBINATORICS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/combinatorics.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/combinatorics.hpp
layout: document
redirect_from:
- /library/cplib/math/combinatorics.hpp
- /library/cplib/math/combinatorics.hpp.html
title: cplib/math/combinatorics.hpp
---
