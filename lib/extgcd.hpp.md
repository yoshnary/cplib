---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/chinese_remainder_theorem.hpp
    title: lib/chinese_remainder_theorem.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/chinese_remainder_theorem.yuki.447.test.cpp
    title: test/chinese_remainder_theorem.yuki.447.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/extgcd.aoj.NTL_1_E.test.cpp
    title: test/extgcd.aoj.NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/extgcd.hpp\"\n\n\n\n#include <tuple>\n#include <utility>\n\
    \n// Find x and y such that a*x + b*y = gcd(a, b)\n// Return gcd(a, b)\nlong long\
    \ extgcd(long long a, long long b, long long &x, long long &y) {\n    if (b ==\
    \ 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    long long ret = extgcd(b,\
    \ a%b, x, y);\n    std::tie(x, y) = std::make_pair(y, x - a / b * y);\n    return\
    \ ret;\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_EXTGCD_H_\n#define CPLIB_LIB_EXTGCD_H_\n\n#include <tuple>\n\
    #include <utility>\n\n// Find x and y such that a*x + b*y = gcd(a, b)\n// Return\
    \ gcd(a, b)\nlong long extgcd(long long a, long long b, long long &x, long long\
    \ &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n\
    \    long long ret = extgcd(b, a%b, x, y);\n    std::tie(x, y) = std::make_pair(y,\
    \ x - a / b * y);\n    return ret;\n}\n\n#endif  // CPLIB_LIB_EXTGCD_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/extgcd.hpp
  requiredBy:
  - lib/chinese_remainder_theorem.hpp
  timestamp: '2020-05-10 11:45:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/chinese_remainder_theorem.yuki.447.test.cpp
  - test/extgcd.aoj.NTL_1_E.test.cpp
documentation_of: lib/extgcd.hpp
layout: document
redirect_from:
- /library/lib/extgcd.hpp
- /library/lib/extgcd.hpp.html
title: lib/extgcd.hpp
---
