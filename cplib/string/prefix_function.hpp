#ifndef CPLIB_PREFIX_FUNCTION_HPP
#define CPLIB_PREFIX_FUNCTION_HPP

#include <string>
#include <vector>

namespace cplib
{
using namespace std;
template <typename EQF = std::equal_to<char>>
vector<int> prefix_function(string const &s, EQF eq = std::equal_to<char>())
{
    int         n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and not eq(s[i], s[j]))
            j = pi[j - 1];
        if (eq(s[i], s[j]))
            j++;
        pi[i] = j;
    }
    return pi;
}
} // namespace cplib

#endif // CPLIB_PREFIX_FUNCTION_HPP
