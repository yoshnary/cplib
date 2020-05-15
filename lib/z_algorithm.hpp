#ifndef CPLIB_CLIB_Z_ALGORITHM_H_
#define CPLIB_CLIB_Z_ALGORITHM_H_

#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_algorithm(const std::string &s) {
    int n = s.size();
    std::vector<int> ret(n);
    ret[0] = n;
    int begin = 1, len = 0;
    while (begin < n) {
        while (begin + len < n && s[len] == s[begin + len]) len++;
        ret[begin] = len;
        int t = 1;
        while (t < len && t + ret[t] < len) {
            ret[len + t] = ret[t];
            t++;
        }
        begin += t; len = std::max(0, len - t);
    }
    return ret;
}

#endif  // CPLIB_CLIB_Z_ALGORITHM_H_
