#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include "../lib/lazy_segment_tree.hpp"
#include <iostream>

int main() {
    int n, q; std::cin >> n >> q;
    auto seg = make_rars_segment_tree(std::vector<long long>(n, 0));
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
