#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_D"

#include <iostream>
#include "../lib/modint.hpp"
#include "../lib/combination.hpp"

int main() {
    init_fact();
    int n, k; std::cin >> n >> k;
    std::cout << H(k, n) << std::endl;
    return 0;
}
