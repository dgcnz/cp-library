---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/math/pfint.hpp
    title: cplib/math/pfint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/misc.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\
    \ntemplate <class T>\nstruct minimum : binary_function<T, T, T>\n{\n    T operator()(const\
    \ T &x, const T &y) const { return std::min(x, y); }\n    template <class Compare>\n\
    \    T operator()(const T &x, const T &y, Compare comp) const\n    {\n       \
    \ return std::min(x, y, comp);\n    }\n};\n\ntemplate <class T>\nstruct maximum\
    \ : binary_function<T, T, T>\n{\n    T operator()(const T &x, const T &y) const\
    \ { return std::max(x, y); }\n    template <class Compare>\n    T operator()(const\
    \ T &x, const T &y, Compare comp) const\n    {\n        return std::max(x, y,\
    \ comp);\n    }\n};\n\ntemplate <typename T1, typename T2>\nvector<pair<T1, T2>>\
    \ map_union(vector<pair<T1, T2>> const &a,\n                               vector<pair<T1,\
    \ T2>> const &b)\n{\n    vector<pair<T1, T2>> ans;\n    ans.reserve(max(size(a),\
    \ size(b)));\n    int i = 0, j = 0;\n    while (i < (int)a.size() and j < (int)b.size())\n\
    \    {\n        if (a[i].first == b[j].first)\n        {\n            ans.emplace_back(a[i].first,\
    \ a[i].second + b[j].second);\n            i++, j++;\n        }\n        else\
    \ if (a[i].first < b[j].first)\n            ans.push_back(a[i++]);\n        else\n\
    \            ans.push_back(b[j++]);\n    }\n    while (i < (int)a.size())\n  \
    \      ans.push_back(a[i++]);\n\n    while (j < (int)b.size())\n        ans.push_back(b[j++]);\n\
    \    return ans;\n}\n\ntemplate <typename T1, typename T2>\nvector<pair<T1, T2>>\
    \ map_intersection(vector<pair<T1, T2>> const &a,\n                          \
    \            vector<pair<T1, T2>> const &b)\n{\n    vector<pair<T1, T2>> ans;\n\
    \    int                  i = 0, j = 0;\n    while (i < (int)a.size() and j <\
    \ (int)b.size())\n    {\n        if (a[i].first == b[j].first)\n        {\n  \
    \          ans.emplace_back(a[i].first, min(a[i].second, b[j].second));\n    \
    \        i++, j++;\n        }\n        else if (a[i].first < b[j].first)\n   \
    \         i++;\n        else\n            j++;\n    }\n    return ans;\n}\n} //\
    \ namespace cplib\n\n\n"
  code: "#ifndef CPLIB_UTILS_MISC_HPP\n#define CPLIB_UTILS_MISC_HPP\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct minimum : binary_function<T, T, T>\n{\n \
    \   T operator()(const T &x, const T &y) const { return std::min(x, y); }\n  \
    \  template <class Compare>\n    T operator()(const T &x, const T &y, Compare\
    \ comp) const\n    {\n        return std::min(x, y, comp);\n    }\n};\n\ntemplate\
    \ <class T>\nstruct maximum : binary_function<T, T, T>\n{\n    T operator()(const\
    \ T &x, const T &y) const { return std::max(x, y); }\n    template <class Compare>\n\
    \    T operator()(const T &x, const T &y, Compare comp) const\n    {\n       \
    \ return std::max(x, y, comp);\n    }\n};\n\ntemplate <typename T1, typename T2>\n\
    vector<pair<T1, T2>> map_union(vector<pair<T1, T2>> const &a,\n              \
    \                 vector<pair<T1, T2>> const &b)\n{\n    vector<pair<T1, T2>>\
    \ ans;\n    ans.reserve(max(size(a), size(b)));\n    int i = 0, j = 0;\n    while\
    \ (i < (int)a.size() and j < (int)b.size())\n    {\n        if (a[i].first ==\
    \ b[j].first)\n        {\n            ans.emplace_back(a[i].first, a[i].second\
    \ + b[j].second);\n            i++, j++;\n        }\n        else if (a[i].first\
    \ < b[j].first)\n            ans.push_back(a[i++]);\n        else\n          \
    \  ans.push_back(b[j++]);\n    }\n    while (i < (int)a.size())\n        ans.push_back(a[i++]);\n\
    \n    while (j < (int)b.size())\n        ans.push_back(b[j++]);\n    return ans;\n\
    }\n\ntemplate <typename T1, typename T2>\nvector<pair<T1, T2>> map_intersection(vector<pair<T1,\
    \ T2>> const &a,\n                                      vector<pair<T1, T2>> const\
    \ &b)\n{\n    vector<pair<T1, T2>> ans;\n    int                  i = 0, j = 0;\n\
    \    while (i < (int)a.size() and j < (int)b.size())\n    {\n        if (a[i].first\
    \ == b[j].first)\n        {\n            ans.emplace_back(a[i].first, min(a[i].second,\
    \ b[j].second));\n            i++, j++;\n        }\n        else if (a[i].first\
    \ < b[j].first)\n            i++;\n        else\n            j++;\n    }\n   \
    \ return ans;\n}\n} // namespace cplib\n\n#endif // CPLIB_UTILS_MISC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/misc.hpp
  requiredBy:
  - cplib/math/pfint.hpp
  timestamp: '2021-08-26 21:23:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/misc.hpp
layout: document
redirect_from:
- /library/cplib/utils/misc.hpp
- /library/cplib/utils/misc.hpp.html
title: cplib/utils/misc.hpp
---
