---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
    title: test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/knuth_morris_pratt.hpp\"\n\n\n\n#include <vector>\n\
    #include <string>\n\n// Find a string t from a string s.\n// For each element\
    \ i in returned vector,\n// s.substr(i, t.size()) == t holds.\n// Assume '#' is\
    \ not in s and t.\n// Actually, this is the Morris-Pratt algorithm.\nstd::vector<int>\
    \ kmp(const std::string &s, std::string t) {\n    int n = s.size(), m = t.size();\n\
    \    std::vector<int> id(m + 1);\n    id[0] = -1;\n    int j = -1;\n    for (int\
    \ i = 0; i < m; i++) {\n        while (j >= 0 && t[i] != t[j]) j = id[j];\n  \
    \      id[i + 1] = ++j;\n    }\n    t += '#';\n    std::vector<int> ret;\n   \
    \ int is = 0, it = 0;\n    while (is < n) {\n        if (s[is] == t[it]) is++,\
    \ it++;\n        else if (it == 0) is++;\n        else it = id[it];\n        if\
    \ (it == m) {\n            ret.push_back(is - m);\n        }\n    }\n    return\
    \ ret;\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_KNUTH_MORRIS_PRATT_H_\n#define CPLIB_LIB_KNUTH_MORRIS_PRATT_H_\n\
    \n#include <vector>\n#include <string>\n\n// Find a string t from a string s.\n\
    // For each element i in returned vector,\n// s.substr(i, t.size()) == t holds.\n\
    // Assume '#' is not in s and t.\n// Actually, this is the Morris-Pratt algorithm.\n\
    std::vector<int> kmp(const std::string &s, std::string t) {\n    int n = s.size(),\
    \ m = t.size();\n    std::vector<int> id(m + 1);\n    id[0] = -1;\n    int j =\
    \ -1;\n    for (int i = 0; i < m; i++) {\n        while (j >= 0 && t[i] != t[j])\
    \ j = id[j];\n        id[i + 1] = ++j;\n    }\n    t += '#';\n    std::vector<int>\
    \ ret;\n    int is = 0, it = 0;\n    while (is < n) {\n        if (s[is] == t[it])\
    \ is++, it++;\n        else if (it == 0) is++;\n        else it = id[it];\n  \
    \      if (it == m) {\n            ret.push_back(is - m);\n        }\n    }\n\
    \    return ret;\n}\n\n#endif  // CPLIB_LIB_KNUTH_MORRIS_PRATT_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/knuth_morris_pratt.hpp
  requiredBy: []
  timestamp: '2020-05-16 01:16:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
documentation_of: lib/knuth_morris_pratt.hpp
layout: document
redirect_from:
- /library/lib/knuth_morris_pratt.hpp
- /library/lib/knuth_morris_pratt.hpp.html
title: lib/knuth_morris_pratt.hpp
---
