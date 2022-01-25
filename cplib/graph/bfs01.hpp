#ifndef CPLIB_BFS01_HPP
#define CPLIB_BFS01_HPP

#include <algorithm>
#include <cplib/graph/graph>
#include <deque>
#include <limits>
#include <vector>

namespace cplib
{
using namespace std;
template <typename W,
          W INF                             = numeric_limits<W>::max(),
          template <typename> class graph_t = Graph>
struct BFS01
{
    graph_t<W> const &g;
    int               src;
    vector<int>       p;
    vector<W>         d;
    BFS01(graph_t<W> const &g) : g(g), p(g.size()), d(g.size()){};
    void run(int src = 0)
    {
        this->src = src;
        fill(begin(p), end(p), -1);
        fill(begin(d), end(d), INF);

        deque<int> q;
        d[src] = 0;
        q.push_front(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop_front();

            for (auto [v, w] : g[u])
            {
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    p[v] = u;
                    if (w == 1)
                        q.push_back(v);
                    else
                        q.push_front(v);
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

#endif // CPLIB_BFS01_HPPk
