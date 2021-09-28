---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/number_iterator.hpp
    title: cplib/utils/number_iterator.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/utils/rev_range.hpp
    title: cplib/utils/rev_range.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/reverse_number_iterator.hpp\"\n\n\n\n#include\
    \ <cplib/utils/number_iterator.hpp>\n\ntemplate <typename T>\nclass ReverseNumberIterator\
    \ : public NumberIterator<T>\n{\n    T n;\n\n  public:\n    using self = NumberIterator<T>;\n\
    \    ReverseNumberIterator(T n) : NumberIterator<T>(n) {}\n\n    self &operator++(int)\
    \ { return this->operator--(0); }\n    self &operator++() { return this->operator--();\
    \ }\n    self &operator--(int) { return this->operator++(0); }\n    self &operator--()\
    \ { return this->operator++(); }\n};\n\n\n"
  code: "#ifndef CPLIB_REVERSE_NUMBER_ITERATOR_HPP\n#define CPLIB_REVERSE_NUMBER_ITERATOR_HPP\n\
    \n#include <cplib/utils/number_iterator.hpp>\n\ntemplate <typename T>\nclass ReverseNumberIterator\
    \ : public NumberIterator<T>\n{\n    T n;\n\n  public:\n    using self = NumberIterator<T>;\n\
    \    ReverseNumberIterator(T n) : NumberIterator<T>(n) {}\n\n    self &operator++(int)\
    \ { return this->operator--(0); }\n    self &operator++() { return this->operator--();\
    \ }\n    self &operator--(int) { return this->operator++(0); }\n    self &operator--()\
    \ { return this->operator++(); }\n};\n\n#endif // CPLIB_REVERSE_NUMBER_ITERATOR_HPP\n"
  dependsOn:
  - cplib/utils/number_iterator.hpp
  isVerificationFile: false
  path: cplib/utils/reverse_number_iterator.hpp
  requiredBy:
  - cplib/utils/rev_range.hpp
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/reverse_number_iterator.hpp
layout: document
redirect_from:
- /library/cplib/utils/reverse_number_iterator.hpp
- /library/cplib/utils/reverse_number_iterator.hpp.html
title: cplib/utils/reverse_number_iterator.hpp
---
