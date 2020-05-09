#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../lib/topological_sort.hpp"
#include <iostream>
#include <vector>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int s, t; std::cin >> s >> t;
        edg[s].push_back(t);
    }
    TopologicalSort topo(edg);
    for (int i : topo.ord) std::cout << i << std::endl;
    return 0;
}
