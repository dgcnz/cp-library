---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Checks if vector is a palindromic sequence
    links: []
  bundledCode: "#line 1 \"cplib/string/utils.hpp\"\n\n\n\n#include <string>\n#include\
    \ <vector>\n\nnamespace cplib\n{\nusing namespace std;\nnamespace bounded_lexicographical\n\
    {\nstruct compare\n{\n    bool operator()(string a, string b) const\n    {\n \
    \       if (a.size() == b.size())\n            return a < b;\n        return a.size()\
    \ < b.size();\n    }\n};\nstring next(string s)\n{\n    if (s == \"\")\n     \
    \   return \"a\";\n    int i = s.size() - 1;\n    while (s[i] == 'z' && i >= 0)\n\
    \        s[i--] = 'a';\n    if (i == -1)\n        s.push_back('a');\n    else\n\
    \        s[i]++;\n    return s;\n}\n}; // namespace bounded_lexicographical\n\n\
    namespace lexicographical\n{\nstruct compare\n{\n    bool operator()(string a,\
    \ string b) const { return a < b; }\n};\nstring next(string s)\n{\n    if (s ==\
    \ \"\")\n        return \"a\";\n    int i = s.size() - 1;\n    while (s[i] ==\
    \ 'z' && i >= 0)\n        i--;\n    if (i == -1)\n        s.push_back('a');\n\
    \    else\n        s[i]++;\n\n    return s;\n}\n}; // namespace lexicographical\n\
    \n/*\n * @brief Checks if vector is a palindromic sequence\n * @param a vector\
    \ to be checked for\n */\ntemplate <typename T>\nbool is_palindrome(vector<T>\
    \ const &a)\n{\n    return a == vector<T>(a.rbegin(), a.rend());\n}\n\n/*\n *\
    \ @brief Checks if string is a palindromic sequence\n * @param a string to be\
    \ checked for\n */\nbool is_palindrome(string const &a)\n{\n    return a == string(a.rbegin(),\
    \ a.rend());\n}\n\n}; // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_STRING_UTILS_HPP\n#define CPLIB_STRING_UTILS_HPP\n\n#include\
    \ <string>\n#include <vector>\n\nnamespace cplib\n{\nusing namespace std;\nnamespace\
    \ bounded_lexicographical\n{\nstruct compare\n{\n    bool operator()(string a,\
    \ string b) const\n    {\n        if (a.size() == b.size())\n            return\
    \ a < b;\n        return a.size() < b.size();\n    }\n};\nstring next(string s)\n\
    {\n    if (s == \"\")\n        return \"a\";\n    int i = s.size() - 1;\n    while\
    \ (s[i] == 'z' && i >= 0)\n        s[i--] = 'a';\n    if (i == -1)\n        s.push_back('a');\n\
    \    else\n        s[i]++;\n    return s;\n}\n}; // namespace bounded_lexicographical\n\
    \nnamespace lexicographical\n{\nstruct compare\n{\n    bool operator()(string\
    \ a, string b) const { return a < b; }\n};\nstring next(string s)\n{\n    if (s\
    \ == \"\")\n        return \"a\";\n    int i = s.size() - 1;\n    while (s[i]\
    \ == 'z' && i >= 0)\n        i--;\n    if (i == -1)\n        s.push_back('a');\n\
    \    else\n        s[i]++;\n\n    return s;\n}\n}; // namespace lexicographical\n\
    \n/*\n * @brief Checks if vector is a palindromic sequence\n * @param a vector\
    \ to be checked for\n */\ntemplate <typename T>\nbool is_palindrome(vector<T>\
    \ const &a)\n{\n    return a == vector<T>(a.rbegin(), a.rend());\n}\n\n/*\n *\
    \ @brief Checks if string is a palindromic sequence\n * @param a string to be\
    \ checked for\n */\nbool is_palindrome(string const &a)\n{\n    return a == string(a.rbegin(),\
    \ a.rend());\n}\n\n}; // namespace cplib\n\n#endif // CPLIB_STRING_UTILS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/string/utils.hpp
  requiredBy: []
  timestamp: '2022-01-02 13:06:06-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/string/utils.hpp
layout: document
redirect_from:
- /library/cplib/string/utils.hpp
- /library/cplib/string/utils.hpp.html
title: Checks if vector is a palindromic sequence
---
