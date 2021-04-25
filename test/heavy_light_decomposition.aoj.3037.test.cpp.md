---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/heavy_light_decomposition.hpp
    title: lib/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: lib/lowest_common_ancestor.hpp
    title: lib/lowest_common_ancestor.hpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037
  bundledCode: "#line 1 \"test/heavy_light_decomposition.aoj.3037.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037\"\n\n\
    #include <iostream>\n#include <vector>\n#include <numeric>\n#include <queue>\n\
    #include <utility>\n#line 1 \"lib/heavy_light_decomposition.hpp\"\n\n\n\n#line\
    \ 5 \"lib/heavy_light_decomposition.hpp\"\n\nstruct HLDecomposition {\n    using\
    \ Edge = std::vector<std::vector<int>>;\n\n    // USAGE: pos[par[left[v]]], pos[left[v]]\n\
    \n    // pos[v]: position in a line of the vertex v\n    std::vector<int> pos;\n\
    \n    // left[v]: the leftmost vertex\n    // of the connected component including\
    \ v.\n    // If left[v] == v, it means v is itself\n    // the leftmost vertex.\n\
    \    std::vector<int> left;\n\n    // par[v]: parent of the vertex v.\n    //\
    \ If par[v] == v, it means v is the root.\n    std::vector<int> par;\n\n    HLDecomposition(const\
    \ Edge &edg, int root)\n        : pos(edg.size())\n        , left(edg.size(),\
    \ -1)\n        , par(edg.size(), -1)\n        , weight(edg.size(), 1) {\n\n  \
    \      build_weight(edg, root);\n        left[root] = par[root] = root;\n    \
    \    decompose(edg, root);\n    }\n\nprivate:\n    std::vector<int> weight;\n\n\
    \    int build_weight(const Edge &edg, int v, int prev = -1) {\n        for (int\
    \ c : edg[v]) {\n            if (c == prev) continue;\n            weight[v] +=\
    \ build_weight(edg, c, v);\n        }\n        return weight[v];\n    }\n\n  \
    \  void decompose(const Edge &edg, int v, int prev = -1) {\n        static int\
    \ cnt = 0;\n\n        pos[v] = cnt++;\n        int max_weight = 0, max_id = -1;\n\
    \        for (int c : edg[v]) {\n            if (c == prev) continue;\n      \
    \      if (weight[c] > max_weight) {\n                max_weight = weight[c];\n\
    \                max_id = c;\n            }\n        }\n        if (max_id ==\
    \ -1) return;\n\n        par[max_id] = v;\n        left[max_id] = left[v];\n \
    \       decompose(edg, max_id, v);\n\n        for (int c : edg[v]) {\n       \
    \     if (c == prev || c == max_id) continue;\n            par[c] = v;\n     \
    \       left[c] = c;\n            decompose(edg, c, v);\n        }\n    }\n};\n\
    \n\n#line 1 \"lib/lowest_common_ancestor.hpp\"\n\n\n\n#line 6 \"lib/lowest_common_ancestor.hpp\"\
    \n\nstruct LowestCommonAncestor {\n    using Edge = std::vector<std::vector<int>>;\n\
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
    \ = anc[i - 1][anc[i - 1][j]];\n            }\n        }\n    }\n};\n\n\n#line\
    \ 1 \"lib/segment_tree.hpp\"\n\n\n\n#line 5 \"lib/segment_tree.hpp\"\n#include\
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
    \ 11 \"test/heavy_light_decomposition.aoj.3037.test.cpp\"\n\nlong long chmax(long\
    \ long &a, long long b) {\n    return a = std::max(a, b);\n}\n\nint main() {\n\
    \    int n; std::cin >> n;\n    std::vector<std::vector<int>> edg(n);\n    std::vector<long\
    \ long> w(n);\n    for (int i = 0; i < n; i++) std::cin >> w[i];\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        int u, v; std::cin >> u >> v;\n        u--;\
    \ v--;\n        edg[u].push_back(v);\n        edg[v].push_back(u);\n    }\n  \
    \  long long sum = std::accumulate(w.begin(), w.end(), 0LL);\n    LowestCommonAncestor\
    \ lca(edg, 0);\n    HLDecomposition hld(edg, 0);\n    std::vector<long long> init(n),\
    \ subsize(n);\n    std::vector<std::priority_queue<std::pair<long long, int>>>\
    \ ques(n);\n    auto initialize = [&](\n        const auto &self, int pos = 0,\
    \ int prev = -1) -> long long {\n\n        subsize[pos] = w[pos];\n        for\
    \ (int c : edg[pos]) {\n            if (c == prev) continue;\n            long\
    \ long res = self(self, c, pos);\n            subsize[pos] += res;\n         \
    \   ques[pos].emplace(res, c);\n        }\n        for (int c : edg[pos]) {\n\
    \            if (c == prev) continue;\n            if (ques[pos].top().second\
    \ == c) {\n                auto p = ques[pos].top();\n                ques[pos].pop();\n\
    \                if (!ques[pos].empty())\n                    init[hld.pos[c]]\
    \ = ques[pos].top().first;\n                ques[pos].push(p);\n            }\n\
    \            else {\n                init[hld.pos[c]] = ques[pos].top().first;\n\
    \            }\n        }\n        return subsize[pos];\n    };\n    initialize(initialize);\n\
    \    SegmentTree<long long>\n        seg(init, [](long long a, long long b){return\
    \ std::max(a, b);}, 0);\n    auto prev = [&](const int anc, int a) {\n       \
    \ if (anc == a) return anc;\n        for (int i = 29; i >= 0; i--) {\n       \
    \     if (((lca.depth[a] - (lca.depth[anc] + 1)) >> i) & 1) {\n              \
    \  a = lca.anc[i][a];\n            }\n        }\n        return a;\n    };\n \
    \   auto func = [&](const int targ, int a) {\n        long long ret = 0;\n   \
    \     while (hld.pos[hld.left[a]] > hld.pos[targ]) {\n            chmax(ret, seg.getval(hld.pos[hld.left[a]],\
    \ hld.pos[a] + 1));\n            a = hld.par[hld.left[a]];\n        }\n      \
    \  chmax(ret, seg.getval(hld.pos[targ] + 1, hld.pos[a] + 1));\n        return\
    \ ret;\n    };\n    std::vector<std::pair<long long, int>> buf;\n    auto handle\
    \ = [&](int anc, int a, int preva, int prevb) {\n\n        long long ret = 0;\n\
    \        if (anc != a) {\n            chmax(ret, func(preva, a));\n          \
    \  if (!ques[a].empty()) chmax(ret, ques[a].top().first);\n            buf.clear();\n\
    \            while (!ques[anc].empty()\n                && (ques[anc].top().second\
    \ == preva\n                || ques[anc].top().second == prevb)) {\n\n       \
    \         buf.push_back(ques[anc].top());\n                ques[anc].pop();\n\
    \            }\n            if (!ques[anc].empty()) chmax(ret, ques[anc].top().first);\n\
    \            for (auto &p : buf) ques[anc].push(p);\n        }\n        else {\n\
    \            chmax(ret, sum - subsize[a]);\n        }\n        return ret;\n \
    \   };\n    int q; std::cin >> q;\n    while (q--) {\n        int a, b; std::cin\
    \ >> a >> b;\n        a--; b--;\n        if (a == b) {\n            std::cout\
    \ << std::max(\n                ques[a].top().first, sum - subsize[a]) << std::endl;\n\
    \            continue;\n        }\n        int anc = lca.query(a, b);\n      \
    \  int preva = prev(anc, a), prevb = prev(anc, b);\n        long long ans = std::max({\n\
    \            sum - subsize[anc],\n            handle(anc, a, preva, prevb),\n\
    \            handle(anc, b, prevb, preva)});\n        std::cout << ans << std::endl;\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037\"\
    \n\n#include <iostream>\n#include <vector>\n#include <numeric>\n#include <queue>\n\
    #include <utility>\n#include \"../lib/heavy_light_decomposition.hpp\"\n#include\
    \ \"../lib/lowest_common_ancestor.hpp\"\n#include \"../lib/segment_tree.hpp\"\n\
    \nlong long chmax(long long &a, long long b) {\n    return a = std::max(a, b);\n\
    }\n\nint main() {\n    int n; std::cin >> n;\n    std::vector<std::vector<int>>\
    \ edg(n);\n    std::vector<long long> w(n);\n    for (int i = 0; i < n; i++) std::cin\
    \ >> w[i];\n    for (int i = 0; i < n - 1; i++) {\n        int u, v; std::cin\
    \ >> u >> v;\n        u--; v--;\n        edg[u].push_back(v);\n        edg[v].push_back(u);\n\
    \    }\n    long long sum = std::accumulate(w.begin(), w.end(), 0LL);\n    LowestCommonAncestor\
    \ lca(edg, 0);\n    HLDecomposition hld(edg, 0);\n    std::vector<long long> init(n),\
    \ subsize(n);\n    std::vector<std::priority_queue<std::pair<long long, int>>>\
    \ ques(n);\n    auto initialize = [&](\n        const auto &self, int pos = 0,\
    \ int prev = -1) -> long long {\n\n        subsize[pos] = w[pos];\n        for\
    \ (int c : edg[pos]) {\n            if (c == prev) continue;\n            long\
    \ long res = self(self, c, pos);\n            subsize[pos] += res;\n         \
    \   ques[pos].emplace(res, c);\n        }\n        for (int c : edg[pos]) {\n\
    \            if (c == prev) continue;\n            if (ques[pos].top().second\
    \ == c) {\n                auto p = ques[pos].top();\n                ques[pos].pop();\n\
    \                if (!ques[pos].empty())\n                    init[hld.pos[c]]\
    \ = ques[pos].top().first;\n                ques[pos].push(p);\n            }\n\
    \            else {\n                init[hld.pos[c]] = ques[pos].top().first;\n\
    \            }\n        }\n        return subsize[pos];\n    };\n    initialize(initialize);\n\
    \    SegmentTree<long long>\n        seg(init, [](long long a, long long b){return\
    \ std::max(a, b);}, 0);\n    auto prev = [&](const int anc, int a) {\n       \
    \ if (anc == a) return anc;\n        for (int i = 29; i >= 0; i--) {\n       \
    \     if (((lca.depth[a] - (lca.depth[anc] + 1)) >> i) & 1) {\n              \
    \  a = lca.anc[i][a];\n            }\n        }\n        return a;\n    };\n \
    \   auto func = [&](const int targ, int a) {\n        long long ret = 0;\n   \
    \     while (hld.pos[hld.left[a]] > hld.pos[targ]) {\n            chmax(ret, seg.getval(hld.pos[hld.left[a]],\
    \ hld.pos[a] + 1));\n            a = hld.par[hld.left[a]];\n        }\n      \
    \  chmax(ret, seg.getval(hld.pos[targ] + 1, hld.pos[a] + 1));\n        return\
    \ ret;\n    };\n    std::vector<std::pair<long long, int>> buf;\n    auto handle\
    \ = [&](int anc, int a, int preva, int prevb) {\n\n        long long ret = 0;\n\
    \        if (anc != a) {\n            chmax(ret, func(preva, a));\n          \
    \  if (!ques[a].empty()) chmax(ret, ques[a].top().first);\n            buf.clear();\n\
    \            while (!ques[anc].empty()\n                && (ques[anc].top().second\
    \ == preva\n                || ques[anc].top().second == prevb)) {\n\n       \
    \         buf.push_back(ques[anc].top());\n                ques[anc].pop();\n\
    \            }\n            if (!ques[anc].empty()) chmax(ret, ques[anc].top().first);\n\
    \            for (auto &p : buf) ques[anc].push(p);\n        }\n        else {\n\
    \            chmax(ret, sum - subsize[a]);\n        }\n        return ret;\n \
    \   };\n    int q; std::cin >> q;\n    while (q--) {\n        int a, b; std::cin\
    \ >> a >> b;\n        a--; b--;\n        if (a == b) {\n            std::cout\
    \ << std::max(\n                ques[a].top().first, sum - subsize[a]) << std::endl;\n\
    \            continue;\n        }\n        int anc = lca.query(a, b);\n      \
    \  int preva = prev(anc, a), prevb = prev(anc, b);\n        long long ans = std::max({\n\
    \            sum - subsize[anc],\n            handle(anc, a, preva, prevb),\n\
    \            handle(anc, b, prevb, preva)});\n        std::cout << ans << std::endl;\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - lib/heavy_light_decomposition.hpp
  - lib/lowest_common_ancestor.hpp
  - lib/segment_tree.hpp
  isVerificationFile: true
  path: test/heavy_light_decomposition.aoj.3037.test.cpp
  requiredBy: []
  timestamp: '2020-05-11 17:18:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heavy_light_decomposition.aoj.3037.test.cpp
layout: document
redirect_from:
- /verify/test/heavy_light_decomposition.aoj.3037.test.cpp
- /verify/test/heavy_light_decomposition.aoj.3037.test.cpp.html
title: test/heavy_light_decomposition.aoj.3037.test.cpp
---
