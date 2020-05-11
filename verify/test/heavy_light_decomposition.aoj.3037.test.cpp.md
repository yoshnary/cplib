---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/heavy_light_decomposition.aoj.3037.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/heavy_light_decomposition.aoj.3037.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 17:18:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/heavy_light_decomposition.hpp.html">lib/heavy_light_decomposition.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/lowest_common_ancestor.hpp.html">lib/lowest_common_ancestor.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/segment_tree.hpp.html">lib/segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037"

#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <utility>
#include "../lib/heavy_light_decomposition.hpp"
#include "../lib/lowest_common_ancestor.hpp"
#include "../lib/segment_tree.hpp"

long long chmax(long long &a, long long b) {
    return a = std::max(a, b);
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    std::vector<long long> w(n);
    for (int i = 0; i < n; i++) std::cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    long long sum = std::accumulate(w.begin(), w.end(), 0LL);
    LowestCommonAncestor lca(edg, 0);
    HLDecomposition hld(edg, 0);
    std::vector<long long> init(n), subsize(n);
    std::vector<std::priority_queue<std::pair<long long, int>>> ques(n);
    auto initialize = [&](
        const auto &self, int pos = 0, int prev = -1) -> long long {

        subsize[pos] = w[pos];
        for (int c : edg[pos]) {
            if (c == prev) continue;
            long long res = self(self, c, pos);
            subsize[pos] += res;
            ques[pos].emplace(res, c);
        }
        for (int c : edg[pos]) {
            if (c == prev) continue;
            if (ques[pos].top().second == c) {
                auto p = ques[pos].top();
                ques[pos].pop();
                if (!ques[pos].empty())
                    init[hld.pos[c]] = ques[pos].top().first;
                ques[pos].push(p);
            }
            else {
                init[hld.pos[c]] = ques[pos].top().first;
            }
        }
        return subsize[pos];
    };
    initialize(initialize);
    SegmentTree<long long>
        seg(init, [](long long a, long long b){return std::max(a, b);}, 0);
    auto prev = [&](const int anc, int a) {
        if (anc == a) return anc;
        for (int i = 29; i >= 0; i--) {
            if (((lca.depth[a] - (lca.depth[anc] + 1)) >> i) & 1) {
                a = lca.anc[i][a];
            }
        }
        return a;
    };
    auto func = [&](const int targ, int a) {
        long long ret = 0;
        while (hld.pos[hld.left[a]] > hld.pos[targ]) {
            chmax(ret, seg.getval(hld.pos[hld.left[a]], hld.pos[a] + 1));
            a = hld.par[hld.left[a]];
        }
        chmax(ret, seg.getval(hld.pos[targ] + 1, hld.pos[a] + 1));
        return ret;
    };
    std::vector<std::pair<long long, int>> buf;
    auto handle = [&](int anc, int a, int preva, int prevb) {

        long long ret = 0;
        if (anc != a) {
            chmax(ret, func(preva, a));
            if (!ques[a].empty()) chmax(ret, ques[a].top().first);
            buf.clear();
            while (!ques[anc].empty()
                && (ques[anc].top().second == preva
                || ques[anc].top().second == prevb)) {

                buf.push_back(ques[anc].top());
                ques[anc].pop();
            }
            if (!ques[anc].empty()) chmax(ret, ques[anc].top().first);
            for (auto &p : buf) ques[anc].push(p);
        }
        else {
            chmax(ret, sum - subsize[a]);
        }
        return ret;
    };
    int q; std::cin >> q;
    while (q--) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        if (a == b) {
            std::cout << std::max(
                ques[a].top().first, sum - subsize[a]) << std::endl;
            continue;
        }
        int anc = lca.query(a, b);
        int preva = prev(anc, a), prevb = prev(anc, b);
        long long ans = std::max({
            sum - subsize[anc],
            handle(anc, a, preva, prevb),
            handle(anc, b, prevb, preva)});
        std::cout << ans << std::endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/heavy_light_decomposition.aoj.3037.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037"

#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <utility>
#line 1 "lib/heavy_light_decomposition.hpp"



#line 5 "lib/heavy_light_decomposition.hpp"

struct HLDecomposition {
    using Edge = std::vector<std::vector<int>>;

    // USAGE: pos[par[left[v]]], pos[left[v]]

    // pos[v]: position in a line of the vertex v
    std::vector<int> pos;

    // left[v]: the leftmost vertex
    // of the connected component including v.
    // If left[v] == v, it means v is itself
    // the leftmost vertex.
    std::vector<int> left;

    // par[v]: parent of the vertex v.
    // If par[v] == v, it means v is the root.
    std::vector<int> par;

    HLDecomposition(const Edge &edg, int root)
        : pos(edg.size())
        , left(edg.size(), -1)
        , par(edg.size(), -1)
        , weight(edg.size(), 1) {

        build_weight(edg, root);
        left[root] = par[root] = root;
        decompose(edg, root);
    }

private:
    std::vector<int> weight;

    int build_weight(const Edge &edg, int v, int prev = -1) {
        for (int c : edg[v]) {
            if (c == prev) continue;
            weight[v] += build_weight(edg, c, v);
        }
        return weight[v];
    }

    void decompose(const Edge &edg, int v, int prev = -1) {
        static int cnt = 0;

        pos[v] = cnt++;
        int max_weight = 0, max_id = -1;
        for (int c : edg[v]) {
            if (c == prev) continue;
            if (weight[c] > max_weight) {
                max_weight = weight[c];
                max_id = c;
            }
        }
        if (max_id == -1) return;

        par[max_id] = v;
        left[max_id] = left[v];
        decompose(edg, max_id, v);

        for (int c : edg[v]) {
            if (c == prev || c == max_id) continue;
            par[c] = v;
            left[c] = c;
            decompose(edg, c, v);
        }
    }
};


#line 1 "lib/lowest_common_ancestor.hpp"



#line 6 "lib/lowest_common_ancestor.hpp"

struct LowestCommonAncestor {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> depth;
    std::vector<std::vector<int>> anc;

    LowestCommonAncestor(const Edge &edg, int root)
        : depth(edg.size()), anc(L, std::vector<int>(edg.size(), root)) {

        build(edg, root);
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int i = L - 1; i >= 0; i--) {
            if (((depth[v] - depth[u]) >> i) & 1) {
                v = anc[i][v];
            }
        }
        if (u == v) return u;

        for (int i = L - 1; i >= 0; i--) {
            if (anc[i][u] == anc[i][v]) continue;
            u = anc[i][u];
            v = anc[i][v];
        }
        return anc[0][u];
    }

private:
    static const int L = 30;

    void dfs(const Edge &edg, int pos, int prev = -1) {
        for (int v : edg[pos]) {
            if (v == prev) continue;
            depth[v] = depth[pos] + 1;
            anc[0][v] = pos;
            dfs(edg, v, pos);
        }
    }

    void build(const Edge &edg, int root) {
        dfs(edg, root);
        int n = edg.size();
        for (int i = 1; i < L; i++) {
            for (int j = 0; j < n; j++) {
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
    }
};


#line 1 "lib/segment_tree.hpp"



#line 5 "lib/segment_tree.hpp"
#include <algorithm>
#include <functional>

template<typename Monoid>
class SegmentTree {
public:
    using Operator = std::function<Monoid(Monoid, Monoid)>;

    SegmentTree(int n, const Operator &op, const Monoid init)
        : op(op), init(init) {

        num = 1;
        while (num < n) num *= 2;
        dat.resize(2 * num, init);
    }

    SegmentTree(const std::vector<Monoid> &m,
        const Operator &op, const Monoid init)
        : SegmentTree(m.size(), op, init) {

        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

    // Update the k-th value (0-indexed) to a.
    void update(int k, Monoid a) {
        k += num - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) {
        if (right < 0) right = num;
        if (right <= a || b <= left) return init;
        if (a <= left && right <= b) return dat[k];
        Monoid vleft = getval(
            a, b, 2 * k + 1, left, left + (right - left) / 2);
        Monoid vright = getval(
            a, b, 2 * k + 2, left + (right - left) / 2, right);
        return op(vleft, vright);
    }

private:
    int num;
    std::vector<Monoid> dat;
    const Operator op;
    const Monoid init;
};

// Example: Range-Minimum Point-Update Segment Tree
SegmentTree<int> make_rmpu_segment_tree(const std::vector<int> &init) {
    const int INF = 1e9 + 2;
    auto op = [](int a, int b) { return std::min(a, b); };
    return SegmentTree<int>(init, op, INF);
}


#line 11 "test/heavy_light_decomposition.aoj.3037.test.cpp"

long long chmax(long long &a, long long b) {
    return a = std::max(a, b);
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    std::vector<long long> w(n);
    for (int i = 0; i < n; i++) std::cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    long long sum = std::accumulate(w.begin(), w.end(), 0LL);
    LowestCommonAncestor lca(edg, 0);
    HLDecomposition hld(edg, 0);
    std::vector<long long> init(n), subsize(n);
    std::vector<std::priority_queue<std::pair<long long, int>>> ques(n);
    auto initialize = [&](
        const auto &self, int pos = 0, int prev = -1) -> long long {

        subsize[pos] = w[pos];
        for (int c : edg[pos]) {
            if (c == prev) continue;
            long long res = self(self, c, pos);
            subsize[pos] += res;
            ques[pos].emplace(res, c);
        }
        for (int c : edg[pos]) {
            if (c == prev) continue;
            if (ques[pos].top().second == c) {
                auto p = ques[pos].top();
                ques[pos].pop();
                if (!ques[pos].empty())
                    init[hld.pos[c]] = ques[pos].top().first;
                ques[pos].push(p);
            }
            else {
                init[hld.pos[c]] = ques[pos].top().first;
            }
        }
        return subsize[pos];
    };
    initialize(initialize);
    SegmentTree<long long>
        seg(init, [](long long a, long long b){return std::max(a, b);}, 0);
    auto prev = [&](const int anc, int a) {
        if (anc == a) return anc;
        for (int i = 29; i >= 0; i--) {
            if (((lca.depth[a] - (lca.depth[anc] + 1)) >> i) & 1) {
                a = lca.anc[i][a];
            }
        }
        return a;
    };
    auto func = [&](const int targ, int a) {
        long long ret = 0;
        while (hld.pos[hld.left[a]] > hld.pos[targ]) {
            chmax(ret, seg.getval(hld.pos[hld.left[a]], hld.pos[a] + 1));
            a = hld.par[hld.left[a]];
        }
        chmax(ret, seg.getval(hld.pos[targ] + 1, hld.pos[a] + 1));
        return ret;
    };
    std::vector<std::pair<long long, int>> buf;
    auto handle = [&](int anc, int a, int preva, int prevb) {

        long long ret = 0;
        if (anc != a) {
            chmax(ret, func(preva, a));
            if (!ques[a].empty()) chmax(ret, ques[a].top().first);
            buf.clear();
            while (!ques[anc].empty()
                && (ques[anc].top().second == preva
                || ques[anc].top().second == prevb)) {

                buf.push_back(ques[anc].top());
                ques[anc].pop();
            }
            if (!ques[anc].empty()) chmax(ret, ques[anc].top().first);
            for (auto &p : buf) ques[anc].push(p);
        }
        else {
            chmax(ret, sum - subsize[a]);
        }
        return ret;
    };
    int q; std::cin >> q;
    while (q--) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        if (a == b) {
            std::cout << std::max(
                ques[a].top().first, sum - subsize[a]) << std::endl;
            continue;
        }
        int anc = lca.query(a, b);
        int preva = prev(anc, a), prevb = prev(anc, b);
        long long ans = std::max({
            sum - subsize[anc],
            handle(anc, a, preva, prevb),
            handle(anc, b, prevb, preva)});
        std::cout << ans << std::endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

