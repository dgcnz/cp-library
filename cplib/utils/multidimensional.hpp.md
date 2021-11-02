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
  bundledCode: "#line 1 \"cplib/utils/multidimensional.hpp\"\n\n\n#include <algorithm>\n\
    #include <array>\n#include <iostream>\n#include <iterator>\n#include <numeric>\n\
    #include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename T, size_t dims>\n\
    struct multidimensional_vector\n{\n    typedef std::vector<typename multidimensional_vector<T,\
    \ dims - 1>::type>\n        type;\n};\n\ntemplate <typename T>\nstruct multidimensional_vector<T,\
    \ 0>\n{\n    typedef T type;\n};\n\ntemplate <class... Args>\nauto create_multidimensional(size_t\
    \ n, Args &&...args)\n{\n    if constexpr (sizeof...(args) == 1)\n        return\
    \ std::vector(n, args...);\n    else\n        return std::vector(n, create_multidimensional(args...));\n\
    }\n\ntemplate <typename T, size_t N, class... Args>\nvoid resize(typename multidimensional_vector<T,\
    \ N>::type &v,\n            size_t                                        n,\n\
    \            Args &&...args)\n{\n    v.resize(n);\n    if constexpr (sizeof...(args)\
    \ > 0)\n        for (auto &x : v)\n            resize<T, N - 1>(x, args...);\n\
    }\n\ntemplate <typename T, size_t N, class... Args>\nvoid assign(typename multidimensional_vector<T,\
    \ N>::type &v,\n            T                                             val,\n\
    \            size_t                                        n,\n            Args\
    \ &&...args)\n{\n    if constexpr (sizeof...(args) > 0)\n    {\n        v.resize(n);\n\
    \        for (auto &x : v)\n            assign<T, N - 1>(x, val, args...);\n \
    \   }\n    else\n        v.assign(n, val);\n}\n\ntemplate <typename T, size_t\
    \ N, typename InputIterator>\nvoid fill(InputIterator first, InputIterator last,\
    \ T val)\n{\n    if constexpr (N > 1)\n        for (; first != last; ++first)\n\
    \            fill<T, N - 1>(begin(*first), end(*first), val);\n    else\n    \
    \    fill(first, last, val);\n}\n\ntemplate <size_t N, typename InputIterator,\
    \ typename UnaryFunction>\nvoid for_each(InputIterator first, InputIterator last,\
    \ UnaryFunction f)\n{\n    if constexpr (N > 1)\n        for (; first != last;\
    \ ++first)\n            for_each<N - 1>(std::begin(*first), std::end(*first),\
    \ f);\n    else\n        std::for_each(first, last, f);\n}\n\ntemplate <size_t\
    \ N,\n          typename InputIterator,\n          typename T,\n          typename\
    \ BinaryOperation>\nT accumulate(InputIterator   first,\n             InputIterator\
    \   last,\n             T               init,\n             BinaryOperation op)\n\
    {\n    if constexpr (N > 1)\n        for (; first != last; ++first)\n        \
    \    init = accumulate<N - 1>(\n                std::begin(*first), std::end(*first),\
    \ init, op);\n    else\n        init = std::accumulate(first, last, init, op);\n\
    \    return init;\n}\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_MULTIDIMENSIONAL_HPP\n#define CPLIB_MULTIDIMENSIONAL_HPP\n\
    #include <algorithm>\n#include <array>\n#include <iostream>\n#include <iterator>\n\
    #include <numeric>\n#include <vector>\n\nnamespace cplib\n{\n\ntemplate <typename\
    \ T, size_t dims>\nstruct multidimensional_vector\n{\n    typedef std::vector<typename\
    \ multidimensional_vector<T, dims - 1>::type>\n        type;\n};\n\ntemplate <typename\
    \ T>\nstruct multidimensional_vector<T, 0>\n{\n    typedef T type;\n};\n\ntemplate\
    \ <class... Args>\nauto create_multidimensional(size_t n, Args &&...args)\n{\n\
    \    if constexpr (sizeof...(args) == 1)\n        return std::vector(n, args...);\n\
    \    else\n        return std::vector(n, create_multidimensional(args...));\n\
    }\n\ntemplate <typename T, size_t N, class... Args>\nvoid resize(typename multidimensional_vector<T,\
    \ N>::type &v,\n            size_t                                        n,\n\
    \            Args &&...args)\n{\n    v.resize(n);\n    if constexpr (sizeof...(args)\
    \ > 0)\n        for (auto &x : v)\n            resize<T, N - 1>(x, args...);\n\
    }\n\ntemplate <typename T, size_t N, class... Args>\nvoid assign(typename multidimensional_vector<T,\
    \ N>::type &v,\n            T                                             val,\n\
    \            size_t                                        n,\n            Args\
    \ &&...args)\n{\n    if constexpr (sizeof...(args) > 0)\n    {\n        v.resize(n);\n\
    \        for (auto &x : v)\n            assign<T, N - 1>(x, val, args...);\n \
    \   }\n    else\n        v.assign(n, val);\n}\n\ntemplate <typename T, size_t\
    \ N, typename InputIterator>\nvoid fill(InputIterator first, InputIterator last,\
    \ T val)\n{\n    if constexpr (N > 1)\n        for (; first != last; ++first)\n\
    \            fill<T, N - 1>(begin(*first), end(*first), val);\n    else\n    \
    \    fill(first, last, val);\n}\n\ntemplate <size_t N, typename InputIterator,\
    \ typename UnaryFunction>\nvoid for_each(InputIterator first, InputIterator last,\
    \ UnaryFunction f)\n{\n    if constexpr (N > 1)\n        for (; first != last;\
    \ ++first)\n            for_each<N - 1>(std::begin(*first), std::end(*first),\
    \ f);\n    else\n        std::for_each(first, last, f);\n}\n\ntemplate <size_t\
    \ N,\n          typename InputIterator,\n          typename T,\n          typename\
    \ BinaryOperation>\nT accumulate(InputIterator   first,\n             InputIterator\
    \   last,\n             T               init,\n             BinaryOperation op)\n\
    {\n    if constexpr (N > 1)\n        for (; first != last; ++first)\n        \
    \    init = accumulate<N - 1>(\n                std::begin(*first), std::end(*first),\
    \ init, op);\n    else\n        init = std::accumulate(first, last, init, op);\n\
    \    return init;\n}\n} // namespace cplib\n\n#endif // CPLIB_MULTIDIMENSIONAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/multidimensional.hpp
  requiredBy: []
  timestamp: '2021-11-02 13:44:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/multidimensional.hpp
layout: document
redirect_from:
- /library/cplib/utils/multidimensional.hpp
- /library/cplib/utils/multidimensional.hpp.html
title: cplib/utils/multidimensional.hpp
---
