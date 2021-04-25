---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.aoj.3037.test.cpp
    title: test/heavy_light_decomposition.aoj.3037.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
    title: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/heavy_light_decomposition.hpp\"\n\n\n\n#include <vector>\n\
    \nstruct HLDecomposition {\n    using Edge = std::vector<std::vector<int>>;\n\n\
    \    // USAGE: pos[par[left[v]]], pos[left[v]]\n\n    // pos[v]: position in a\
    \ line of the vertex v\n    std::vector<int> pos;\n\n    // left[v]: the leftmost\
    \ vertex\n    // of the connected component including v.\n    // If left[v] ==\
    \ v, it means v is itself\n    // the leftmost vertex.\n    std::vector<int> left;\n\
    \n    // par[v]: parent of the vertex v.\n    // If par[v] == v, it means v is\
    \ the root.\n    std::vector<int> par;\n\n    HLDecomposition(const Edge &edg,\
    \ int root)\n        : pos(edg.size())\n        , left(edg.size(), -1)\n     \
    \   , par(edg.size(), -1)\n        , weight(edg.size(), 1) {\n\n        build_weight(edg,\
    \ root);\n        left[root] = par[root] = root;\n        decompose(edg, root);\n\
    \    }\n\nprivate:\n    std::vector<int> weight;\n\n    int build_weight(const\
    \ Edge &edg, int v, int prev = -1) {\n        for (int c : edg[v]) {\n       \
    \     if (c == prev) continue;\n            weight[v] += build_weight(edg, c,\
    \ v);\n        }\n        return weight[v];\n    }\n\n    void decompose(const\
    \ Edge &edg, int v, int prev = -1) {\n        static int cnt = 0;\n\n        pos[v]\
    \ = cnt++;\n        int max_weight = 0, max_id = -1;\n        for (int c : edg[v])\
    \ {\n            if (c == prev) continue;\n            if (weight[c] > max_weight)\
    \ {\n                max_weight = weight[c];\n                max_id = c;\n  \
    \          }\n        }\n        if (max_id == -1) return;\n\n        par[max_id]\
    \ = v;\n        left[max_id] = left[v];\n        decompose(edg, max_id, v);\n\n\
    \        for (int c : edg[v]) {\n            if (c == prev || c == max_id) continue;\n\
    \            par[c] = v;\n            left[c] = c;\n            decompose(edg,\
    \ c, v);\n        }\n    }\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_\n#define CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_\n\
    \n#include <vector>\n\nstruct HLDecomposition {\n    using Edge = std::vector<std::vector<int>>;\n\
    \n    // USAGE: pos[par[left[v]]], pos[left[v]]\n\n    // pos[v]: position in\
    \ a line of the vertex v\n    std::vector<int> pos;\n\n    // left[v]: the leftmost\
    \ vertex\n    // of the connected component including v.\n    // If left[v] ==\
    \ v, it means v is itself\n    // the leftmost vertex.\n    std::vector<int> left;\n\
    \n    // par[v]: parent of the vertex v.\n    // If par[v] == v, it means v is\
    \ the root.\n    std::vector<int> par;\n\n    HLDecomposition(const Edge &edg,\
    \ int root)\n        : pos(edg.size())\n        , left(edg.size(), -1)\n     \
    \   , par(edg.size(), -1)\n        , weight(edg.size(), 1) {\n\n        build_weight(edg,\
    \ root);\n        left[root] = par[root] = root;\n        decompose(edg, root);\n\
    \    }\n\nprivate:\n    std::vector<int> weight;\n\n    int build_weight(const\
    \ Edge &edg, int v, int prev = -1) {\n        for (int c : edg[v]) {\n       \
    \     if (c == prev) continue;\n            weight[v] += build_weight(edg, c,\
    \ v);\n        }\n        return weight[v];\n    }\n\n    void decompose(const\
    \ Edge &edg, int v, int prev = -1) {\n        static int cnt = 0;\n\n        pos[v]\
    \ = cnt++;\n        int max_weight = 0, max_id = -1;\n        for (int c : edg[v])\
    \ {\n            if (c == prev) continue;\n            if (weight[c] > max_weight)\
    \ {\n                max_weight = weight[c];\n                max_id = c;\n  \
    \          }\n        }\n        if (max_id == -1) return;\n\n        par[max_id]\
    \ = v;\n        left[max_id] = left[v];\n        decompose(edg, max_id, v);\n\n\
    \        for (int c : edg[v]) {\n            if (c == prev || c == max_id) continue;\n\
    \            par[c] = v;\n            left[c] = c;\n            decompose(edg,\
    \ c, v);\n        }\n    }\n};\n\n#endif  // CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2020-05-09 20:14:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
  - test/heavy_light_decomposition.aoj.3037.test.cpp
documentation_of: lib/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/lib/heavy_light_decomposition.hpp
- /library/lib/heavy_light_decomposition.hpp.html
title: lib/heavy_light_decomposition.hpp
---
