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


# :heavy_check_mark: test/segment_tree.aoj.DSL_2_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/segment_tree.aoj.DSL_2_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:45:03+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/segment_tree.hpp.html">lib/segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include "../lib/segment_tree.hpp"
#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    auto op = [](long long a, long long b) { return std::min(a, b); };
    SegmentTree<long long>
        seg(std::vector<long long>(n, (1LL << 31) - 1),
            op, (1LL << 31) - 1);
    for (int i = 0; i < q; i++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com) std::cout << seg.getval(x, y + 1) << std::endl;
        else seg.update(x, y);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/segment_tree.aoj.DSL_2_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#line 1 "lib/segment_tree.hpp"



#include <vector>
#include <algorithm>
#include <functional>

// USAGE:
// const int INF = 1e9 + 2;
// auto op = [](int a, int b) { return std::min(a, b); };
// SegmentTree<int> seg(m, op, INF);
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


#line 4 "test/segment_tree.aoj.DSL_2_A.test.cpp"
#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    auto op = [](long long a, long long b) { return std::min(a, b); };
    SegmentTree<long long>
        seg(std::vector<long long>(n, (1LL << 31) - 1),
            op, (1LL << 31) - 1);
    for (int i = 0; i < q; i++) {
        int com, x, y; std::cin >> com >> x >> y;
        if (com) std::cout << seg.getval(x, y + 1) << std::endl;
        else seg.update(x, y);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

