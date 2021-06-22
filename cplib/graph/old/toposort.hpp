#pragma once

#include <cplib/graphs/graph>
#include <functional>
#include <vector>

using namespace std;

namespace cplib
{
template <typename W>
vector<int> toposort(Graph<W> g)
{
    int         n = g.size();
    vector<int> visited(n, false), order;

    function<bool(int)> dfs = [&](int u) {
        if (visited[u] == 1)
            return false;
        if (visited[u] == 2)
            return true;

        visited[u] = 1;
        for (auto v : g.neighbors(u))
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
} // namespace cplib
