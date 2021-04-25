---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/euler_tour.aoj.GRL_5_D.test.cpp
    title: test/euler_tour.aoj.GRL_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/euler_tour.hpp\"\n\n\n\n#include <vector>\n\n// Vertex\
    \ ver.\nstruct EulerTourV {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> left, right;\n\n    // A range [left[i], right[i]) corresponds\
    \ to a subtree from a vertex i\n    EulerTourV(const Edge &edg, int root) : left(edg.size()),\
    \ right(edg.size()) {\n        int n = 0;\n        dfs(edg, root, n);\n    }\n\
    \nprivate:\n    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {\n\
    \        left[pos] = id++;\n        for (int c : edg[pos]) {\n            if (c\
    \ == prev) continue;\n            dfs(edg, c, id, pos);\n        }\n        right[pos]\
    \ = id;\n    }\n};\n\n// Edge ver.\nstruct EulerTourE {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> left, right;\n\n    // A range [left[i], right[i]) corresponds\
    \ to a subtree from a vertex i\n    EulerTourE(const Edge &edg, int root) : left(edg.size()),\
    \ right(edg.size()) {\n        int n = 0;\n        dfs(edg, root, n);\n    }\n\
    \nprivate:\n    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {\n\
    \        left[pos] = id++;\n        for (int c : edg[pos]) {\n            if (c\
    \ == prev) continue;\n            dfs(edg, c, id, pos);\n        }\n        right[pos]\
    \ = id++;\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_EULER_TOUR_H_\n#define CPLIB_LIB_EULER_TOUR_H_\n\n#include\
    \ <vector>\n\n// Vertex ver.\nstruct EulerTourV {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> left, right;\n\n    // A range [left[i], right[i]) corresponds\
    \ to a subtree from a vertex i\n    EulerTourV(const Edge &edg, int root) : left(edg.size()),\
    \ right(edg.size()) {\n        int n = 0;\n        dfs(edg, root, n);\n    }\n\
    \nprivate:\n    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {\n\
    \        left[pos] = id++;\n        for (int c : edg[pos]) {\n            if (c\
    \ == prev) continue;\n            dfs(edg, c, id, pos);\n        }\n        right[pos]\
    \ = id;\n    }\n};\n\n// Edge ver.\nstruct EulerTourE {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> left, right;\n\n    // A range [left[i], right[i]) corresponds\
    \ to a subtree from a vertex i\n    EulerTourE(const Edge &edg, int root) : left(edg.size()),\
    \ right(edg.size()) {\n        int n = 0;\n        dfs(edg, root, n);\n    }\n\
    \nprivate:\n    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {\n\
    \        left[pos] = id++;\n        for (int c : edg[pos]) {\n            if (c\
    \ == prev) continue;\n            dfs(edg, c, id, pos);\n        }\n        right[pos]\
    \ = id++;\n    }\n};\n\n#endif  // CPLIB_LIB_EULER_TOUR_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/euler_tour.hpp
  requiredBy: []
  timestamp: '2020-05-09 20:29:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/euler_tour.aoj.GRL_5_D.test.cpp
documentation_of: lib/euler_tour.hpp
layout: document
redirect_from:
- /library/lib/euler_tour.hpp
- /library/lib/euler_tour.hpp.html
title: lib/euler_tour.hpp
---
