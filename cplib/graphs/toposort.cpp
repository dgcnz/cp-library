#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int const NMAX = 3e5 + 11;

int n, visited[NMAX];
vi  g[NMAX], order;

bool dfs(int u)
{
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
}

bool toposort(void)
{
    memset(visited, 0, sizeof(visited));
    for (int u = 0; u < n; ++u)
        if (not visited[u] and not dfs(u))
            return false;
    return true;
}
