#ifndef CPLIB_DIJKSTRA_HPP
#define CPLIB_DIJKSTRA_HPP

#include "cplib/graph/graph.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

template <typename W, W INF = numeric_limits<W>::max()>
struct Dijkstra
{
    Graph<W> const &g;
    int             src;
    vector<int>     p;
    vector<W>       d;

    Dijkstra(Graph<W> const &g) : g(g), p(g.size()), d(g.size()){};
    void run(int src = 0)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);

        set<pair<W, int>> q;
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

    void run_avoid(int src, int prohibited)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);

        set<pair<W, int>> q;
        d[src] = 0;
        q.emplace(d[src], src);
        while (!q.empty())
        {
            int u = q.begin()->second;
            q.erase(q.begin());

            for (auto [v, w] : g[u])
            {
                if (v == prohibited)
                    continue;
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

    Graph<W> shortest_path_DAG(void) const
    {
        int      n = g.size();
        Graph<W> dag(n);
        for (int v = 0; v < n; ++v)
            if (auto u = p[v]; u != -1)
                dag.add_edge(u, v, d[v] - d[u]);
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
    bool is_reachable(int u) { return d[u] != INF; }
    W    distance(int u) { return d[u]; }
    void operator()(int src = 0) { run(src); }
};
} // namespace cplib

#endif // CPLIB_DIJKSTRA_HPP
