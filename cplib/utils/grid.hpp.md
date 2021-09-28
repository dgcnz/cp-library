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
  bundledCode: "#line 1 \"cplib/utils/grid.hpp\"\n\n\n\n#include <stdexcept>\n#include\
    \ <utility>\n\nnamespace cplib\n{\n\nusing namespace std;\n\nstruct Direction\n\
    {\n    int first;\n    int second;\n\n    bool operator==(Direction const &other)\
    \ const\n    {\n        return first == other.first and second == other.second;\n\
    \    }\n\n    bool operator!=(Direction const &other) const\n    {\n        return\
    \ first != other.first or second != other.second;\n    }\n\n    Direction opposite()\
    \ const { return Direction{-first, -second}; }\n    friend pair<int, int> operator+(pair<int,\
    \ int> const &a, Direction const &b)\n    {\n        return make_pair(a.first\
    \ + b.first, a.second + b.second);\n    }\n};\n\nDirection const UP{-1, 0};\n\
    Direction const RIGHT{0, +1};\nDirection const DOWN{+1, 0};\nDirection const LEFT{0,\
    \ -1};\n\nchar dir_to_char(Direction const &dir)\n{\n    if (dir == UP)\n    \
    \    return 'U';\n    if (dir == RIGHT)\n        return 'R';\n    if (dir == DOWN)\n\
    \        return 'D';\n    if (dir == LEFT)\n        return 'L';\n    throw std::runtime_error(\"\
    Unrecognized standard direction character.\");\n}\n\nDirection char_to_dir(char\
    \ c)\n{\n    switch (c)\n    {\n    case 'U':\n        return UP;\n    case 'R':\n\
    \        return RIGHT;\n    case 'D':\n        return DOWN;\n    case 'L':\n \
    \       return LEFT;\n    default:\n        throw std::runtime_error(\"Unrecognized\
    \ standard direction.\");\n    };\n}\n\n} // namespace cplib\n\n\n"
  code: "#ifndef CPLIB_GRID_HPP\n#define CPLIB_GRID_HPP\n\n#include <stdexcept>\n\
    #include <utility>\n\nnamespace cplib\n{\n\nusing namespace std;\n\nstruct Direction\n\
    {\n    int first;\n    int second;\n\n    bool operator==(Direction const &other)\
    \ const\n    {\n        return first == other.first and second == other.second;\n\
    \    }\n\n    bool operator!=(Direction const &other) const\n    {\n        return\
    \ first != other.first or second != other.second;\n    }\n\n    Direction opposite()\
    \ const { return Direction{-first, -second}; }\n    friend pair<int, int> operator+(pair<int,\
    \ int> const &a, Direction const &b)\n    {\n        return make_pair(a.first\
    \ + b.first, a.second + b.second);\n    }\n};\n\nDirection const UP{-1, 0};\n\
    Direction const RIGHT{0, +1};\nDirection const DOWN{+1, 0};\nDirection const LEFT{0,\
    \ -1};\n\nchar dir_to_char(Direction const &dir)\n{\n    if (dir == UP)\n    \
    \    return 'U';\n    if (dir == RIGHT)\n        return 'R';\n    if (dir == DOWN)\n\
    \        return 'D';\n    if (dir == LEFT)\n        return 'L';\n    throw std::runtime_error(\"\
    Unrecognized standard direction character.\");\n}\n\nDirection char_to_dir(char\
    \ c)\n{\n    switch (c)\n    {\n    case 'U':\n        return UP;\n    case 'R':\n\
    \        return RIGHT;\n    case 'D':\n        return DOWN;\n    case 'L':\n \
    \       return LEFT;\n    default:\n        throw std::runtime_error(\"Unrecognized\
    \ standard direction.\");\n    };\n}\n\n} // namespace cplib\n\n#endif // CPLIB_GRID_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: cplib/utils/grid.hpp
  requiredBy: []
  timestamp: '2021-09-28 10:47:46-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cplib/utils/grid.hpp
layout: document
redirect_from:
- /library/cplib/utils/grid.hpp
- /library/cplib/utils/grid.hpp.html
title: cplib/utils/grid.hpp
---
