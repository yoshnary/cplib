#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../lib/lowest_common_ancestor.hpp"
#include <iostream>
#include <vector>

int main() {
    int n; std::cin>> n;
    std::vector<std::vector<int>> edg(n);
    bool used[100003] = {};
    for (int i = 0; i < n; i++) {
        int k; std::cin >> k;
        for (int j = 0; j < k ;j++) {
            int c; std::cin >> c;
            edg[i].push_back(c);
            edg[c].push_back(i);
            used[c] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!used[i]) root = i;
    }
    LowestCommonAncestor lca(edg, root);
    int q; std::cin >> q;
    while (q--) {
        int u, v; std::cin >> u >> v;
        std::cout << lca.query(u, v) << std::endl;
    }
    return 0;
}
