
struct LCA
{
    using vi   = vector<int>;
    using Tree = vector<vi>;

    int        n;
    vector<vi> up;
    vi         tin, tout;

    LCA(const Tree &g) : n(g.size()), up(n, vi(log2(n) + 2)), tin(n), tout(n)
    {
        int timer = 0;
        preprocess(g, 0, 0, timer);
    }

    void preprocess(const Tree &g, int u, int p, int &timer)
    {
        tin[u]   = ++timer;
        up[u][0] = p;
        for (int i = 1, height = up[0].size(); i < height; ++i)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for (int v : g[u])
            if (v != p)
                preprocess(g, v, u, timer);

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
