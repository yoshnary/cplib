#ifndef CPLIB_LIB_KNUTH_MORRIS_PRATT_H_
#define CPLIB_LIB_KNUTH_MORRIS_PRATT_H_

#include <vector>
#include <string>

// Find a string t from a string s.
// For each element i in returned vector,
// s.substr(i, t.size()) == t holds.
// Assume '#' is not in s and t.
// Actually, this is the Morris-Pratt algorithm.
std::vector<int> kmp(const std::string &s, std::string t) {
    int n = s.size(), m = t.size();
    std::vector<int> id(m + 1);
    id[0] = -1;
    int j = -1;
    for (int i = 0; i < m; i++) {
        while (j >= 0 && t[i] != t[j]) j = id[j];
        id[i + 1] = ++j;
    }
    t += '#';
    std::vector<int> ret;
    int is = 0, it = 0;
    while (is < n) {
        if (s[is] == t[it]) is++, it++;
        else if (it == 0) is++;
        else it = id[it];
        if (it == m) {
            ret.push_back(is - m);
        }
    }
    return ret;
}

#endif  // CPLIB_LIB_KNUTH_MORRIS_PRATT_H_
