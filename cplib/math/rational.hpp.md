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
    - https://hitonanode.github.io/cplib-cpp/rational/rational_number.hpp
  bundledCode: "#line 1 \"cplib/math/rational.hpp\"\n\n\n#include <iostream>\n#include\
    \ <numeric>\n\n// source: https://hitonanode.github.io/cplib-cpp/rational/rational_number.hpp\n\
    \n// rational number + {infinity(1 / 0), -infinity(-1 / 0)}\ntemplate <typename\
    \ T = long long int>\nstruct rational\n{\n    T num, den;\n    rational(T num\
    \ = 0, T den = 1) : num(num), den(den) { normalize(); }\n    void normalize()\n\
    \    {\n        auto g = gcd(num, den);\n        num /= g, den /= g;\n       \
    \ if (den < 0)\n            num = -num, den = -den;\n    }\n    rational operator+(const\
    \ rational &r) const\n    {\n        return rational(num * r.den + den * r.num,\
    \ den * r.den);\n    }\n    rational operator-(const rational &r) const\n    {\n\
    \        return rational(num * r.den - den * r.num, den * r.den);\n    }\n   \
    \ rational operator*(const rational &r) const\n    {\n        return rational(num\
    \ * r.num, den * r.den);\n    }\n    rational operator/(const rational &r) const\n\
    \    {\n        return rational(num * r.den, den * r.num);\n    }\n    rational\
    \ &operator+=(const rational &r) { return *this = *this + r; }\n    rational &operator-=(const\
    \ rational &r) { return *this = *this - r; }\n    rational &operator*=(const rational\
    \ &r) { return *this = *this * r; }\n    rational &operator/=(const rational &r)\
    \ { return *this = *this / r; }\n    rational  operator-() const { return rational(-num,\
    \ den); }\n    rational  abs() const { return rational(num > 0 ? num : -num, den);\
    \ }\n    bool      operator==(const rational &r) const\n    {\n        return\
    \ num == r.num and den == r.den;\n    }\n    bool operator!=(const rational &r)\
    \ const\n    {\n        return num != r.num or den != r.den;\n    }\n    bool\
    \ operator<(const rational &r) const\n    {\n        if (den == 0 and r.den ==\
    \ 0)\n            return num < r.num;\n        else if (den == 0)\n          \
    \  return num < 0;\n        else if (r.den == 0)\n            return r.num > 0;\n\
    \        else\n            return num * r.den < den * r.num;\n    }\n    bool\
    \ operator<=(const rational &r) const\n    {\n        return (*this == r) or (*this\
    \ < r);\n    }\n    bool operator>(const rational &r) const { return r < *this;\
    \ }\n    bool operator>=(const rational &r) const\n    {\n        return (r ==\
    \ *this) or (r < *this);\n    }\n    explicit operator double() const { return\
    \ (double)num / (double)den; }\n    explicit operator long double() const\n  \
    \  {\n        return (long double)num / (long double)den;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const rational &x)\n    {\n        return os <<\
    \ x.num << '/' << x.den;\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_RATIONAL_HPP\n#define CPLIB_RATIONAL_HPP\n#include <iostream>\n\
    #include <numeric>\n\n// source: https://hitonanode.github.io/cplib-cpp/rational/rational_number.hpp\n\
    \n// rational number + {infinity(1 / 0), -infinity(-1 / 0)}\ntemplate <typename\
    \ T = long long int>\nstruct rational\n{\n    T num, den;\n    rational(T num\
    \ = 0, T den = 1) : num(num), den(den) { normalize(); }\n    void normalize()\n\
    \    {\n        auto g = gcd(num, den);\n        num /= g, den /= g;\n       \
    \ if (den < 0)\n            num = -num, den = -den;\n    }\n    rational operator+(const\
    \ rational &r) const\n    {\n        return rational(num * r.den + den * r.num,\
    \ den * r.den);\n    }\n    rational operator-(const rational &r) const\n    {\n\
    \        return rational(num * r.den - den * r.num, den * r.den);\n    }\n   \
    \ rational operator*(const rational &r) const\n    {\n        return rational(num\
    \ * r.num, den * r.den);\n    }\n    rational operator/(const rational &r) const\n\
    \    {\n        return rational(num * r.den, den * r.num);\n    }\n    rational\
    \ &operator+=(const rational &r) { return *this = *this + r; }\n    rational &operator-=(const\
    \ rational &r) { return *this = *this - r; }\n    rational &operator*=(const rational\
    \ &r) { return *this = *this * r; }\n    rational &operator/=(const rational &r)\
    \ { return *this = *this / r; }\n    rational  operator-() const { return rational(-num,\
    \ den); }\n    rational  abs() const { return rational(num > 0 ? num : -num, den);\
    \ }\n    bool      operator==(const rational &r) const\n    {\n        return\
    \ num == r.num and den == r.den;\n    }\n    bool operator!=(const rational &r)\
    \ const\n    {\n        return num != r.num or den != r.den;\n    }\n    bool\
    \ operator<(const rational &r) const\n    {\n        if (den == 0 and r.den ==\
    \ 0)\n            return num < r.num;\n        else if (den == 0)\n          \
    \  return num < 0;\n        else if (r.den == 0)\n            return r.num > 0;\n\
    \        else\n            return num * r.den < den * r.num;\n    }\n    bool\
    \ operator<=(const rational &r) const\n    {\n        return (*this == r) or (*this\
    \ < r);\n    }\n    bool operator>(const rational &r) const { return r < *this;\
    \ }\n    bool operator>=(const rational &r) const\n    {\n        return (r ==\
    \ *this) or (r < *this);\n    }\n    explicit operator double() const { return\
    \ (double)num / (double)den; }\n    explicit operator long double() const\n  \
    \  {\n        return (long double)num / (long double)den;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const rational &x)\n    {\n        return os <<\
    \ x.num << '/' << x.den;\n    }\n};\n\n#endif // CPLIB_RATIONAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/rational.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:44:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/rational.hpp
layout: document
redirect_from:
- /library/cplib/math/rational.hpp
- /library/cplib/math/rational.hpp.html
title: cplib/math/rational.hpp
---
