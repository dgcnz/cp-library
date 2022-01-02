#ifndef CPLIB_SPFA_HPP
#define CPLIB_SPFA_HPP

#include "cplib/graph/graph.hpp"
#include <limits>
#include <queue>

namespace cplib
{
using namespace std;

template <typename W, W INF = numeric_limits<W>::max()>
struct SPFA
{
    Graph<W> const &g;
    vector<W>       dist;
    SPFA(Graph<W> const &g) : g(g) {}
    bool operator()(int s)
    {
        int n = g.size();
        dist.assign(n, INF);
        vector<int>  cnt(n, 0);
        vector<bool> inqueue(n, false);
        queue<int>   q;

        dist[s] = 0;
        q.push(s);
        inqueue[s] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            inqueue[v] = false;

            for (auto edge : g[v])
            {
                int to  = edge.first;
                int len = edge.second;

                if (dist[v] + len < dist[to])
                {
                    dist[to] = dist[v] + len;
                    if (!inqueue[to])
                    {
                        q.push(to);
                        inqueue[to] = true;
                        cnt[to]++;
                        if (cnt[to] > n)
                            return false; // negative cycle
                    }
                }
            }
        }
        return true;
    }
};
} // namespace cplib

#endif // CPLIB_SPFA_HPP
