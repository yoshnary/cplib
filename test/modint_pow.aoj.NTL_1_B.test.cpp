#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>
#include "../lib/modint.hpp"

int main() {
    int m, n; std::cin >> m >> n;
    std::cout << pow(Mint(m), (long long)n) << std::endl;
}
