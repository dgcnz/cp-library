#ifndef CPLIB_BASE_GRAPH_HPP
#define CPLIB_BASE_GRAPH_HPP

#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

// TODO: allocator template -> Create class ordered_base_graph
// TODO: undirected edges
template <typename T>
struct BaseGraph
{
    using self       = BaseGraph<T>;
    using value_type = vector<T>;

  protected:
    vector<vector<T>> g;
    BaseGraph(int n) : g(n) {}

    template <bool DIRECTED = true, typename... Types>
    void add_edges(vector<tuple<int, int, Types...>> edges)
    {
        auto f = [this](int u, int v, auto &&...args) {
            add_edge(u, v, args...);
        };
        auto g = [this](int u, int v, auto &&...args) {
            add_edge(v, u, args...);
        };
        for (auto e : edges)
        {
            apply(f, e);
            if (!DIRECTED)
                apply(g, e);
        }
    }

    template <bool DIRECTED=true, typename... Types>
    void add_edge(int u, int v, Types... t)
    {
        g[u].emplace_back(v, t...);
        if (!DIRECTED)
            g[v].emplace_back(u, t...);
    }

    size_t     size() const { return g.size(); }
    vector<T> &operator[](int u) { return g[u]; }
    vector<T>  operator[](int u) const { return g[u]; }

    typename vector<vector<T>>::iterator begin() { return g.begin(); };
    typename vector<vector<T>>::iterator end() { return g.end(); }
};
} // namespace cplib

#endif // CPLIB_BASE_GRAPH_HPP
