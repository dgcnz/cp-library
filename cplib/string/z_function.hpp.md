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
  bundledCode: "#line 1 \"cplib/string/z_function.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <functional>\n#include <string>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\ntemplate <typename EQF = std::equal_to<char>>\nvector<int>\
    \ z_function(string s, EQF eq = std::equal_to<char>())\n{\n    int         n =\
    \ (int)s.length();\n    vector<int> z(n);\n    for (int i = 1, l = 0, r = 0; i\
    \ < n; ++i)\n    {\n        if (i <= r)\n            z[i] = min(r - i + 1, z[i\
    \ - l]);\n        while (i + z[i] < n and eq(s[z[i]], s[i + z[i]]))\n        \
    \    ++z[i];\n        if (i + z[i] - 1 > r)\n            l = i, r = i + z[i] -\
    \ 1;\n    }\n    return z;\n}\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_Z_FUNCTION_HPP\n#define CPLIB_Z_FUNCTION_HPP\n\n#include <algorithm>\n\
    #include <functional>\n#include <string>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\ntemplate <typename EQF = std::equal_to<char>>\nvector<int>\
    \ z_function(string s, EQF eq = std::equal_to<char>())\n{\n    int         n =\
    \ (int)s.length();\n    vector<int> z(n);\n    for (int i = 1, l = 0, r = 0; i\
    \ < n; ++i)\n    {\n        if (i <= r)\n            z[i] = min(r - i + 1, z[i\
    \ - l]);\n        while (i + z[i] < n and eq(s[z[i]], s[i + z[i]]))\n        \
    \    ++z[i];\n        if (i + z[i] - 1 > r)\n            l = i, r = i + z[i] -\
    \ 1;\n    }\n    return z;\n}\n} // namespace cplib\n\n#endif // CPLIB_Z_FUNCTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/z_function.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:46:07-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/z_function.hpp
layout: document
redirect_from:
- /library/cplib/string/z_function.hpp
- /library/cplib/string/z_function.hpp.html
title: cplib/string/z_function.hpp
---
