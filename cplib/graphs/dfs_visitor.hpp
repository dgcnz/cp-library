#ifndef CPLIB_DFS_VISITOR_HPP
#define CPLIB_DFS_VISITOR_HPP
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;
// BOOST GRAPH LIBRARY
template <typename Graph>
struct DFSVisitor
{
    const Graph &g;

    DFSVisitor(const Graph &g) : g(g) {}
    void initialize_vertex([[maybe_unused]] int s)
    {
        // This is invoked on every vertex of the graph before the start of the
        // graph search.
    }
    void start_search([[maybe_unused]] int s)
    {
        // This is invoked on the source vertex once before the start of the
        // search.
    }
    void discover_vertex([[maybe_unused]] int u)
    {
        // This is invoked when a vertex is encountered for the first time.
    }
    template <typename... EdgeTypes>
    void examine_edge([[maybe_unused]] EdgeTypes... e)
    {
        // This is invoked on every out-edge of each vertex after it is
        // discovered.
    }

    template <typename... EdgeTypes>
    void on_tree_edge([[maybe_unused]] EdgeTypes... e)
    {
        // This is invoked on each edge just befor it becomes a member of the
        // edges that form the search tree.
    }

    template <typename... EdgeTypes>
    void off_tree_edge([[maybe_unused]] EdgeTypes... e)
    {
        // This is invoked on each edge just after it becomes a member of the
        // edges that form the search tree.
    }

    template <typename... EdgeTypes>
    void back_edge([[maybe_unused]] EdgeTypes... e)
    {
        // This is invoked on the back edges in the graph. For an undirected
        // graph there is some ambiguity between tree edges and back edges since
        // the edge (u,v) and (v,u) are the same edge, but both the tree_edge()
        // and back_edge() functions will be invoked. One way to resolve this
        // ambiguity is to record the tree edges, and then disregard the
        // back-edges that are already marked as tree edges. An easy way to
        // record tree edges is to record predecessors at the tree_edge event
        // point.
    }

    template <typename... EdgeTypes>
    void cross_edge([[maybe_unused]] EdgeTypes... e)
    {
        // This is invoked on forward or cross edges in the graph. In an
        // undirected graph this method is never called.
    }

    template <typename... EdgeTypes>
    void finish_edge([[maybe_unused]] EdgeTypes...)
    {
        /* This is invoked on each non-tree edge as well as on each tree edge
         * after finish_vertex has been called on its target vertex. */
    }

    void finish_vertex([[maybe_unused]] int u)
    {
        /* This is invoked on vertex u after finish_vertex has been called for
         *  all the vertices in the DFS-tree rooted at vertex u. If vertex u is
         * a leaf in the DFS-tree, then the finish_vertex function is called on
         * u after all the out-edges of u have been examined. */
    }

    void end_search([[maybe_unused]] int s)
    {
        // This is invoked on the source vertex once after the end of the
        // search.
    }
};

} // namespace cplib

#endif // CPLIB_DFS_VISITOR_HPP
