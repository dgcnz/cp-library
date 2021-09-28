---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/graph/experimental/dfs_visitor.hpp\"\n\n\n#include\
    \ <functional>\n#include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ cplib\n{\nusing namespace std;\n// BOOST GRAPH LIBRARY\ntemplate <typename Graph>\n\
    struct DFSVisitor\n{\n    const Graph &g;\n\n    DFSVisitor(const Graph &g) :\
    \ g(g) {}\n    void initialize_vertex([[maybe_unused]] int s)\n    {\n       \
    \ // This is invoked on every vertex of the graph before the start of the\n  \
    \      // graph search.\n    }\n    void start_search([[maybe_unused]] int s)\n\
    \    {\n        // This is invoked on the source vertex once before the start\
    \ of the\n        // search.\n    }\n    void discover_vertex([[maybe_unused]]\
    \ int u)\n    {\n        // This is invoked when a vertex is encountered for the\
    \ first time.\n    }\n    template <typename... EdgeTypes>\n    void examine_edge([[maybe_unused]]\
    \ EdgeTypes... e)\n    {\n        // This is invoked on every out-edge of each\
    \ vertex after it is\n        // discovered.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void on_tree_edge([[maybe_unused]] EdgeTypes... e)\n    {\n\
    \        // This is invoked on each edge just befor it becomes a member of the\n\
    \        // edges that form the search tree.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void off_tree_edge([[maybe_unused]] EdgeTypes... e)\n    {\n\
    \        // This is invoked on each edge just after it becomes a member of the\n\
    \        // edges that form the search tree.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void back_edge([[maybe_unused]] EdgeTypes... e)\n    {\n   \
    \     // This is invoked on the back edges in the graph. For an undirected\n \
    \       // graph there is some ambiguity between tree edges and back edges since\n\
    \        // the edge (u,v) and (v,u) are the same edge, but both the tree_edge()\n\
    \        // and back_edge() functions will be invoked. One way to resolve this\n\
    \        // ambiguity is to record the tree edges, and then disregard the\n  \
    \      // back-edges that are already marked as tree edges. An easy way to\n \
    \       // record tree edges is to record predecessors at the tree_edge event\n\
    \        // point.\n    }\n\n    template <typename... EdgeTypes>\n    void cross_edge([[maybe_unused]]\
    \ EdgeTypes... e)\n    {\n        // This is invoked on forward or cross edges\
    \ in the graph. In an\n        // undirected graph this method is never called.\n\
    \    }\n\n    template <typename... EdgeTypes>\n    void finish_edge([[maybe_unused]]\
    \ EdgeTypes...)\n    {\n        /* This is invoked on each non-tree edge as well\
    \ as on each tree edge\n         * after finish_vertex has been called on its\
    \ target vertex. */\n    }\n\n    void finish_vertex([[maybe_unused]] int u)\n\
    \    {\n        /* This is invoked on vertex u after finish_vertex has been called\
    \ for\n         *  all the vertices in the DFS-tree rooted at vertex u. If vertex\
    \ u is\n         * a leaf in the DFS-tree, then the finish_vertex function is\
    \ called on\n         * u after all the out-edges of u have been examined. */\n\
    \    }\n\n    void end_search([[maybe_unused]] int s)\n    {\n        // This\
    \ is invoked on the source vertex once after the end of the\n        // search.\n\
    \    }\n};\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_DFS_VISITOR_HPP\n#define CPLIB_DFS_VISITOR_HPP\n#include <functional>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace cplib\n{\n\
    using namespace std;\n// BOOST GRAPH LIBRARY\ntemplate <typename Graph>\nstruct\
    \ DFSVisitor\n{\n    const Graph &g;\n\n    DFSVisitor(const Graph &g) : g(g)\
    \ {}\n    void initialize_vertex([[maybe_unused]] int s)\n    {\n        // This\
    \ is invoked on every vertex of the graph before the start of the\n        //\
    \ graph search.\n    }\n    void start_search([[maybe_unused]] int s)\n    {\n\
    \        // This is invoked on the source vertex once before the start of the\n\
    \        // search.\n    }\n    void discover_vertex([[maybe_unused]] int u)\n\
    \    {\n        // This is invoked when a vertex is encountered for the first\
    \ time.\n    }\n    template <typename... EdgeTypes>\n    void examine_edge([[maybe_unused]]\
    \ EdgeTypes... e)\n    {\n        // This is invoked on every out-edge of each\
    \ vertex after it is\n        // discovered.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void on_tree_edge([[maybe_unused]] EdgeTypes... e)\n    {\n\
    \        // This is invoked on each edge just befor it becomes a member of the\n\
    \        // edges that form the search tree.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void off_tree_edge([[maybe_unused]] EdgeTypes... e)\n    {\n\
    \        // This is invoked on each edge just after it becomes a member of the\n\
    \        // edges that form the search tree.\n    }\n\n    template <typename...\
    \ EdgeTypes>\n    void back_edge([[maybe_unused]] EdgeTypes... e)\n    {\n   \
    \     // This is invoked on the back edges in the graph. For an undirected\n \
    \       // graph there is some ambiguity between tree edges and back edges since\n\
    \        // the edge (u,v) and (v,u) are the same edge, but both the tree_edge()\n\
    \        // and back_edge() functions will be invoked. One way to resolve this\n\
    \        // ambiguity is to record the tree edges, and then disregard the\n  \
    \      // back-edges that are already marked as tree edges. An easy way to\n \
    \       // record tree edges is to record predecessors at the tree_edge event\n\
    \        // point.\n    }\n\n    template <typename... EdgeTypes>\n    void cross_edge([[maybe_unused]]\
    \ EdgeTypes... e)\n    {\n        // This is invoked on forward or cross edges\
    \ in the graph. In an\n        // undirected graph this method is never called.\n\
    \    }\n\n    template <typename... EdgeTypes>\n    void finish_edge([[maybe_unused]]\
    \ EdgeTypes...)\n    {\n        /* This is invoked on each non-tree edge as well\
    \ as on each tree edge\n         * after finish_vertex has been called on its\
    \ target vertex. */\n    }\n\n    void finish_vertex([[maybe_unused]] int u)\n\
    \    {\n        /* This is invoked on vertex u after finish_vertex has been called\
    \ for\n         *  all the vertices in the DFS-tree rooted at vertex u. If vertex\
    \ u is\n         * a leaf in the DFS-tree, then the finish_vertex function is\
    \ called on\n         * u after all the out-edges of u have been examined. */\n\
    \    }\n\n    void end_search([[maybe_unused]] int s)\n    {\n        // This\
    \ is invoked on the source vertex once after the end of the\n        // search.\n\
    \    }\n};\n\n} // namespace cplib\n\n#endif // CPLIB_DFS_VISITOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/graph/experimental/dfs_visitor.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/graph/experimental/dfs_visitor.hpp
layout: document
redirect_from:
- /library/cplib/graph/experimental/dfs_visitor.hpp
- /library/cplib/graph/experimental/dfs_visitor.hpp.html
title: cplib/graph/experimental/dfs_visitor.hpp
---
