#ifndef CPLIB_LCA_HPP
#define CPLIB_LCA_HPP

#include "cplib/graph/graph.hpp"
#include <cmath>
#include <vector>

namespace cplib
{
using namespace std;

template <typename W>
struct LCA
{
    Graph<W> const &    g;
    vector<vector<int>> up;
    vector<int>         tin, tout;

    LCA(Graph<W> const &g)
        : g(g), up(g.size(), vector<int>(log2(g.size()) + 2)), tin(g.size()),
          tout(g.size())
    {
    }

    void operator()(void)
    {
        int timer = 0;
        preprocess(0, 0, timer);
    }

    void preprocess(int u, int p, int &timer)
    {
        tin[u]   = ++timer;
        up[u][0] = p;
        for (int i = 1, height = up[0].size(); i < height; ++i)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for (auto [v, w] : g[u])
            if (v != p)
                preprocess(v, u, timer);

        tout[u] = ++timer;
    }

    bool is_ancestor(int u, int v) const
    {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    }

    int ancestor(int u, int k) const
    {
        int i;
        while (k)
        {
            i = 8 * sizeof(k) - __builtin_clz(k) - 1;
            u = up[u][i];
            k ^= 1LL << i;
        }
        if (u == 0)
            return -1;
        return u;
    }

    int lca(int u, int v) const
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = up[0].size() - 1; i >= 0; --i)
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
};
} // namespace cplib

#endif // CPLIB_LCA_HPP
