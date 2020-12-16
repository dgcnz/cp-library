#ifndef MODINT_HPP
#define MODINT_HPP

#include "binary_exponentiation.hpp"
#include <cassert>
#include <vector>

template <int M>
class ModInt
{
    using ll   = long long;
    using mint = ModInt<M>;
    ll x;

  public:
    static const int         MOD = M;
    static std::vector<mint> inv;

    ModInt(ll x) : x(x) {}
    ModInt() : x(0) {}
    ModInt(mint const &y) : x(y.v()) {}
    explicit  operator ll() const { return v(); }
    ll        v(void) const { return mint::v(x); }
    static ll v(ll x)
    {
        if (x < 0)
            return x + M;
        return (x >= M ? x % M : x);
    }
    mint &operator=(mint const &y)
    {
        x = y.v();
        return *this;
    }
    mint &operator=(ll const &y) { return operator=(mint(y)); }
    mint &operator+=(mint const &y) { return operator=(operator+(y)); }
    mint &operator-=(mint const &y) { return operator=(operator-(y)); }
    mint &operator*=(mint const &y) { return operator=(operator*(y)); }
    mint  operator+(mint const &y) const { return mint::v(v() + y.v()); }
    mint  operator+(ll const &y) const { return operator+(mint(y)); }
    mint  operator-(mint const &y) const { return mint::v(v() - y.v()); }
    mint  operator-(ll const &y) const { return operator-(mint(y)); }
    mint  operator*(mint const &y) const { return mint::v(v() * y.v()); }
    mint  operator*(ll const &y) const { return operator*(mint(y)); }
    mint  operator/(mint const &y) const { return operator*(y.inverse()); }
    mint  operator/(ll const &y) const { return operator*(mint::inverse(y)); }

    static void precompute_inverses(int len)
    {
        assert(len < 1e8 and len > 0);
        int plen = inv.size();
        if (len > plen)
        {
            inv.resize(len);
            for (int i = plen; i < len; ++i)
                inv[i] = MOD - ll(inv[MOD % i] * (MOD / i));
        }
    }
    mint        inverse(void) const { return mint::inverse(v()); }
    static mint inverse(ll x)
    {
        assert(x > 0);
        if (x < ll(inv.size()))
            return inv[x];
        return binpow(mint(x), MOD - 2);
    }
};

template <int MOD>
std::vector<ModInt<MOD>> ModInt<MOD>::inv{0, 1};

#endif
