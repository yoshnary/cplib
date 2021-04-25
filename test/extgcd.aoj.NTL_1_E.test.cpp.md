---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/extgcd.hpp
    title: lib/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
  bundledCode: "#line 1 \"test/extgcd.aoj.NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#include <iostream>\n#line 1 \"lib/extgcd.hpp\"\n\n\n\n#include <tuple>\n\
    #include <utility>\n\n// Find x and y such that a*x + b*y = gcd(a, b)\n// Return\
    \ gcd(a, b)\nlong long extgcd(long long a, long long b, long long &x, long long\
    \ &y) {\n    if (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n\
    \    long long ret = extgcd(b, a%b, x, y);\n    std::tie(x, y) = std::make_pair(y,\
    \ x - a / b * y);\n    return ret;\n}\n\n\n#line 5 \"test/extgcd.aoj.NTL_1_E.test.cpp\"\
    \n\nint main() {\n    long long a, b; std::cin >> a >> b;\n    long long x, y;\n\
    \    extgcd(a, b, x, y);\n    std::cout << x << \" \" << y << std::endl;\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#include <iostream>\n#include \"../lib/extgcd.hpp\"\n\nint main() {\n    long\
    \ long a, b; std::cin >> a >> b;\n    long long x, y;\n    extgcd(a, b, x, y);\n\
    \    std::cout << x << \" \" << y << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/extgcd.hpp
  isVerificationFile: true
  path: test/extgcd.aoj.NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2020-05-10 11:45:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/extgcd.aoj.NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/extgcd.aoj.NTL_1_E.test.cpp
- /verify/test/extgcd.aoj.NTL_1_E.test.cpp.html
title: test/extgcd.aoj.NTL_1_E.test.cpp
---
