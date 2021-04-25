---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
  bundledCode: "#line 1 \"test/lazy_segment_tree.aoj.DSL_2_G.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\n\n#include\
    \ <iostream>\n#line 1 \"lib/lazy_segment_tree.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n#include <functional>\n\ntemplate<typename Monoid, typename\
    \ Operator>\nclass LazySegmentTree {\npublic:\n    // mono_product(a, b)\n   \
    \ using MonoidProduct = std::function<Monoid(Monoid, Monoid)>;\n\n    // op_product(p,\
    \ q)(a) = p(q(a)) (not q(p(a)))\n    using OperatorProduct = std::function<Operator(Operator,\
    \ Operator)>;\n\n    // act(p, n, a) = (p, n)(a)\n    // n: Length of the range.\n\
    \    using Actor = std::function<Monoid(Operator, int, Monoid)>;\n\n    LazySegmentTree(int\
    \ n,\n        const MonoidProduct &mono_product, Monoid init_mono,\n        const\
    \ OperatorProduct &op_product, Operator init_op,\n        const Actor &act)\n\
    \        : mono_product(mono_product), init_mono(init_mono)\n        , op_product(op_product),\
    \ init_op(init_op)\n        , act(act) {\n\n        num = 1;\n        while (num\
    \ < n) num *= 2;\n        dat_mono = std::vector<Monoid>(2 * num, init_mono);\n\
    \        dat_op = std::vector<Operator>(2 * num, init_op);\n    }\n\n    LazySegmentTree(const\
    \ std::vector<Monoid> &m,\n        const MonoidProduct &mono_product, Monoid init_mono,\n\
    \        const OperatorProduct &op_product, Operator init_op,\n        const Actor\
    \ &act)\n        : LazySegmentTree(m.size(), mono_product, init_mono,\n      \
    \      op_product, init_op, act) {\n\n        int n = m.size();\n        for (int\
    \ i = 0; i < n; i++) {\n            dat_mono[num - 1 + i] = m[i];\n        }\n\
    \        for (int i = num - 2; i >= 0; i--) {\n            dat_mono[i]\n     \
    \           = mono_product(dat_mono[2 * i + 1], dat_mono[2 * i + 2]);\n      \
    \  }\n    }\n\n    // Apply the operator q to the range [a, b).\n    // k: The\
    \ index of the node.\n    // Call like apply(q, a, b)\n    void apply(Operator\
    \ q, int a, int b,\n        int k = 0, int left = 0, int right = -1) {\n\n   \
    \     if (right < 0) right = num;\n        if (right <= a || b <= left) return;\n\
    \        if (a <= left && right <= b) {\n            dat_mono[k] = act(q, right\
    \ - left, dat_mono[k]);\n            dat_op[k] = op_product(q, dat_op[k]);\n \
    \           return;\n        }\n        apply(dat_op[k], left, left + (right -\
    \ left) / 2,\n            2 * k + 1, left, left + (right - left) / 2); // Left\
    \ side\n        apply(dat_op[k], left + (right - left) / 2, right,\n         \
    \   2 * k + 2, left + (right - left) / 2, right); // Right side\n        dat_op[k]\
    \ = init_op;\n        apply(q, a, b,\n            2 * k + 1, left, left + (right\
    \ - left) / 2); // Left side\n        apply(q, a, b,\n            2 * k + 2, left\
    \ + (right - left) / 2, right); // Right side\n        dat_mono[k]\n         \
    \   = mono_product(dat_mono[2 * k + 1], dat_mono[2 * k + 2]);\n    }\n\n    //\
    \ Get the value of the range [a, b).\n    // k: The index of the node.\n    //\
    \ [left, right): The range corresponds to the k-th node.\n    // Call like getval(a,\
    \ b).\n    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1)\
    \ {\n        if (right < 0) right = num;\n        if (right <= a || b <= left)\
    \ return init_mono;\n        if (a <= left && right <= b) return dat_mono[k];\n\
    \        Monoid vleft = getval(a, b,\n            2 * k + 1, left, left + (right\
    \ - left) / 2); // Left side\n        Monoid vright = getval(a, b,\n         \
    \   2 * k + 2, left + (right - left) / 2, right); // Right side\n        return\
    \ act(dat_op[k],\n            std::max(0, std::min(b, right) - std::max(a, left)),\n\
    \            mono_product(vleft, vright));\n    }\n\nprivate:\n    int num;\n\
    \    std::vector<Monoid> dat_mono;\n    std::vector<Operator> dat_op;\n\n    const\
    \ MonoidProduct mono_product;\n    const Monoid init_mono;\n    const OperatorProduct\
    \ op_product;\n    const Operator init_op;\n    const Actor act;\n};\n\n// Example:\
    \ Range-Add Range-Sum Segment Tree\nLazySegmentTree<long long, long long>\nmake_rars_segment_tree(const\
    \ std::vector<long long> &init) {\n    auto mono_product = [](long long a, long\
    \ long b) { return a + b; };\n    const long long init_mono = 0;\n    auto op_product\
    \ = [](long long p, long long q) { return p + q; };\n    const long long init_op\
    \ = 0;\n    auto act = [](long long p, int n, long long a) { return p*n + a; };\n\
    \    return LazySegmentTree<long long, long long>(\n        init, mono_product,\
    \ init_mono, op_product, init_op, act);\n}\n\n\n#line 5 \"test/lazy_segment_tree.aoj.DSL_2_G.test.cpp\"\
    \n\nint main() {\n    int n, q; std::cin >> n >> q;\n    auto seg = make_rars_segment_tree(std::vector<long\
    \ long>(n, 0));\n    for (int i = 0; i < q; i++) {\n        int com, s, t; std::cin\
    \ >> com >> s >> t;\n        s--;\n        if (com) {\n            std::cout <<\
    \ seg.getval(s, t) << std::endl;\n        }\n        else {\n            int x;\
    \ std::cin >> x;\n            seg.apply(x, s, t);\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include <iostream>\n#include \"../lib/lazy_segment_tree.hpp\"\n\nint main()\
    \ {\n    int n, q; std::cin >> n >> q;\n    auto seg = make_rars_segment_tree(std::vector<long\
    \ long>(n, 0));\n    for (int i = 0; i < q; i++) {\n        int com, s, t; std::cin\
    \ >> com >> s >> t;\n        s--;\n        if (com) {\n            std::cout <<\
    \ seg.getval(s, t) << std::endl;\n        }\n        else {\n            int x;\
    \ std::cin >> x;\n            seg.apply(x, s, t);\n        }\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - lib/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/lazy_segment_tree.aoj.DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 19:52:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy_segment_tree.aoj.DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_segment_tree.aoj.DSL_2_G.test.cpp
- /verify/test/lazy_segment_tree.aoj.DSL_2_G.test.cpp.html
title: test/lazy_segment_tree.aoj.DSL_2_G.test.cpp
---
