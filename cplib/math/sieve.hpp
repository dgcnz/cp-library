#ifndef CPLIB_SIEVE_HPP
#define CPLIB_SIEVE_HPP

#include <bitset>
#include <cassert>
#include <vector>

template <int SIZE>
struct Sieve
{
    static_assert(0 <= SIZE and SIZE <= 1e8, "0 <= SIZE <= 1e8");
    using byte = unsigned char;
    std::bitset<SIZE> is_prime;
    std::vector<int>  primes;

    Sieve()
    {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < SIZE; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i < SIZE; i += 2)
            if (is_prime[i])
                for (int j = i * i; j < SIZE; j += i * 2)
                    is_prime[j] = 0;

        for (int i = 2; i < SIZE; ++i)
            if (is_prime[i])
                primes.push_back(i);
    }
};

#endif // CPLIB_SIEVE_HPP
