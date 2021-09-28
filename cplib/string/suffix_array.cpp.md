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
  bundledCode: "#line 1 \"cplib/string/suffix_array.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n// p[i] : the index of the i'th substring --> s[i...2^k]\n\
    // c[i] : equivalence class of i'th substring\nvector<int> sort_cyclic_shifts(string\
    \ const &s)\n{\n    int       n        = s.size();\n    const int alphabet = 256;\n\
    \n    // counting sort\n    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);\n\
    \    for (int i = 0; i < n; i++) // counting the ocurrences of s[i]\n        cnt[s[i]]++;\n\
    \    for (int i = 1; i < alphabet; i++) // creating accumulated count\n      \
    \  cnt[i] += cnt[i - 1];\n    for (int i = 0; i < n; i++)\n        p[--cnt[s[i]]]\
    \ = i;\n    c[p[0]]     = 0;\n    int classes = 1;\n    for (int i = 1; i < n;\
    \ i++)\n    {\n        if (s[p[i]] != s[p[i - 1]])\n            classes++;\n \
    \       c[p[i]] = classes - 1;\n    }\n\n    // radix sort\n    vector<int> pn(n),\
    \ cn(n);\n    for (int h = 0; (1 << h) < n; ++h)\n    {\n        for (int i =\
    \ 0; i < n; i++)\n        {\n            pn[i] = p[i] - (1 << h);\n          \
    \  if (pn[i] < 0)\n                pn[i] += n;\n        }\n        fill(cnt.begin(),\
    \ cnt.begin() + classes, 0);\n        for (int i = 0; i < n; i++)\n          \
    \  cnt[c[pn[i]]]++;\n        for (int i = 1; i < classes; i++)\n            cnt[i]\
    \ += cnt[i - 1];\n        for (int i = n - 1; i >= 0; i--)\n            p[--cnt[c[pn[i]]]]\
    \ = pn[i];\n        cn[p[0]] = 0;\n        classes  = 1;\n        for (int i =\
    \ 1; i < n; i++)\n        {\n            pair<int, int> cur  = {c[p[i]], c[(p[i]\
    \ + (1 << h)) % n]};\n            pair<int, int> prev = {c[p[i - 1]], c[(p[i -\
    \ 1] + (1 << h)) % n]};\n            if (cur != prev)\n                ++classes;\n\
    \            cn[p[i]] = classes - 1;\n        }\n\n        c.swap(cn);\n    }\n\
    \    return p;\n}\n\nvector<int> suffix_array_construction(string s)\n{\n    s\
    \ += \"$\";\n    vector<int> sorted_shifts = sort_cyclic_shifts(s);\n    sorted_shifts.erase(sorted_shifts.begin());\n\
    \    return sorted_shifts;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n// p[i] : the index of\
    \ the i'th substring --> s[i...2^k]\n// c[i] : equivalence class of i'th substring\n\
    vector<int> sort_cyclic_shifts(string const &s)\n{\n    int       n        = s.size();\n\
    \    const int alphabet = 256;\n\n    // counting sort\n    vector<int> p(n),\
    \ c(n), cnt(max(alphabet, n), 0);\n    for (int i = 0; i < n; i++) // counting\
    \ the ocurrences of s[i]\n        cnt[s[i]]++;\n    for (int i = 1; i < alphabet;\
    \ i++) // creating accumulated count\n        cnt[i] += cnt[i - 1];\n    for (int\
    \ i = 0; i < n; i++)\n        p[--cnt[s[i]]] = i;\n    c[p[0]]     = 0;\n    int\
    \ classes = 1;\n    for (int i = 1; i < n; i++)\n    {\n        if (s[p[i]] !=\
    \ s[p[i - 1]])\n            classes++;\n        c[p[i]] = classes - 1;\n    }\n\
    \n    // radix sort\n    vector<int> pn(n), cn(n);\n    for (int h = 0; (1 <<\
    \ h) < n; ++h)\n    {\n        for (int i = 0; i < n; i++)\n        {\n      \
    \      pn[i] = p[i] - (1 << h);\n            if (pn[i] < 0)\n                pn[i]\
    \ += n;\n        }\n        fill(cnt.begin(), cnt.begin() + classes, 0);\n   \
    \     for (int i = 0; i < n; i++)\n            cnt[c[pn[i]]]++;\n        for (int\
    \ i = 1; i < classes; i++)\n            cnt[i] += cnt[i - 1];\n        for (int\
    \ i = n - 1; i >= 0; i--)\n            p[--cnt[c[pn[i]]]] = pn[i];\n        cn[p[0]]\
    \ = 0;\n        classes  = 1;\n        for (int i = 1; i < n; i++)\n        {\n\
    \            pair<int, int> cur  = {c[p[i]], c[(p[i] + (1 << h)) % n]};\n    \
    \        pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};\n\
    \            if (cur != prev)\n                ++classes;\n            cn[p[i]]\
    \ = classes - 1;\n        }\n\n        c.swap(cn);\n    }\n    return p;\n}\n\n\
    vector<int> suffix_array_construction(string s)\n{\n    s += \"$\";\n    vector<int>\
    \ sorted_shifts = sort_cyclic_shifts(s);\n    sorted_shifts.erase(sorted_shifts.begin());\n\
    \    return sorted_shifts;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/suffix_array.cpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/suffix_array.cpp
layout: document
redirect_from:
- /library/cplib/string/suffix_array.cpp
- /library/cplib/string/suffix_array.cpp.html
title: cplib/string/suffix_array.cpp
---
