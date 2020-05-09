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


# :heavy_check_mark: test/lazy_segment_tree.aoj.DSL_2_G.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/lazy_segment_tree.aoj.DSL_2_G.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 15:05:12+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/lazy_segment_tree.hpp.html">lib/lazy_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include "../lib/lazy_segment_tree.hpp"
#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    LazySegmentTree seg(n);
    for (int i = 0; i < q; i++) {
        int com, s, t; std::cin >> com >> s >> t;
        s--;
        if (com) {
            std::cout << seg.getval(s, t) << std::endl;
        }
        else {
            int x; std::cin >> x;
            seg.apply(x, s, t);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/lazy_segment_tree.aoj.DSL_2_G.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#line 1 "lib/lazy_segment_tree.hpp"



#include <vector>
#include <algorithm>

class LazySegmentTree {
    // TODO: Change Monid and Operator,
    // their identity, their product, and the action.
    using Monoid = long long;
    const Monoid INI_MONOID = 0;
    Monoid monoid_product(const Monoid &a, const Monoid &b) {
        return a + b;
    }

    using Operator = long long;
    const Operator INI_OPERATOR = 0;
    // p(q(a)) (i.e., not q(p(a)))
    Operator operator_product(const Operator &p, const Operator &q) {
        return p + q;
    }

    // a |-> b = (p, n)(a)
    // n: Length of the range.
    Monoid act(const Operator &p, int n, const Monoid &a) {
        return p*n + a;
    }

public:
    LazySegmentTree(int n) {
        num = 1;
        while (num < n) num *= 2;
        dat_mono = std::vector<Monoid>(2 * num, INI_MONOID);
        dat_op = std::vector<Operator>(2 * num, INI_OPERATOR);
    }

    LazySegmentTree(const std::vector<Monoid> &m)
        : LazySegmentTree(m.size()) {

        int n = m.size();
        for (int i = 0; i < n; i++) {
            dat_mono[num - 1 + i] = m[i];
        }
        for (int i = num - 2; i >= 0; i--) {
            dat_mono[i]
                = monoid_product(dat_mono[2 * i + 1], dat_mono[2 * i + 2]);
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
            dat_op[k] = operator_product(q, dat_op[k]);
            return;
        }
        apply(dat_op[k], left, left + (right - left) / 2,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        apply(dat_op[k], left + (right - left) / 2, right,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        dat_op[k] = INI_OPERATOR;
        apply(q, a, b,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        apply(q, a, b,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        dat_mono[k]
            = monoid_product(dat_mono[2 * k + 1], dat_mono[2 * k + 2]);
    }

    // Get the value of the range [a, b).
    // k: The index of the node.
    // [left, right): The range corresponds to the k-th node.
    // Call like getval(a, b).
    Monoid getval(int a, int b, int k = 0, int left = 0, int right = -1) {
        if (right < 0) right = num;
        if (right <= a || b <= left) return INI_MONOID;
        if (a <= left && right <= b) return dat_mono[k];
        Monoid vleft = getval(a, b,
            2 * k + 1, left, left + (right - left) / 2); // Left side
        Monoid vright = getval(a, b,
            2 * k + 2, left + (right - left) / 2, right); // Right side
        return act(dat_op[k],
            std::max(0, std::min(b, right) - std::max(a, left)),
            monoid_product(vleft, vright));
    }

private:
    int num;
    std::vector<Monoid> dat_mono;
    std::vector<Operator> dat_op;
};


#line 4 "test/lazy_segment_tree.aoj.DSL_2_G.test.cpp"
#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    LazySegmentTree seg(n);
    for (int i = 0; i < q; i++) {
        int com, s, t; std::cin >> com >> s >> t;
        s--;
        if (com) {
            std::cout << seg.getval(s, t) << std::endl;
        }
        else {
            int x; std::cin >> x;
            seg.apply(x, s, t);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

