---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/chinese_remainder_theorem.hpp
    title: lib/chinese_remainder_theorem.hpp
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
    PROBLEM: https://yukicoder.me/problems/447
    links:
    - https://yukicoder.me/problems/447
  bundledCode: "#line 1 \"test/chinese_remainder_theorem.yuki.447.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include <iostream>\n#include\
    \ <tuple>\n#line 1 \"lib/chinese_remainder_theorem.hpp\"\n\n\n\n#include <utility>\n\
    #line 1 \"lib/extgcd.hpp\"\n\n\n\n#line 6 \"lib/extgcd.hpp\"\n\n// Find x and\
    \ y such that a*x + b*y = gcd(a, b)\n// Return gcd(a, b)\nlong long extgcd(long\
    \ long a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n    \
    \    x = 1, y = 0;\n        return a;\n    }\n    long long ret = extgcd(b, a%b,\
    \ x, y);\n    std::tie(x, y) = std::make_pair(y, x - a / b * y);\n    return ret;\n\
    }\n\n\n#line 6 \"lib/chinese_remainder_theorem.hpp\"\n\n// Chinese Remainder Theorem\n\
    // Find rem such that 0 <= rem < lcm(m1, m2) and\n// rem % m1 = r1 and rem % m2\
    \ = r2\n// Return { -1, -1 } if such rem doesn't exist,\n// otherwise return {\
    \ lcm(m1, m2), rem }\nstd::pair<long long, long long>\ncrt(long long m1, long\
    \ long r1, long long m2, long long r2) {\n    long long x = 0, y = 0;\n    long\
    \ long d = extgcd(m1, m2, x, y);\n    if (r1%d != r2%d) {\n        return { -1,\
    \ -1 };\n    }\n    long long lcm = m1 / d * m2;\n    long long rem = ((r2 - r1)\
    \ / d * x % (m2 / d)) * m1;\n    rem = ((rem + r1) % lcm + lcm) % lcm;\n    return\
    \ { lcm, rem };\n}\n\n\n#line 6 \"test/chinese_remainder_theorem.yuki.447.test.cpp\"\
    \n\nint main() {\n    long long x, y; std::cin >> x >> y;\n    for (int i = 0;\
    \ i < 2; i++) {\n        long long a, b; std::cin >> a >> b;\n        std::tie(y,\
    \ x) = crt(y, x, b, a);\n        if (x == -1) {\n            std::cout << -1 <<\
    \ std::endl;\n            return 0;\n        }\n    }\n    std::cout << (x ==\
    \ 0 ? y : x) << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include <iostream>\n\
    #include <tuple>\n#include \"../lib/chinese_remainder_theorem.hpp\"\n\nint main()\
    \ {\n    long long x, y; std::cin >> x >> y;\n    for (int i = 0; i < 2; i++)\
    \ {\n        long long a, b; std::cin >> a >> b;\n        std::tie(y, x) = crt(y,\
    \ x, b, a);\n        if (x == -1) {\n            std::cout << -1 << std::endl;\n\
    \            return 0;\n        }\n    }\n    std::cout << (x == 0 ? y : x) <<\
    \ std::endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/chinese_remainder_theorem.hpp
  - lib/extgcd.hpp
  isVerificationFile: true
  path: test/chinese_remainder_theorem.yuki.447.test.cpp
  requiredBy: []
  timestamp: '2020-05-10 13:15:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/chinese_remainder_theorem.yuki.447.test.cpp
layout: document
redirect_from:
- /verify/test/chinese_remainder_theorem.yuki.447.test.cpp
- /verify/test/chinese_remainder_theorem.yuki.447.test.cpp.html
title: test/chinese_remainder_theorem.yuki.447.test.cpp
---
