#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"

#include <iostream>
#include "../lib/modint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    std::cout << pow(Mint(k), (long long)n) << std::endl;
    return 0;
}
