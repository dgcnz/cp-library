#ifndef CPLIB_GRIDGRAPH_HPP
#define CPLIB_GRIDGRAPH_HPP

#include <cplib/graph/graph>
#include <cplib/utils/grid>
#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace cplib
{

template <typename W>
struct GridGraph
{
    using ii       = pair<int, int>;
    using adj_list = vector<pair<int, W>>;

    vector<string> const &table;
    int                   n, m;
    Graph<W>              g;
    function<bool(ii)>    valid;
    function<W(ii, ii)>   cost;

    GridGraph(vector<string> const &table,
              function<bool(ii)>    valid,
              function<W(ii, ii)>   cost)
        : table(table), n(table.size()), m(table[0].size()), g(n * m),
          valid(valid), cost(cost)
    {
        build();
    }
    adj_list   &operator[](int u) { return g[u]; }
    adj_list    operator[](int u) const { return g[u]; }
    vector<int> neighbors(int u) const
    {
        vector<int> ans(g[u].size());
        transform(
            all(g[u]), begin(ans), [](pair<int, W> p) { return p.first; });
        return ans;
    }
    size_t     size() const { return g.size(); }
    inline ii  rid(int u) { return {u / m, u % m}; }
    inline int id(int r, int c) { return r * m + c; }
    inline int id(ii pos) { return pos.first * m + pos.second; }
    void       build()
    {
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < m; ++c)
            {
                int u = id(r, c);
                if (r > 0 and valid({r - 1, c}))
                {
                    int v = id(r - 1, c);
                    g.add_edge(u, v, cost({r, c}, {r - 1, c}));
                }
                if (r < n - 1 and valid({r + 1, c}))
                {
                    int v = id(r + 1, c);
                    g.add_edge(u, v, cost({r, c}, {r + 1, c}));
                }
                if (c > 0 and valid({r, c - 1}))
                {
                    int v = id(r, c - 1);
                    g.add_edge(u, v, cost({r, c}, {r, c - 1}));
                }
                if (c < m - 1 and valid({r, c + 1}))
                {
                    int v = id(r, c + 1);
                    g.add_edge(u, v, cost({r, c}, {r, c + 1}));
                }
            }
        }
    }
};

template <typename W>
struct ImplicitGridGraph
{
    using self     = ImplicitGridGraph<W>;
    using ii       = pair<int, int>;
    using edge_t   = pair<int, W>;
    using adj_list = vector<edge_t>;
    vector<string> const     &grid;
    int                       n, m, sz;
    function<bool(ii)> const  valid;
    function<W(ii, ii)> const cost;

    ImplicitGridGraph(vector<string> const     &_grid,
                      function<bool(ii)> const  _valid,
                      function<W(ii, ii)> const _cost)
        : grid(_grid), n(_grid.size()), m(_grid[0].size()), sz(n * m),
          valid(_valid), cost(_cost)
    {
    }
    size_t      size() const { return sz; }
    inline ii   rid(int u) const { return make_pair(u / m, u % m); }
    inline int  id(int r, int c) const { return r * m + c; }
    inline int  id(ii rc) const { return rc.first * m + rc.second; }
    inline bool in_range(int r, int c) const
    {
        return 0 <= r and r < n and 0 <= c and c < m;
    }

    inline bool in_range(ii rc) const
    {
        return 0 <= rc.first and rc.first < n and 0 <= rc.second and
               rc.second < m;
    }
    inline int vertex(pair<int, W> vw) const { return get<0>(vw); }
    auto       operator[](int u) const { return neighbor_view(u, 0, *this); }
    struct neighbor_view
    {
        int                         n, m, u, i;
        ii                          u_rc, v_rc;
        ImplicitGridGraph<W> const &g;
        neighbor_view(int _u, int _i, ImplicitGridGraph<W> const &_g)
            : u(_u), i(_i), g(_g)
        {
            if ((i = min(i, 4)) == 4)
                return;
            u_rc = g.rid(u);
            v_rc = u_rc + cardinal_directions[i];
            while (i < 4 and not(g.in_range(v_rc) and g.valid(v_rc)))
            {
                ++i;
                if (i < 4)
                    v_rc = u_rc + cardinal_directions[i];
            }
        }

        pair<int, W> operator*() const
        {
            if (i == 4)
                throw out_of_range("Trying to derefernce end.");
            return make_pair(g.id(v_rc), g.cost(u_rc, v_rc));
        }
        neighbor_view &operator++()
        {
            ++i;
            if ((i = min(i, 4)) == 4)
                return *this;
            v_rc = u_rc + cardinal_directions[i];
            while (i < 4 and not(g.in_range(v_rc) and g.valid(v_rc)))
            {
                ++i;
                if (i < 4)
                    v_rc = u_rc + cardinal_directions[i];
            }
            return *this;
        }
        inline bool operator==(neighbor_view const &other) const
        {
            return i == other.i;
        }
        inline bool operator!=(neighbor_view const &other) const
        {
            return i != other.i;
        }
        neighbor_view begin() const { return neighbor_view(u, 0, g); }
        neighbor_view end() const { return neighbor_view(u, 4, g); }
    };

    vector<int> neighbors(int u) const
    {
        // todo wrong
        vector<int> neighbors;
        auto [r, c] = rid(u);
        if (r > 0 and valid({r - 1, c}))
            neighbors.emplace(id(r - 1, c));
        if (r < n - 1 and valid({r + 1, c}))
            neighbors.emplace(id(r + 1, c));
        if (c > 0 and valid({r, c - 1}))
            neighbors.emplace(id(r, c - 1));
        if (c < m - 1 and valid({r, c + 1}))
            neighbors.emplace(id(r, c + 1));
        return neighbors;
    }
};

} // namespace cplib

#endif // CPLIB_GRIDGRAPH_HPP
