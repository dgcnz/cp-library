#ifndef CPLIB_MATRIX_HPP
#define CPLIB_MATRIX_HPP

// source:
// https://hitonanode.github.io/cplib-cpp/linear_algebra_matrix/matrix.hpp

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

namespace cplib
{

template <typename T>
struct matrix
{
    int                               H, W;
    std::vector<T>                    elem;
    typename std::vector<T>::iterator operator[](int i)
    {
        return elem.begin() + i * W;
    }
    inline T &at(int i, int j) { return elem[i * W + j]; }
    inline T  get(int i, int j) const { return elem[i * W + j]; }
    int       height() const { return H; }
    int       width() const { return W; }
    std::vector<std::vector<T>> std() const
    {
        std::vector<std::vector<T>> ret(H, std::vector<T>(W));
        for (int i = 0; i < H; i++)
            std::copy(elem.begin() + i * W,
                      elem.begin() + (i + 1) * W,
                      std::begin(ret[i]));
        return ret;
    }
    operator std::vector<std::vector<T>>() const { return std(); }
    matrix() = default;
    matrix(int H, int W) : H(H), W(W), elem(H * W) {}
    matrix(const std::vector<std::vector<T>> &d)
        : H(d.size()), W(d.size() ? d[0].size() : 0), elem(H * W)
    {
        for (int i = 0; i < H; ++i)
            std::copy(d[i].begin(), d[i].end(), begin(elem) + i * W);
    }

    static matrix Identity(int N)
    {
        matrix ret(N, N);
        for (int i = 0; i < N; i++)
            ret.at(i, i) = 1;
        return ret;
    }

