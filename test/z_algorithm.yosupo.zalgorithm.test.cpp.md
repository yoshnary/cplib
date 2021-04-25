---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/z_algorithm.hpp
    title: lib/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/z_algorithm.yosupo.zalgorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <iostream>\n#include\
    \ <string>\n#line 1 \"lib/z_algorithm.hpp\"\n\n\n\n#include <vector>\n#line 6\
    \ \"lib/z_algorithm.hpp\"\n#include <algorithm>\n\nstd::vector<int> z_algorithm(const\
    \ std::string &s) {\n    int n = s.size();\n    std::vector<int> ret(n);\n   \
    \ ret[0] = n;\n    int begin = 1, len = 0;\n    while (begin < n) {\n        while\
    \ (begin + len < n && s[len] == s[begin + len]) len++;\n        ret[begin] = len;\n\
    \        int t = 1;\n        while (t < len && t + ret[t] < len) {\n         \
    \   ret[begin + t] = ret[t];\n            t++;\n        }\n        begin += t;\
    \ len = std::max(0, len - t);\n    }\n    return ret;\n}\n\n\n#line 6 \"test/z_algorithm.yosupo.zalgorithm.test.cpp\"\
    \n\nint main() {\n    std::string s; std::cin >> s;\n    auto ans = z_algorithm(s);\n\
    \    int n = s.size();\n    for (int i = 0; i < n; i++)\n        std::cout <<\
    \ ans[i] << \" \\n\"[i == n - 1];\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n#include \"../lib/z_algorithm.hpp\"\n\nint main()\
    \ {\n    std::string s; std::cin >> s;\n    auto ans = z_algorithm(s);\n    int\
    \ n = s.size();\n    for (int i = 0; i < n; i++)\n        std::cout << ans[i]\
    \ << \" \\n\"[i == n - 1];\n    return 0;\n}\n"
  dependsOn:
  - lib/z_algorithm.hpp
  isVerificationFile: true
  path: test/z_algorithm.yosupo.zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2020-05-15 17:57:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/z_algorithm.yosupo.zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/z_algorithm.yosupo.zalgorithm.test.cpp
- /verify/test/z_algorithm.yosupo.zalgorithm.test.cpp.html
title: test/z_algorithm.yosupo.zalgorithm.test.cpp
---
