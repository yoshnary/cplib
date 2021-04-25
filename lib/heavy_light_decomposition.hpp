#ifndef CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_
#define CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_

#include <vector>

struct HLDecomposition {
    using Edge = std::vector<std::vector<int>>;

    // USAGE: pos[par[left[v]]], pos[left[v]]

    // pos[v]: position in a line of the vertex v
    std::vector<int> pos;

    // left[v]: the leftmost vertex
    // of the connected component including v.
    // If left[v] == v, it means v is itself
    // the leftmost vertex.
    std::vector<int> left;

    // par[v]: parent of the vertex v.
    // If par[v] == v, it means v is the root.
    std::vector<int> par;

    HLDecomposition(const Edge &edg, int root)
        : pos(edg.size())
        , left(edg.size(), -1)
        , par(edg.size(), -1)
        , weight(edg.size(), 1) {

        build_weight(edg, root);
        left[root] = par[root] = root;
        decompose(edg, root);
    }

private:
    std::vector<int> weight;

    int build_weight(const Edge &edg, int v, int prev = -1) {
        for (int c : edg[v]) {
            if (c == prev) continue;
            weight[v] += build_weight(edg, c, v);
        }
        return weight[v];
    }

    void decompose(const Edge &edg, int v, int prev = -1) {
        static int cnt = 0;

        pos[v] = cnt++;
        int max_weight = 0, max_id = -1;
        for (int c : edg[v]) {
            if (c == prev) continue;
            if (weight[c] > max_weight) {
                max_weight = weight[c];
                max_id = c;
            }
        }
        if (max_id == -1) return;

        par[max_id] = v;
        left[max_id] = left[v];
        decompose(edg, max_id, v);

        for (int c : edg[v]) {
            if (c == prev || c == max_id) continue;
            par[c] = v;
            left[c] = c;
            decompose(edg, c, v);
        }
    }
};

#endif  // CPLIB_LIB_HEAVY_LIGHT_DECOMPOSITION_H_
