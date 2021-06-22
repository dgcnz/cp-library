#ifndef CPLIB_SUBSET_SUM_HPP
#define CPLIB_SUBSET_SUM_HPP

#include <vector>
namespace cplib
{
using namespace std;
struct SubsetSum
{
    vector<int> const &a;
    long long const    target;

    vector<vector<bool>> dp;
    SubsetSum(const vector<int> &a, long long target) : a(a), target(target) {}
    bool solve(void)
    {
        int n = a.size();
        dp    = vector<vector<bool>>(n + 1, vector<bool>(target + 1));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int x = 1; x <= target; ++x)
            {
                dp[i][x] = dp[i - 1][x];
                if (x >= a[i - 1])
                    dp[i][x] = dp[i][x] || dp[i - 1][x - a[i - 1]];
            }
        }
        return dp[n][target];
    }
};
} // namespace cplib

#endif // CPLIB_SUBSET_SUM_HPP
