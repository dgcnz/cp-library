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
    \ <cassert>\n#include <functional>\n#include <map>\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <class T>\n\
    struct minimum : binary_function<T, T, T>\n{\n    T operator()(const T &x, const\
    \ T &y) const { return std::min(x, y); }\n    template <class Compare>\n    T\
    \ operator()(const T &x, const T &y, Compare comp) const\n    {\n        return\
    \ std::min(x, y, comp);\n    }\n};\n\ntemplate <class T>\nstruct maximum : binary_function<T,\
    \ T, T>\n{\n    T operator()(const T &x, const T &y) const { return std::max(x,\
    \ y); }\n    template <class Compare>\n    T operator()(const T &x, const T &y,\
    \ Compare comp) const\n    {\n        return std::max(x, y, comp);\n    }\n};\n\
    \ntemplate <typename T1, typename T2>\nvector<pair<T1, T2>> map_union(vector<pair<T1,\
    \ T2>> const &a,\n                               vector<pair<T1, T2>> const &b)\n\
    {\n    vector<pair<T1, T2>> ans;\n    ans.reserve(max(size(a), size(b)));\n  \
    \  int i = 0, j = 0;\n    while (i < (int)a.size() and j < (int)b.size())\n  \
    \  {\n        if (a[i].first == b[j].first)\n        {\n            ans.emplace_back(a[i].first,\
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
    \         i++;\n        else\n            j++;\n    }\n    return ans;\n}\n\n\
    template <typename T>\nlong long count_inversions(vector<T> const &a)\n{\n   \
    \ int       n   = a.size();\n    long long ans = 0;\n    for (int i = 1; i < n;\
    \ ++i)\n        for (int j = 0; j < i; ++j)\n            ans += a[i] < a[j];\n\
    \    return ans;\n}\n\nlong long permutation_sign(vector<int> const &sigma)\n\
    {\n    return count_inversions(sigma) & 1LL ? -1 : +1;\n}\n\ntemplate <typename\
    \ InputIt,\n          typename T    = typename iterator_traits<InputIt>::value_type,\n\
    \          class Compare = std::less<T>>\nvector<int> argsort(InputIt first, InputIt\
    \ last, Compare cmp = std::less<T>())\n{\n    vector<int> indices(distance(first,\
    \ last));\n    std::iota(indices.begin(), indices.end(), 0);\n    std::sort(indices.begin(),\n\
    \              indices.end(),\n              [&](int i, int j) { return cmp(*(first\
    \ + i), *(first + j)); });\n    return indices;\n}\n\ntemplate <typename InputIt,\n\
    \          typename T    = typename iterator_traits<InputIt>::value_type,\n  \
    \        class Compare = std::less<T>>\nvector<int>\nstable_argsort(InputIt first,\
    \ InputIt last, Compare cmp = std::less<T>())\n{\n    vector<int> indices(distance(first,\
    \ last));\n    std::iota(indices.begin(), indices.end(), 0);\n    std::sort(indices.begin(),\n\
    \              indices.end(),\n              [&](int i, int j)\n             \
    \ {\n                  T a = *(first + i), b = *(first + j);\n               \
    \   if (!cmp(a, b) and !cmp(b, a)) // equal\n                      return i <\
    \ j;\n                  return cmp(a, b);\n              });\n    return indices;\n\
    }\n\ntemplate <typename InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    vector<T>\napply_permutation(InputIt first, InputIt last, vector<int> const &sigma)\n\
    {\n    // TODO: deal with strings\n    int n = distance(first, last);\n    assert(n\
    \ == (int)sigma.size());\n    vector<T> a_sigma(n);\n    for (int i = 0; i < n;\
    \ ++i)\n        a_sigma[i] = *(first + sigma[i]);\n    return a_sigma;\n}\n\n\
    vector<int> inverse_permutation(vector<int> const &sigma)\n{\n    int        \
    \ n = sigma.size();\n    vector<int> inv(n);\n    for (int i = 0; i < n; ++i)\n\
    \        inv[sigma[i]] = i;\n    return inv;\n}\n\ntemplate <typename T>\nmap<T,\
    \ int> compress(vector<T> values)\n{\n    map<T, int> mp;\n    int         cnt\
    \ = 0;\n    for (auto v : values)\n        mp[v];\n    for (auto &[k, v] : mp)\n\
    \        v = cnt++;\n    return mp;\n}\n\ntemplate <typename T>\nvector<T> apply_map(vector<T>\
    \ values, map<T, T> m)\n{\n    for (auto &x : values)\n        x = m[x];\n   \
    \ return values;\n}\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_UTILS_MISC_HPP\n#define CPLIB_UTILS_MISC_HPP\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <map>\n#include <numeric>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <class\
    \ T>\nstruct minimum : binary_function<T, T, T>\n{\n    T operator()(const T &x,\
    \ const T &y) const { return std::min(x, y); }\n    template <class Compare>\n\
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
    \         i++;\n        else\n            j++;\n    }\n    return ans;\n}\n\n\
    template <typename T>\nlong long count_inversions(vector<T> const &a)\n{\n   \
    \ int       n   = a.size();\n    long long ans = 0;\n    for (int i = 1; i < n;\
    \ ++i)\n        for (int j = 0; j < i; ++j)\n            ans += a[i] < a[j];\n\
    \    return ans;\n}\n\nlong long permutation_sign(vector<int> const &sigma)\n\
    {\n    return count_inversions(sigma) & 1LL ? -1 : +1;\n}\n\ntemplate <typename\
    \ InputIt,\n          typename T    = typename iterator_traits<InputIt>::value_type,\n\
    \          class Compare = std::less<T>>\nvector<int> argsort(InputIt first, InputIt\
    \ last, Compare cmp = std::less<T>())\n{\n    vector<int> indices(distance(first,\
    \ last));\n    std::iota(indices.begin(), indices.end(), 0);\n    std::sort(indices.begin(),\n\
    \              indices.end(),\n              [&](int i, int j) { return cmp(*(first\
    \ + i), *(first + j)); });\n    return indices;\n}\n\ntemplate <typename InputIt,\n\
    \          typename T    = typename iterator_traits<InputIt>::value_type,\n  \
    \        class Compare = std::less<T>>\nvector<int>\nstable_argsort(InputIt first,\
    \ InputIt last, Compare cmp = std::less<T>())\n{\n    vector<int> indices(distance(first,\
    \ last));\n    std::iota(indices.begin(), indices.end(), 0);\n    std::sort(indices.begin(),\n\
    \              indices.end(),\n              [&](int i, int j)\n             \
    \ {\n                  T a = *(first + i), b = *(first + j);\n               \
    \   if (!cmp(a, b) and !cmp(b, a)) // equal\n                      return i <\
    \ j;\n                  return cmp(a, b);\n              });\n    return indices;\n\
    }\n\ntemplate <typename InputIt,\n          typename T = typename iterator_traits<InputIt>::value_type>\n\
    vector<T>\napply_permutation(InputIt first, InputIt last, vector<int> const &sigma)\n\
    {\n    // TODO: deal with strings\n    int n = distance(first, last);\n    assert(n\
    \ == (int)sigma.size());\n    vector<T> a_sigma(n);\n    for (int i = 0; i < n;\
    \ ++i)\n        a_sigma[i] = *(first + sigma[i]);\n    return a_sigma;\n}\n\n\
    vector<int> inverse_permutation(vector<int> const &sigma)\n{\n    int        \
    \ n = sigma.size();\n    vector<int> inv(n);\n    for (int i = 0; i < n; ++i)\n\
    \        inv[sigma[i]] = i;\n    return inv;\n}\n\ntemplate <typename T>\nmap<T,\
    \ int> compress(vector<T> values)\n{\n    map<T, int> mp;\n    int         cnt\
    \ = 0;\n    for (auto v : values)\n        mp[v];\n    for (auto &[k, v] : mp)\n\
    \        v = cnt++;\n    return mp;\n}\n\ntemplate <typename T>\nvector<T> apply_map(vector<T>\
    \ values, map<T, T> m)\n{\n    for (auto &x : values)\n        x = m[x];\n   \
    \ return values;\n}\n\n} // namespace cplib\n\n#endif // CPLIB_UTILS_MISC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/misc.hpp
  requiredBy:
  - cplib/math/pfint.hpp
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/misc.hpp
layout: document
redirect_from:
- /library/cplib/utils/misc.hpp
- /library/cplib/utils/misc.hpp.html
title: cplib/utils/misc.hpp
---
