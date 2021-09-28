#ifndef CPLIB_MANACHER_HPP
#define CPLIB_MANACHER_HPP
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

namespace cplib
{

using namespace std;

pair<vector<int>, vector<int>> manacher(string const &s)
{
    int         n = s.size();
    vector<int> d1(n), d2(n);
    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 1 : min(d1[j], j - l + 1);
        while (0 <= i - k and i + k < n and s[i - k] == s[i + k])
            ++k;
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int j = l + r - i;
        int k = (i > r) ? 0 : min(d2[j + 1], j - l + 1);
        while (0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k])
            ++k;
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k;
        }
    }
    return {d1, d2};
}
}; // namespace cplib

#endif // CPLIB_MANACHER_HPP
