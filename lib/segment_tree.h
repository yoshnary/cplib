#ifndef CPLIB_SEGMENT_TREE_H_
#define CPLIB_SEGMENT_TREE_H_

#include <vector>
#include <algorithm>

class SegmentTree {
private:
    using Monoid = int;
    const Monoid INI = (int)1e9 + 2;
    Monoid op(Monoid a, Monoid b) {
        return std::min(a, b);
    }

public:
    SegmentTree(int n_) {
        num = 1;
        while (num < n_) num *= 2;
        dat.resize(2 * num, INI);
    }

    SegmentTree(const std::vector<Monoid> &m) : SegmentTree(m.size()) {
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
        if (right <= a || b <= left) return INI;
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
};

#endif  // CPLIB_SEGMENT_TREE_H_