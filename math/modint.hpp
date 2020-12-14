#ifndef MODINT_HPP
#define MODINT_HPP

#include <cassert>
#include <vector>

template <int M>
class ModInt
{
    using ll   = long long;
    using mint = ModInt<M>;
    ll x;

  public:
    static const int                MOD = M;
    static inline std::vector<mint> inv{};

    ModInt(ll x) : x(x) {}
    ModInt() : x(0) {}
    ModInt(mint const &y) : x(y.v()) {}
    explicit operator ll() const { return v(); }
    ll       v(void) const { return (this->x + M) % M; }
    mint &   operator=(mint const &y)
    {
        this->x = y.v();
        return *this;
    }
    mint &operator=(ll const &y) { return this->operator=(mint(y)); }
    mint &operator+=(mint const &y) { return this->operator=(operator+(y)); }
    mint &operator-=(mint const &y) { return this->operator=(operator-(y)); }
    mint &operator*=(mint const &y) { return this->operator=(operator*(y)); }
    mint  operator+(mint const &y) const { return (v() + y.v()) % M; }
    mint  operator+(ll const &y) const { return this->operator+(mint(y)); }
    mint  operator-(mint const &y) const { return (v() - y.v()) % M; }
    mint  operator-(ll const &y) const { return this->operator-(mint(y)); }
    mint  operator*(mint const &y) const { return (v() * y.v()) % M; }
    mint  operator*(ll const &y) const { return this->operator*(mint(y)); }
    mint operator/(mint const &y) const { return this->operator*(y.inverse()); }

    // Precompute len inverses
    static void precompute_inverses(int len)
    {
        assert(len < 1e8 and len >= 2);

        int len0 = inv.size();
        inv.resize(std::max(int(inv.size()), len), 0);
        if (len0 == 0)
            inv[1] = 1, len0 = 2;
        for (int i = len0; i < len; ++i)
            inv[i] = MOD - ll(inv[MOD % i] * (MOD / i));
    }
    mint        inverse(void) const { return binpow(*this, MOD - 2); }
    static mint inverse(ll x)
    {
        assert(x > 0);
        if (x < ll(inv.size()))
            return inv[x];
        return binpow(mint(x), MOD - 2);
    }
};

#endif
