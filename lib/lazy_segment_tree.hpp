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
