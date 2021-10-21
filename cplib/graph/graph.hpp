#ifndef CPLIB_GRAPH_HPP
#define CPLIB_GRAPH_HPP

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

template <typename W>
struct Graph
{
    using adj_list = vector<pair<int, W>>;
    vector<adj_list> g;

    Graph(int n = 0) : g(n) {}

    size_t size() const { return g.size(); }
    int    vertex(pair<int, W> e) const { return e.first; }
    void   add_edge(int u, int v) { g[u].emplace_back(v, W()); }
    void   add_edge(int u, int v, W weights) { g[u].emplace_back(v, weights); }
    void   add_undirected_edge(int u, int v)
    {
        g[u].emplace_back(v, W());
        g[v].emplace_back(u, W());
    }
    void add_undirected_edge(int u, int v, W weights)
    {
        g[u].emplace_back(v, weights);
        g[v].emplace_back(u, weights);
    }
    int add_node(void)
    {
        g.push_back({});
        return g.size() - 1;
    }

    adj_list &operator[](int u) { return g[u]; }
    adj_list  operator[](int u) const { return g[u]; }

    typename vector<adj_list>::iterator begin() { return g.begin(); };
    typename vector<adj_list>::iterator end() { return g.end(); }

    typename vector<adj_list>::const_iterator begin() const
    {
        return g.begin();
    };
    typename vector<adj_list>::const_iterator end() const { return g.end(); }
};

template <>
struct Graph<void>
{
    using adj_list = vector<int>;
    vector<adj_list> g;

    Graph(int n = 0) : g(n) {}

    size_t size() const { return g.size(); }
    int    vertex(int e) const { return e; }
    void   add_edge(int u, int v) { g[u].emplace_back(v); }
    void   add_undirected_edge(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int add_node(void)
    {
        g.push_back({});
        return g.size() - 1;
    }

    adj_list &operator[](int u) { return g[u]; }
    adj_list  operator[](int u) const { return g[u]; }

    typename vector<adj_list>::iterator begin() { return g.begin(); };
    typename vector<adj_list>::iterator end() { return g.end(); }

    typename vector<adj_list>::const_iterator begin() const
    {
        return g.begin();
    };
    typename vector<adj_list>::const_iterator end() const { return g.end(); }
};

} // namespace cplib

#endif // CPLIB_GRAPH_HPP
