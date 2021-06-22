#ifndef CPLIB_PFINT_HPP
#define CPLIB_PFINT_HPP

#include <cassert>
#include <cplib/math/binary_exponentiation>
#include <cplib/utils/misc>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;
struct pfint
{
    vector<pair<int, int>> pf;
    bool                   zero;

    pfint() : zero(true) {}
    pfint(vector<pair<int, int>> pf, bool zero = false) : pf(pf), zero(zero) {}

    template <typename T>
    T val() const
    {
        T ans = 1;
        for (auto [p, e] : pf)
            ans *= binpow(T(p), e);
        return ans;
    }
    static pfint    e() { return {{}, true}; }
    size_t          size() const { return pf.size(); }
    pair<int, int> &operator[](int i)
    {
        assert(0 <= i and i < (int)pf.size());
        return pf[i];
    }

    const pair<int, int> &operator[](int i) const
    {
        assert(0 <= i and i < (int)pf.size());
        return pf[i];
    }

    pfint operator*(pfint a) const
    {
        /*
         * Takes the union/aggrefation of prime factors of both numbers
         */
        if (zero or a.zero)
            return this->e();
        return map_union(pf, a.pf);
    }
    friend pfint gcd(pfint a, pfint b)
    {
        /*
         * Takes the intersection of prime factors of both numbers
         */
        if (a.zero)
            return b;
        if (b.zero)
            return a;
        return map_intersection(a.pf, b.pf);
    };
};
} // namespace cplib

#endif // CPLIB_PFINT_HPP