    matrix operator-() const
    {
        matrix ret(H, W);
        for (int i = 0; i < H * W; i++)
            ret.elem[i] = -elem[i];
        return ret;
    }
    matrix operator*(const T &v) const
    {
        matrix ret = *this;
        for (auto &x : ret.elem)
            x *= v;
        return ret;
    }
    matrix operator/(const T &v) const
    {
        matrix  ret  = *this;
        const T vinv = T(1) / v;
        for (auto &x : ret.elem)
            x *= vinv;
        return ret;
    }
    matrix operator+(const matrix &r) const
    {
        assert(H == r.height() and W == r.width());
        matrix ret = *this;
        for (int i = 0; i < H * W; i++)
            ret.elem[i] += r.elem[i];
        return ret;
    }
    matrix operator-(const matrix &r) const
    {
        assert(H == r.height() and W == r.width());
        matrix ret = *this;
        for (int i = 0; i < H * W; i++)
            ret.elem[i] -= r.elem[i];
        return ret;
    }
    matrix operator*(const matrix &r) const
    {
        assert(W == r.height());
        matrix ret(H, r.W);
        for (int i = 0; i < H; i++)
            for (int k = 0; k < W; k++)
                for (int j = 0; j < r.W; j++)
                    ret.at(i, j) += this->get(i, k) * r.get(k, j);
        return ret;
    }
    matrix &operator*=(const T &v) { return *this = *this * v; }
    matrix &operator/=(const T &v) { return *this = *this / v; }
    matrix &operator+=(const matrix &r) { return *this = *this + r; }
    matrix &operator-=(const matrix &r) { return *this = *this - r; }
    matrix &operator*=(const matrix &r) { return *this = *this * r; }
    bool    operator==(const matrix &r) const
    {
        return H == r.H and W == r.W and elem == r.elem;
    }
    bool operator!=(const matrix &r) const
    {
        return H != r.H or W != r.W or elem != r.elem;
    }
    bool   operator<(const matrix &r) const { return elem < r.elem; }
    matrix pow(long long int n) const
    {
        matrix ret       = Identity(H);
        bool   ret_is_id = true;
        if (n == 0)
            return ret;
        for (int i = 63 - __builtin_clzll(n); i >= 0; i--)
        {
            if (!ret_is_id)
                ret *= ret;
            if ((n >> i) & 1)
                ret *= (*this), ret_is_id = false;
        }
        return ret;
    }
    std::vector<T> pow_vec(long long int n, std::vector<T> vec) const
    {
        matrix x = *this;
        while (n)
        {
            if (n & 1)
                vec = x * vec;
            x *= x;
            n >>= 1;
        }
        return vec;
    };
    matrix transpose() const
    {
        matrix ret(W, H);
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                ret.at(j, i) = this->get(i, j);
        return ret;
    }
    // Gauss-Jordan elimination
    // - Require inverse for every non-zero element
    // - Complexity: O(H^2 W)
    template <typename T2,
              typename std::enable_if<std::is_floating_point<T2>::value>::type
                  * = nullptr>
    static int choose_pivot(const matrix<T2> &mtr, int h, int c) noexcept
    {
        int piv = -1;
        for (int j = h; j < mtr.H; j++)
            if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j, c)) >
                                                  std::abs(mtr.get(piv, c))))
                piv = j;
        return piv;
    }
    template <typename T2,
              typename std::enable_if<!std::is_floating_point<T2>::value>::type
                  * = nullptr>
    static int choose_pivot(const matrix<T2> &mtr, int h, int c) noexcept
    {
        for (int j = h; j < mtr.H; j++)
            if (mtr.get(j, c))
                return j;
        return -1;
    }
    matrix gauss_jordan() const
    {
        int              c = 0;
        matrix           mtr(*this);
        std::vector<int> ws;
        ws.reserve(W);
        for (int h = 0; h < H; h++)
        {
            if (c == W)
                break;
            int piv = choose_pivot(mtr, h, c);
            if (piv == -1)
            {
                c++;
                h--;
                continue;
            }
            if (h != piv)
            {
                for (int w = 0; w < W; w++)
                {
                    std::swap(mtr[piv][w], mtr[h][w]);
                    mtr.at(piv, w) *= -1; // To preserve sign of determinant
                }
            }
            ws.clear();
            for (int w = c; w < W; w++)
            {
                if (mtr.at(h, w) != 0)
                    ws.emplace_back(w);
            }
            const T hcinv = T(1) / mtr.at(h, c);
            for (int hh = 0; hh < H; hh++)
                if (hh != h)
                {
                    const T coeff = mtr.at(hh, c) * hcinv;
                    for (auto w : ws)
                        mtr.at(hh, w) -= mtr.at(h, w) * coeff;
                    mtr.at(hh, c) = 0;
                }
            c++;
        }
        return mtr;
    }
    int rank_of_gauss_jordan() const
    {
        for (int i = H * W - 1; i >= 0; i--)
            if (elem[i])
                return i / W + 1;
        return 0;
    }
    T determinant_of_upper_triangle() const
    {
        T ret = 1;
        for (int i = 0; i < H; i++)
            ret *= get(i, i);
        return ret;
    }
    int inverse()
    {
        assert(H == W);
        std::vector<std::vector<T>> ret = Identity(H), tmp = *this;
        int                         rank = 0;
        for (int i = 0; i < H; i++)
        {
            int ti = i;
            while (ti < H and tmp[ti][i] == 0)
                ti++;
            if (ti == H)
                continue;
            else
                rank++;
            ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);
            T inv = T(1) / tmp[i][i];
            for (int j = 0; j < W; j++)
                ret[i][j] *= inv;
            for (int j = i + 1; j < W; j++)
                tmp[i][j] *= inv;
            for (int h = 0; h < H; h++)
            {
                if (i == h)
                    continue;
                const T c = -tmp[h][i];
                for (int j = 0; j < W; j++)
                    ret[h][j] += ret[i][j] * c;
                for (int j = i + 1; j < W; j++)
                    tmp[h][j] += tmp[i][j] * c;
            }
        }
        *this = ret;
        return rank;
    }
    friend std::vector<T> operator*(const matrix &m, const std::vector<T> &v)
    {
        assert(m.W == int(v.size()));
        std::vector<T> ret(m.H);
        for (int i = 0; i < m.H; i++)
        {
            for (int j = 0; j < m.W; j++)
                ret[i] += m.get(i, j) * v[j];
        }
        return ret;
    }
    friend std::vector<T> operator*(const std::vector<T> &v, const matrix &m)
    {
        assert(int(v.size()) == m.H);
        std::vector<T> ret(m.W);
        for (int i = 0; i < m.H; i++)
            for (int j = 0; j < m.W; j++)
                ret[j] += v[i] * m.get(i, j);
        return ret;
    }
    std::vector<T> prod(const std::vector<T> &v) const { return (*this) * v; }
    std::vector<T> prod_left(const std::vector<T> &v) const
    {
        return v * (*this);
    }
    friend std::ostream &operator<<(std::ostream &os, const matrix &x)
    {
        os << "[(" << x.H << " * " << x.W << " matrix)";
        os << "\n[column sums: ";
        for (int j = 0; j < x.W; j++)
        {
            T s = 0;
            for (int i = 0; i < x.H; i++)
                s += x.get(i, j);
            os << s << ",";
        }
        os << "]";
        for (int i = 0; i < x.H; i++)
        {
            os << "\n[";
            for (int j = 0; j < x.W; j++)
                os << x.get(i, j) << ",";
            os << "]";
        }
        os << "]\n";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, matrix &x)
    {
        for (auto &v : x.elem)
            is >> v;
        return is;
    }
};

// Example: Fibonacci numbers f(n) = af(n - 1) + bf(n - 2)
// (a = b = 1): 0=>1, 1=>1, 2=>2, 3=>3, 4=>5, ...
template <typename T>
T Fibonacci(long long int k, int a = 1, int b = 1)
{
    matrix<T> mat(2, 2);
    mat[0][1] = 1;
    mat[1][0] = b;
    mat[1][1] = a;
    return mat.pow(k + 1)[0][1];
}
} // namespace cplib

#endif // CPLIB_MATRIX_HPP
