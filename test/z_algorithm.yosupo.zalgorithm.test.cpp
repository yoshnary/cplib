#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "../lib/z_algorithm.hpp"

int main() {
    std::string s; std::cin >> s;
    auto ans = z_algorithm(s);
    int n = s.size();
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}
