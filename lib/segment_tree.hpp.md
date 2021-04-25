---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/euler_tour.aoj.GRL_5_D.test.cpp
    title: test/euler_tour.aoj.GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.aoj.3037.test.cpp
    title: test/heavy_light_decomposition.aoj.3037.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.aoj.DSL_2_A.test.cpp
    title: test/segment_tree.aoj.DSL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/segment_tree.hpp\"\n\n\n\n#include <vector>\n#include\
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
    \ std::min(a, b); };\n    return SegmentTree<int>(init, op, INF);\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_SEGMENT_TREE_H_\n#define CPLIB_LIB_SEGMENT_TREE_H_\n\n\
    #include <vector>\n#include <algorithm>\n#include <functional>\n\ntemplate<typename\
    \ Monoid>\nclass SegmentTree {\npublic:\n    using Operator = std::function<Monoid(Monoid,\
    \ Monoid)>;\n\n    SegmentTree(int n, const Operator &op, const Monoid init)\n\
    \        : op(op), init(init) {\n\n        num = 1;\n        while (num < n) num\
    \ *= 2;\n        dat.resize(2 * num, init);\n    }\n\n    SegmentTree(const std::vector<Monoid>\
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
    \ std::min(a, b); };\n    return SegmentTree<int>(init, op, INF);\n}\n\n#endif\
    \  // CPLIB_LIB_SEGMENT_TREE_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment_tree.hpp
  requiredBy: []
  timestamp: '2020-05-11 17:18:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree.aoj.DSL_2_A.test.cpp
  - test/euler_tour.aoj.GRL_5_D.test.cpp
  - test/heavy_light_decomposition.aoj.3037.test.cpp
documentation_of: lib/segment_tree.hpp
layout: document
redirect_from:
- /library/lib/segment_tree.hpp
- /library/lib/segment_tree.hpp.html
title: lib/segment_tree.hpp
---
