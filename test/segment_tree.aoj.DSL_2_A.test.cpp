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
