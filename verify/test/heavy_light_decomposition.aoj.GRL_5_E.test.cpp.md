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


# :heavy_check_mark: test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 20:19:23+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/heavy_light_decomposition.hpp.html">lib/heavy_light_decomposition.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/lazy_segment_tree.hpp.html">lib/lazy_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>
#include "../lib/heavy_light_decomposition.hpp"
#include "../lib/lazy_segment_tree.hpp"

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < n; i++) {
        int k; std::cin >> k;
        for (int j = 0; j < k; j++) {
            int c; std::cin >> c;
            edg[i].push_back(c);
            edg[c].push_back(i);
        }
    }
    HLDecomposition hld(edg, 0);
    LazySegmentTree<long long, long long>
        seg(n, std::plus<long long>(), 0, std::plus<long long>(), 0,
            [](long long p, int n, long long a){return p*n + a;});
    auto sum_query = [&](int u) {
        long long ret = 0;
        while (u > 0) {
            ret += seg.getval(hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        return ret;
    };
    auto add_query = [&](int u, long long w) {
        while (u > 0) {
            seg.apply(w, hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        seg.apply(-seg.getval(hld.pos[0], hld.pos[0] + 1), hld.pos[0], hld.pos[0] + 1);
    };
    int q; std::cin >> q;
    while (q--) {
        int com, v; std::cin >> com >> v;
        if (com) {
            std::cout << sum_query(v) << std::endl;
        }
        else {
            long long w; std::cin >> w;
            add_query(v, w);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>
#line 1 "lib/heavy_light_decomposition.hpp"



#include <vector>

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


#line 1 "lib/lazy_segment_tree.hpp"



#line 5 "lib/lazy_segment_tree.hpp"
#include <algorithm>
#include <functional>

template<typename Monoid, typename Operator>
class LazySegmentTree {
public:
    // mono_product(a, b)
    using MonoidProduct = std::function<Monoid(Monoid, Monoid)>;

    // op_product(p, q)(a) = p(q(a)) (not q(p(a)))
    using OperatorProduct = std::function<Operator(Operator, Operator)>;

    // act(p, n, a) = (p, n)(a)
    // n: Length of the range.
    using Actor = std::function<Monoid(Operator, int, Monoid)>;

    LazySegmentTree(int n,
        const MonoidProduct &mono_product, Monoid init_mono,
        const OperatorProduct &op_product, Operator init_op,
        const Actor &act)
        : mono_product(mono_product), init_mono(init_mono)
        , op_product(op_product), init_op(init_op)
        , act(act) {

        num = 1;
        while (num < n) num *= 2;
        dat_mono = std::vector<Monoid>(2 * num, init_mono);
        dat_op = std::vector<Operator>(2 * num, init_op);
    }

    LazySegmentTree(const std::vector<Monoid> &m,
        const MonoidProduct &mono_product, Monoid init_mono,
        const OperatorProduct &op_product, Operator init_op,
        const Actor &act)
        : LazySegmentTree(m.size(), mono_product, init_mono,
            op_product, init_op, act) {

        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat_mono[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat_mono[i]
                = mono_product(dat_mono[2 * i + 1], dat_mono[2 * i + 2]);
        }
    }

    // Apply the operator q to the range [a, b).
    // k: The index of the node.
    // Call like apply(q, a, b)
    void apply(Operator q, int a, int b,
        int k = 0, int left = 0, int right = -1) {

        if (right < 0) right = num;
        if (right <= a || b <= left) return;
        if (a <= left && right <= b) {
            dat_mono[k] = act(q, right - left, dat_mono[k]);
            dat_op[k] = op_product(q, dat_op[k]);
            return;
        }
        apply(dat_op[k], left, left + (right - left) / 2,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        apply(dat_op[k], left + (right - left) / 2, right,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        dat_op[k] = init_op;
        apply(q, a, b,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        apply(q, a, b,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        dat_mono[k]
            = mono_product(dat_mono[2 * k + 1], dat_mono[2 * k + 2]);
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) {
        if (right < 0) right = num;
        if (right <= a || b <= left) return init_mono;
        if (a <= left && right <= b) return dat_mono[k];
        Monoid vleft = getval(a, b,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        Monoid vright = getval(a, b,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        return act(dat_op[k],
            std::max(0, std::min(b, right) - std::max(a, left)),
            mono_product(vleft, vright));
    }

private:
    int num;
    std::vector<Monoid> dat_mono;
    std::vector<Operator> dat_op;

    const MonoidProduct mono_product;
    const Monoid init_mono;
    const OperatorProduct op_product;
    const Operator init_op;
    const Actor act;
};

// Example: Range-Add Range-Sum Segment Tree
LazySegmentTree<long long, long long>
make_rars_segment_tree(const std::vector<long long> &init) {
    auto mono_product = [](long long a, long long b) { return a + b; };
    const long long init_mono = 0;
    auto op_product = [](long long p, long long q) { return p + q; };
    const long long init_op = 0;
    auto act = [](long long p, int n, long long a) { return p*n + a; };
    return LazySegmentTree<long long, long long>(
        init, mono_product, init_mono, op_product, init_op, act);
}


#line 6 "test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp"

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < n; i++) {
        int k; std::cin >> k;
        for (int j = 0; j < k; j++) {
            int c; std::cin >> c;
            edg[i].push_back(c);
            edg[c].push_back(i);
        }
    }
    HLDecomposition hld(edg, 0);
    LazySegmentTree<long long, long long>
        seg(n, std::plus<long long>(), 0, std::plus<long long>(), 0,
            [](long long p, int n, long long a){return p*n + a;});
    auto sum_query = [&](int u) {
        long long ret = 0;
        while (u > 0) {
            ret += seg.getval(hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        return ret;
    };
    auto add_query = [&](int u, long long w) {
        while (u > 0) {
            seg.apply(w, hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        seg.apply(-seg.getval(hld.pos[0], hld.pos[0] + 1), hld.pos[0], hld.pos[0] + 1);
    };
    int q; std::cin >> q;
    while (q--) {
        int com, v; std::cin >> com >> v;
        if (com) {
            std::cout << sum_query(v) << std::endl;
        }
        else {
            long long w; std::cin >> w;
            add_query(v, w);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

