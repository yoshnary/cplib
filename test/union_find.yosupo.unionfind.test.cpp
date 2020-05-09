#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../lib/union_find.hpp"

int main() {
    int n, q; std::cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v; std::cin >> t >> u >> v;
        if (t) std::cout << uf.same(u, v) << std::endl;
        else uf.unite(u, v);
    }
    return 0;
}
