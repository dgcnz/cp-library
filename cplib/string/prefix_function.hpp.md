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
  bundledCode: "#line 1 \"cplib/string/prefix_function.hpp\"\n\n\n\n#include <string>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\ntemplate <typename\
    \ EQF = std::equal_to<char>>\nvector<int> prefix_function(string const &s, EQF\
    \ eq = std::equal_to<char>())\n{\n    int         n = s.size();\n    vector<int>\
    \ pi(n, 0);\n    for (int i = 1; i < n; i++)\n    {\n        int j = pi[i - 1];\n\
    \        while (j > 0 and not eq(s[i], s[j]))\n            j = pi[j - 1];\n  \
    \      if (eq(s[i], s[j]))\n            j++;\n        pi[i] = j;\n    }\n    return\
    \ pi;\n}\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_PREFIX_FUNCTION_HPP\n#define CPLIB_PREFIX_FUNCTION_HPP\n\n\
    #include <string>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    template <typename EQF = std::equal_to<char>>\nvector<int> prefix_function(string\
    \ const &s, EQF eq = std::equal_to<char>())\n{\n    int         n = s.size();\n\
    \    vector<int> pi(n, 0);\n    for (int i = 1; i < n; i++)\n    {\n        int\
    \ j = pi[i - 1];\n        while (j > 0 and not eq(s[i], s[j]))\n            j\
    \ = pi[j - 1];\n        if (eq(s[i], s[j]))\n            j++;\n        pi[i] =\
    \ j;\n    }\n    return pi;\n}\n} // namespace cplib\n\n#endif // CPLIB_PREFIX_FUNCTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/prefix_function.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:46:07-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/prefix_function.hpp
layout: document
redirect_from:
- /library/cplib/string/prefix_function.hpp
- /library/cplib/string/prefix_function.hpp.html
title: cplib/string/prefix_function.hpp
---
