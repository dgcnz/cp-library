#ifndef CPLIB_BLOCKCUT_HPP
#define CPLIB_BLOCKCUT_HPP
// Source: https://codeforces.com/blog/entry/50428?#comment-343460
#include <cplib/graph/graph>
#include <vector>

namespace cplib
{
using namespace std;

template <typename W>
struct BlockCut
{

    vector<int>         id, cut;
    vector<vector<int>> comps;
    Graph<W>            tree;

    BlockCut(Graph<W> const &g) : id(g.size()), cut(g.size())
    {
        int         t, n = g.size();
        vector<int> tin(n, 0), low(n, 0), stk;

        function<void(int, int)> dfs = [&](int u, int p = -1)
        {
            int children = 0;
            tin[u] = low[u] = ++t;
            stk.push_back(u);

            for (auto vw : g[u])
            {
                int v = g.vertex(vw);
                if (v == p)
                    continue;

                if (!tin[v]) // not visited
                {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);

                    if (low[v] >= tin[u])
                    {
                        cut[u] = (tin[u] > 1 || tin[v] > 2);

                        comps.push_back({u});
                        while (comps.back().back() != v)
                            comps.back().push_back(stk.back()), stk.pop_back();
                    }
                    children++;
                }
                else
                    low[u] = min(low[u], tin[v]);
            }
            if (p == -1 and children == 0)
            {
                stk.pop_back();
                comps.push_back({u});
            }
        };

        for (int u = 0; u < n; ++u)
            if (!tin[u])
                t = 0, dfs(u, -1);

        for (int u = 0; u < n; ++u)
            if (cut[u])
                id[u] = tree.add_node();

        for (auto &comp : comps)
        {
            int v = tree.add_node();
            for (int u : comp)
            {
                if (!cut[u])
                    id[u] = v;
                else
                    tree.add_undirected_edge(v, id[u]);
            }
        }
    }
};
} // namespace cplib

#endif // CPLIB_BLOCKCUT_HPP
