---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/utils/lazy_vector.hpp
    title: cplib/utils/lazy_vector.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_vector_iterator.hpp
    title: cplib/utils/lazy_vector_iterator.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_view.hpp
    title: cplib/utils/lazy_view.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/lazy_state.hpp\"\n\n\n\nnamespace cplib\n{\n\
    template <typename T>\nstruct LazyState\n{\n    virtual T    value() const   \
    \   = 0;\n    virtual void next()             = 0;\n    virtual void init()  \
    \           = 0;\n    virtual bool terminated() const = 0;\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_LAZY_STATE_HPP\n#define CPLIB_LAZY_STATE_HPP\n\nnamespace cplib\n\
    {\ntemplate <typename T>\nstruct LazyState\n{\n    virtual T    value() const\
    \      = 0;\n    virtual void next()             = 0;\n    virtual void init()\
    \             = 0;\n    virtual bool terminated() const = 0;\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_LAZY_STATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/lazy_state.hpp
  requiredBy:
  - cplib/utils/lazy_view.hpp
  - cplib/utils/lazy_vector_iterator.hpp
  - cplib/utils/lazy_vector.hpp
  timestamp: '2021-06-24 17:56:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/lazy_state.hpp
layout: document
redirect_from:
- /library/cplib/utils/lazy_state.hpp
- /library/cplib/utils/lazy_state.hpp.html
title: cplib/utils/lazy_state.hpp
---
