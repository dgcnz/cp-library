#include <algorithm>
#include <array>
#include <cassert>

namespace cplib
{
using namespace std;

template <typename T, int N, int M>
struct Matrix
{
    using allocator_type = array<array<T, M>, N>;
    using self           = Matrix<T, N, M>;
    allocator_type A;

    static Matrix<T, N, M> e(void)
    {
        static_assert(N == M);
        Matrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = i == j;
        return C;
    }

    template <int R>
    Matrix<T, N, R> operator*(Matrix<T, M, R> const &B) const
    {
        Matrix<T, N, R> C;
        for (int i = 0; i < N; ++i)
            fill(all(C[i]), 0);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < M; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    Matrix<T, N, M> operator+(Matrix<T, N, M> const &B)
    {
        Matrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    Matrix<T, N, M> pow(long long k) const
    {
        static_assert(N == M);
        auto B = *this;
        auto C = Matrix<T, N, M>::e();
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

    Matrix<T, N, M> &operator=(array<array<T, N>, M> B)
    {
        A = B;
        return *this;
    }
    Matrix<T, N, M> operator+=(Matrix<T, N, M> const &B)
    {
        return *this = *this + B;
    }
    Matrix<T, N, M> operator-=(Matrix<T, N, M> const &B)
    {
        return *this = *this - B;
    }

    Matrix<T, N, M> operator*=(Matrix<T, N, M> const &B)
    {
        return *this = *this * B;
    }
    Matrix<T, N, M> operator==(Matrix<T, N, M> const &B) { return A == B.A; }
    Matrix<T, N, M> operator!=(Matrix<T, N, M> const &B) { return A != B.A; }
};

template <typename T, int N>
using SquareMatrix = Matrix<T, N, N>;

} // namespace cplib
