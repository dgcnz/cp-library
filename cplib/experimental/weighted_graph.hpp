#ifndef CPLIB_WEIGHTED_GRAPH_HPP
#define CPLIB_WEIGHTED_GRAPH_HPP
#include "cplib/graphs/base_graph.hpp"
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

template <typename... EdgeContents>
struct WeightedGraph : protected BaseGraph<tuple<int, EdgeContents...>>
{
    using self     = WeightedGraph<EdgeContents...>;
    using EdgeType = tuple<int, EdgeContents...>;
    using BaseType = BaseGraph<EdgeType>;

    using BaseType::add_edge;
    using BaseType::add_edges;
    using BaseType::g;
    using BaseType::size;
    using BaseType::operator[];
    using BaseType::begin;
    using BaseType::end;

    WeightedGraph(int n) : BaseType(n) {}

    template <typename Visitor>
    void dfs(int src, Visitor &vis)
    {
        // 0 unvisited, 1 visiting, 2 visited
        int         n = g.size();
        vector<int> color(n, 0);

        for (int u = 0, n = g.size(); u < n; ++u)
            vis.initialize_vertex(src);

        function<void(int)> traverse = [&](int u) {
            color[u] = 1;
            vis.discover_vertex(u);
            for (auto e : g[u])
            {
                int  v    = get<0>(e);
                auto edge = tuple_cat(make_tuple(u), e);
                apply([&vis](int u,
                             auto &&...args) { vis.examine_edge(u, args...); },
                      edge);

                if (color[v] == 0)
                {
                    apply(
                        [&vis](int u, auto &&...args) {
                            vis.on_tree_edge(u, args...);
                        },
                        edge);
                    traverse(v);
                    apply(
                        [&vis](int u, auto &&...args) {
                            vis.off_tree_edge(u, args...);
                        },
                        edge);
                }
                else if (color[v] == 1)
                    apply([&vis](int u,
                                 auto &&...args) { vis.back_edge(u, args...); },
                          edge);
                else
                    apply(
                        [&vis](int u, auto &&...args) {
                            vis.cross_edge(u, args...);
                        },
                        edge);
                apply([&vis](int u,
                             auto &&...args) { vis.finish_edge(u, args...); },
                      edge);
            }
            color[u] = 2;
            vis.finish_vertex(u);
        };

        vis.start_search(src), traverse(src), vis.end_search(src);
        for (int u = 0; u < n; ++u)
            if (color[u] == 0)
                vis.start_search(u), traverse(u), vis.end_search(u);
    }
};

} // namespace cplib

#endif // CPLIB_WEIGHTED_GRAPH_HPP
