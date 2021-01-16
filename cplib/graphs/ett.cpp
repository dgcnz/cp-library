struct ETT
{
    using Tree = vector<vector<int>>;
    int         n, timer;
    vector<int> vtime, sz;

    ETT(const Tree &g) : n(g.size()), timer(0), vtime(n, 0), sz(n, 0)
    {
        flatten(g, 0, 0);
    }
    void flatten(const Tree &g, int u, int p)
    {
        vtime[u] = timer++;
        sz[u]    = 1;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            flatten(g, v, u);
            sz[u] += sz[v];
        }
    }

    pair<int, int> subtree(int u) { return {u, u + sz[u] - 1}; }
};
