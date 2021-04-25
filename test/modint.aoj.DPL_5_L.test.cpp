#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L"

#include <iostream>
#include <vector>
#include "../lib/modint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    if (n < k) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<std::vector<Mint>> dp(n - k + 2, std::vector<Mint>(k + 2));
    for (int i = 0; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] += dp[i - j][j];
        }
    }
    std::cout << dp[n - k][k] << std::endl;
    return 0;
}
