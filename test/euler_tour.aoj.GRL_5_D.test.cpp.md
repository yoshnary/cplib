---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/euler_tour.hpp
    title: lib/euler_tour.hpp
  - icon: ':heavy_check_mark:'
    path: lib/segment_tree.hpp
    title: lib/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
  bundledCode: "#line 1 \"test/euler_tour.aoj.GRL_5_D.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\n\n#include\
    \ <iostream>\n#line 1 \"lib/euler_tour.hpp\"\n\n\n\n#include <vector>\n\n// Vertex\
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
    \ = id++;\n    }\n};\n\n\n#line 1 \"lib/segment_tree.hpp\"\n\n\n\n#line 5 \"lib/segment_tree.hpp\"\
    \n#include <algorithm>\n#include <functional>\n\ntemplate<typename Monoid>\nclass\
    \ SegmentTree {\npublic:\n    using Operator = std::function<Monoid(Monoid, Monoid)>;\n\
    \n    SegmentTree(int n, const Operator &op, const Monoid init)\n        : op(op),\
    \ init(init) {\n\n        num = 1;\n        while (num < n) num *= 2;\n      \
    \  dat.resize(2 * num, init);\n    }\n\n    SegmentTree(const std::vector<Monoid>\
    \ &m,\n        const Operator &op, const Monoid init)\n        : SegmentTree(m.size(),\
    \ op, init) {\n\n        int n = m.size();\n        for (int i = 0; i < n; i++)\
    \ {\n            dat[num - 1 + i] = m[i];\n        }\n        for (int i = num\
    \ - 2; i >= 0; i--) {\n            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);\n\
    \        }\n    }\n\n    // Update the k-th value (0-indexed) to a.\n    void\
    \ update(int k, Monoid a) {\n        k += num - 1;\n        dat[k] = a;\n    \
    \    while (k > 0) {\n            k = (k - 1) / 2;\n            dat[k] = op(dat[2\
    \ * k + 1], dat[2 * k + 2]);\n        }\n    }\n\n    // Get the value of the\
    \ range [a, b).\n    // k: The index of the node.\n    // [left, right): The range\
    \ corresponds to the k-th node.\n    // Call like getval(a, b).\n    Monoid getval(int\
    \ a, int b, int k = 0, int left = 0, int right = -1) {\n        if (right < 0)\
    \ right = num;\n        if (right <= a || b <= left) return init;\n        if\
    \ (a <= left && right <= b) return dat[k];\n        Monoid vleft = getval(\n \
    \           a, b, 2 * k + 1, left, left + (right - left) / 2);\n        Monoid\
    \ vright = getval(\n            a, b, 2 * k + 2, left + (right - left) / 2, right);\n\
    \        return op(vleft, vright);\n    }\n\nprivate:\n    int num;\n    std::vector<Monoid>\
    \ dat;\n    const Operator op;\n    const Monoid init;\n};\n\n// Example: Range-Minimum\
    \ Point-Update Segment Tree\nSegmentTree<int> make_rmpu_segment_tree(const std::vector<int>\
    \ &init) {\n    const int INF = 1e9 + 2;\n    auto op = [](int a, int b) { return\
    \ std::min(a, b); };\n    return SegmentTree<int>(init, op, INF);\n}\n\n\n#line\
    \ 6 \"test/euler_tour.aoj.GRL_5_D.test.cpp\"\n\nint main() {\n    int n; std::cin\
    \ >> n;\n    std::vector<std::vector<int>> edg(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        int k; std::cin >> k;\n        for (int j = 0; j < k; j++) {\n\
    \            int c; std::cin >> c;\n            edg[i].push_back(c);\n       \
    \     edg[c].push_back(i);\n        }\n    }\n    EulerTourE et(edg, 0);\n   \
    \ SegmentTree<long long> seg(2*n, std::plus<long long>(), 0);\n    int q; std::cin\
    \ >> q;\n    while (q--) {\n        int com, v; std::cin >> com >> v;\n      \
    \  if (com) {\n            std::cout << seg.getval(0, et.left[v] + 1) << std::endl;\n\
    \        }\n        else {\n            int w; std::cin >> w;\n            long\
    \ long val = seg.getval(et.left[v], et.left[v] + 1) + w;\n            seg.update(et.left[v],\
    \ val);\n            seg.update(et.right[v], -val);\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include <iostream>\n#include \"../lib/euler_tour.hpp\"\n#include \"../lib/segment_tree.hpp\"\
    \n\nint main() {\n    int n; std::cin >> n;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    for (int i = 0; i < n; i++) {\n        int k; std::cin >> k;\n\
    \        for (int j = 0; j < k; j++) {\n            int c; std::cin >> c;\n  \
    \          edg[i].push_back(c);\n            edg[c].push_back(i);\n        }\n\
    \    }\n    EulerTourE et(edg, 0);\n    SegmentTree<long long> seg(2*n, std::plus<long\
    \ long>(), 0);\n    int q; std::cin >> q;\n    while (q--) {\n        int com,\
    \ v; std::cin >> com >> v;\n        if (com) {\n            std::cout << seg.getval(0,\
    \ et.left[v] + 1) << std::endl;\n        }\n        else {\n            int w;\
    \ std::cin >> w;\n            long long val = seg.getval(et.left[v], et.left[v]\
    \ + 1) + w;\n            seg.update(et.left[v], val);\n            seg.update(et.right[v],\
    \ -val);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/euler_tour.hpp
  - lib/segment_tree.hpp
  isVerificationFile: true
  path: test/euler_tour.aoj.GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2020-05-11 17:18:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/euler_tour.aoj.GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/euler_tour.aoj.GRL_5_D.test.cpp
- /verify/test/euler_tour.aoj.GRL_5_D.test.cpp.html
title: test/euler_tour.aoj.GRL_5_D.test.cpp
---
