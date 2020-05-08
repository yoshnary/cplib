#ifndef CPLIB_LAZY_SEGMENT_TREE_H_
#define CPLIB_LAZY_SEGMENT_TREE_H_

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


#endif  // CPLIB_LAZY_SEGMENT_TREE_H_