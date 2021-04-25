---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.aoj.3037.test.cpp
    title: test/heavy_light_decomposition.aoj.3037.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
    title: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/lowest_common_ancestor.hpp\"\n\n\n\n#include <vector>\n\
    #include <utility>\n\nstruct LowestCommonAncestor {\n    using Edge = std::vector<std::vector<int>>;\n\
    \    std::vector<int> depth;\n    std::vector<std::vector<int>> anc;\n\n    LowestCommonAncestor(const\
    \ Edge &edg, int root)\n        : depth(edg.size()), anc(L, std::vector<int>(edg.size(),\
    \ root)) {\n\n        build(edg, root);\n    }\n\n    int query(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) std::swap(u, v);\n        for (int i = L\
    \ - 1; i >= 0; i--) {\n            if (((depth[v] - depth[u]) >> i) & 1) {\n \
    \               v = anc[i][v];\n            }\n        }\n        if (u == v)\
    \ return u;\n\n        for (int i = L - 1; i >= 0; i--) {\n            if (anc[i][u]\
    \ == anc[i][v]) continue;\n            u = anc[i][u];\n            v = anc[i][v];\n\
    \        }\n        return anc[0][u];\n    }\n\nprivate:\n    static const int\
    \ L = 30;\n\n    void dfs(const Edge &edg, int pos, int prev = -1) {\n       \
    \ for (int v : edg[pos]) {\n            if (v == prev) continue;\n           \
    \ depth[v] = depth[pos] + 1;\n            anc[0][v] = pos;\n            dfs(edg,\
    \ v, pos);\n        }\n    }\n\n    void build(const Edge &edg, int root) {\n\
    \        dfs(edg, root);\n        int n = edg.size();\n        for (int i = 1;\
    \ i < L; i++) {\n            for (int j = 0; j < n; j++) {\n                anc[i][j]\
    \ = anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_\n#define CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_\n\
    \n#include <vector>\n#include <utility>\n\nstruct LowestCommonAncestor {\n   \
    \ using Edge = std::vector<std::vector<int>>;\n    std::vector<int> depth;\n \
    \   std::vector<std::vector<int>> anc;\n\n    LowestCommonAncestor(const Edge\
    \ &edg, int root)\n        : depth(edg.size()), anc(L, std::vector<int>(edg.size(),\
    \ root)) {\n\n        build(edg, root);\n    }\n\n    int query(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) std::swap(u, v);\n        for (int i = L\
    \ - 1; i >= 0; i--) {\n            if (((depth[v] - depth[u]) >> i) & 1) {\n \
    \               v = anc[i][v];\n            }\n        }\n        if (u == v)\
    \ return u;\n\n        for (int i = L - 1; i >= 0; i--) {\n            if (anc[i][u]\
    \ == anc[i][v]) continue;\n            u = anc[i][u];\n            v = anc[i][v];\n\
    \        }\n        return anc[0][u];\n    }\n\nprivate:\n    static const int\
    \ L = 30;\n\n    void dfs(const Edge &edg, int pos, int prev = -1) {\n       \
    \ for (int v : edg[pos]) {\n            if (v == prev) continue;\n           \
    \ depth[v] = depth[pos] + 1;\n            anc[0][v] = pos;\n            dfs(edg,\
    \ v, pos);\n        }\n    }\n\n    void build(const Edge &edg, int root) {\n\
    \        dfs(edg, root);\n        int n = edg.size();\n        for (int i = 1;\
    \ i < L; i++) {\n            for (int j = 0; j < n; j++) {\n                anc[i][j]\
    \ = anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n};\n\n#endif\
    \  // CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2020-05-09 15:54:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.aoj.3037.test.cpp
  - test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
documentation_of: lib/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/lib/lowest_common_ancestor.hpp
- /library/lib/lowest_common_ancestor.hpp.html
title: lib/lowest_common_ancestor.hpp
---
