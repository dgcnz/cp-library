#include <array>
#include <cassert>

namespace cplib
{
using namespace std;

template <typename T, int N, int M>
struct Matrix
{
    // TODO
    // 1. pow
    // 2. iterators
    using allocator_type = array<array<T, M>, N>;
    using self           = Matrix<T, N, M>;
    allocator_type A;

    template <int R>
    Matrix<T, N, R> operator*(const Matrix<T, M, R> &B) const
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

    Matrix<T, N, M> operator+(const Matrix<T, N, M> &B)
    {
        Matrix<T, N, M> C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[i][j] = A[i][j] + B[i][j];
    }

    template <typename V>
    Matrix<T, N, M> pow(V x) const
    {
        return *this;
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
};
} // namespace cplib
