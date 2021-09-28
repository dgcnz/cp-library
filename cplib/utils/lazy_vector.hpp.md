---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: cplib/utils/lazy_state.hpp
    title: cplib/utils/lazy_state.hpp
  - icon: ':warning:'
    path: cplib/utils/lazy_vector_iterator.hpp
    title: cplib/utils/lazy_vector_iterator.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cplib/utils/lazy_vector_iterator.hpp
    title: cplib/utils/lazy_vector_iterator.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cplib/utils/lazy_vector.hpp\"\n\n\n\n#include <cplib/utils/lazy_state>\n\
    #include <cplib/utils/lazy_vector_iterator>\n#include <exception>\n#include <iterator>\n\
    #include <stdexcept>\n#include <type_traits>\n#include <vector>\n\nnamespace cplib\n\
    {\nusing namespace std;\n\ntemplate <class S, typename T>\nstruct lazy_vector_iterator;\n\
    \nusing namespace std;\n\ntemplate <class S, typename T>\nstruct lazy_vector\n\
    {\n    using self     = lazy_vector<S, T>;\n    using iterator = lazy_vector_iterator<S,\
    \ T>;\n    vector<T> v;\n\n  private:\n    S state;\n\n  public:\n    lazy_vector(S\
    \ _state, int len = 0) : state(_state)\n    {\n        if (len)\n            v.reserve(len);\n\
    \        state.init();\n        if (!state.terminated())\n            v.push_back(state.value());\n\
    \    }\n    T operator[](int i)\n    {\n        cache(i);\n        if (i >= (int)v.size())\n\
    \            throw std::out_of_range(\"Out of bounds in lazy_vector\");\n    \
    \    return v[i];\n    }\n    void cache(int i)\n    {\n        if (i >= (int)v.size())\n\
    \        {\n            if (state.terminated())\n                return;\n   \
    \         while (i >= (int)v.size())\n            {\n                state.next();\n\
    \                if (state.terminated())\n                    return;\n      \
    \          v.push_back(state.value());\n            }\n        }\n    }\n    bool\
    \ cached() const { return state.terminated(); }\n    void cache_next() { cache(v.size());\
    \ }\n    void cache_all()\n    {\n        while (!state.terminated())\n      \
    \      cache_next();\n    }\n\n    size_t size()\n    {\n        if (not cached())\n\
    \            cache_all();\n        return v.size();\n    }\n\n    size_t   cached_size()\
    \ { return v.size(); }\n    iterator begin() { return iterator(*this, 0, state.terminated());\
    \ }\n    iterator end() { return iterator(*this, -1, true); }\n};\n} // namespace\
    \ cplib\n\n\n"
  code: "#ifndef CPLIB_LAZY_VECTOR_HPP\n#define CPLIB_LAZY_VECTOR_HPP\n\n#include\
    \ <cplib/utils/lazy_state>\n#include <cplib/utils/lazy_vector_iterator>\n#include\
    \ <exception>\n#include <iterator>\n#include <stdexcept>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace cplib\n{\nusing namespace std;\n\ntemplate <class\
    \ S, typename T>\nstruct lazy_vector_iterator;\n\nusing namespace std;\n\ntemplate\
    \ <class S, typename T>\nstruct lazy_vector\n{\n    using self     = lazy_vector<S,\
    \ T>;\n    using iterator = lazy_vector_iterator<S, T>;\n    vector<T> v;\n\n\
    \  private:\n    S state;\n\n  public:\n    lazy_vector(S _state, int len = 0)\
    \ : state(_state)\n    {\n        if (len)\n            v.reserve(len);\n    \
    \    state.init();\n        if (!state.terminated())\n            v.push_back(state.value());\n\
    \    }\n    T operator[](int i)\n    {\n        cache(i);\n        if (i >= (int)v.size())\n\
    \            throw std::out_of_range(\"Out of bounds in lazy_vector\");\n    \
    \    return v[i];\n    }\n    void cache(int i)\n    {\n        if (i >= (int)v.size())\n\
    \        {\n            if (state.terminated())\n                return;\n   \
    \         while (i >= (int)v.size())\n            {\n                state.next();\n\
    \                if (state.terminated())\n                    return;\n      \
    \          v.push_back(state.value());\n            }\n        }\n    }\n    bool\
    \ cached() const { return state.terminated(); }\n    void cache_next() { cache(v.size());\
    \ }\n    void cache_all()\n    {\n        while (!state.terminated())\n      \
    \      cache_next();\n    }\n\n    size_t size()\n    {\n        if (not cached())\n\
    \            cache_all();\n        return v.size();\n    }\n\n    size_t   cached_size()\
    \ { return v.size(); }\n    iterator begin() { return iterator(*this, 0, state.terminated());\
    \ }\n    iterator end() { return iterator(*this, -1, true); }\n};\n} // namespace\
    \ cplib\n\n#endif // CPLIB_LAZY_VECTOR_HPP\n"
  dependsOn:
  - cplib/utils/lazy_state.hpp
  - cplib/utils/lazy_vector_iterator.hpp
  isVerificationFile: false
  path: cplib/utils/lazy_vector.hpp
  requiredBy:
  - cplib/utils/lazy_vector_iterator.hpp
  timestamp: '2021-06-24 17:56:08-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/lazy_vector.hpp
layout: document
redirect_from:
- /library/cplib/utils/lazy_vector.hpp
- /library/cplib/utils/lazy_vector.hpp.html
title: cplib/utils/lazy_vector.hpp
---
