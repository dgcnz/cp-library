---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/math/binary_exponentiation.hpp
    title: cplib/math/binary_exponentiation.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/math/modint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cplib/math/binary_exponentiation>\n#include <vector>\n\nnamespace cplib\n{\n\
    using namespace std;\n\ntemplate <int M>\nclass ModInt\n{\n    using ll   = long\
    \ long;\n    using mint = ModInt<M>;\n    ll x;\n\n  public:\n    static const\
    \ int           MOD = M;\n    inline static vector<mint> inverse{0, 1};\n\n  \
    \  ModInt(ll x) : x(x) {}\n    ModInt() : x(0) {}\n    ModInt(mint const &y) :\
    \ x(y.val()) {}\n    explicit  operator ll() const { return val(); }\n    explicit\
    \  operator int() const { return val(); }\n    ll        val(void) const { return\
    \ mint::val(x); }\n    int       mod() const { return MOD; }\n    mint      pow(ll\
    \ n) const { return binpow(val(), n); }\n    static ll val(ll x)\n    {\n    \
    \    if (x < 0)\n            return x + M;\n        return (x >= M ? x % M : x);\n\
    \    }\n    mint &operator=(mint const &y)\n    {\n        x = y.val();\n    \
    \    return *this;\n    }\n    mint &operator=(ll const &y) { return operator=(mint(y));\
    \ }\n    mint &operator+=(mint const &y) { return operator=(operator+(y)); }\n\
    \    mint &operator-=(mint const &y) { return operator=(operator-(y)); }\n   \
    \ mint &operator*=(mint const &y) { return operator=(operator*(y)); }\n    mint\
    \  operator+(mint const &y) const { return mint::val(val() + y.val()); }\n   \
    \ mint  operator+(ll const &y) const { return operator+(mint(y)); }\n    mint\
    \  operator-(mint const &y) const { return mint::val(val() - y.val()); }\n   \
    \ mint  operator-(ll const &y) const { return operator-(mint(y)); }\n    mint\
    \  operator*(mint const &y) const { return mint::val(val() * y.val()); }\n   \
    \ mint  operator*(ll const &y) const { return operator*(mint(y)); }\n    mint\
    \  operator/(mint const &y) const { return operator*(y.inv()); }\n    mint  operator/(ll\
    \ const &y) const { return operator*(mint::inv(y)); }\n\n    static void precompute_inverses(int\
    \ len)\n    {\n        assert(len < 1e8 and len > 0);\n        int plen = inverse.size();\n\
    \        if (len > plen)\n        {\n            inverse.resize(len);\n      \
    \      for (int i = plen; i < len; ++i)\n                inverse[i] = MOD - ll(inverse[MOD\
    \ % i] * (MOD / i));\n        }\n    }\n    mint        inv(void) const { return\
    \ mint::inv(val()); }\n    static mint inv(ll x)\n    {\n        assert(x > 0);\n\
    \        if (x < ll(inverse.size()))\n            return inverse[x];\n       \
    \ return binpow(mint(x), MOD - 2);\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_MODINT_HPP\n#define CPLIB_MODINT_HPP\n\n#include <cassert>\n\
    #include <cplib/math/binary_exponentiation>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <int M>\nclass ModInt\n{\n    using ll   =\
    \ long long;\n    using mint = ModInt<M>;\n    ll x;\n\n  public:\n    static\
    \ const int           MOD = M;\n    inline static vector<mint> inverse{0, 1};\n\
    \n    ModInt(ll x) : x(x) {}\n    ModInt() : x(0) {}\n    ModInt(mint const &y)\
    \ : x(y.val()) {}\n    explicit  operator ll() const { return val(); }\n    explicit\
    \  operator int() const { return val(); }\n    ll        val(void) const { return\
    \ mint::val(x); }\n    int       mod() const { return MOD; }\n    mint      pow(ll\
    \ n) const { return binpow(val(), n); }\n    static ll val(ll x)\n    {\n    \
    \    if (x < 0)\n            return x + M;\n        return (x >= M ? x % M : x);\n\
    \    }\n    mint &operator=(mint const &y)\n    {\n        x = y.val();\n    \
    \    return *this;\n    }\n    mint &operator=(ll const &y) { return operator=(mint(y));\
    \ }\n    mint &operator+=(mint const &y) { return operator=(operator+(y)); }\n\
    \    mint &operator-=(mint const &y) { return operator=(operator-(y)); }\n   \
    \ mint &operator*=(mint const &y) { return operator=(operator*(y)); }\n    mint\
    \  operator+(mint const &y) const { return mint::val(val() + y.val()); }\n   \
    \ mint  operator+(ll const &y) const { return operator+(mint(y)); }\n    mint\
    \  operator-(mint const &y) const { return mint::val(val() - y.val()); }\n   \
    \ mint  operator-(ll const &y) const { return operator-(mint(y)); }\n    mint\
    \  operator*(mint const &y) const { return mint::val(val() * y.val()); }\n   \
    \ mint  operator*(ll const &y) const { return operator*(mint(y)); }\n    mint\
    \  operator/(mint const &y) const { return operator*(y.inv()); }\n    mint  operator/(ll\
    \ const &y) const { return operator*(mint::inv(y)); }\n\n    static void precompute_inverses(int\
    \ len)\n    {\n        assert(len < 1e8 and len > 0);\n        int plen = inverse.size();\n\
    \        if (len > plen)\n        {\n            inverse.resize(len);\n      \
    \      for (int i = plen; i < len; ++i)\n                inverse[i] = MOD - ll(inverse[MOD\
    \ % i] * (MOD / i));\n        }\n    }\n    mint        inv(void) const { return\
    \ mint::inv(val()); }\n    static mint inv(ll x)\n    {\n        assert(x > 0);\n\
    \        if (x < ll(inverse.size()))\n            return inverse[x];\n       \
    \ return binpow(mint(x), MOD - 2);\n    }\n};\n} // namespace cplib\n\n#endif\
    \ // CPLIB_MODINT_HPP\n"
  dependsOn:
  - cplib/math/binary_exponentiation.hpp
  isVerificationFile: false
  path: cplib/math/modint.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/modint.hpp
layout: document
redirect_from:
- /library/cplib/math/modint.hpp
- /library/cplib/math/modint.hpp.html
title: cplib/math/modint.hpp
---
