#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_G"

#include "../lib/modint.hpp"
#include "../lib/combinatorics.hpp"
#include <iostream>

int main() {
    init_fact();
    int n, k; std::cin >> n >> k;
    Mint ans = 0;
    for (int j = 1; j <= k; j++) {
        Mint cnt = 0;
        for (int i = 0; i < j; i++) {
            cnt += Mint(i&1 ? -1 : 1)*C(j, i)*pow(Mint(j - i), (long long)n);
        }
        cnt *= inv[j];
        ans += cnt;
    }
    std::cout << ans << std::endl;
    return 0;
}
