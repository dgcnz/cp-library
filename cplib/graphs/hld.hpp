#ifndef CPLIB_HLD_HPP
#define CPLIB_HLD_HPP

#include <algorithm>
#include <vector>

using namespace std;

template <template <class S, S (*op)(S, S), S (*e)()> class segtree,
          class S,
          S (*op)(S, S),
          S (*e)()>
struct HLD
{
    using Tree        = vector<vector<int>>;
    using SegmentTree = segtree<S, op, e>;

    Tree        g;
    SegmentTree st;

    vector<int> parent, depth, heavy, head, pos;

    HLD(int n)
        : g(n), st(n), parent(n, 0), depth(n, 0), heavy(n, -1), head(n, 0),
          pos(n, 0)
    {
    }
    HLD(Tree _g) : HLD(_g.size()) { copy(begin(_g), end(_g), begin(g)); }
    void add_edge(int u, int v) { g[u].push_back(v), g[v].push_back(u); }

    void operator()(void)
    {
        int hld_pos = 0;
        dfs(0);
        decompose(0, 0, hld_pos);
    }

    int dfs(int u)
    {
        /*
         * Build depth and heavy array.
         *
         * u_sz: size of u's subtree
         * v_sz: size of v's subtree
         */

        int u_sz = 1, mx_v_sz = 0, v_sz;

        for (int v : g[u])
        {
            if (v != parent[u])
            {
                parent[v] = u;
                depth[v]  = depth[u] + 1;
                v_sz      = dfs(v);
                u_sz += v_sz;

                if (v_sz > mx_v_sz)
                {
                    mx_v_sz  = v_sz;
                    heavy[u] = v;
                }
            }
        }
        return u_sz;
    }

    // u: node, h: head of node
    void decompose(int u, int h, int &hld_pos)
    {
        /*
         * Decompose tree
         *
         * u: current node
         * h: head of node
         */
        head[u] = h;
        pos[u]  = hld_pos++;

        // If u is not a leaf, first decompose its heavy path with head = u's
        // head. This will guarantee that heavy paths are contiguous in pos[]
        // array Later this will help to maintain the tree with only one segment
        // tree
        if (heavy[u] != -1)
            decompose(heavy[u], h, hld_pos);
        for (int v : g[u])
            if (v != parent[u] and v != heavy[u])
                decompose(v, v, hld_pos); // New heavy path with v as start
    }

    // The path from a to b can be decomposed to a -> lca(a, b) + b -> lca(a,
    // b). This query implementation will force the deepest node to climb up
    // until both of them are on the same chain, computing partial answers as
    // they go. Once there one query will do the job.

    S query(int a, int b)
    {
        /*
         * Query range [a, b].
         *
         * The path from a to b can be decomposed to a -> lca(a, b) + b ->
         * lca(a, b). This query implementation will force the deepest node to
         * climb up until both of them are on the same chain, computing partial
         * answers as they go. Once there one query will do the job.
         */

        S ans = e();

        // This loop will allow the deeper node to climb chains until it gets to
        // a and b's lca. It will compute the partial answers on each chain.
        while (head[a] != head[b]) // While a and b are on different chains
        {
            // We need to find a and b's lca. The node whose chain is furthest
            // down has to climb up. We will refer as b to that node. Note that
            // it can stop referring to the same node if the the node that's
            // climbing becomes less deeper than the other.
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            ans = op(ans, st.prod(pos[head[b]], pos[b] + 1));
            b   = parent[head[b]];
        }
        // Now both a and b are on the same chain, same trick as before, b will
        // refer to the deeper node (the one that appears last in the segment
        // tree).
        if (depth[a] > depth[b])
            swap(a, b);
        return op(ans, st.prod(pos[a], pos[b] + 1));
    }

    void set(int u, S new_value) { st.set(pos[u], new_value); }
    S    get(int u) { return st.get(pos[u]); }
};

#endif // CPLIB_HLD_HPP
