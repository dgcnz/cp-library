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
    - https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/matrix.hpp
  bundledCode: "#line 1 \"cplib/math/matrix.hpp\"\n\n\n\n// source:\n// https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/matrix.hpp\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    #include <iterator>\n#include <type_traits>\n#include <vector>\n\nnamespace cplib\n\
    {\n\ntemplate <typename T>\nstruct matrix\n{\n    int                        \
    \       H, W;\n    std::vector<T>                    elem;\n    typename std::vector<T>::iterator\
    \ operator[](int i)\n    {\n        return elem.begin() + i * W;\n    }\n    inline\
    \ T &at(int i, int j) { return elem[i * W + j]; }\n    inline T  get(int i, int\
    \ j) const { return elem[i * W + j]; }\n    int       height() const { return\
    \ H; }\n    int       width() const { return W; }\n    std::vector<std::vector<T>>\
    \ std() const\n    {\n        std::vector<std::vector<T>> ret(H, std::vector<T>(W));\n\
    \        for (int i = 0; i < H; i++)\n            std::copy(elem.begin() + i *\
    \ W,\n                      elem.begin() + (i + 1) * W,\n                    \
    \  std::begin(ret[i]));\n        return ret;\n    }\n    operator std::vector<std::vector<T>>()\
    \ const { return std(); }\n    matrix() = default;\n    matrix(int H, int W) :\
    \ H(H), W(W), elem(H * W) {}\n    matrix(const std::vector<std::vector<T>> &d)\n\
    \        : H(d.size()), W(d.size() ? d[0].size() : 0), elem(H * W)\n    {\n  \
    \      for (int i = 0; i < H; ++i)\n            std::copy(d[i].begin(), d[i].end(),\
    \ begin(elem) + i * W);\n    }\n\n    static matrix Identity(int N)\n    {\n \
    \       matrix ret(N, N);\n        for (int i = 0; i < N; i++)\n            ret.at(i,\
    \ i) = 1;\n        return ret;\n    }\n\n    matrix operator-() const\n    {\n\
    \        matrix ret(H, W);\n        for (int i = 0; i < H * W; i++)\n        \
    \    ret.elem[i] = -elem[i];\n        return ret;\n    }\n    matrix operator*(const\
    \ T &v) const\n    {\n        matrix ret = *this;\n        for (auto &x : ret.elem)\n\
    \            x *= v;\n        return ret;\n    }\n    matrix operator/(const T\
    \ &v) const\n    {\n        matrix  ret  = *this;\n        const T vinv = T(1)\
    \ / v;\n        for (auto &x : ret.elem)\n            x *= vinv;\n        return\
    \ ret;\n    }\n    matrix operator+(const matrix &r) const\n    {\n        assert(H\
    \ == r.height() and W == r.width());\n        matrix ret = *this;\n        for\
    \ (int i = 0; i < H * W; i++)\n            ret.elem[i] += r.elem[i];\n       \
    \ return ret;\n    }\n    matrix operator-(const matrix &r) const\n    {\n   \
    \     assert(H == r.height() and W == r.width());\n        matrix ret = *this;\n\
    \        for (int i = 0; i < H * W; i++)\n            ret.elem[i] -= r.elem[i];\n\
    \        return ret;\n    }\n    matrix operator*(const matrix &r) const\n   \
    \ {\n        assert(W == r.height());\n        matrix ret(H, r.W);\n        for\
    \ (int i = 0; i < H; i++)\n            for (int k = 0; k < W; k++)\n         \
    \       for (int j = 0; j < r.W; j++)\n                    ret.at(i, j) += this->get(i,\
    \ k) * r.get(k, j);\n        return ret;\n    }\n    matrix &operator*=(const\
    \ T &v) { return *this = *this * v; }\n    matrix &operator/=(const T &v) { return\
    \ *this = *this / v; }\n    matrix &operator+=(const matrix &r) { return *this\
    \ = *this + r; }\n    matrix &operator-=(const matrix &r) { return *this = *this\
    \ - r; }\n    matrix &operator*=(const matrix &r) { return *this = *this * r;\
    \ }\n    bool    operator==(const matrix &r) const\n    {\n        return H ==\
    \ r.H and W == r.W and elem == r.elem;\n    }\n    bool operator!=(const matrix\
    \ &r) const\n    {\n        return H != r.H or W != r.W or elem != r.elem;\n \
    \   }\n    bool   operator<(const matrix &r) const { return elem < r.elem; }\n\
    \    matrix pow(long long int n) const\n    {\n        matrix ret       = Identity(H);\n\
    \        bool   ret_is_id = true;\n        if (n == 0)\n            return ret;\n\
    \        for (int i = 63 - __builtin_clzll(n); i >= 0; i--)\n        {\n     \
    \       if (!ret_is_id)\n                ret *= ret;\n            if ((n >> i)\
    \ & 1)\n                ret *= (*this), ret_is_id = false;\n        }\n      \
    \  return ret;\n    }\n    std::vector<T> pow_vec(long long int n, std::vector<T>\
    \ vec) const\n    {\n        matrix x = *this;\n        while (n)\n        {\n\
    \            if (n & 1)\n                vec = x * vec;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return vec;\n    };\n    matrix transpose()\
    \ const\n    {\n        matrix ret(W, H);\n        for (int i = 0; i < H; i++)\n\
    \            for (int j = 0; j < W; j++)\n                ret.at(j, i) = this->get(i,\
    \ j);\n        return ret;\n    }\n    // Gauss-Jordan elimination\n    // - Require\
    \ inverse for every non-zero element\n    // - Complexity: O(H^2 W)\n    template\
    \ <typename T2,\n              typename std::enable_if<std::is_floating_point<T2>::value>::type\n\
    \                  * = nullptr>\n    static int choose_pivot(const matrix<T2>\
    \ &mtr, int h, int c) noexcept\n    {\n        int piv = -1;\n        for (int\
    \ j = h; j < mtr.H; j++)\n            if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j,\
    \ c)) >\n                                                  std::abs(mtr.get(piv,\
    \ c))))\n                piv = j;\n        return piv;\n    }\n    template <typename\
    \ T2,\n              typename std::enable_if<!std::is_floating_point<T2>::value>::type\n\
    \                  * = nullptr>\n    static int choose_pivot(const matrix<T2>\
    \ &mtr, int h, int c) noexcept\n    {\n        for (int j = h; j < mtr.H; j++)\n\
    \            if (mtr.get(j, c))\n                return j;\n        return -1;\n\
    \    }\n    matrix gauss_jordan() const\n    {\n        int              c = 0;\n\
    \        matrix           mtr(*this);\n        std::vector<int> ws;\n        ws.reserve(W);\n\
    \        for (int h = 0; h < H; h++)\n        {\n            if (c == W)\n   \
    \             break;\n            int piv = choose_pivot(mtr, h, c);\n       \
    \     if (piv == -1)\n            {\n                c++;\n                h--;\n\
    \                continue;\n            }\n            if (h != piv)\n       \
    \     {\n                for (int w = 0; w < W; w++)\n                {\n    \
    \                std::swap(mtr[piv][w], mtr[h][w]);\n                    mtr.at(piv,\
    \ w) *= -1; // To preserve sign of determinant\n                }\n          \
    \  }\n            ws.clear();\n            for (int w = c; w < W; w++)\n     \
    \       {\n                if (mtr.at(h, w) != 0)\n                    ws.emplace_back(w);\n\
    \            }\n            const T hcinv = T(1) / mtr.at(h, c);\n           \
    \ for (int hh = 0; hh < H; hh++)\n                if (hh != h)\n             \
    \   {\n                    const T coeff = mtr.at(hh, c) * hcinv;\n          \
    \          for (auto w : ws)\n                        mtr.at(hh, w) -= mtr.at(h,\
    \ w) * coeff;\n                    mtr.at(hh, c) = 0;\n                }\n   \
    \         c++;\n        }\n        return mtr;\n    }\n    int rank_of_gauss_jordan()\
    \ const\n    {\n        for (int i = H * W - 1; i >= 0; i--)\n            if (elem[i])\n\
    \                return i / W + 1;\n        return 0;\n    }\n    T determinant_of_upper_triangle()\
    \ const\n    {\n        T ret = 1;\n        for (int i = 0; i < H; i++)\n    \
    \        ret *= get(i, i);\n        return ret;\n    }\n    int inverse()\n  \
    \  {\n        assert(H == W);\n        std::vector<std::vector<T>> ret = Identity(H),\
    \ tmp = *this;\n        int                         rank = 0;\n        for (int\
    \ i = 0; i < H; i++)\n        {\n            int ti = i;\n            while (ti\
    \ < H and tmp[ti][i] == 0)\n                ti++;\n            if (ti == H)\n\
    \                continue;\n            else\n                rank++;\n      \
    \      ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);\n            T inv = T(1) /\
    \ tmp[i][i];\n            for (int j = 0; j < W; j++)\n                ret[i][j]\
    \ *= inv;\n            for (int j = i + 1; j < W; j++)\n                tmp[i][j]\
    \ *= inv;\n            for (int h = 0; h < H; h++)\n            {\n          \
    \      if (i == h)\n                    continue;\n                const T c =\
    \ -tmp[h][i];\n                for (int j = 0; j < W; j++)\n                 \
    \   ret[h][j] += ret[i][j] * c;\n                for (int j = i + 1; j < W; j++)\n\
    \                    tmp[h][j] += tmp[i][j] * c;\n            }\n        }\n \
    \       *this = ret;\n        return rank;\n    }\n    friend std::vector<T> operator*(const\
    \ matrix &m, const std::vector<T> &v)\n    {\n        assert(m.W == int(v.size()));\n\
    \        std::vector<T> ret(m.H);\n        for (int i = 0; i < m.H; i++)\n   \
    \     {\n            for (int j = 0; j < m.W; j++)\n                ret[i] +=\
    \ m.get(i, j) * v[j];\n        }\n        return ret;\n    }\n    friend std::vector<T>\
    \ operator*(const std::vector<T> &v, const matrix &m)\n    {\n        assert(int(v.size())\
    \ == m.H);\n        std::vector<T> ret(m.W);\n        for (int i = 0; i < m.H;\
    \ i++)\n            for (int j = 0; j < m.W; j++)\n                ret[j] += v[i]\
    \ * m.get(i, j);\n        return ret;\n    }\n    std::vector<T> prod(const std::vector<T>\
    \ &v) const { return (*this) * v; }\n    std::vector<T> prod_left(const std::vector<T>\
    \ &v) const\n    {\n        return v * (*this);\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const matrix &x)\n    {\n        os << \"[(\"\
    \ << x.H << \" * \" << x.W << \" matrix)\";\n        os << \"\\n[column sums:\
    \ \";\n        for (int j = 0; j < x.W; j++)\n        {\n            T s = 0;\n\
    \            for (int i = 0; i < x.H; i++)\n                s += x.get(i, j);\n\
    \            os << s << \",\";\n        }\n        os << \"]\";\n        for (int\
    \ i = 0; i < x.H; i++)\n        {\n            os << \"\\n[\";\n            for\
    \ (int j = 0; j < x.W; j++)\n                os << x.get(i, j) << \",\";\n   \
    \         os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, matrix &x)\n   \
    \ {\n        for (auto &v : x.elem)\n            is >> v;\n        return is;\n\
    \    }\n};\n\n// Example: Fibonacci numbers f(n) = af(n - 1) + bf(n - 2)\n// (a\
    \ = b = 1): 0=>1, 1=>1, 2=>2, 3=>3, 4=>5, ...\ntemplate <typename T>\nT Fibonacci(long\
    \ long int k, int a = 1, int b = 1)\n{\n    matrix<T> mat(2, 2);\n    mat[0][1]\
    \ = 1;\n    mat[1][0] = b;\n    mat[1][1] = a;\n    return mat.pow(k + 1)[0][1];\n\
    }\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_MATRIX_HPP\n#define CPLIB_MATRIX_HPP\n\n// source:\n// https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/matrix.hpp\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    #include <iterator>\n#include <type_traits>\n#include <vector>\n\nnamespace cplib\n\
    {\n\ntemplate <typename T>\nstruct matrix\n{\n    int                        \
    \       H, W;\n    std::vector<T>                    elem;\n    typename std::vector<T>::iterator\
    \ operator[](int i)\n    {\n        return elem.begin() + i * W;\n    }\n    inline\
    \ T &at(int i, int j) { return elem[i * W + j]; }\n    inline T  get(int i, int\
    \ j) const { return elem[i * W + j]; }\n    int       height() const { return\
    \ H; }\n    int       width() const { return W; }\n    std::vector<std::vector<T>>\
    \ std() const\n    {\n        std::vector<std::vector<T>> ret(H, std::vector<T>(W));\n\
    \        for (int i = 0; i < H; i++)\n            std::copy(elem.begin() + i *\
    \ W,\n                      elem.begin() + (i + 1) * W,\n                    \
    \  std::begin(ret[i]));\n        return ret;\n    }\n    operator std::vector<std::vector<T>>()\
    \ const { return std(); }\n    matrix() = default;\n    matrix(int H, int W) :\
    \ H(H), W(W), elem(H * W) {}\n    matrix(const std::vector<std::vector<T>> &d)\n\
    \        : H(d.size()), W(d.size() ? d[0].size() : 0), elem(H * W)\n    {\n  \
    \      for (int i = 0; i < H; ++i)\n            std::copy(d[i].begin(), d[i].end(),\
    \ begin(elem) + i * W);\n    }\n\n    static matrix Identity(int N)\n    {\n \
    \       matrix ret(N, N);\n        for (int i = 0; i < N; i++)\n            ret.at(i,\
    \ i) = 1;\n        return ret;\n    }\n\n    matrix operator-() const\n    {\n\
    \        matrix ret(H, W);\n        for (int i = 0; i < H * W; i++)\n        \
    \    ret.elem[i] = -elem[i];\n        return ret;\n    }\n    matrix operator*(const\
    \ T &v) const\n    {\n        matrix ret = *this;\n        for (auto &x : ret.elem)\n\
    \            x *= v;\n        return ret;\n    }\n    matrix operator/(const T\
    \ &v) const\n    {\n        matrix  ret  = *this;\n        const T vinv = T(1)\
    \ / v;\n        for (auto &x : ret.elem)\n            x *= vinv;\n        return\
    \ ret;\n    }\n    matrix operator+(const matrix &r) const\n    {\n        assert(H\
    \ == r.height() and W == r.width());\n        matrix ret = *this;\n        for\
    \ (int i = 0; i < H * W; i++)\n            ret.elem[i] += r.elem[i];\n       \
    \ return ret;\n    }\n    matrix operator-(const matrix &r) const\n    {\n   \
    \     assert(H == r.height() and W == r.width());\n        matrix ret = *this;\n\
    \        for (int i = 0; i < H * W; i++)\n            ret.elem[i] -= r.elem[i];\n\
    \        return ret;\n    }\n    matrix operator*(const matrix &r) const\n   \
    \ {\n        assert(W == r.height());\n        matrix ret(H, r.W);\n        for\
    \ (int i = 0; i < H; i++)\n            for (int k = 0; k < W; k++)\n         \
    \       for (int j = 0; j < r.W; j++)\n                    ret.at(i, j) += this->get(i,\
    \ k) * r.get(k, j);\n        return ret;\n    }\n    matrix &operator*=(const\
    \ T &v) { return *this = *this * v; }\n    matrix &operator/=(const T &v) { return\
    \ *this = *this / v; }\n    matrix &operator+=(const matrix &r) { return *this\
    \ = *this + r; }\n    matrix &operator-=(const matrix &r) { return *this = *this\
    \ - r; }\n    matrix &operator*=(const matrix &r) { return *this = *this * r;\
    \ }\n    bool    operator==(const matrix &r) const\n    {\n        return H ==\
    \ r.H and W == r.W and elem == r.elem;\n    }\n    bool operator!=(const matrix\
    \ &r) const\n    {\n        return H != r.H or W != r.W or elem != r.elem;\n \
    \   }\n    bool   operator<(const matrix &r) const { return elem < r.elem; }\n\
    \    matrix pow(long long int n) const\n    {\n        matrix ret       = Identity(H);\n\
    \        bool   ret_is_id = true;\n        if (n == 0)\n            return ret;\n\
    \        for (int i = 63 - __builtin_clzll(n); i >= 0; i--)\n        {\n     \
    \       if (!ret_is_id)\n                ret *= ret;\n            if ((n >> i)\
    \ & 1)\n                ret *= (*this), ret_is_id = false;\n        }\n      \
    \  return ret;\n    }\n    std::vector<T> pow_vec(long long int n, std::vector<T>\
    \ vec) const\n    {\n        matrix x = *this;\n        while (n)\n        {\n\
    \            if (n & 1)\n                vec = x * vec;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return vec;\n    };\n    matrix transpose()\
    \ const\n    {\n        matrix ret(W, H);\n        for (int i = 0; i < H; i++)\n\
    \            for (int j = 0; j < W; j++)\n                ret.at(j, i) = this->get(i,\
    \ j);\n        return ret;\n    }\n    // Gauss-Jordan elimination\n    // - Require\
    \ inverse for every non-zero element\n    // - Complexity: O(H^2 W)\n    template\
    \ <typename T2,\n              typename std::enable_if<std::is_floating_point<T2>::value>::type\n\
    \                  * = nullptr>\n    static int choose_pivot(const matrix<T2>\
    \ &mtr, int h, int c) noexcept\n    {\n        int piv = -1;\n        for (int\
    \ j = h; j < mtr.H; j++)\n            if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j,\
    \ c)) >\n                                                  std::abs(mtr.get(piv,\
    \ c))))\n                piv = j;\n        return piv;\n    }\n    template <typename\
    \ T2,\n              typename std::enable_if<!std::is_floating_point<T2>::value>::type\n\
    \                  * = nullptr>\n    static int choose_pivot(const matrix<T2>\
    \ &mtr, int h, int c) noexcept\n    {\n        for (int j = h; j < mtr.H; j++)\n\
    \            if (mtr.get(j, c))\n                return j;\n        return -1;\n\
    \    }\n    matrix gauss_jordan() const\n    {\n        int              c = 0;\n\
    \        matrix           mtr(*this);\n        std::vector<int> ws;\n        ws.reserve(W);\n\
    \        for (int h = 0; h < H; h++)\n        {\n            if (c == W)\n   \
    \             break;\n            int piv = choose_pivot(mtr, h, c);\n       \
    \     if (piv == -1)\n            {\n                c++;\n                h--;\n\
    \                continue;\n            }\n            if (h != piv)\n       \
    \     {\n                for (int w = 0; w < W; w++)\n                {\n    \
    \                std::swap(mtr[piv][w], mtr[h][w]);\n                    mtr.at(piv,\
    \ w) *= -1; // To preserve sign of determinant\n                }\n          \
    \  }\n            ws.clear();\n            for (int w = c; w < W; w++)\n     \
    \       {\n                if (mtr.at(h, w) != 0)\n                    ws.emplace_back(w);\n\
    \            }\n            const T hcinv = T(1) / mtr.at(h, c);\n           \
    \ for (int hh = 0; hh < H; hh++)\n                if (hh != h)\n             \
    \   {\n                    const T coeff = mtr.at(hh, c) * hcinv;\n          \
    \          for (auto w : ws)\n                        mtr.at(hh, w) -= mtr.at(h,\
    \ w) * coeff;\n                    mtr.at(hh, c) = 0;\n                }\n   \
    \         c++;\n        }\n        return mtr;\n    }\n    int rank_of_gauss_jordan()\
    \ const\n    {\n        for (int i = H * W - 1; i >= 0; i--)\n            if (elem[i])\n\
    \                return i / W + 1;\n        return 0;\n    }\n    T determinant_of_upper_triangle()\
    \ const\n    {\n        T ret = 1;\n        for (int i = 0; i < H; i++)\n    \
    \        ret *= get(i, i);\n        return ret;\n    }\n    int inverse()\n  \
    \  {\n        assert(H == W);\n        std::vector<std::vector<T>> ret = Identity(H),\
    \ tmp = *this;\n        int                         rank = 0;\n        for (int\
    \ i = 0; i < H; i++)\n        {\n            int ti = i;\n            while (ti\
    \ < H and tmp[ti][i] == 0)\n                ti++;\n            if (ti == H)\n\
    \                continue;\n            else\n                rank++;\n      \
    \      ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);\n            T inv = T(1) /\
    \ tmp[i][i];\n            for (int j = 0; j < W; j++)\n                ret[i][j]\
    \ *= inv;\n            for (int j = i + 1; j < W; j++)\n                tmp[i][j]\
    \ *= inv;\n            for (int h = 0; h < H; h++)\n            {\n          \
    \      if (i == h)\n                    continue;\n                const T c =\
    \ -tmp[h][i];\n                for (int j = 0; j < W; j++)\n                 \
    \   ret[h][j] += ret[i][j] * c;\n                for (int j = i + 1; j < W; j++)\n\
    \                    tmp[h][j] += tmp[i][j] * c;\n            }\n        }\n \
    \       *this = ret;\n        return rank;\n    }\n    friend std::vector<T> operator*(const\
    \ matrix &m, const std::vector<T> &v)\n    {\n        assert(m.W == int(v.size()));\n\
    \        std::vector<T> ret(m.H);\n        for (int i = 0; i < m.H; i++)\n   \
    \     {\n            for (int j = 0; j < m.W; j++)\n                ret[i] +=\
    \ m.get(i, j) * v[j];\n        }\n        return ret;\n    }\n    friend std::vector<T>\
    \ operator*(const std::vector<T> &v, const matrix &m)\n    {\n        assert(int(v.size())\
    \ == m.H);\n        std::vector<T> ret(m.W);\n        for (int i = 0; i < m.H;\
    \ i++)\n            for (int j = 0; j < m.W; j++)\n                ret[j] += v[i]\
    \ * m.get(i, j);\n        return ret;\n    }\n    std::vector<T> prod(const std::vector<T>\
    \ &v) const { return (*this) * v; }\n    std::vector<T> prod_left(const std::vector<T>\
    \ &v) const\n    {\n        return v * (*this);\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const matrix &x)\n    {\n        os << \"[(\"\
    \ << x.H << \" * \" << x.W << \" matrix)\";\n        os << \"\\n[column sums:\
    \ \";\n        for (int j = 0; j < x.W; j++)\n        {\n            T s = 0;\n\
    \            for (int i = 0; i < x.H; i++)\n                s += x.get(i, j);\n\
    \            os << s << \",\";\n        }\n        os << \"]\";\n        for (int\
    \ i = 0; i < x.H; i++)\n        {\n            os << \"\\n[\";\n            for\
    \ (int j = 0; j < x.W; j++)\n                os << x.get(i, j) << \",\";\n   \
    \         os << \"]\";\n        }\n        os << \"]\\n\";\n        return os;\n\
    \    }\n    friend std::istream &operator>>(std::istream &is, matrix &x)\n   \
    \ {\n        for (auto &v : x.elem)\n            is >> v;\n        return is;\n\
    \    }\n};\n\n// Example: Fibonacci numbers f(n) = af(n - 1) + bf(n - 2)\n// (a\
    \ = b = 1): 0=>1, 1=>1, 2=>2, 3=>3, 4=>5, ...\ntemplate <typename T>\nT Fibonacci(long\
    \ long int k, int a = 1, int b = 1)\n{\n    matrix<T> mat(2, 2);\n    mat[0][1]\
    \ = 1;\n    mat[1][0] = b;\n    mat[1][1] = a;\n    return mat.pow(k + 1)[0][1];\n\
    }\n} // namespace cplib\n\n#endif // CPLIB_MATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/math/matrix.hpp
  requiredBy: []
  timestamp: '2021-12-25 20:18:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/math/matrix.hpp
layout: document
redirect_from:
- /library/cplib/math/matrix.hpp
- /library/cplib/math/matrix.hpp.html
title: cplib/math/matrix.hpp
---
