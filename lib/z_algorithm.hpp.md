---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/z_algorithm.yosupo.zalgorithm.test.cpp
    title: test/z_algorithm.yosupo.zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/z_algorithm.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <string>\n#include <algorithm>\n\nstd::vector<int> z_algorithm(const std::string\
    \ &s) {\n    int n = s.size();\n    std::vector<int> ret(n);\n    ret[0] = n;\n\
    \    int begin = 1, len = 0;\n    while (begin < n) {\n        while (begin +\
    \ len < n && s[len] == s[begin + len]) len++;\n        ret[begin] = len;\n   \
    \     int t = 1;\n        while (t < len && t + ret[t] < len) {\n            ret[begin\
    \ + t] = ret[t];\n            t++;\n        }\n        begin += t; len = std::max(0,\
    \ len - t);\n    }\n    return ret;\n}\n\n\n"
  code: "#ifndef CPLIB_CLIB_Z_ALGORITHM_H_\n#define CPLIB_CLIB_Z_ALGORITHM_H_\n\n\
    #include <vector>\n#include <string>\n#include <algorithm>\n\nstd::vector<int>\
    \ z_algorithm(const std::string &s) {\n    int n = s.size();\n    std::vector<int>\
    \ ret(n);\n    ret[0] = n;\n    int begin = 1, len = 0;\n    while (begin < n)\
    \ {\n        while (begin + len < n && s[len] == s[begin + len]) len++;\n    \
    \    ret[begin] = len;\n        int t = 1;\n        while (t < len && t + ret[t]\
    \ < len) {\n            ret[begin + t] = ret[t];\n            t++;\n        }\n\
    \        begin += t; len = std::max(0, len - t);\n    }\n    return ret;\n}\n\n\
    #endif  // CPLIB_CLIB_Z_ALGORITHM_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/z_algorithm.hpp
  requiredBy: []
  timestamp: '2020-05-15 17:57:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/z_algorithm.yosupo.zalgorithm.test.cpp
documentation_of: lib/z_algorithm.hpp
layout: document
redirect_from:
- /library/lib/z_algorithm.hpp
- /library/lib/z_algorithm.hpp.html
title: lib/z_algorithm.hpp
---
