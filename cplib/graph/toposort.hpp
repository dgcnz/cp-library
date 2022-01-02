#ifndef CPLIB_TOPOSORT_HPP
#define CPLIB_TOPOSORT_HPP

#include <algorithm>
#include <cplib/graph/graph>
#include <functional>
#include <vector>

namespace cplib
{
using namespace std;

/*
 * @brief Computes one iteration of the dfs in a topological sorting.
 * @param g Graph
 * @param u Source node
 * @param order Reverse ordering
 * @param color n-sized vector where 0:unvisited, 1:visiting, 2:visited
 * @note O(n + m)
 */
template <typename T>
bool toposort_dfs(Graph<T> const &g,
                  int             u,
                  vector<int>    &order,
                  vector<int>    &color)
{
    if (color[u] == 1) // Cycle
        return false;
    if (color[u] == 2) // Intersection
        return true;

    color[u] = 1;
    for (auto edge : g[u])
        if (not toposort_dfs(g, g.vertex(edge), order, color))
            return false;
    color[u] = 2;
    order.push_back(u);
    return true;
}

/*
 * @brief Computes the topological sorting of Graph g.
 * @param g Graph
 * @note O(n + m)
 */
template <typename T>
vector<int> toposort(Graph<T> const &g)
{
    int         n = g.size();
    vector<int> order, color(n, false);
    for (int u = 0; u < n; ++u)
        if (not color[u] and not toposort_dfs(g, u, order, color))
            return {};
    reverse(order.begin(), order.end());
    return order;
}

/*
 * @brief Computes the topological sorting of the nodes reachable from src.
 * @param g Graph
 * @param src Source node
 * @note O(n + m)
 */
template <typename T>
vector<int> toposort(Graph<T> const &g, int src)
{
    int         n = g.size();
    vector<int> order, color(n, false);
    if (not toposort_dfs(g, src, order, color))
        return {};
    reverse(order.begin(), order.end());
    return order;
}

} // namespace cplib

#endif // CPLIB_TOPOSORT_HPP
