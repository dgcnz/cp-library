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
  bundledCode: "#line 1 \"cplib/dp/subset_sum.hpp\"\n\n\n\n#include <vector>\nnamespace\
    \ cplib\n{\nusing namespace std;\nstruct SubsetSum\n{\n    vector<int> const &a;\n\
    \    long long const    target;\n\n    vector<vector<bool>> dp;\n    SubsetSum(const\
    \ vector<int> &a, long long target) : a(a), target(target) {}\n    bool solve(void)\n\
    \    {\n        int n = a.size();\n        dp    = vector<vector<bool>>(n + 1,\
    \ vector<bool>(target + 1));\n        for (int i = 0; i <= n; ++i)\n         \
    \   dp[i][0] = true;\n\n        for (int i = 1; i <= n; ++i)\n        {\n    \
    \        for (int x = 1; x <= target; ++x)\n            {\n                dp[i][x]\
    \ = dp[i - 1][x];\n                if (x >= a[i - 1])\n                    dp[i][x]\
    \ = dp[i][x] || dp[i - 1][x - a[i - 1]];\n            }\n        }\n        return\
    \ dp[n][target];\n    }\n};\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_SUBSET_SUM_HPP\n#define CPLIB_SUBSET_SUM_HPP\n\n#include <vector>\n\
    namespace cplib\n{\nusing namespace std;\nstruct SubsetSum\n{\n    vector<int>\
    \ const &a;\n    long long const    target;\n\n    vector<vector<bool>> dp;\n\
    \    SubsetSum(const vector<int> &a, long long target) : a(a), target(target)\
    \ {}\n    bool solve(void)\n    {\n        int n = a.size();\n        dp    =\
    \ vector<vector<bool>>(n + 1, vector<bool>(target + 1));\n        for (int i =\
    \ 0; i <= n; ++i)\n            dp[i][0] = true;\n\n        for (int i = 1; i <=\
    \ n; ++i)\n        {\n            for (int x = 1; x <= target; ++x)\n        \
    \    {\n                dp[i][x] = dp[i - 1][x];\n                if (x >= a[i\
    \ - 1])\n                    dp[i][x] = dp[i][x] || dp[i - 1][x - a[i - 1]];\n\
    \            }\n        }\n        return dp[n][target];\n    }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_SUBSET_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/dp/subset_sum.hpp
  requiredBy: []
  timestamp: '2021-06-22 17:00:12-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/dp/subset_sum.hpp
layout: document
redirect_from:
- /library/cplib/dp/subset_sum.hpp
- /library/cplib/dp/subset_sum.hpp.html
title: cplib/dp/subset_sum.hpp
---
