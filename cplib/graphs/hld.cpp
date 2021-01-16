#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int NMAX = 1e5;

// parent[i]: parent of node i
// depth[i]: depth of node i
// heavy[i]: next heavy node from node i
// head[i]: node at the top of chain in which i lies
// pos[i]: position of node i in the segment tree that maintains the hld

vi  g[NMAX];
int parent[NMAX], depth[NMAX], heavy[NMAX], head[NMAX], pos[NMAX];

int segment_tree_query(int ql, int qr) { return 0; }

// DFS's Purpose:
// - Build depth and heavy array.
int dfs(int u)
{
    // u_sz: size of u's subtree, v_sz: size of v's subtree
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
    head[u] = h;
    pos[u]  = hld_pos++;

    // If u is not a leaf, first decompose its heavy path with head = u's head.
    // This will guarantee that heavy paths are contiguous in pos[] array
    // Later this will help to maintain the tree with only one segment tree
    if (heavy[u] != -1)
        decompose(heavy[u], h, hld_pos);
    for (int v : g[u])
    {
        if (v != parent[u] and v != heavy[u])
            decompose(v, v, hld_pos); // Form a new heavy path with v as start
    }
}

void init(void)
{
    int hld_pos = 0;

    memset(heavy, -1, sizeof(*heavy) * NMAX);
    dfs(0);
    decompose(0, 0, hld_pos);
}

// The path from a to b can be decomposed to a -> lca(a, b) + b -> lca(a, b).
// This query implementation will force the deepest node to climb up until both
// of them are on the same chain, computing partial answers as they go.
// Once there one query will do the job.
int query(int a, int b)
{
    int ans = 0;

    // This loop will allow the deeper node to climb chains until it gets to a
    // and b's lca. It will compute the partial answers on each chain.
    while (head[a] != head[b]) // While a and b are on different chains
    {
        // We need to find a and b's lca. The node whose chain is furthest down
        // has to climb up. We will refer as b to that node.
        // Note that it can stop referring to the same node if the the node
        // that's climbing becomes less deeper than the other.
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        ans                    = max(ans, cur_heavy_path_max);
        b                      = parent[head[b]];
    }
    // Now both a and b are on the same chain, same trick as before, b will
    // refer to the deeper node (the one that appears last in the segment tree).
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    ans                     = max(ans, last_heavy_path_max);
    return ans;
}
