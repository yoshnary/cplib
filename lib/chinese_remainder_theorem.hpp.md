---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/extgcd.hpp
    title: lib/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/chinese_remainder_theorem.yuki.447.test.cpp
    title: test/chinese_remainder_theorem.yuki.447.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/chinese_remainder_theorem.hpp\"\n\n\n\n#include <utility>\n\
    #line 1 \"lib/extgcd.hpp\"\n\n\n\n#include <tuple>\n#line 6 \"lib/extgcd.hpp\"\
    \n\n// Find x and y such that a*x + b*y = gcd(a, b)\n// Return gcd(a, b)\nlong\
    \ long extgcd(long long a, long long b, long long &x, long long &y) {\n    if\
    \ (b == 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    long long ret\
    \ = extgcd(b, a%b, x, y);\n    std::tie(x, y) = std::make_pair(y, x - a / b *\
    \ y);\n    return ret;\n}\n\n\n#line 6 \"lib/chinese_remainder_theorem.hpp\"\n\
    \n// Chinese Remainder Theorem\n// Find rem such that 0 <= rem < lcm(m1, m2) and\n\
    // rem % m1 = r1 and rem % m2 = r2\n// Return { -1, -1 } if such rem doesn't exist,\n\
    // otherwise return { lcm(m1, m2), rem }\nstd::pair<long long, long long>\ncrt(long\
    \ long m1, long long r1, long long m2, long long r2) {\n    long long x = 0, y\
    \ = 0;\n    long long d = extgcd(m1, m2, x, y);\n    if (r1%d != r2%d) {\n   \
    \     return { -1, -1 };\n    }\n    long long lcm = m1 / d * m2;\n    long long\
    \ rem = ((r2 - r1) / d * x % (m2 / d)) * m1;\n    rem = ((rem + r1) % lcm + lcm)\
    \ % lcm;\n    return { lcm, rem };\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_\n#define CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_\n\
    \n#include <utility>\n#include \"../lib/extgcd.hpp\"\n\n// Chinese Remainder Theorem\n\
    // Find rem such that 0 <= rem < lcm(m1, m2) and\n// rem % m1 = r1 and rem % m2\
    \ = r2\n// Return { -1, -1 } if such rem doesn't exist,\n// otherwise return {\
    \ lcm(m1, m2), rem }\nstd::pair<long long, long long>\ncrt(long long m1, long\
    \ long r1, long long m2, long long r2) {\n    long long x = 0, y = 0;\n    long\
    \ long d = extgcd(m1, m2, x, y);\n    if (r1%d != r2%d) {\n        return { -1,\
    \ -1 };\n    }\n    long long lcm = m1 / d * m2;\n    long long rem = ((r2 - r1)\
    \ / d * x % (m2 / d)) * m1;\n    rem = ((rem + r1) % lcm + lcm) % lcm;\n    return\
    \ { lcm, rem };\n}\n\n#endif  // CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_\n"
  dependsOn:
  - lib/extgcd.hpp
  isVerificationFile: false
  path: lib/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2020-05-10 13:15:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/chinese_remainder_theorem.yuki.447.test.cpp
documentation_of: lib/chinese_remainder_theorem.hpp
layout: document
redirect_from:
- /library/lib/chinese_remainder_theorem.hpp
- /library/lib/chinese_remainder_theorem.hpp.html
title: lib/chinese_remainder_theorem.hpp
---
