---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
  bundledCode: "#line 1 \"test/segment_tree.aoj.DSL_2_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\n\n#include\
    \ <iostream>\n#line 1 \"lib/segment_tree.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <functional>\n\ntemplate<typename Monoid>\nclass SegmentTree\
    \ {\npublic:\n    using Operator = std::function<Monoid(Monoid, Monoid)>;\n\n\
    \    SegmentTree(int n, const Operator &op, const Monoid init)\n        : op(op),\
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
    \ 5 \"test/segment_tree.aoj.DSL_2_A.test.cpp\"\n\nint main() {\n    int n, q;\
    \ std::cin >> n >> q;\n    auto op = [](long long a, long long b) { return std::min(a,\
    \ b); };\n    SegmentTree<long long>\n        seg(std::vector<long long>(n, (1LL\
    \ << 31) - 1),\n            op, (1LL << 31) - 1);\n    for (int i = 0; i < q;\
    \ i++) {\n        int com, x, y; std::cin >> com >> x >> y;\n        if (com)\
    \ std::cout << seg.getval(x, y + 1) << std::endl;\n        else seg.update(x,\
    \ y);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\
    \n\n#include <iostream>\n#include \"../lib/segment_tree.hpp\"\n\nint main() {\n\
    \    int n, q; std::cin >> n >> q;\n    auto op = [](long long a, long long b)\
    \ { return std::min(a, b); };\n    SegmentTree<long long>\n        seg(std::vector<long\
    \ long>(n, (1LL << 31) - 1),\n            op, (1LL << 31) - 1);\n    for (int\
    \ i = 0; i < q; i++) {\n        int com, x, y; std::cin >> com >> x >> y;\n  \
    \      if (com) std::cout << seg.getval(x, y + 1) << std::endl;\n        else\
    \ seg.update(x, y);\n    }\n    return 0;\n}\n"
  dependsOn:
  - lib/segment_tree.hpp
  isVerificationFile: true
  path: test/segment_tree.aoj.DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-11 17:18:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment_tree.aoj.DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/segment_tree.aoj.DSL_2_A.test.cpp
- /verify/test/segment_tree.aoj.DSL_2_A.test.cpp.html
title: test/segment_tree.aoj.DSL_2_A.test.cpp
---
