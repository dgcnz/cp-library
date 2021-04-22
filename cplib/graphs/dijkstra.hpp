#ifndef CPLIB_DIJKSTRA_HPP
#define CPLIB_DIJKSTRA_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

template <typename T>
struct Dijkstra
{
    using Graph = vector<vector<pair<int, T>>>;
    T INF       = numeric_limits<T>::max();

    Graph       g;
    int         src;
    vector<int> p;
    vector<T>   d;

    Dijkstra(int n) : g(n), p(n), d(n){};
    void add_edge(int u, int v, T w = 1) { g[u].emplace_back(v, w); }

    void run(int src = 0)
    {
        clear(src);

        set<pair<T, int>> q;
        d[src] = 0;
        q.emplace(d[src], src);
        while (!q.empty())
        {
            int u = q.begin()->second;
            q.erase(q.begin());

            for (auto [v, w] : g[u])
            {
                if (d[u] + w < d[v])
                {
                    q.erase({d[v], v});
                    d[v] = d[u] + w;
                    p[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    }

    vector<vector<pair<int, T>>> shortest_path_DAG(void) const
    {
        int                          n = g.size();
        vector<vector<pair<int, T>>> dag(n);
        for (int v = 0; v < n; ++v)
            if (auto u = p[v]; u != -1)
                dag[u].emplace_back(v, d[v] - d[u]);
        return dag;
    }

    vector<int> shortest_path(int u) const
    {
        if (d[u] == INF)
            return {};
        vector<int> path;

        for (int v = u; v != src; v = p[v])
            path.push_back(v);
        path.push_back(src);

        reverse(begin(path), end(path));
        return path;
    }
    void clear(int src)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);
    }
    bool is_reachable(int u) { return d[u] != INF; }
    T    distance(int u) { return d[u]; }
    void operator()(int src = 0) { run(src); }
};
} // namespace cplib

#endif // CPLIB_DIJKSTRA_HPP
