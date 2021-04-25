#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_B"

#include <iostream>
#include "../lib/modint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    Mint ans = 1;
    for (int i = 0; i < n; i++) ans *= Mint(k - i);
    std::cout << ans << std::endl;
    return 0;
}
