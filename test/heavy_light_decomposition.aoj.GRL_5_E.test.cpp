#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include <iostream>
#include "../lib/heavy_light_decomposition.hpp"
#include "../lib/lazy_segment_tree.hpp"

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
    HLDecomposition hld(edg, 0);
    LazySegmentTree<long long, long long>
        seg(n, std::plus<long long>(), 0, std::plus<long long>(), 0,
            [](long long p, int n, long long a){return p*n + a;});
    auto sum_query = [&](int u) {
        long long ret = 0;
        while (u > 0) {
            ret += seg.getval(hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        return ret;
    };
    auto add_query = [&](int u, long long w) {
        while (u > 0) {
            seg.apply(w, hld.pos[hld.left[u]], hld.pos[u] + 1);
            u = hld.par[hld.left[u]];
        }
        seg.apply(-seg.getval(hld.pos[0], hld.pos[0] + 1), hld.pos[0], hld.pos[0] + 1);
    };
    int q; std::cin >> q;
    while (q--) {
        int com, v; std::cin >> com >> v;
        if (com) {
            std::cout << sum_query(v) << std::endl;
        }
        else {
            long long w; std::cin >> w;
            add_query(v, w);
        }
    }
    return 0;
}
