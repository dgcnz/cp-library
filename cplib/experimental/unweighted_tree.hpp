#ifndef CPLIB_UNWEIGHTED_TREE_HPP
#define CPLIB_UNWEIGHTED_TREE_HPP
#include "cplib/graphs/unweighted_graph.hpp"
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
struct UnweightedTree : public UnweightedGraph
{
    using BaseType = UnweightedGraph;
    using BaseType::add_edge;
    using BaseType::add_edges;
    using BaseType::g;
    using BaseType::size;
    using BaseType::operator[];
    using BaseType::begin;
    using BaseType::dfs;
    using BaseType::end;

    UnweightedTree(int n) : UnweightedGraph(n){};
};

} // namespace cplib

#endif // CPLIB_UNWEIGHTED_TREE_HPP
