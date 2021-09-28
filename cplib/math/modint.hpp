#ifndef CPLIB_MODINT_HPP
#define CPLIB_MODINT_HPP

#include <cassert>
#include <cplib/math/binary_exponentiation>
#include <vector>

namespace cplib
{
using namespace std;

template <int M>
class ModInt
{
    using ll   = long long;
    using mint = ModInt<M>;
    ll x;

  public:
    static const int           MOD = M;
    inline static vector<mint> inverse{0, 1};

    ModInt(ll x) : x(x) {}
    ModInt() : x(0) {}
    ModInt(mint const &y) : x(y.val()) {}
    explicit  operator ll() const { return val(); }
    explicit  operator int() const { return val(); }
    ll        val(void) const { return mint::val(x); }
    int       mod() const { return MOD; }
    mint      pow(ll n) const { return binpow(val(), n); }
    static ll val(ll x)
    {
        if (x < 0)
            return x + MOD;
        return (x >= MOD ? x % MOD : x);
    }
    mint &operator=(mint const &y)
    {
        x = y.val();
        return *this;
    }
    mint &operator=(ll const &y) { return operator=(mint(y)); }
    mint &operator+=(mint const &y) { return operator=(operator+(y)); }
    mint &operator-=(mint const &y) { return operator=(operator-(y)); }
    mint &operator*=(mint const &y) { return operator=(operator*(y)); }
    mint  operator+(mint const &y) const { return mint::val(val() + y.val()); }
    mint  operator+(ll const &y) const { return operator+(mint(y)); }
    mint  operator-(mint const &y) const { return mint::val(val() - y.val()); }
    mint  operator-(ll const &y) const { return operator-(mint(y)); }
    mint  operator*(mint const &y) const { return mint::val(val() * y.val()); }
    mint  operator*(ll const &y) const { return operator*(mint(y)); }
    mint  operator/(mint const &y) const { return operator*(y.inv()); }
    mint  operator/(ll const &y) const { return operator*(mint::inv(y)); }

    static void precompute_inverses(int len)
    {
        assert(len < 1e8 and len > 0);
        int plen = inverse.size();
        if (len > plen)
        {
            inverse.resize(len);
            for (int i = plen; i < len; ++i)
                inverse[i] = MOD - ll(inverse[MOD % i] * (MOD / i));
        }
    }
    mint        inv(void) const { return mint::inv(val()); }
    static mint inv(ll x)
    {
        assert(x > 0);
        if (x < ll(inverse.size()))
            return inverse[x];
        return binpow(mint(x), MOD - 2);
    }
};
} // namespace cplib

#endif // CPLIB_MODINT_HPP
