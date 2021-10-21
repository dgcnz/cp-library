---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/utils/range.hpp
    title: cplib/utils/range.hpp
  - icon: ':warning:'
    path: cplib/utils/rev_range.hpp
    title: cplib/utils/rev_range.hpp
  - icon: ':warning:'
    path: cplib/utils/reverse_number_iterator.hpp
    title: cplib/utils/reverse_number_iterator.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/number_iterator.hpp\"\n\n\n\n#include <iterator>\n\
    \nnamespace cplib\n{\n\ntemplate <typename T = int>\nclass NumberIterator\n{\n\
    \    T n;\n\n    static_assert(std::is_integral<T>::value, \"Integral required.\"\
    );\n\n  public:\n    using self              = NumberIterator<T>;\n    using value_type\
    \        = T;\n    using difference_type   = T;\n    using reference         =\
    \ T &;\n    using pointer           = T *;\n    using iterator_category = std::random_access_iterator_tag;\n\
    \n    NumberIterator(T n) : n(n) {}\n    self &operator=(T n)\n    {\n       \
    \ this->n = n;\n        return *this;\n    }\n    T &   operator*() { return n;\
    \ }\n    self  operator+(T delta) const { return self(n + delta); }\n    self\
    \ &operator+=(T delta)\n    {\n        n += delta;\n        return *this;\n  \
    \  }\n    self  operator-(T delta) const { return self(n - delta); }\n    self\
    \ &operator++()\n    {\n        n++;\n        return (*this);\n    }\n    self\
    \ &operator++(int)\n    {\n        ++n;\n        return *this;\n    }\n    self\
    \ &operator--()\n    {\n        n--;\n        return (*this);\n    }\n    self\
    \ &operator--(int)\n    {\n        --n;\n        return *this;\n    }\n    difference_type\
    \ operator-(const self &rhs) const { return n - rhs.n; }\n    bool           \
    \ operator==(const self &rhs) const { return n == rhs.n; }\n    bool     operator!=(const\
    \ self &rhs) const { return !(*this == rhs.n); }\n    explicit operator T() const\
    \ { return n; }\n};\n\ntemplate <typename T>\nusing nit   = NumberIterator<T>;\n\
    using itll  = NumberIterator<long long>;\nusing itint = NumberIterator<int>;\n\
    } // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_NUMBER_ITERATOR_HPP\n#define CPLIB_NUMBER_ITERATOR_HPP\n\n\
    #include <iterator>\n\nnamespace cplib\n{\n\ntemplate <typename T = int>\nclass\
    \ NumberIterator\n{\n    T n;\n\n    static_assert(std::is_integral<T>::value,\
    \ \"Integral required.\");\n\n  public:\n    using self              = NumberIterator<T>;\n\
    \    using value_type        = T;\n    using difference_type   = T;\n    using\
    \ reference         = T &;\n    using pointer           = T *;\n    using iterator_category\
    \ = std::random_access_iterator_tag;\n\n    NumberIterator(T n) : n(n) {}\n  \
    \  self &operator=(T n)\n    {\n        this->n = n;\n        return *this;\n\
    \    }\n    T &   operator*() { return n; }\n    self  operator+(T delta) const\
    \ { return self(n + delta); }\n    self &operator+=(T delta)\n    {\n        n\
    \ += delta;\n        return *this;\n    }\n    self  operator-(T delta) const\
    \ { return self(n - delta); }\n    self &operator++()\n    {\n        n++;\n \
    \       return (*this);\n    }\n    self &operator++(int)\n    {\n        ++n;\n\
    \        return *this;\n    }\n    self &operator--()\n    {\n        n--;\n \
    \       return (*this);\n    }\n    self &operator--(int)\n    {\n        --n;\n\
    \        return *this;\n    }\n    difference_type operator-(const self &rhs)\
    \ const { return n - rhs.n; }\n    bool            operator==(const self &rhs)\
    \ const { return n == rhs.n; }\n    bool     operator!=(const self &rhs) const\
    \ { return !(*this == rhs.n); }\n    explicit operator T() const { return n; }\n\
    };\n\ntemplate <typename T>\nusing nit   = NumberIterator<T>;\nusing itll  = NumberIterator<long\
    \ long>;\nusing itint = NumberIterator<int>;\n} // namespace cplib\n\n#endif //\
    \ CPLIB_NUMBER_ITERATOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/number_iterator.hpp
  requiredBy:
  - cplib/utils/rev_range.hpp
  - cplib/utils/range.hpp
  - cplib/utils/reverse_number_iterator.hpp
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/number_iterator.hpp
layout: document
redirect_from:
- /library/cplib/utils/number_iterator.hpp
- /library/cplib/utils/number_iterator.hpp.html
title: cplib/utils/number_iterator.hpp
---
