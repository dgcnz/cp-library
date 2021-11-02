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
  bundledCode: "#line 1 \"cplib/utils/io.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <iterator>\n\nnamespace cplib\n{\nusing namespace std;\ntemplate <typename InputIt,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nvoid read_n(InputIt\
    \ it, int n)\n{\n    copy_n(istream_iterator<T>(cin), n, it);\n}\n\ntemplate <typename\
    \ InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    void read(InputIt first, InputIt last)\n{\n    read_n(first, distance(first, last));\n\
    }\n\ntemplate <typename InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    void write(InputIt first, InputIt last, const char *delim = \"\\n\")\n{\n    copy(first,\
    \ last, ostream_iterator<T>(cout, delim));\n}\n\ntemplate <typename InputIt,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nvoid decrement(InputIt\
    \ first, InputIt last, T k = 1)\n{\n    transform(first, last, first, [k](T x)\
    \ { return x - k; });\n}\n\ntemplate <typename InputIt,\n          typename T\
    \ = typename iterator_traits<InputIt>::value_type>\nvoid increment(InputIt first,\
    \ InputIt last, T k = 1)\n{\n    transform(first, last, first, [k](T x) { return\
    \ x + k; });\n}\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_IO_HPP\n#define CPLIB_IO_HPP\n\n#include <iostream>\n#include\
    \ <iterator>\n\nnamespace cplib\n{\nusing namespace std;\ntemplate <typename InputIt,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nvoid read_n(InputIt\
    \ it, int n)\n{\n    copy_n(istream_iterator<T>(cin), n, it);\n}\n\ntemplate <typename\
    \ InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    void read(InputIt first, InputIt last)\n{\n    read_n(first, distance(first, last));\n\
    }\n\ntemplate <typename InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    void write(InputIt first, InputIt last, const char *delim = \"\\n\")\n{\n    copy(first,\
    \ last, ostream_iterator<T>(cout, delim));\n}\n\ntemplate <typename InputIt,\n\
    \          typename T = typename iterator_traits<InputIt>::value_type>\nvoid decrement(InputIt\
    \ first, InputIt last, T k = 1)\n{\n    transform(first, last, first, [k](T x)\
    \ { return x - k; });\n}\n\ntemplate <typename InputIt,\n          typename T\
    \ = typename iterator_traits<InputIt>::value_type>\nvoid increment(InputIt first,\
    \ InputIt last, T k = 1)\n{\n    transform(first, last, first, [k](T x) { return\
    \ x + k; });\n}\n\n} // namespace cplib\n\n#endif // CPLIB_IO_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/io.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:45:41-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/io.hpp
layout: document
redirect_from:
- /library/cplib/utils/io.hpp
- /library/cplib/utils/io.hpp.html
title: cplib/utils/io.hpp
---
