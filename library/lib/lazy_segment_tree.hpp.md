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


# :heavy_check_mark: lib/lazy_segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/lazy_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 19:52:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/lazy_segment_tree.aoj.DSL_2_G.test.cpp.html">test/lazy_segment_tree.aoj.DSL_2_G.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_LAZY_SEGMENT_TREE_H_
#define CPLIB_LIB_LAZY_SEGMENT_TREE_H_

#include <vector>
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

#endif  // CPLIB_LIB_LAZY_SEGMENT_TREE_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/lazy_segment_tree.hpp"



#include <vector>
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

