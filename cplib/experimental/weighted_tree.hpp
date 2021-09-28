#ifndef CPLIB_WEIGHTED_TREE_HPP
#define CPLIB_WEIGHTED_TREE_HPP
#include "cplib/graphs/weighted_graph.hpp"
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace cplib
{
using namespace std;

template <typename EdgeWeights>
struct WeightedTree : protected WeightedGraph<EdgeWeights>
{
    using BaseType = WeightedGraph<EdgeWeights>;
    using BaseType::add_edge;
    using BaseType::add_edges;
    using BaseType::g;
    using BaseType::size;
    using BaseType::operator[];
    using BaseType::begin;
    using BaseType::dfs;
    using BaseType::end;

    WeightedTree(int n) : BaseType(n) {}
};
} // namespace cplib

#endif // CPLIB_WEIGHTED_TREE_HPP
