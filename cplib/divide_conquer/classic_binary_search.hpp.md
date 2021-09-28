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
  bundledCode: "#line 1 \"cplib/divide_conquer/classic_binary_search.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <functional>\n\ntemplate <typename\
    \ T>\nT binary_search(T lo, T hi, std::function<bool(T)> p)\n{\n    assert(lo\
    \ <= hi);\n    while (lo < hi)\n    {\n        T mid = lo + (hi - lo) / 2;\n \
    \       if (p(mid))\n            hi = mid;\n        else\n            lo = mid\
    \ + 1;\n    }\n    if (p(lo) == false)\n        return -1; // p(x) is false for\
    \ all x\n    return lo;\n}\n\n\n"
  code: "#ifndef CPLIB_BINARY_SEARCH_HPP\n#define CPLIB_BINARY_SEARCH_HPP\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n\ntemplate <typename\
    \ T>\nT binary_search(T lo, T hi, std::function<bool(T)> p)\n{\n    assert(lo\
    \ <= hi);\n    while (lo < hi)\n    {\n        T mid = lo + (hi - lo) / 2;\n \
    \       if (p(mid))\n            hi = mid;\n        else\n            lo = mid\
    \ + 1;\n    }\n    if (p(lo) == false)\n        return -1; // p(x) is false for\
    \ all x\n    return lo;\n}\n\n#endif // CPLIB_BINARY_SEARCH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/divide_conquer/classic_binary_search.hpp
  requiredBy: []
  timestamp: '2021-04-22 18:17:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/divide_conquer/classic_binary_search.hpp
layout: document
redirect_from:
- /library/cplib/divide_conquer/classic_binary_search.hpp
- /library/cplib/divide_conquer/classic_binary_search.hpp.html
title: cplib/divide_conquer/classic_binary_search.hpp
---
