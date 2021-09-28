---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/number_iterator.hpp
    title: cplib/utils/number_iterator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/range.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cplib/utils/number_iterator.hpp>\n\ntemplate <typename T = int>\nclass range\n\
    {\n    T l, r;\n\n  public:\n    using iterator         = NumberIterator<T>;\n\
    \    using forward_iterator = NumberIterator<T>;\n    // using reverse_iterator\
    \ = ReverseNumberIterator<T>;\n\n    range(T l, T r) : l(l), r(r) { assert(r >=\
    \ l); }\n    range(T n) : range(0, n) {}\n    iterator begin() { return iterator(l);\
    \ }\n    iterator end() { return iterator(r); }\n};\n\n\n"
  code: "#ifndef CPLIB_RANGE_HPP\n#define CPLIB_RANGE_HPP\n\n#include <cassert>\n\
    #include <cplib/utils/number_iterator.hpp>\n\ntemplate <typename T = int>\nclass\
    \ range\n{\n    T l, r;\n\n  public:\n    using iterator         = NumberIterator<T>;\n\
    \    using forward_iterator = NumberIterator<T>;\n    // using reverse_iterator\
    \ = ReverseNumberIterator<T>;\n\n    range(T l, T r) : l(l), r(r) { assert(r >=\
    \ l); }\n    range(T n) : range(0, n) {}\n    iterator begin() { return iterator(l);\
    \ }\n    iterator end() { return iterator(r); }\n};\n\n#endif // CPLIB_RANGE_HPP\n"
  dependsOn:
  - cplib/utils/number_iterator.hpp
  isVerificationFile: false
  path: cplib/utils/range.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/range.hpp
layout: document
redirect_from:
- /library/cplib/utils/range.hpp
- /library/cplib/utils/range.hpp.html
title: cplib/utils/range.hpp
---
