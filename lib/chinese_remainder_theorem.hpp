#ifndef CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_
#define CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_

#include <utility>
#include "../lib/extgcd.hpp"

// Chinese Remainder Theorem
// Find rem such that 0 <= rem < lcm(m1, m2) and
// rem % m1 = r1 and rem % m2 = r2
// Return { -1, -1 } if such rem doesn't exist,
// otherwise return { lcm(m1, m2), rem }
std::pair<long long, long long>
crt(long long m1, long long r1, long long m2, long long r2) {
    long long x = 0, y = 0;
    long long d = extgcd(m1, m2, x, y);
    if (r1%d != r2%d) {
        return { -1, -1 };
    }
    long long lcm = m1 / d * m2;
    long long rem = ((r2 - r1) / d * x % (m2 / d)) * m1;
    rem = ((rem + r1) % lcm + lcm) % lcm;
    return { lcm, rem };
}

#endif  // CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_
