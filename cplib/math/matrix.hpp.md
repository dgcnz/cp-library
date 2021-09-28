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
  bundledCode: "#line 1 \"cplib/math/matrix.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n\nnamespace cplib\n{\nusing namespace std;\n\n\
    template <typename T, int N, int M>\nstruct Matrix\n{\n    using allocator_type\
    \ = array<array<T, M>, N>;\n    using self           = Matrix<T, N, M>;\n    allocator_type\
    \ A;\n\n    static Matrix<T, N, M> e(void)\n    {\n        static_assert(N ==\
    \ M);\n        Matrix<T, N, M> C;\n        for (int i = 0; i < N; ++i)\n     \
    \       for (int j = 0; j < M; ++j)\n                C[i][j] = i == j;\n     \
    \   return C;\n    }\n\n    template <int R>\n    Matrix<T, N, R> operator*(Matrix<T,\
    \ M, R> const &B) const\n    {\n        Matrix<T, N, R> C;\n        for (int i\
    \ = 0; i < N; ++i)\n            fill(all(C[i]), 0);\n\n        for (int i = 0;\
    \ i < N; ++i)\n            for (int j = 0; j < R; ++j)\n                for (int\
    \ k = 0; k < M; ++k)\n                    C[i][j] += A[i][k] * B[k][j];\n    \
    \    return C;\n    }\n\n    Matrix<T, N, M> operator+(Matrix<T, N, M> const &B)\n\
    \    {\n        Matrix<T, N, M> C;\n        for (int i = 0; i < N; ++i)\n    \
    \        for (int j = 0; j < M; ++j)\n                C[i][j] = A[i][j] + B[i][j];\n\
    \        return C;\n    }\n\n    Matrix<T, N, M> pow(long long k) const\n    {\n\
    \        static_assert(N == M);\n        auto B = *this;\n        auto C = Matrix<T,\
    \ N, M>::e();\n        while (k)\n        {\n            if (k & 1)\n        \
    \        C = C * B;\n            B = B * B;\n            k >>= 1;\n        }\n\
    \        return C;\n    }\n\n    array<T, M> &operator[](int i)\n    {\n     \
    \   assert(0 <= i and i < N);\n        return A[i];\n    }\n\n    const array<T,\
    \ M> &operator[](int i) const\n    {\n        assert(0 <= i and i < N);\n    \
    \    return A[i];\n    }\n\n    Matrix<T, N, M> &operator=(array<array<T, N>,\
    \ M> B)\n    {\n        A = B;\n        return *this;\n    }\n    Matrix<T, N,\
    \ M> operator+=(Matrix<T, N, M> const &B)\n    {\n        return *this = *this\
    \ + B;\n    }\n    Matrix<T, N, M> operator-=(Matrix<T, N, M> const &B)\n    {\n\
    \        return *this = *this - B;\n    }\n\n    Matrix<T, N, M> operator*=(Matrix<T,\
    \ N, M> const &B)\n    {\n        return *this = *this * B;\n    }\n    Matrix<T,\
    \ N, M> operator==(Matrix<T, N, M> const &B) { return A == B.A; }\n    Matrix<T,\
    \ N, M> operator!=(Matrix<T, N, M> const &B) { return A != B.A; }\n};\n\ntemplate\
    \ <typename T, int N>\nusing SquareMatrix = Matrix<T, N, N>;\n\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_MATRIX_HPP\n#define CPLIB_MATRIX_HPP\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \ntemplate <typename T, int N, int M>\nstruct Matrix\n{\n    using allocator_type\
    \ = array<array<T, M>, N>;\n    using self           = Matrix<T, N, M>;\n    allocator_type\
    \ A;\n\n    static Matrix<T, N, M> e(void)\n    {\n        static_assert(N ==\
    \ M);\n        Matrix<T, N, M> C;\n        for (int i = 0; i < N; ++i)\n     \
    \       for (int j = 0; j < M; ++j)\n                C[i][j] = i == j;\n     \
    \   return C;\n    }\n\n    template <int R>\n    Matrix<T, N, R> operator*(Matrix<T,\
    \ M, R> const &B) const\n    {\n        Matrix<T, N, R> C;\n        for (int i\
    \ = 0; i < N; ++i)\n            fill(all(C[i]), 0);\n\n        for (int i = 0;\
    \ i < N; ++i)\n            for (int j = 0; j < R; ++j)\n                for (int\
    \ k = 0; k < M; ++k)\n                    C[i][j] += A[i][k] * B[k][j];\n    \
    \    return C;\n    }\n\n    Matrix<T, N, M> operator+(Matrix<T, N, M> const &B)\n\
    \    {\n        Matrix<T, N, M> C;\n        for (int i = 0; i < N; ++i)\n    \
    \        for (int j = 0; j < M; ++j)\n                C[i][j] = A[i][j] + B[i][j];\n\
    \        return C;\n    }\n\n    Matrix<T, N, M> pow(long long k) const\n    {\n\
    \        static_assert(N == M);\n        auto B = *this;\n        auto C = Matrix<T,\
    \ N, M>::e();\n        while (k)\n        {\n            if (k & 1)\n        \
    \        C = C * B;\n            B = B * B;\n            k >>= 1;\n        }\n\
    \        return C;\n    }\n\n    array<T, M> &operator[](int i)\n    {\n     \
    \   assert(0 <= i and i < N);\n        return A[i];\n    }\n\n    const array<T,\
    \ M> &operator[](int i) const\n    {\n        assert(0 <= i and i < N);\n    \
    \    return A[i];\n    }\n\n    Matrix<T, N, M> &operator=(array<array<T, N>,\
    \ M> B)\n    {\n        A = B;\n        return *this;\n    }\n    Matrix<T, N,\
    \ M> operator+=(Matrix<T, N, M> const &B)\n    {\n        return *this = *this\
    \ + B;\n    }\n    Matrix<T, N, M> operator-=(Matrix<T, N, M> const &B)\n    {\n\
    \        return *this = *this - B;\n    }\n\n    Matrix<T, N, M> operator*=(Matrix<T,\
    \ N, M> const &B)\n    {\n        return *this = *this * B;\n    }\n    Matrix<T,\
    \ N, M> operator==(Matrix<T, N, M> const &B) { return A == B.A; }\n    Matrix<T,\
    \ N, M> operator!=(Matrix<T, N, M> const &B) { return A != B.A; }\n};\n\ntemplate\
    \ <typename T, int N>\nusing SquareMatrix = Matrix<T, N, N>;\n\n} // namespace\
    \ cplib\n\n#endif // CPLIB_MATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/matrix.hpp
  requiredBy: []
  timestamp: '2021-09-28 18:32:30-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/matrix.hpp
layout: document
redirect_from:
- /library/cplib/math/matrix.hpp
- /library/cplib/math/matrix.hpp.html
title: cplib/math/matrix.hpp
---
