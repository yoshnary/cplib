---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union_find.yosupo.unionfind.test.cpp
    title: test/union_find.yosupo.unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/union_find.hpp\"\n\n\n\n#include <vector>\n\nclass UnionFind\
    \ {\npublic:\n    UnionFind(int n) : par(n, -1), ran(n, -1) {}\n\n    void unite(int\
    \ x, int y) {\n        x = find_root(x);\n        y = find_root(y);\n        if\
    \ (x == y) return;\n\n        if (ran[x] < ran[y]) {\n            par[find_root(y)]\
    \ += par[find_root(x)];\n            par[x] = y;\n        }\n        else {\n\
    \            par[find_root(x)] += par[find_root(y)];\n            par[y] = x;\n\
    \            if (ran[x] == ran[y]) ran[x]++;\n        }\n    }\n\n    int size(int\
    \ x) {\n        return -par[find_root(x)];\n    }\n\n    bool same(int x, int\
    \ y) {\n        return find_root(x) == find_root(y);\n    }\n\n    int find_root(int\
    \ x) {\n        if (par[x] < 0) {\n            return x;\n        }\n        else\
    \ {\n            return par[x] = find_root(par[x]);\n        }\n    }\n\nprivate:\n\
    \    std::vector<int> par, ran;\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_UNION_FIND_H_\n#define CPLIB_LIB_UNION_FIND_H_\n\n#include\
    \ <vector>\n\nclass UnionFind {\npublic:\n    UnionFind(int n) : par(n, -1), ran(n,\
    \ -1) {}\n\n    void unite(int x, int y) {\n        x = find_root(x);\n      \
    \  y = find_root(y);\n        if (x == y) return;\n\n        if (ran[x] < ran[y])\
    \ {\n            par[find_root(y)] += par[find_root(x)];\n            par[x] =\
    \ y;\n        }\n        else {\n            par[find_root(x)] += par[find_root(y)];\n\
    \            par[y] = x;\n            if (ran[x] == ran[y]) ran[x]++;\n      \
    \  }\n    }\n\n    int size(int x) {\n        return -par[find_root(x)];\n   \
    \ }\n\n    bool same(int x, int y) {\n        return find_root(x) == find_root(y);\n\
    \    }\n\n    int find_root(int x) {\n        if (par[x] < 0) {\n            return\
    \ x;\n        }\n        else {\n            return par[x] = find_root(par[x]);\n\
    \        }\n    }\n\nprivate:\n    std::vector<int> par, ran;\n};\n\n#endif  //\
    \ CPLIB_LIB_UNION_FIND_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/union_find.hpp
  requiredBy: []
  timestamp: '2020-05-09 04:18:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union_find.yosupo.unionfind.test.cpp
documentation_of: lib/union_find.hpp
layout: document
redirect_from:
- /library/lib/union_find.hpp
- /library/lib/union_find.hpp.html
title: lib/union_find.hpp
---
