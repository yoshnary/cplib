#ifndef CPLIB_LIB_EULER_TOUR_H_
#define CPLIB_LIB_EULER_TOUR_H_

#include <vector>

// Vertex ver.
struct EulerTourV {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> left, right;

    // A range [left[i], right[i]) corresponds to a subtree from a vertex i
    EulerTourV(const Edge &edg, int root) : left(edg.size()), right(edg.size()) {
        int n = 0;
        dfs(edg, root, n);
    }

private:
    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {
        left[pos] = id++;
        for (int c : edg[pos]) {
            if (c == prev) continue;
            dfs(edg, c, id, pos);
        }
        right[pos] = id;
    }
};

// Edge ver.
struct EulerTourE {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> left, right;

    // A range [left[i], right[i]) corresponds to a subtree from a vertex i
    EulerTourE(const Edge &edg, int root) : left(edg.size()), right(edg.size()) {
        int n = 0;
        dfs(edg, root, n);
    }

private:
    void dfs(const Edge &edg, int pos, int &id, int prev = -1) {
        left[pos] = id++;
        for (int c : edg[pos]) {
            if (c == prev) continue;
            dfs(edg, c, id, pos);
        }
        right[pos] = id++;
    }
};

#endif  // CPLIB_LIB_EULER_TOUR_H_
