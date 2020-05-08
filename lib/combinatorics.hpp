#ifndef CPLIB_LIB_COMBINATORICS_H_
#define CPLIB_LIB_COMBINATORICS_H_

#include "../lib/modint.hpp"
#include <vector>

// Combinatorics
constexpr int MAX_N = 2000003;
std::vector<Mint> fact(MAX_N), inv(MAX_N);

void init_fact() {
    fact[0] = inv[0] = 1;
    for (long long i = 1; i < MAX_N; i++) {
        fact[i] = fact[i - 1] * Mint(i);
        inv[i] = fact[i].inv();
    }
}

// aCb
Mint C(int a, int b) {
    if (a < b) return 0;
    Mint res = fact[a];
    res *= inv[b];
    res *= inv[a - b];
    return res;
}

// aPb
Mint P(int a, int b) {
    if (a < b) return 0;
    return fact[a] * inv[a - b];
}

// aHb
Mint H(int a, int b) {
    if (b == 0) return 1;
    return C(a + b - 1, b);
}

#endif  // CPLIB_LIB_COMBINATORICS_H_
