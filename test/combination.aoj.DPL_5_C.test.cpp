#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include <iostream>
#include "../lib/modint.hpp"
#include "../lib/combination.hpp"

int main() {
    init_fact();
    int n, k; std::cin >> n >> k;
    Mint ans = pow(Mint(k), (long long)n);
    for (int i = 1; i < k; i++) {
        ans += Mint(i&1 ? -1 : 1)*C(k, i)*pow(Mint(k - i), (long long)n);
    }
    std::cout << ans << std::endl;
    return 0;
}
