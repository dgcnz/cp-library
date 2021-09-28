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
  bundledCode: "#line 1 \"cplib/old/modint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cplib/math/binary_exponentiation.hpp>\n#include <vector>\n\ntemplate <int M>\n\
    class ModInt\n{\n    using ll   = long long;\n    using mint = ModInt<M>;\n  \
    \  ll x;\n\n  public:\n    static const int                MOD = M;\n    inline\
    \ static std::vector<mint> inv{0, 1};\n\n    ModInt(ll x) : x(x) {}\n    ModInt()\
    \ : x(0) {}\n    ModInt(mint const &y) : x(y.v()) {}\n    explicit  operator ll()\
    \ const { return v(); }\n    ll        v(void) const { return mint::v(x); }\n\
    \    static ll v(ll x)\n    {\n        if (x < 0)\n            return x + M;\n\
    \        return (x >= M ? x % M : x);\n    }\n    mint &operator=(mint const &y)\n\
    \    {\n        x = y.v();\n        return *this;\n    }\n    mint &operator=(ll\
    \ const &y) { return operator=(mint(y)); }\n    mint &operator+=(mint const &y)\
    \ { return operator=(operator+(y)); }\n    mint &operator-=(mint const &y) { return\
    \ operator=(operator-(y)); }\n    mint &operator*=(mint const &y) { return operator=(operator*(y));\
    \ }\n    mint  operator+(mint const &y) const { return mint::v(v() + y.v()); }\n\
    \    mint  operator+(ll const &y) const { return operator+(mint(y)); }\n    mint\
    \  operator-(mint const &y) const { return mint::v(v() - y.v()); }\n    mint \
    \ operator-(ll const &y) const { return operator-(mint(y)); }\n    mint  operator*(mint\
    \ const &y) const { return mint::v(v() * y.v()); }\n    mint  operator*(ll const\
    \ &y) const { return operator*(mint(y)); }\n    mint  operator/(mint const &y)\
    \ const { return operator*(y.inverse()); }\n    mint  operator/(ll const &y) const\
    \ { return operator*(mint::inverse(y)); }\n\n    static void precompute_inverses(int\
    \ len)\n    {\n        assert(len < 1e8 and len > 0);\n        int plen = inv.size();\n\
    \        if (len > plen)\n        {\n            inv.resize(len);\n          \
    \  for (int i = plen; i < len; ++i)\n                inv[i] = MOD - ll(inv[MOD\
    \ % i] * (MOD / i));\n        }\n    }\n    mint        inverse(void) const {\
    \ return mint::inverse(v()); }\n    static mint inverse(ll x)\n    {\n       \
    \ assert(x > 0);\n        if (x < ll(inv.size()))\n            return inv[x];\n\
    \        return binpow(mint(x), MOD - 2);\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_MODINT_HPP\n#define CPLIB_MODINT_HPP\n\n#include <cassert>\n\
    #include <cplib/math/binary_exponentiation.hpp>\n#include <vector>\n\ntemplate\
    \ <int M>\nclass ModInt\n{\n    using ll   = long long;\n    using mint = ModInt<M>;\n\
    \    ll x;\n\n  public:\n    static const int                MOD = M;\n    inline\
    \ static std::vector<mint> inv{0, 1};\n\n    ModInt(ll x) : x(x) {}\n    ModInt()\
    \ : x(0) {}\n    ModInt(mint const &y) : x(y.v()) {}\n    explicit  operator ll()\
    \ const { return v(); }\n    ll        v(void) const { return mint::v(x); }\n\
    \    static ll v(ll x)\n    {\n        if (x < 0)\n            return x + M;\n\
    \        return (x >= M ? x % M : x);\n    }\n    mint &operator=(mint const &y)\n\
    \    {\n        x = y.v();\n        return *this;\n    }\n    mint &operator=(ll\
    \ const &y) { return operator=(mint(y)); }\n    mint &operator+=(mint const &y)\
    \ { return operator=(operator+(y)); }\n    mint &operator-=(mint const &y) { return\
    \ operator=(operator-(y)); }\n    mint &operator*=(mint const &y) { return operator=(operator*(y));\
    \ }\n    mint  operator+(mint const &y) const { return mint::v(v() + y.v()); }\n\
    \    mint  operator+(ll const &y) const { return operator+(mint(y)); }\n    mint\
    \  operator-(mint const &y) const { return mint::v(v() - y.v()); }\n    mint \
    \ operator-(ll const &y) const { return operator-(mint(y)); }\n    mint  operator*(mint\
    \ const &y) const { return mint::v(v() * y.v()); }\n    mint  operator*(ll const\
    \ &y) const { return operator*(mint(y)); }\n    mint  operator/(mint const &y)\
    \ const { return operator*(y.inverse()); }\n    mint  operator/(ll const &y) const\
    \ { return operator*(mint::inverse(y)); }\n\n    static void precompute_inverses(int\
    \ len)\n    {\n        assert(len < 1e8 and len > 0);\n        int plen = inv.size();\n\
    \        if (len > plen)\n        {\n            inv.resize(len);\n          \
    \  for (int i = plen; i < len; ++i)\n                inv[i] = MOD - ll(inv[MOD\
    \ % i] * (MOD / i));\n        }\n    }\n    mint        inverse(void) const {\
    \ return mint::inverse(v()); }\n    static mint inverse(ll x)\n    {\n       \
    \ assert(x > 0);\n        if (x < ll(inv.size()))\n            return inv[x];\n\
    \        return binpow(mint(x), MOD - 2);\n    }\n};\n\n#endif // CPLIB_MODINT_HPP\n"
  dependsOn:
  - cplib/math/binary_exponentiation.hpp
  isVerificationFile: false
  path: cplib/old/modint.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/old/modint.hpp
layout: document
redirect_from:
- /library/cplib/old/modint.hpp
- /library/cplib/old/modint.hpp.html
title: cplib/old/modint.hpp
---
