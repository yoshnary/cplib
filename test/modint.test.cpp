#define PROBLEM "https://yukicoder.me/problems/1504"

#include "../lib/modint.hpp"
#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    Mint ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= Mint(i);
    }
    std::cout << ans << std::endl;
    return 0;
}
