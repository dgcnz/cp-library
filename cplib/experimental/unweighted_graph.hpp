#ifndef CPLIB_UNWEIGHTED_GRAPH_HPP
#define CPLIB_UNWEIGHTED_GRAPH_HPP
#include "cplib/graphs/base_graph.hpp"
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

struct UnweightedGraph : public BaseGraph<int>
{
    using self     = UnweightedGraph;
    using BaseType = BaseGraph<int>;
    using BaseType::add_edge;
    using BaseType::add_edges;
    using BaseType::g;
    using BaseType::size;
    using BaseType::operator[];
    using BaseType::begin;
    using BaseType::end;

    UnweightedGraph(int n) : BaseType(n) {}

    template <typename Visitor>
    void dfs(int src, Visitor &vis) const
    {
        // 0 unvisited, 1 visiting, 2 visited
        int         n = g.size();
        vector<int> color(n, 0);

        for (int u = 0, n = g.size(); u < n; ++u)
            vis.initialize_vertex(src);

        function<void(int)> traverse = [&](int u) {
            color[u] = 1;
            vis.discover_vertex(u);
            for (auto v : g[u])
            {
                vis.examine_edge(u, v);
                if (color[v] == 0)
                    vis.on_tree_edge(u, v), traverse(v),
                        vis.off_tree_edge(u, v);
                else if (color[v] == 1)
                    vis.back_edge(u, v);
                else
                    vis.cross_edge(u, v);
                vis.finish_edge(u, v);
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

#endif // CPLIB_UNWEIGHTED_GRAPH_HPP
