#include <bits/stdc++.h>

using namespace std;

using ll = long long;
template <typename T>
using vx = vector<T>;
template <typename T>
using vvx = vector<vx<T>>;

const ll INF = 1e16;

const vvx<ll> floyd_warshall(int n, const vvx<int> &g)
{
    vvx<ll> dist(n + 1, vx<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (g[i][j])
                dist[i][j] = g[i][j];
            else
                dist[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
