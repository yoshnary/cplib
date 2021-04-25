---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/union_find.hpp
    title: lib/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/union_find.yosupo.unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <iostream>\n#line\
    \ 1 \"lib/union_find.hpp\"\n\n\n\n#include <vector>\n\nclass UnionFind {\npublic:\n\
    \    UnionFind(int n) : par(n, -1), ran(n, -1) {}\n\n    void unite(int x, int\
    \ y) {\n        x = find_root(x);\n        y = find_root(y);\n        if (x ==\
    \ y) return;\n\n        if (ran[x] < ran[y]) {\n            par[find_root(y)]\
    \ += par[find_root(x)];\n            par[x] = y;\n        }\n        else {\n\
    \            par[find_root(x)] += par[find_root(y)];\n            par[y] = x;\n\
    \            if (ran[x] == ran[y]) ran[x]++;\n        }\n    }\n\n    int size(int\
    \ x) {\n        return -par[find_root(x)];\n    }\n\n    bool same(int x, int\
    \ y) {\n        return find_root(x) == find_root(y);\n    }\n\n    int find_root(int\
    \ x) {\n        if (par[x] < 0) {\n            return x;\n        }\n        else\
    \ {\n            return par[x] = find_root(par[x]);\n        }\n    }\n\nprivate:\n\
    \    std::vector<int> par, ran;\n};\n\n\n#line 5 \"test/union_find.yosupo.unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q; std::cin >> n >> q;\n    UnionFind uf(n);\n  \
    \  for (int i = 0; i < q; i++) {\n        int t, u, v; std::cin >> t >> u >> v;\n\
    \        if (t) std::cout << uf.same(u, v) << std::endl;\n        else uf.unite(u,\
    \ v);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"../lib/union_find.hpp\"\n\nint main() {\n    int n, q;\
    \ std::cin >> n >> q;\n    UnionFind uf(n);\n    for (int i = 0; i < q; i++) {\n\
    \        int t, u, v; std::cin >> t >> u >> v;\n        if (t) std::cout << uf.same(u,\
    \ v) << std::endl;\n        else uf.unite(u, v);\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/union_find.hpp
  isVerificationFile: true
  path: test/union_find.yosupo.unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 18:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find.yosupo.unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/union_find.yosupo.unionfind.test.cpp
- /verify/test/union_find.yosupo.unionfind.test.cpp.html
title: test/union_find.yosupo.unionfind.test.cpp
---
