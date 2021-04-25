---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/topological_sort.aoj.GRL_4_A.test.cpp
    title: test/topological_sort.aoj.GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/topological_sort.aoj.GRL_4_B.test.cpp
    title: test/topological_sort.aoj.GRL_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/topological_sort.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n\nstruct TopologicalSort {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> ord;\n    bool isdag;\n\n    TopologicalSort(const Edge\
    \ &edg) : used(edg.size()) {\n        isdag = true;\n        for (int i = 0; i\
    \ < (int)edg.size(); i++) {\n            if (used[i] != 0) continue;\n       \
    \     isdag &= rec(edg, i);\n        }\n        std::reverse(ord.begin(), ord.end());\n\
    \    }\n\nprivate:\n    std::vector<int> used;\n\n    bool rec(const Edge &edg,\
    \ int pos) {\n        if (used[pos] == -1) return false;\n        if (used[pos]\
    \ == 1) return true;\n        used[pos] = -1;\n        for (int c : edg[pos])\
    \ {\n            if (!rec(edg, c)) return false;\n        }\n        used[pos]\
    \ = 1;\n        ord.push_back(pos);\n        return true;\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_TOPOLOGICAL_SORT_H_\n#define CPLIB_LIB_TOPOLOGICAL_SORT_H_\n\
    \n#include <vector>\n#include <algorithm>\n\nstruct TopologicalSort {\n    using\
    \ Edge = std::vector<std::vector<int>>;\n    std::vector<int> ord;\n    bool isdag;\n\
    \n    TopologicalSort(const Edge &edg) : used(edg.size()) {\n        isdag = true;\n\
    \        for (int i = 0; i < (int)edg.size(); i++) {\n            if (used[i]\
    \ != 0) continue;\n            isdag &= rec(edg, i);\n        }\n        std::reverse(ord.begin(),\
    \ ord.end());\n    }\n\nprivate:\n    std::vector<int> used;\n\n    bool rec(const\
    \ Edge &edg, int pos) {\n        if (used[pos] == -1) return false;\n        if\
    \ (used[pos] == 1) return true;\n        used[pos] = -1;\n        for (int c :\
    \ edg[pos]) {\n            if (!rec(edg, c)) return false;\n        }\n      \
    \  used[pos] = 1;\n        ord.push_back(pos);\n        return true;\n    }\n\
    };\n\n#endif  // CPLIB_LIB_TOPOLOGICAL_SORT_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/topological_sort.hpp
  requiredBy: []
  timestamp: '2020-05-09 15:26:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/topological_sort.aoj.GRL_4_B.test.cpp
  - test/topological_sort.aoj.GRL_4_A.test.cpp
documentation_of: lib/topological_sort.hpp
layout: document
redirect_from:
- /library/lib/topological_sort.hpp
- /library/lib/topological_sort.hpp.html
title: lib/topological_sort.hpp
---
