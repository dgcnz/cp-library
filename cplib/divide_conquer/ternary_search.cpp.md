---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/divide_conquer/ternary_search.cpp\"\n#include <algorithm>\n\
    #include <functional>\n\nusing namespace std;\nusing predicate     = function<bool(int)>;\n\
    using cost_function = function<int(int)>;\n\n// last true in [true, true,... true,\
    \ false, ... false]\nint binary_search(int lo, int hi, predicate p)\n{\n    while\
    \ (lo < hi)\n    {\n        int mid = lo + (hi - lo + 1) / 2;\n        if (p(mid)\
    \ == false)\n            hi = mid - 1;\n        else\n            lo = mid;\n\
    \    }\n    if (p(lo) == false)\n        return -1; // p(x) is false for all x\n\
    \    return lo;\n}\n\nint ternary_search(int lo, int hi, cost_function f)\n{\n\
    \    while (hi - lo > 1)\n    {\n        int mid = (hi + lo) >> 1;\n        if\
    \ (f(mid) > f(mid + 1))\n            hi = mid;\n        else\n            lo =\
    \ mid;\n    }\n    return lo;\n}\n"
  code: "#include <algorithm>\n#include <functional>\n\nusing namespace std;\nusing\
    \ predicate     = function<bool(int)>;\nusing cost_function = function<int(int)>;\n\
    \n// last true in [true, true,... true, false, ... false]\nint binary_search(int\
    \ lo, int hi, predicate p)\n{\n    while (lo < hi)\n    {\n        int mid = lo\
    \ + (hi - lo + 1) / 2;\n        if (p(mid) == false)\n            hi = mid - 1;\n\
    \        else\n            lo = mid;\n    }\n    if (p(lo) == false)\n       \
    \ return -1; // p(x) is false for all x\n    return lo;\n}\n\nint ternary_search(int\
    \ lo, int hi, cost_function f)\n{\n    while (hi - lo > 1)\n    {\n        int\
    \ mid = (hi + lo) >> 1;\n        if (f(mid) > f(mid + 1))\n            hi = mid;\n\
    \        else\n            lo = mid;\n    }\n    return lo;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/divide_conquer/ternary_search.cpp
  requiredBy: []
  timestamp: '2021-01-16 15:57:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/divide_conquer/ternary_search.cpp
layout: document
redirect_from:
- /library/cplib/divide_conquer/ternary_search.cpp
- /library/cplib/divide_conquer/ternary_search.cpp.html
title: cplib/divide_conquer/ternary_search.cpp
---
