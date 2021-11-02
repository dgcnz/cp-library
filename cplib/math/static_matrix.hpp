#ifndef CPLIB_StaticMatrix_HPP
#define CPLIB_StaticMatrix_HPP

#include <algorithm>
#include <array>
#include <cassert>

namespace cplib
{
using namespace std;

template <typename T, int N, int M>
struct StaticMatrix
{
    using allocator_type = array<array<T, M>, N>;
    using self           = StaticMatrix<T, N, M>;
    allocator_type A;

    static StaticMatrix<T, N, M> e(void)
    {
        static_assert(N == M);
        StaticMatrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = i == j;
        return C;
    }

    template <int R>
    StaticMatrix<T, N, R> operator*(StaticMatrix<T, M, R> const &B) const
    {
        StaticMatrix<T, N, R> C;
        for (int i = 0; i < N; ++i)
            fill(all(C[i]), 0);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < M; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    StaticMatrix<T, N, M> operator+(StaticMatrix<T, N, M> const &B)
    {
        StaticMatrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    StaticMatrix<T, N, M> pow(long long k) const
    {
        static_assert(N == M);
        auto B = *this;
        auto C = StaticMatrix<T, N, M>::e();
        while (k)
        {
            if (k & 1)
                C = C * B;
            B = B * B;
            k >>= 1;
        }
        return C;
    }

    array<T, M> &operator[](int i)
    {
        assert(0 <= i and i < N);
        return A[i];
    }

    const array<T, M> &operator[](int i) const
    {
        assert(0 <= i and i < N);
        return A[i];
    }

    StaticMatrix<T, N, M> &operator=(array<array<T, N>, M> B)
    {
        A = B;
        return *this;
    }
    StaticMatrix<T, N, M> operator+=(StaticMatrix<T, N, M> const &B)
    {
        return *this = *this + B;
    }
    StaticMatrix<T, N, M> operator-=(StaticMatrix<T, N, M> const &B)
    {
        return *this = *this - B;
    }

    StaticMatrix<T, N, M> operator*=(StaticMatrix<T, N, M> const &B)
    {
        return *this = *this * B;
    }
    StaticMatrix<T, N, M> operator==(StaticMatrix<T, N, M> const &B)
    {
        return A == B.A;
    }
    StaticMatrix<T, N, M> operator!=(StaticMatrix<T, N, M> const &B)
    {
        return A != B.A;
    }
};

template <typename T, int N>
using SquareStaticMatrix = StaticMatrix<T, N, N>;

} // namespace cplib

#endif // CPLIB_StaticMatrix_HPP
