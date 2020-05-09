#ifndef CPLIB_LIB_TOPOLOGICAL_SORT_H_
#define CPLIB_LIB_TOPOLOGICAL_SORT_H_

#include <vector>
#include <algorithm>

struct TopologicalSort {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> ord;
    bool isdag;

    TopologicalSort(const Edge &edg) : used(edg.size()) {
        isdag = true;
        for (int i = 0; i < (int)edg.size(); i++) {
            if (used[i] != 0) continue;
            isdag &= rec(edg, i);
        }
        std::reverse(ord.begin(), ord.end());
    }

private:
    std::vector<int> used;

    bool rec(const Edge &edg, int pos) {
        if (used[pos] == -1) return false;
        if (used[pos] == 1) return true;
        used[pos] = -1;
        for (int c : edg[pos]) {
            if (!rec(edg, c)) return false;
        }
        used[pos] = 1;
        ord.push_back(pos);
        return true;
    }
};

#endif  // CPLIB_LIB_TOPOLOGICAL_SORT_H_
