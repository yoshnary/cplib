#ifndef CPLIB_LIB_EXTGCD_H_
#define CPLIB_LIB_EXTGCD_H_

#include <tuple>
#include <utility>

// Find x and y such that a*x + b*y = gcd(a, b)
// Return gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long ret = extgcd(b, a%b, x, y);
    std::tie(x, y) = std::make_pair(y, x - a / b * y);
    return ret;
}

#endif  // CPLIB_LIB_EXTGCD_H_
