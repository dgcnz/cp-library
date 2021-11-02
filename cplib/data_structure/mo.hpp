#ifndef CPLIB_MO_HPP
#define CPLIB_MO_HPP
#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <utility>
#include <vector>

// source:
// https://hitonanode.github.io/cplib-cpp/other_algorithms/mos_algorithm.hpp

namespace cplib
{
using namespace std;

class Mo
{
    static const int INF = 1 << 30;
    int              nmin, nmax;

  public:
    vector<pair<int, int>> ranges;
    Mo() : nmin(INF), nmax(-INF) {}

    void add_range(int l, int r)
    {
        assert(l <= r);
        nmin = min(nmin, l);
        nmax = max(nmax, r);
        ranges.emplace_back(l, r);
    }
    template <typename F1, typename F2, typename F3, typename F4, typename F5>
    void run(F1 Query, F2 AddLeft, F3 RemoveLeft, F4 AddRight, F5 RemoveRight)
    {
        const int Q = ranges.size();
        if (!Q)
            return;
        const int   nbbucket = max(1, min<int>(nmax - nmin, sqrt(Q)));
        const int   szbucket = (nmax - nmin + nbbucket - 1) / nbbucket;
        vector<int> qs(Q);
        iota(qs.begin(), qs.end(), 0);
        sort(qs.begin(),
             qs.end(),
             [&](int q1, int q2)
             {
                 int b1 = (ranges[q1].first - nmin) / szbucket,
                     b2 = (ranges[q2].first - nmin) / szbucket;
                 if (b1 != b2)
                     return b1 < b2;
                 else
                     return (b1 & 1) ? (ranges[q1].second > ranges[q2].second)
                                     : (ranges[q1].second < ranges[q2].second);
             });

        int l = ranges[qs[0]].first, r = l;
        for (auto q : qs)
        {
            while (r < ranges[q].second)
                AddRight(r++);
            while (l > ranges[q].first)
                AddLeft(--l);
            while (r > ranges[q].second)
                RemoveRight(--r);
            while (l < ranges[q].first)
                RemoveLeft(l++);
            assert(l == ranges[q].first and r == ranges[q].second);
            Query(q);
        }
    }
    template <typename F1, typename F2, typename F3>
    void run(F1 Query, F2 Add, F3 Remove)
    {
        run(Query, Add, Remove, Add, Remove);
    }
};
} // namespace cplib

#endif // CPLIB_MO_HPP
