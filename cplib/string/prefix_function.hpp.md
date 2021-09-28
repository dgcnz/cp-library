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
  bundledCode: "#line 1 \"cplib/string/prefix_function.hpp\"\n#include <string>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\nvector<int> prefix_function(string\
    \ const &s)\n{\n    int         n = s.size();\n    vector<int> pi(n, 0);\n   \
    \ for (int i = 1; i < n; i++)\n    {\n        int j = pi[i - 1];\n        while\
    \ (j > 0 and s[i] != s[j])\n            j = pi[j - 1];\n        if (s[i] == s[j])\n\
    \            j++;\n        pi[i] = j;\n    }\n    return pi;\n}\n} // namespace\
    \ cplib\n"
  code: "#include <string>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace\
    \ std;\nvector<int> prefix_function(string const &s)\n{\n    int         n = s.size();\n\
    \    vector<int> pi(n, 0);\n    for (int i = 1; i < n; i++)\n    {\n        int\
    \ j = pi[i - 1];\n        while (j > 0 and s[i] != s[j])\n            j = pi[j\
    \ - 1];\n        if (s[i] == s[j])\n            j++;\n        pi[i] = j;\n   \
    \ }\n    return pi;\n}\n} // namespace cplib\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/prefix_function.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/prefix_function.hpp
layout: document
redirect_from:
- /library/cplib/string/prefix_function.hpp
- /library/cplib/string/prefix_function.hpp.html
title: cplib/string/prefix_function.hpp
---
