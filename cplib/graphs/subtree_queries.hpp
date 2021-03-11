#ifndef CPLIB_SUBTREE_QUERIES_HPP
#define CPLIB_SUBTREE_QUERIES_HPP

#include "cplib/graphs/dfs_visitor.hpp"
#include "cplib/graphs/unweighted_tree.hpp"
#include <cassert>
#include <vector>

namespace cplib
{
template <template <class S, S (*op)(S, S), S (*e)()> class segtree,
          class S,
          S (*op)(S, S),
          S (*e)()>
struct SubtreeQueries
{
    using SegmentTree = segtree<S, op, e>;
    using Tree        = UnweightedTree;

    int         n;
    SegmentTree st;
    vector<S>   values;
    vector<int> id, sz;

    SubtreeQueries(const Tree &g, int root, vector<S> values)
        : n(g.size()), st(n), id(n), sz(n)
    {
        struct Visitor : public virtual DFSVisitor<Tree>
        {
            int          timer = 0;
            vector<int> &id, &sz;
            Visitor(const Tree &g, vector<int> &id, vector<int> &sz)
                : DFSVisitor<Tree>(g), id(id), sz(sz){};
            void discover_vertex(int u) { id[u] = timer++, sz[id[u]] = 1; }
            void off_tree_edge(int u, int v) { sz[id[u]] += sz[id[v]]; }
        } vis(g, id, sz);

        g.dfs(root, vis);
        for (int u = 0; u < n; ++u)
            st.set(id[u], values[u]);
    }

    S query(int u)
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

#endif // CPLIB_SUBTREE_QUERIES_HPP
