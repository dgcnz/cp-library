#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using vi  = vector<int>;
using mii = map<int, int>;

const int PMAX = 1e7 + 11; // okay for range <= INT_MAX

bitset<PMAX> is_prime; // is_prime[i], true if number i is prime, else false
vector<int>  primes;   // primes[i], prime at pos i

vi prime_factors(ll n)
{
    // mii factors;
    vi factors;
    ll i = 0, pf = primes[i];

    while (pf * pf <= n)
    {
        while (n % pf == 0)
        {
            factors.push_back(pf);
            // ++factors[pf];
            n = n / pf;
        }
        pf = primes[++i];
    }

    if (n != 1) // If n is prime then it will stay the same, add n.
        factors.push_back(n); // ++factors[n];
    return factors;
}

// Note it's only necessary to sieve until sqrt(upperbound), why?
//
// (1) All smaller numbers that are multiples of i necessary also have a prime
// factor which is less than i, so all of them were already sifted earlier.

void sieve(void) // fi primes until upperbound inclusive
{
    is_prime.set(); // set all bits to true
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i < PMAX; i++)
        if (is_prime[i])
        {
            for (ll j = i * i; j < PMAX; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
}
