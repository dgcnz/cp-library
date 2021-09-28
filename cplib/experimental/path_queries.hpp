#ifndef CPLIB_PATH_QUERIES_HPP
#define CPLIB_PATH_QUERIES_HPP

#include "cplib/graphs/lca.hpp"
#include <cassert>
#include <vector>

namespace cplib
{
template <template <class S, S (*op)(S, S), S (*e)()> class segtree,
          class S,
          S (*op)(S, S),
          S (*e)(),
          S (*inv)(S)>
struct PathQueries
{
    int                 n;
    vector<vector<int>> g;
    LCA                 lca;
    segtree<S, op, e>   st;
    vector<S>           values;
    vector<int>         id, sz;

    PathQueries(int n) : g(n), lca(n), st(n) {}

    void add_edge(int u, int v)
    {
        lca.add_edge(u, v);
        g[u].push_back(v), g[v].push_back(u);
    }

    S query(int u) const
    {
        assert(0 <= u and u < n);
        return st.prod(id[u], id[u] + sz[id[u]]);
    }

    void set(int u, S x)
    {
        assert(0 <= u and u < n);
        st.set(id[u], x);
    }
};
} // namespace cplib

#endif // CPLIB_PATH_QUERIES_HPP
