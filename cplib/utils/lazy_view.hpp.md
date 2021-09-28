---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/lazy_state.hpp
    title: cplib/utils/lazy_state.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/graph/gridgraph.hpp
    title: cplib/graph/gridgraph.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/lazy_view.hpp\"\n\n\n\n#include <cplib/utils/lazy_state>\n\
    #include <exception>\n#include <iterator>\n#include <stdexcept>\n#include <type_traits>\n\
    #include <vector>\nnamespace cplib\n{\nusing namespace std;\ntemplate <class S,\
    \ typename T>\nstruct lazy_view\n{\n    using iterator_category = std::forward_iterator_tag;\n\
    \    using difference_type   = std::ptrdiff_t;\n    using value_type        =\
    \ T;\n    using pointer           = T *;\n    using reference         = T &;\n\
    \    using self              = lazy_view<S, T>;\n\n  private:\n    S    state;\n\
    \    bool terminated;\n\n  public:\n    lazy_view(S _state, bool terminated) :\
    \ state(_state), terminated(terminated)\n    {\n    }\n\n    lazy_view &operator++()\n\
    \    {\n        if (!state.terminated())\n            state.next();\n        terminated\
    \ = state.terminated();\n        return *this;\n    }\n    T operator*() { return\
    \ state.value(); }\n\n    inline bool operator==(lazy_view<S, T> const &other)\
    \ const\n    {\n        if (terminated or other.terminated)\n            return\
    \ terminated == other.terminated;\n        return state.value() == other.state.value();\n\
    \    }\n    inline bool operator!=(lazy_view const &other) const\n    {\n    \
    \    return !(operator==(other));\n    }\n\n    lazy_view<S, T> begin() { return\
    \ lazy_view(state, state.terminated()); }\n    lazy_view<S, T> end() { return\
    \ lazy_view(state, true); }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_LAZY_VIEW_HPP\n#define CPLIB_LAZY_VIEW_HPP\n\n#include <cplib/utils/lazy_state>\n\
    #include <exception>\n#include <iterator>\n#include <stdexcept>\n#include <type_traits>\n\
    #include <vector>\nnamespace cplib\n{\nusing namespace std;\ntemplate <class S,\
    \ typename T>\nstruct lazy_view\n{\n    using iterator_category = std::forward_iterator_tag;\n\
    \    using difference_type   = std::ptrdiff_t;\n    using value_type        =\
    \ T;\n    using pointer           = T *;\n    using reference         = T &;\n\
    \    using self              = lazy_view<S, T>;\n\n  private:\n    S    state;\n\
    \    bool terminated;\n\n  public:\n    lazy_view(S _state, bool terminated) :\
    \ state(_state), terminated(terminated)\n    {\n    }\n\n    lazy_view &operator++()\n\
    \    {\n        if (!state.terminated())\n            state.next();\n        terminated\
    \ = state.terminated();\n        return *this;\n    }\n    T operator*() { return\
    \ state.value(); }\n\n    inline bool operator==(lazy_view<S, T> const &other)\
    \ const\n    {\n        if (terminated or other.terminated)\n            return\
    \ terminated == other.terminated;\n        return state.value() == other.state.value();\n\
    \    }\n    inline bool operator!=(lazy_view const &other) const\n    {\n    \
    \    return !(operator==(other));\n    }\n\n    lazy_view<S, T> begin() { return\
    \ lazy_view(state, state.terminated()); }\n    lazy_view<S, T> end() { return\
    \ lazy_view(state, true); }\n};\n} // namespace cplib\n\n#endif // CPLIB_LAZY_VIEW_HPP\n"
  dependsOn:
  - cplib/utils/lazy_state.hpp
  isVerificationFile: false
  path: cplib/utils/lazy_view.hpp
  requiredBy:
  - cplib/graph/gridgraph.hpp
  timestamp: '2021-06-24 17:56:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/lazy_view.hpp
layout: document
redirect_from:
- /library/cplib/utils/lazy_view.hpp
- /library/cplib/utils/lazy_view.hpp.html
title: cplib/utils/lazy_view.hpp
---
