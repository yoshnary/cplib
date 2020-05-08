#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include "../lib/lazy_segment_tree.h"
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
