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

    Graph(int n) : g(n) {}

    size_t size() const { return g.size(); }
    void   add_edge(int u, int v) { g[u].emplace_back(v, W()); }
    void   add_edge(int u, int v, W weights) { g[u].emplace_back(v, weights); }

    adj_list &operator[](int u) { return g[u]; }
    adj_list  operator[](int u) const { return g[u]; }

    typename vector<adj_list>::iterator begin() { return g.begin(); };
    typename vector<adj_list>::iterator end() { return g.end(); }
};

template <>
struct Graph<void>
{
    using adj_list = vector<int>;
    vector<adj_list> g;

    Graph(int n) : g(n) {}

    size_t size() const { return g.size(); }
    void   add_edge(int u, int v) { g[u].emplace_back(v); }

    adj_list &operator[](int u) { return g[u]; }
    adj_list  operator[](int u) const { return g[u]; }

    typename vector<adj_list>::iterator begin() { return g.begin(); };
    typename vector<adj_list>::iterator end() { return g.end(); }
};

} // namespace cplib

#endif // CPLIB_GRAPH_HPP
