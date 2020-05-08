#ifndef CPLIB_LIB_UNION_FIND_H_
#define CPLIB_LIB_UNION_FIND_H_

#include <vector>

class UnionFind {
public:
    UnionFind(int n) : par(n, -1), ran(n, -1) {};

    void unite(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        if (x == y) return;

        if (ran[x] < ran[y]) {
            par[find_root(y)] += par[find_root(x)];
            par[x] = y;
        }
        else {
            par[find_root(x)] += par[find_root(y)];
            par[y] = x;
            if (ran[x] == ran[y]) ran[x]++;
        }
    }

    int size(int x) {
        return -par[find_root(x)];
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

    int find_root(int x) {
        if (par[x] < 0) {
            return x;
        }
        else {
            return par[x] = find_root(par[x]);
        }
    }

private:
    std::vector<int> par, ran;
};

#endif  // CPLIB_LIB_UNION_FIND_H_
