#ifndef CPLIB_SIEVE_HPP
#define CPLIB_SIEVE_HPP

#include <cassert>
#include <vector>

struct Sieve
{
    using byte = unsigned char;
    using ll   = long long;
    std::vector<byte> is_prime{0, 0, 1};

    Sieve() {}

    void precompute(int n) // upperbound inclusive
    {
        assert(n > 3 and n < 1e8);
        if (n < (int)is_prime.size())
            return;
        is_prime.resize(n + 1, true);

        for (int i = 2; i * i <= n; ++i)
            if (is_prime[i])
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
    }

    std::vector<int> get_primes(int n)
    {
        assert(n < int(is_prime.size()));
        if (n < 2)
            return {};
        std::vector<int> primes = {2};
        for (int i = 3; i <= n; i += 2)
            if (is_prime[i])
                primes.push_back(i);
        return primes;
    }
};

#endif // CPLIB_SIEVE_HPP
