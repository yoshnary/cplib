#define PROBlEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444"

#include <iostream>
#include <string>
#include <set>
#include "../lib/rolling_hash.hpp"

int main() {
    int n, m; std::cin >> n >> m;
    std::string s; std::cin >> s;
    DoubleRollingHash rh(s);
    std::set<std::pair<unsigned long long, unsigned long long>> st;
    int l = 0, r = 1;
    for (int i = 0; i < m; i++) {
        std::string t; std::cin >> t;
        if (t == "L++") l++;
        if (t == "L--") l--;
        if (t == "R++") r++;
        if (t == "R--") r--;
        st.insert(rh.hash(l, r));
    }
    std::cout << st.size() << std::endl;
    return 0;
}
