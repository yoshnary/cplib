---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/heavy_light_decomposition.hpp
    title: lib/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: lib/lazy_segment_tree.hpp
    title: lib/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include <iostream>\n#line 1 \"lib/heavy_light_decomposition.hpp\"\n\n\n\n\
    #include <vector>\n\nstruct HLDecomposition {\n    using Edge = std::vector<std::vector<int>>;\n\
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
    \ c, v);\n        }\n    }\n};\n\n\n#line 1 \"lib/lazy_segment_tree.hpp\"\n\n\n\
    \n#line 5 \"lib/lazy_segment_tree.hpp\"\n#include <algorithm>\n#include <functional>\n\
    \ntemplate<typename Monoid, typename Operator>\nclass LazySegmentTree {\npublic:\n\
    \    // mono_product(a, b)\n    using MonoidProduct = std::function<Monoid(Monoid,\
    \ Monoid)>;\n\n    // op_product(p, q)(a) = p(q(a)) (not q(p(a)))\n    using OperatorProduct\
    \ = std::function<Operator(Operator, Operator)>;\n\n    // act(p, n, a) = (p,\
    \ n)(a)\n    // n: Length of the range.\n    using Actor = std::function<Monoid(Operator,\
    \ int, Monoid)>;\n\n    LazySegmentTree(int n,\n        const MonoidProduct &mono_product,\
    \ Monoid init_mono,\n        const OperatorProduct &op_product, Operator init_op,\n\
    \        const Actor &act)\n        : mono_product(mono_product), init_mono(init_mono)\n\
    \        , op_product(op_product), init_op(init_op)\n        , act(act) {\n\n\
    \        num = 1;\n        while (num < n) num *= 2;\n        dat_mono = std::vector<Monoid>(2\
    \ * num, init_mono);\n        dat_op = std::vector<Operator>(2 * num, init_op);\n\
    \    }\n\n    LazySegmentTree(const std::vector<Monoid> &m,\n        const MonoidProduct\
    \ &mono_product, Monoid init_mono,\n        const OperatorProduct &op_product,\
    \ Operator init_op,\n        const Actor &act)\n        : LazySegmentTree(m.size(),\
    \ mono_product, init_mono,\n            op_product, init_op, act) {\n\n      \
    \  int n = m.size();\n        for (int i = 0; i < n; i++) {\n            dat_mono[num\
    \ - 1 + i] = m[i];\n        }\n        for (int i = num - 2; i >= 0; i--) {\n\
    \            dat_mono[i]\n                = mono_product(dat_mono[2 * i + 1],\
    \ dat_mono[2 * i + 2]);\n        }\n    }\n\n    // Apply the operator q to the\
    \ range [a, b).\n    // k: The index of the node.\n    // Call like apply(q, a,\
    \ b)\n    void apply(Operator q, int a, int b,\n        int k = 0, int left =\
    \ 0, int right = -1) {\n\n        if (right < 0) right = num;\n        if (right\
    \ <= a || b <= left) return;\n        if (a <= left && right <= b) {\n       \
    \     dat_mono[k] = act(q, right - left, dat_mono[k]);\n            dat_op[k]\
    \ = op_product(q, dat_op[k]);\n            return;\n        }\n        apply(dat_op[k],\
    \ left, left + (right - left) / 2,\n            2 * k + 1, left, left + (right\
    \ - left) / 2); // Left side\n        apply(dat_op[k], left + (right - left) /\
    \ 2, right,\n            2 * k + 2, left + (right - left) / 2, right); // Right\
    \ side\n        dat_op[k] = init_op;\n        apply(q, a, b,\n            2 *\
    \ k + 1, left, left + (right - left) / 2); // Left side\n        apply(q, a, b,\n\
    \            2 * k + 2, left + (right - left) / 2, right); // Right side\n   \
    \     dat_mono[k]\n            = mono_product(dat_mono[2 * k + 1], dat_mono[2\
    \ * k + 2]);\n    }\n\n    // Get the value of the range [a, b).\n    // k: The\
    \ index of the node.\n    // [left, right): The range corresponds to the k-th\
    \ node.\n    // Call like getval(a, b).\n    Monoid getval(int a, int b, int k\
    \ = 0, int left = 0, int right = -1) {\n        if (right < 0) right = num;\n\
    \        if (right <= a || b <= left) return init_mono;\n        if (a <= left\
    \ && right <= b) return dat_mono[k];\n        Monoid vleft = getval(a, b,\n  \
    \          2 * k + 1, left, left + (right - left) / 2); // Left side\n       \
    \ Monoid vright = getval(a, b,\n            2 * k + 2, left + (right - left) /\
    \ 2, right); // Right side\n        return act(dat_op[k],\n            std::max(0,\
    \ std::min(b, right) - std::max(a, left)),\n            mono_product(vleft, vright));\n\
    \    }\n\nprivate:\n    int num;\n    std::vector<Monoid> dat_mono;\n    std::vector<Operator>\
    \ dat_op;\n\n    const MonoidProduct mono_product;\n    const Monoid init_mono;\n\
    \    const OperatorProduct op_product;\n    const Operator init_op;\n    const\
    \ Actor act;\n};\n\n// Example: Range-Add Range-Sum Segment Tree\nLazySegmentTree<long\
    \ long, long long>\nmake_rars_segment_tree(const std::vector<long long> &init)\
    \ {\n    auto mono_product = [](long long a, long long b) { return a + b; };\n\
    \    const long long init_mono = 0;\n    auto op_product = [](long long p, long\
    \ long q) { return p + q; };\n    const long long init_op = 0;\n    auto act =\
    \ [](long long p, int n, long long a) { return p*n + a; };\n    return LazySegmentTree<long\
    \ long, long long>(\n        init, mono_product, init_mono, op_product, init_op,\
    \ act);\n}\n\n\n#line 6 \"test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp\"\
    \n\nint main() {\n    int n; std::cin >> n;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    for (int i = 0; i < n; i++) {\n        int k; std::cin >> k;\n\
    \        for (int j = 0; j < k; j++) {\n            int c; std::cin >> c;\n  \
    \          edg[i].push_back(c);\n            edg[c].push_back(i);\n        }\n\
    \    }\n    HLDecomposition hld(edg, 0);\n    LazySegmentTree<long long, long\
    \ long>\n        seg(n, std::plus<long long>(), 0, std::plus<long long>(), 0,\n\
    \            [](long long p, int n, long long a){return p*n + a;});\n    auto\
    \ sum_query = [&](int u) {\n        long long ret = 0;\n        while (u > 0)\
    \ {\n            ret += seg.getval(hld.pos[hld.left[u]], hld.pos[u] + 1);\n  \
    \          u = hld.par[hld.left[u]];\n        }\n        return ret;\n    };\n\
    \    auto add_query = [&](int u, long long w) {\n        while (u > 0) {\n   \
    \         seg.apply(w, hld.pos[hld.left[u]], hld.pos[u] + 1);\n            u =\
    \ hld.par[hld.left[u]];\n        }\n        seg.apply(-seg.getval(hld.pos[0],\
    \ hld.pos[0] + 1), hld.pos[0], hld.pos[0] + 1);\n    };\n    int q; std::cin >>\
    \ q;\n    while (q--) {\n        int com, v; std::cin >> com >> v;\n        if\
    \ (com) {\n            std::cout << sum_query(v) << std::endl;\n        }\n  \
    \      else {\n            long long w; std::cin >> w;\n            add_query(v,\
    \ w);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include <iostream>\n#include \"../lib/heavy_light_decomposition.hpp\"\n#include\
    \ \"../lib/lazy_segment_tree.hpp\"\n\nint main() {\n    int n; std::cin >> n;\n\
    \    std::vector<std::vector<int>> edg(n);\n    for (int i = 0; i < n; i++) {\n\
    \        int k; std::cin >> k;\n        for (int j = 0; j < k; j++) {\n      \
    \      int c; std::cin >> c;\n            edg[i].push_back(c);\n            edg[c].push_back(i);\n\
    \        }\n    }\n    HLDecomposition hld(edg, 0);\n    LazySegmentTree<long\
    \ long, long long>\n        seg(n, std::plus<long long>(), 0, std::plus<long long>(),\
    \ 0,\n            [](long long p, int n, long long a){return p*n + a;});\n   \
    \ auto sum_query = [&](int u) {\n        long long ret = 0;\n        while (u\
    \ > 0) {\n            ret += seg.getval(hld.pos[hld.left[u]], hld.pos[u] + 1);\n\
    \            u = hld.par[hld.left[u]];\n        }\n        return ret;\n    };\n\
    \    auto add_query = [&](int u, long long w) {\n        while (u > 0) {\n   \
    \         seg.apply(w, hld.pos[hld.left[u]], hld.pos[u] + 1);\n            u =\
    \ hld.par[hld.left[u]];\n        }\n        seg.apply(-seg.getval(hld.pos[0],\
    \ hld.pos[0] + 1), hld.pos[0], hld.pos[0] + 1);\n    };\n    int q; std::cin >>\
    \ q;\n    while (q--) {\n        int com, v; std::cin >> com >> v;\n        if\
    \ (com) {\n            std::cout << sum_query(v) << std::endl;\n        }\n  \
    \      else {\n            long long w; std::cin >> w;\n            add_query(v,\
    \ w);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/heavy_light_decomposition.hpp
  - lib/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 20:19:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
- /verify/test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp.html
title: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp
---
