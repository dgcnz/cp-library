#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vii = vector<ii>;
using lli = pair<ll, int>;
template <typename T>
using pqueue = priority_queue<T>;

const int NMAX = 1e5 + 11;
const ll  INF  = 1e16;

int n, m;
vii g[NMAX]; // node, cost

vector<ll> dijkstra(int start)
{
    pqueue<lli>  q;
    vector<ll>   distance(n + 1, INF);
    vector<bool> processed(n + 1, false);

    distance[start] = 0;
    q.push({0, start});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (processed[u])
            continue;
        processed[u] = true;
        for (auto [v, w] : g[u])
        {
            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                q.push({-distance[v], v}); // negative weight because pq is >
            }
        }
    }
    return distance;
}
