#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../lib/knuth_morris_pratt.hpp"

int main(){
    std::string s, t; std::cin >> s >> t;
    auto ans = kmp(s, t);
    for (int i : ans) std::cout << i << std::endl;
    return 0;
}
