---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/knuth_morris_pratt.hpp
    title: lib/knuth_morris_pratt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#line 1 \"lib/knuth_morris_pratt.hpp\"\
    \n\n\n\n#include <vector>\n#line 6 \"lib/knuth_morris_pratt.hpp\"\n\n// Find a\
    \ string t from a string s.\n// For each element i in returned vector,\n// s.substr(i,\
    \ t.size()) == t holds.\n// Assume '#' is not in s and t.\n// Actually, this is\
    \ the Morris-Pratt algorithm.\nstd::vector<int> kmp(const std::string &s, std::string\
    \ t) {\n    int n = s.size(), m = t.size();\n    std::vector<int> id(m + 1);\n\
    \    id[0] = -1;\n    int j = -1;\n    for (int i = 0; i < m; i++) {\n       \
    \ while (j >= 0 && t[i] != t[j]) j = id[j];\n        id[i + 1] = ++j;\n    }\n\
    \    t += '#';\n    std::vector<int> ret;\n    int is = 0, it = 0;\n    while\
    \ (is < n) {\n        if (s[is] == t[it]) is++, it++;\n        else if (it ==\
    \ 0) is++;\n        else it = id[it];\n        if (it == m) {\n            ret.push_back(is\
    \ - m);\n        }\n    }\n    return ret;\n}\n\n\n#line 6 \"test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp\"\
    \n\nint main(){\n    std::string s, t; std::cin >> s >> t;\n    auto ans = kmp(s,\
    \ t);\n    for (int i : ans) std::cout << i << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#include \"../lib/knuth_morris_pratt.hpp\"\
    \n\nint main(){\n    std::string s, t; std::cin >> s >> t;\n    auto ans = kmp(s,\
    \ t);\n    for (int i : ans) std::cout << i << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/knuth_morris_pratt.hpp
  isVerificationFile: true
  path: test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2020-05-16 01:16:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
- /verify/test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp.html
title: test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp
---
