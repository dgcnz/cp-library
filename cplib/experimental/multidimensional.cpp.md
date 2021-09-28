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
  bundledCode: "#line 1 \"cplib/experimental/multidimensional.cpp\"\n#include <algorithm>\n\
    #include <array>\n#include <dbg.h>\n#include <iostream>\n#include <iterator>\n\
    #include <numeric>\n#include <vector>\n\ntemplate <typename T, size_t dims>\n\
    struct multidimensional_vector\n{\n    typedef std::vector<typename multidimensional_vector<T,\
    \ dims - 1>::type>\n        type;\n};\n\ntemplate <typename T>\nstruct multidimensional_vector<T,\
    \ 0>\n{\n    typedef T type;\n};\n\ntemplate <class... Args>\nauto create(size_t\
    \ n, Args &&...args)\n{\n    if constexpr (sizeof...(args) == 1)\n        return\
    \ std::vector(n, args...);\n    else\n        return std::vector(n, create(args...));\n\
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
    \    return init;\n}\n\nint main(void)\n{\n    using namespace std;\n    multidimensional_vector<int,\
    \ 3>::type v;\n\n    resize<int, 3>(v, 2, 2, 2);\n    fill<int, 3>(begin(v), end(v),\
    \ 3);\n    // or instead: assign<int, 2>(v, 3, 3, 2)\n\n    // Results in 3 x\
    \ 2 vector filled with 3's:\n    // 3 3\n    // 3 3\n    // 3 3\n\n    // for_each<2>(begin(v),\
    \ end(v), [](int x) { cout << x << \" \"; }),\n    //     cout << endl;\n    //\
    \ 3 3 3 3 3 3\n\n    cout << accumulate<3>(begin(v), end(v), 0, plus<int>()) <<\
    \ endl;\n    // 6\n\n    return 0;\n}\n"
  code: "#include <algorithm>\n#include <array>\n#include <dbg.h>\n#include <iostream>\n\
    #include <iterator>\n#include <numeric>\n#include <vector>\n\ntemplate <typename\
    \ T, size_t dims>\nstruct multidimensional_vector\n{\n    typedef std::vector<typename\
    \ multidimensional_vector<T, dims - 1>::type>\n        type;\n};\n\ntemplate <typename\
    \ T>\nstruct multidimensional_vector<T, 0>\n{\n    typedef T type;\n};\n\ntemplate\
    \ <class... Args>\nauto create(size_t n, Args &&...args)\n{\n    if constexpr\
    \ (sizeof...(args) == 1)\n        return std::vector(n, args...);\n    else\n\
    \        return std::vector(n, create(args...));\n}\n\ntemplate <typename T, size_t\
    \ N, class... Args>\nvoid resize(typename multidimensional_vector<T, N>::type\
    \ &v,\n            size_t                                        n,\n        \
    \    Args &&...args)\n{\n    v.resize(n);\n    if constexpr (sizeof...(args) >\
    \ 0)\n        for (auto &x : v)\n            resize<T, N - 1>(x, args...);\n}\n\
    \ntemplate <typename T, size_t N, class... Args>\nvoid assign(typename multidimensional_vector<T,\
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
    \    return init;\n}\n\nint main(void)\n{\n    using namespace std;\n    multidimensional_vector<int,\
    \ 3>::type v;\n\n    resize<int, 3>(v, 2, 2, 2);\n    fill<int, 3>(begin(v), end(v),\
    \ 3);\n    // or instead: assign<int, 2>(v, 3, 3, 2)\n\n    // Results in 3 x\
    \ 2 vector filled with 3's:\n    // 3 3\n    // 3 3\n    // 3 3\n\n    // for_each<2>(begin(v),\
    \ end(v), [](int x) { cout << x << \" \"; }),\n    //     cout << endl;\n    //\
    \ 3 3 3 3 3 3\n\n    cout << accumulate<3>(begin(v), end(v), 0, plus<int>()) <<\
    \ endl;\n    // 6\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/experimental/multidimensional.cpp
  requiredBy: []
  timestamp: '2021-01-16 15:57:17-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/experimental/multidimensional.cpp
layout: document
redirect_from:
- /library/cplib/experimental/multidimensional.cpp
- /library/cplib/experimental/multidimensional.cpp.html
title: cplib/experimental/multidimensional.cpp
---
