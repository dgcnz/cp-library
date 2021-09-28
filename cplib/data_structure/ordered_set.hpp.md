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
  bundledCode: "#line 1 \"cplib/data_structure/ordered_set.hpp\"\n\n\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <iterator>\n#include <utility>\n\
    \nnamespace cplib\n{\nusing namespace std;\ntemplate <typename Key, class Compare\
    \ = std::less<Key>>\nstruct ordered_set\n{\n    using oset =\n        __gnu_pbds::tree<Key,\n\
    \                         __gnu_pbds::null_type,\n                         Compare,\n\
    \                         __gnu_pbds::rb_tree_tag,\n                         __gnu_pbds::tree_order_statistics_node_update>;\n\
    \    using oset_iterator = typename oset::iterator;\n\n    oset ord;\n    struct\
    \ iterator\n    {\n        using value_type        = Key;\n        using difference_type\
    \   = std::ptrdiff_t;\n        using reference         = Key &;\n        using\
    \ pointer           = Key *;\n        using iterator_category = std::random_access_iterator_tag;\n\
    \        oset_iterator it;\n        oset const &  ord;\n        iterator(oset_iterator\
    \ it, oset const &ord) : it(it), ord(ord) {}\n        Key       operator*() const\
    \ { return *it; };\n        iterator &operator++()\n        {\n            it++;\n\
    \            return *this;\n        }\n        difference_type operator-(iterator\
    \ const &other)\n        {\n            int r = it == ord.end() ? ord.size() :\
    \ ord.order_of_key(*it);\n            int l = other.it == ord.end() ? ord.size()\n\
    \                                          : ord.order_of_key(*other.it);\n  \
    \          return r - l;\n        }\n        bool operator==(iterator const &other)\
    \ const { return it == other.it; }\n        bool operator!=(iterator const &other)\
    \ const { return it != other.it; }\n    };\n\n    iterator lower_bound(Key key)\
    \ const\n    {\n        return iterator(ord.lower_bound(key), ord);\n    }\n\n\
    \    iterator upper_bound(Key key) const\n    {\n        return iterator(ord.upper_bound(key),\
    \ ord);\n    }\n    iterator begin() const { return iterator(ord.begin(), ord);\
    \ }\n    iterator end() const { return iterator(ord.end(), ord); }\n};\n\n} //\
    \ namespace cplib\n\n\n"
  code: "#ifndef CPLIB_ORDERED_SET_HPP\n#define CPLIB_ORDERED_SET_HPP\n\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n#include\
    \ <iterator>\n#include <utility>\n\nnamespace cplib\n{\nusing namespace std;\n\
    template <typename Key, class Compare = std::less<Key>>\nstruct ordered_set\n\
    {\n    using oset =\n        __gnu_pbds::tree<Key,\n                         __gnu_pbds::null_type,\n\
    \                         Compare,\n                         __gnu_pbds::rb_tree_tag,\n\
    \                         __gnu_pbds::tree_order_statistics_node_update>;\n  \
    \  using oset_iterator = typename oset::iterator;\n\n    oset ord;\n    struct\
    \ iterator\n    {\n        using value_type        = Key;\n        using difference_type\
    \   = std::ptrdiff_t;\n        using reference         = Key &;\n        using\
    \ pointer           = Key *;\n        using iterator_category = std::random_access_iterator_tag;\n\
    \        oset_iterator it;\n        oset const &  ord;\n        iterator(oset_iterator\
    \ it, oset const &ord) : it(it), ord(ord) {}\n        Key       operator*() const\
    \ { return *it; };\n        iterator &operator++()\n        {\n            it++;\n\
    \            return *this;\n        }\n        difference_type operator-(iterator\
    \ const &other)\n        {\n            int r = it == ord.end() ? ord.size() :\
    \ ord.order_of_key(*it);\n            int l = other.it == ord.end() ? ord.size()\n\
    \                                          : ord.order_of_key(*other.it);\n  \
    \          return r - l;\n        }\n        bool operator==(iterator const &other)\
    \ const { return it == other.it; }\n        bool operator!=(iterator const &other)\
    \ const { return it != other.it; }\n    };\n\n    iterator lower_bound(Key key)\
    \ const\n    {\n        return iterator(ord.lower_bound(key), ord);\n    }\n\n\
    \    iterator upper_bound(Key key) const\n    {\n        return iterator(ord.upper_bound(key),\
    \ ord);\n    }\n    iterator begin() const { return iterator(ord.begin(), ord);\
    \ }\n    iterator end() const { return iterator(ord.end(), ord); }\n};\n\n} //\
    \ namespace cplib\n\n#endif // CPLIB_ORDERED_SET_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/data_structure/ordered_set.hpp
  requiredBy: []
  timestamp: '2021-08-21 11:37:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/data_structure/ordered_set.hpp
layout: document
redirect_from:
- /library/cplib/data_structure/ordered_set.hpp
- /library/cplib/data_structure/ordered_set.hpp.html
title: cplib/data_structure/ordered_set.hpp
---
