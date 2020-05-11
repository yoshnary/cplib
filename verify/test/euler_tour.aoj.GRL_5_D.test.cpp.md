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


# :heavy_check_mark: test/euler_tour.aoj.GRL_5_D.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/euler_tour.aoj.GRL_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 17:18:45+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/euler_tour.hpp.html">lib/euler_tour.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/segment_tree.hpp.html">lib/segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include <iostream>
#include "../lib/euler_tour.hpp"
#include "../lib/segment_tree.hpp"

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
    EulerTourE et(edg, 0);
    SegmentTree<long long> seg(2*n, std::plus<long long>(), 0);
    int q; std::cin >> q;
    while (q--) {
        int com, v; std::cin >> com >> v;
        if (com) {
            std::cout << seg.getval(0, et.left[v] + 1) << std::endl;
        }
        else {
            int w; std::cin >> w;
            long long val = seg.getval(et.left[v], et.left[v] + 1) + w;
            seg.update(et.left[v], val);
            seg.update(et.right[v], -val);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/euler_tour.aoj.GRL_5_D.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include <iostream>
#line 1 "lib/euler_tour.hpp"



#include <vector>

// Vertex ver.
struct EulerTourV {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> left, right;

    // A range [left[i], right[i]) corresponds to a subtree from a vertex i
    EulerTourV(const Edge &edg, int root) : left(edg.size()), right(edg.size()) {
        int n = 0;
        dfs(edg, root, n);
    }

private:
    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {
        left[pos] = id++;
        for (int c : edg[pos]) {
            if (c == prev) continue;
            dfs(edg, c, id, pos);
        }
        right[pos] = id;
    }
};

// Edge ver.
struct EulerTourE {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> left, right;

    // A range [left[i], right[i]) corresponds to a subtree from a vertex i
    EulerTourE(const Edge &edg, int root) : left(edg.size()), right(edg.size()) {
        int n = 0;
        dfs(edg, root, n);
    }

private:
    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {
        left[pos] = id++;
        for (int c : edg[pos]) {
            if (c == prev) continue;
            dfs(edg, c, id, pos);
        }
        right[pos] = id++;
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


#line 6 "test/euler_tour.aoj.GRL_5_D.test.cpp"

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
    EulerTourE et(edg, 0);
    SegmentTree<long long> seg(2*n, std::plus<long long>(), 0);
    int q; std::cin >> q;
    while (q--) {
        int com, v; std::cin >> com >> v;
        if (com) {
            std::cout << seg.getval(0, et.left[v] + 1) << std::endl;
        }
        else {
            int w; std::cin >> w;
            long long val = seg.getval(et.left[v], et.left[v] + 1) + w;
            seg.update(et.left[v], val);
            seg.update(et.right[v], -val);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

