#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/3037"

#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <utility>
#include "../lib/heavy_light_decomposition.hpp"
#include "../lib/lowest_common_ancestor.hpp"
#include "../lib/segment_tree.hpp"

long long chmax(long long &a, long long b) {
    return a = std::max(a, b);
}

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> edg(n);
    std::vector<long long> w(n);
    for (int i = 0; i < n; i++) std::cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; std::cin >> u >> v;
        u--; v--;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    long long sum = std::accumulate(w.begin(), w.end(), 0LL);
    LowestCommonAncestor lca(edg, 0);
    HLDecomposition hld(edg, 0);
    std::vector<long long> init(n), subsize(n);
    std::vector<std::priority_queue<std::pair<long long, int>>> ques(n);
    auto initialize = [&](
        const auto &self, int pos = 0, int prev = -1) -> long long {

        subsize[pos] = w[pos];
        for (int c : edg[pos]) {
            if (c == prev) continue;
            long long res = self(self, c, pos);
            subsize[pos] += res;
            ques[pos].emplace(res, c);
        }
        for (int c : edg[pos]) {
            if (c == prev) continue;
            if (ques[pos].top().second == c) {
                auto p = ques[pos].top();
                ques[pos].pop();
                if (!ques[pos].empty())
                    init[hld.pos[c]] = ques[pos].top().first;
                ques[pos].push(p);
            }
            else {
                init[hld.pos[c]] = ques[pos].top().first;
            }
        }
        return subsize[pos];
    };
    initialize(initialize);
    SegmentTree<long long>
        seg(init, [](long long a, long long b){return std::max(a, b);}, 0);
    auto prev = [&](const int anc, int a) {
        if (anc == a) return anc;
        for (int i = 29; i >= 0; i--) {
            if (((lca.depth[a] - (lca.depth[anc] + 1)) >> i) & 1) {
                a = lca.anc[i][a];
            }
        }
        return a;
    };
    auto func = [&](const int targ, int a) {
        long long ret = 0;
        while (hld.pos[hld.left[a]] > hld.pos[targ]) {
            chmax(ret, seg.getval(hld.pos[hld.left[a]], hld.pos[a] + 1));
            a = hld.par[hld.left[a]];
        }
        chmax(ret, seg.getval(hld.pos[targ] + 1, hld.pos[a] + 1));
        return ret;
    };
    std::vector<std::pair<long long, int>> buf;
    auto handle = [&](int anc, int a, int preva, int prevb) {

        long long ret = 0;
        if (anc != a) {
            chmax(ret, func(preva, a));
            if (!ques[a].empty()) chmax(ret, ques[a].top().first);
            buf.clear();
            while (!ques[anc].empty()
                && (ques[anc].top().second == preva
                || ques[anc].top().second == prevb)) {

                buf.push_back(ques[anc].top());
                ques[anc].pop();
            }
            if (!ques[anc].empty()) chmax(ret, ques[anc].top().first);
            for (auto &p : buf) ques[anc].push(p);
        }
        else {
            chmax(ret, sum - subsize[a]);
        }
        return ret;
    };
    int q; std::cin >> q;
    while (q--) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        if (a == b) {
            std::cout << std::max(
                ques[a].top().first, sum - subsize[a]) << std::endl;
            continue;
        }
        int anc = lca.query(a, b);
        int preva = prev(anc, a), prevb = prev(anc, b);
        long long ans = std::max({
            sum - subsize[anc],
            handle(anc, a, preva, prevb),
            handle(anc, b, prevb, preva)});
        std::cout << ans << std::endl;
    }
    return 0;
}
