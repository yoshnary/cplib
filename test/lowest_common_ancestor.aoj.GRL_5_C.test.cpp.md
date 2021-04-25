---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/lowest_common_ancestor.hpp
    title: lib/lowest_common_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 1 \"lib/lowest_common_ancestor.hpp\"\
    \n\n\n\n#line 5 \"lib/lowest_common_ancestor.hpp\"\n#include <utility>\n\nstruct\
    \ LowestCommonAncestor {\n    using Edge = std::vector<std::vector<int>>;\n  \
    \  std::vector<int> depth;\n    std::vector<std::vector<int>> anc;\n\n    LowestCommonAncestor(const\
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
    \ = anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n};\n\n\n#line\
    \ 6 \"test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp\"\n\nint main() {\n   \
    \ int n; std::cin>> n;\n    std::vector<std::vector<int>> edg(n);\n    bool used[100003]\
    \ = {};\n    for (int i = 0; i < n; i++) {\n        int k; std::cin >> k;\n  \
    \      for (int j = 0; j < k ;j++) {\n            int c; std::cin >> c;\n    \
    \        edg[i].push_back(c);\n            edg[c].push_back(i);\n            used[c]\
    \ = true;\n        }\n    }\n    int root;\n    for (int i = 0; i < n; i++) {\n\
    \        if (!used[i]) root = i;\n    }\n    LowestCommonAncestor lca(edg, root);\n\
    \    int q; std::cin >> q;\n    while (q--) {\n        int u, v; std::cin >> u\
    \ >> v;\n        std::cout << lca.query(u, v) << std::endl;\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../lib/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int n; std::cin>> n;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    bool used[100003] = {};\n    for (int i = 0; i < n; i++) {\n  \
    \      int k; std::cin >> k;\n        for (int j = 0; j < k ;j++) {\n        \
    \    int c; std::cin >> c;\n            edg[i].push_back(c);\n            edg[c].push_back(i);\n\
    \            used[c] = true;\n        }\n    }\n    int root;\n    for (int i\
    \ = 0; i < n; i++) {\n        if (!used[i]) root = i;\n    }\n    LowestCommonAncestor\
    \ lca(edg, root);\n    int q; std::cin >> q;\n    while (q--) {\n        int u,\
    \ v; std::cin >> u >> v;\n        std::cout << lca.query(u, v) << std::endl;\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - lib/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 18:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
- /verify/test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp.html
title: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp
---
