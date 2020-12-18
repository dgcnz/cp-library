#ifndef CPLIB_BINARY_EXPONENTIATION_HPP
#define CPLIB_BINARY_EXPONENTIATION_HPP

template <typename T1, typename T2>
T1 binpow(T1 base, T2 exp)
{
    T1 ans = 1;
    while (exp > 0)
    {
        if (exp & 1)
            ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

#endif // CPLIB_BINARY_EXPONENTIATION_HPP
