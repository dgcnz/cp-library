---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/lazy_state.hpp
    title: cplib/utils/lazy_state.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_vector.hpp
    title: cplib/utils/lazy_vector.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/utils/lazy_vector.hpp
    title: cplib/utils/lazy_vector.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/lazy_vector_iterator.hpp\"\n\n\n#include <cplib/utils/lazy_vector.hpp>\n\
    #include <exception>\n#include <iterator>\n#include <stdexcept>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <class\
    \ S, typename T>\nstruct lazy_vector;\n\ntemplate <class S, typename T>\nstruct\
    \ lazy_vector_iterator\n{\n    using iterator_category = std::forward_iterator_tag;\n\
    \    using difference_type   = std::ptrdiff_t;\n    using value_type        =\
    \ T;\n    using pointer           = T *;\n    using reference         = T &;\n\
    \n    lazy_vector<S, T> &v;\n    int                ix;\n    bool            \
    \   is_end;\n    lazy_vector_iterator(lazy_vector<S, T> &v, int ix, bool is_end)\n\
    \        : v(v), ix(ix), is_end(is_end)\n    {\n    }\n\n    T operator*() { return\
    \ v[ix]; }\n\n    lazy_vector_iterator &operator++()\n    {\n        v.cache_next();\n\
    \        ++ix;\n        if (ix >= (int)v.cached_size())\n            is_end =\
    \ true;\n        return *this;\n    }\n    inline bool operator==(lazy_vector_iterator\
    \ const &other) const\n    {\n        if (is_end or other.is_end)\n          \
    \  return is_end == other.is_end;\n        return ix == other.ix;\n    }\n   \
    \ inline bool operator!=(lazy_vector_iterator const &other) const\n    {\n   \
    \     return !(operator==(other));\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_LAZY_VECTOR_ITERATOR_HPP\n#define CPLIB_LAZY_VECTOR_ITERATOR_HPP\n\
    #include <cplib/utils/lazy_vector.hpp>\n#include <exception>\n#include <iterator>\n\
    #include <stdexcept>\n#include <type_traits>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <class S, typename T>\nstruct lazy_vector;\n\
    \ntemplate <class S, typename T>\nstruct lazy_vector_iterator\n{\n    using iterator_category\
    \ = std::forward_iterator_tag;\n    using difference_type   = std::ptrdiff_t;\n\
    \    using value_type        = T;\n    using pointer           = T *;\n    using\
    \ reference         = T &;\n\n    lazy_vector<S, T> &v;\n    int             \
    \   ix;\n    bool               is_end;\n    lazy_vector_iterator(lazy_vector<S,\
    \ T> &v, int ix, bool is_end)\n        : v(v), ix(ix), is_end(is_end)\n    {\n\
    \    }\n\n    T operator*() { return v[ix]; }\n\n    lazy_vector_iterator &operator++()\n\
    \    {\n        v.cache_next();\n        ++ix;\n        if (ix >= (int)v.cached_size())\n\
    \            is_end = true;\n        return *this;\n    }\n    inline bool operator==(lazy_vector_iterator\
    \ const &other) const\n    {\n        if (is_end or other.is_end)\n          \
    \  return is_end == other.is_end;\n        return ix == other.ix;\n    }\n   \
    \ inline bool operator!=(lazy_vector_iterator const &other) const\n    {\n   \
    \     return !(operator==(other));\n    }\n};\n} // namespace cplib\n\n#endif\
    \ // CPLIB_LAZY_VECTOR_ITERATOR_HPP\n"
  dependsOn:
  - cplib/utils/lazy_vector.hpp
  - cplib/utils/lazy_state.hpp
  isVerificationFile: false
  path: cplib/utils/lazy_vector_iterator.hpp
  requiredBy:
  - cplib/utils/lazy_vector.hpp
  timestamp: '2021-06-24 17:56:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/lazy_vector_iterator.hpp
layout: document
redirect_from:
- /library/cplib/utils/lazy_vector_iterator.hpp
- /library/cplib/utils/lazy_vector_iterator.hpp.html
title: cplib/utils/lazy_vector_iterator.hpp
---
