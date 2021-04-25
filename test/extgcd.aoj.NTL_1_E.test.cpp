#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include <iostream>
#include "../lib/extgcd.hpp"

int main() {
    long long a, b; std::cin >> a >> b;
    long long x, y;
    extgcd(a, b, x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}
