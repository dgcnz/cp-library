#ifndef CPLIB_PATHQUERIES_HPP
#define CPLIB_PATHQUERIES_HPP

#include <cplib/graph/graph>
#include <cplib/graph/lca>
#include <functional>
#include <vector>

namespace cplib
{
using namespace std;

template <typename W, typename S, S (*op)(S, S), S (*inv)(S), S (*e)()>
struct PathQueries
{
    LCA<W>           lca;
    vector<S> const &x;
    vector<S>        dp;
    PathQueries(const Graph<W> &g, vector<S> const &x) : lca(g), x(x), dp(x)
    {
        int                 n = g.size();
        vector<bool>        vis(n, false);
        function<void(int)> dfs = [&](int u)
        {
            vis[u] = true;
            for (auto v : g[u])
            {
                if (vis[v])
                    continue;

                dp[v] = op(dp[u], x[v]);
                dfs(v);
            }
        };

        for (int u = 0; u < n; ++u)
            if (not vis[u])
                dfs(u);
    }

    S query(int u, int v) const
    {
        int l   = lca(u, v);
        S   ans = e();
        ans     = op(ans, dp[u]);
        ans     = op(ans, dp[v]);
        ans     = op(ans, inv(dp[l]));
        ans     = op(ans, inv(dp[l]));
        ans     = op(ans, x[l]);
        return ans;
    }

    S query(int u) const { return dp[u]; }
};
} // namespace cplib

#endif // CPLIB_PATHQUERIES_HPP
