#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include <iostream>
#include "../lib/euler-tour.hpp"
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
