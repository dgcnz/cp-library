#ifndef CPLIB_Z_FUNCTION_HPP
#define CPLIB_Z_FUNCTION_HPP

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

namespace cplib
{
using namespace std;
template <typename EQF = std::equal_to<char>>
vector<int> z_function(string s, EQF eq = std::equal_to<char>())
{
    int         n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n and eq(s[z[i]], s[i + z[i]]))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
} // namespace cplib

#endif // CPLIB_Z_FUNCTION_HPP
