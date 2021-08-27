#ifndef CPLIB_GRIDGRAPH_HPP
#define CPLIB_GRIDGRAPH_HPP

#include <cplib/graph/graph>
#include <cplib/utils/lazy_view>
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
    adj_list &  operator[](int u) { return g[u]; }
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
    using adj_list = vector<pair<int, W>>;
    vector<string> const &table;
    int                   n, m;
    function<bool(ii)>    valid;
    function<W(ii, ii)>   cost;
    vector<ii> const      dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    ImplicitGridGraph(vector<string> const &table,
                      function<bool(ii)>    valid,
                      function<W(ii, ii)>   cost)
        : table(table), n(table.size()), m(table[0].size()), valid(valid),
          cost(cost)
    {
    }
    size_t      size() const { return n * m; }
    inline ii   rid(int u) const { return {u / m, u % m}; }
    inline int  id(int r, int c) const { return r * m + c; }
    inline int  id(ii pos) const { return pos.first * m + pos.second; }
    inline bool in_range(int r, int c) const
    {
        return 0 <= r and r < n and 0 <= c and c < m;
    }
    inline bool in_range(ii rc) const { return in_range(rc.first, rc.second); }

    struct neighbor_state : public LazyState<ii>
    {
        int                         u, ix;
        ImplicitGridGraph<W> const &g;
        neighbor_state(int u, int ix, ImplicitGridGraph<W> const &g)
            : u(u), ix(ix), g(g)
        {
        }

        bool is_valid() const
        {
            auto [ur, uc] = g.rid(u);
            auto [dr, dc] = g.dir[ix];
            return g.in_range(ur + dr, uc + dc) and
                   g.valid(ii{ur + dr, uc + dc});
        }

        ii value() const
        {
            auto [ur, uc] = g.rid(u);
            auto [dr, dc] = g.dir[ix];
            auto v        = g.id(ur + dr, uc + dc);
            auto w        = g.cost(ii{ur, uc}, ii{ur + dr, uc + dc});
            return ii{v, w};
        }
        void next()
        {
            if (ix < 4)
                ++ix;
            while (ix < 4 and not is_valid())
                ++ix;
        }
        void init()
        {
            if (not is_valid())
                next();
        };
        bool terminated() const { return ix >= 4; };
    };

    lazy_view<neighbor_state, ii> operator[](int u) const
    {
        neighbor_state s{u, 0, *this};
        s.init();
        return lazy_view<neighbor_state, ii>(s, s.terminated());
    }

    vector<int> neighbors(int u) const
    {
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
