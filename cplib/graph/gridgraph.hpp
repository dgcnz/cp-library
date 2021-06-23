#ifndef CPLIB_GRIDGRAPH_HPP
#define CPLIB_GRIDGRAPH_HPP

#include <cplib/graph/graph>
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
    using ii       = pair<int, int>;
    using adj_list = vector<pair<int, W>>;
    vector<string> const &table;
    int                   n, m;
    function<bool(ii)>    valid;
    function<W(ii, ii)>   cost;
    ImplicitGridGraph(vector<string> const &table,
                      function<bool(ii)>    valid,
                      function<W(ii, ii)>   cost)
        : table(table), n(table.size()), m(table[0].size()), valid(valid),
          cost(cost)
    {
    }
    size_t     size() const { return n * m; }
    inline ii  rid(int u) const { return {u / m, u % m}; }
    inline int id(int r, int c) const { return r * m + c; }
    inline int id(ii pos) const { return pos.first * m + pos.second; }

    adj_list operator[](int u) const
    {
        adj_list neighbors;
        auto [r, c] = rid(u);
        if (r > 0 and valid({r - 1, c}))
            neighbors.emplace_back(id(r - 1, c), cost({r, c}, {r - 1, c}));
        if (r < n - 1 and valid({r + 1, c}))
            neighbors.emplace_back(id(r + 1, c), cost({r, c}, {r + 1, c}));
        if (c > 0 and valid({r, c - 1}))
            neighbors.emplace_back(id(r, c - 1), cost({r, c}, {r, c - 1}));
        if (c < m - 1 and valid({r, c + 1}))
            neighbors.emplace_back(id(r, c + 1), cost({r, c}, {r, c + 1}));
        return neighbors;
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
