---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/topological_sort.hpp
    title: lib/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A
  bundledCode: "#line 1 \"test/topological_sort.aoj.GRL_4_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 1 \"lib/topological_sort.hpp\"\n\n\n\n\
    #line 5 \"lib/topological_sort.hpp\"\n#include <algorithm>\n\nstruct TopologicalSort\
    \ {\n    using Edge = std::vector<std::vector<int>>;\n    std::vector<int> ord;\n\
    \    bool isdag;\n\n    TopologicalSort(const Edge &edg) : used(edg.size()) {\n\
    \        isdag = true;\n        for (int i = 0; i < (int)edg.size(); i++) {\n\
    \            if (used[i] != 0) continue;\n            isdag &= rec(edg, i);\n\
    \        }\n        std::reverse(ord.begin(), ord.end());\n    }\n\nprivate:\n\
    \    std::vector<int> used;\n\n    bool rec(const Edge &edg, int pos) {\n    \
    \    if (used[pos] == -1) return false;\n        if (used[pos] == 1) return true;\n\
    \        used[pos] = -1;\n        for (int c : edg[pos]) {\n            if (!rec(edg,\
    \ c)) return false;\n        }\n        used[pos] = 1;\n        ord.push_back(pos);\n\
    \        return true;\n    }\n};\n\n\n#line 6 \"test/topological_sort.aoj.GRL_4_A.test.cpp\"\
    \n\nint main() {\n    int n, m; std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    for (int i = 0; i < m; i++) {\n        int s, t; std::cin >> s\
    \ >> t;\n        edg[s].push_back(t);\n    }\n    TopologicalSort topo(edg);\n\
    \    std::cout << !topo.isdag << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../lib/topological_sort.hpp\"\
    \n\nint main() {\n    int n, m; std::cin >> n >> m;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    for (int i = 0; i < m; i++) {\n        int s, t; std::cin >> s\
    \ >> t;\n        edg[s].push_back(t);\n    }\n    TopologicalSort topo(edg);\n\
    \    std::cout << !topo.isdag << std::endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/topological_sort.hpp
  isVerificationFile: true
  path: test/topological_sort.aoj.GRL_4_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 18:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/topological_sort.aoj.GRL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/topological_sort.aoj.GRL_4_A.test.cpp
- /verify/test/topological_sort.aoj.GRL_4_A.test.cpp.html
title: test/topological_sort.aoj.GRL_4_A.test.cpp
---
