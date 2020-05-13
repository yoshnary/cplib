#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <map>
#include "../lib/rolling_hash.hpp"

int main() {
    std::string s; std::cin >> s;
    int n = s.size();
    int m; std::cin >> m;
    std::vector<std::string> t(m);
    for (int i = 0; i < m; i++) std::cin >> t[i];
    DoubleRollingHash rh(s);
    auto base = rh.get_base();
    std::map<decltype(rh.hash(0, 0)), int> cnt;
    for (int d = 1; d <= 10; d++) {
        for (int i = 0; i + d <= n; i++) {
            cnt[rh.hash(i, i + d)]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto hash = DoubleRollingHash(
            t[i], base.first, base.second).hash(0, t[i].size());
        ans += cnt[hash];
    }
    std::cout << ans << std::endl;
    return 0;
}
