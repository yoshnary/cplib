#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_J"

#include <iostream>
#include <vector>
#include "../lib/modint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<Mint>> dp(n + 2, std::vector<Mint>(k + 2));
    for (int i = 0; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] += dp[i - j][j];
        }
    }
    std::cout << dp[n][k] << std::endl;
    return 0;
}
