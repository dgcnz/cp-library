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
  bundledCode: "#line 1 \"cplib/divide_conquer/binary_search01.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n\nnamespace cplib\n{\n\
    using namespace std;\ntemplate <typename InputIt,\n          typename UnaryFunction,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nInputIt\
    \ binary_search01(InputIt first, InputIt last, UnaryFunction p)\n{\n    return\
    \ lower_bound(\n        first, last, T(), [&p](T x, [[maybe_unused]] T val) {\
    \ return !p(x); });\n}\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_BINARY_SEARCH01_HPP\n#define CPLIB_BINARY_SEARCH01_HPP\n\n\
    #include <algorithm>\n#include <cassert>\n#include <iterator>\n\nnamespace cplib\n\
    {\nusing namespace std;\ntemplate <typename InputIt,\n          typename UnaryFunction,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nInputIt\
    \ binary_search01(InputIt first, InputIt last, UnaryFunction p)\n{\n    return\
    \ lower_bound(\n        first, last, T(), [&p](T x, [[maybe_unused]] T val) {\
    \ return !p(x); });\n}\n} // namespace cplib\n\n#endif // CPLIB_BINARY_SEARCH01_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/divide_conquer/binary_search01.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/divide_conquer/binary_search01.hpp
layout: document
redirect_from:
- /library/cplib/divide_conquer/binary_search01.hpp
- /library/cplib/divide_conquer/binary_search01.hpp.html
title: cplib/divide_conquer/binary_search01.hpp
---
