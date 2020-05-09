#ifndef CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_
#define CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_

#include <vector>
#include <utility>

struct LowestCommonAncestor {
    using Edge = std::vector<std::vector<int>>;
    std::vector<int> depth;
    std::vector<std::vector<int>> anc;

    LowestCommonAncestor(const Edge &edg, int root)
        : depth(edg.size()), anc(L, std::vector<int>(edg.size(), root)) {

        build(edg, root);
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int i = L - 1; i >= 0; i--) {
            if (((depth[v] - depth[u]) >> i) & 1) {
                v = anc[i][v];
            }
        }
        if (u == v) return u;

        for (int i = L - 1; i >= 0; i--) {
            if (anc[i][u] == anc[i][v]) continue;
            u = anc[i][u];
            v = anc[i][v];
        }
        return anc[0][u];
    }

private:
    static const int L = 30;

    void dfs(const Edge &edg, int pos, int prev = -1) {
        for (int v : edg[pos]) {
            if (v == prev) continue;
            depth[v] = depth[pos] + 1;
            anc[0][v] = pos;
            dfs(edg, v, pos);
        }
    }

    void build(const Edge &edg, int root) {
        dfs(edg, root);
        int n = edg.size();
        for (int i = 1; i < L; i++) {
            for (int j = 0; j < n; j++) {
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
    }
};

#endif  // CPLIB_LIB_LOWEST_COMMON_ANCESTOR_H_
