#ifndef CPLIB_TOPOSORT_HPP
#define CPLIB_TOPOSORT_HPP

#include <functional>
#include <vector>

using namespace std;

vector<int> toposort(const vector<vector<int>> &g)
{
    int         n = g.size();
    vector<int> visited(n, false), order;

    function<bool(int)> dfs = [&](int u) {
        if (visited[u] == 1)
            return false;
        if (visited[u] == 2)
            return true;

        visited[u] = 1;
        for (auto v : g[u])
            if (not dfs(v))
                return false;

        visited[u] = 2;
        order.push_back(u);
        return true;
    };

    for (int u = 0; u < n; ++u)
        if (not visited[u] and not dfs(u))
            return {};
    reverse(order.begin(), order.end());
    return order;
}

#endif // CPLIB_TOPOSORT_HPP
