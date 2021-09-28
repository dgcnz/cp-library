---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/number_iterator.hpp
    title: cplib/utils/number_iterator.hpp
  - icon: ':warning:'
    path: cplib/utils/reverse_number_iterator.hpp
    title: cplib/utils/reverse_number_iterator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/rev_range.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cplib/utils/reverse_number_iterator.hpp>\n\ntemplate <typename T = int>\n\
    class rev_range\n{\n    T l, r;\n\n  public:\n    using iterator         = ReverseNumberIterator<T>;\n\
    \    using forward_iterator = ReverseNumberIterator<T>;\n    // using reverse_iterator\
    \ = NumberIterator<T>;\n\n    rev_range(T l, T r) : l(l), r(r) { assert(l >= r);\
    \ }\n    iterator begin() { return iterator(l); }\n    iterator end() { return\
    \ iterator(r); }\n};\n\n\n"
  code: "#ifndef CPLIB_REV_RANGE_HPP\n#define CPLIB_REV_RANGE_HPP\n\n#include <cassert>\n\
    #include <cplib/utils/reverse_number_iterator.hpp>\n\ntemplate <typename T = int>\n\
    class rev_range\n{\n    T l, r;\n\n  public:\n    using iterator         = ReverseNumberIterator<T>;\n\
    \    using forward_iterator = ReverseNumberIterator<T>;\n    // using reverse_iterator\
    \ = NumberIterator<T>;\n\n    rev_range(T l, T r) : l(l), r(r) { assert(l >= r);\
    \ }\n    iterator begin() { return iterator(l); }\n    iterator end() { return\
    \ iterator(r); }\n};\n\n#endif // CPLIB_REV_RANGE_HPP\n"
  dependsOn:
  - cplib/utils/reverse_number_iterator.hpp
  - cplib/utils/number_iterator.hpp
  isVerificationFile: false
  path: cplib/utils/rev_range.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/rev_range.hpp
layout: document
redirect_from:
- /library/cplib/utils/rev_range.hpp
- /library/cplib/utils/rev_range.hpp.html
title: cplib/utils/rev_range.hpp
---
