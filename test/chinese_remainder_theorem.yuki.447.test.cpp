#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include <tuple>
#include "../lib/chinese_remainder_theorem.hpp"

int main() {
    long long x, y; std::cin >> x >> y;
    for (int i = 0; i < 2; i++) {
        long long a, b; std::cin >> a >> b;
        std::tie(y, x) = crt(y, x, b, a);
        if (x == -1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << (x == 0 ? y : x) << std::endl;
    return 0;
}
