
int const NMAX = 1e7;
int const LMAX = 20;
int const BITS = sizeof(int) * 8;

int         n, l;
int         timer, tin[NMAX], tout[NMAX], up[NMAX][LMAX];
vector<int> g[NMAX];

void dfs(int u, int p)
{
    tin[u]   = ++timer;
    up[u][0] = p;
    for (int i = 1; i < LMAX; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : g[u])
        if (v != p)
            dfs(v, u);

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int ancestor(int u, int k)
{
    int i;
    while (k)
    {
        i = BITS - __builtin_clz(k) - 1;
        u = up[u][i];
        k ^= 1LL << i;
    }
    if (u == 0)
        return -1;
    return u;
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) { dfs(root, root); }
