---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 15:54:53+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/lowest_common_ancestor.hpp.html">lib/lowest_common_ancestor.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../lib/lowest_common_ancestor.hpp"
#include <iostream>
#include <vector>

int main() {
    int n; std::cin>> n;
    std::vector<std::vector<int>> edg(n);
    bool used[100003] = {};
    for (int i = 0; i < n; i++) {
        int k; std::cin >> k;
        for (int j = 0; j < k ;j++) {
            int c; std::cin >> c;
            edg[i].push_back(c);
            edg[c].push_back(i);
            used[c] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!used[i]) root = i;
    }
    LowestCommonAncestor lca(edg, root);
    int q; std::cin >> q;
    while (q--) {
        int u, v; std::cin >> u >> v;
        std::cout << lca.query(u, v) << std::endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#line 1 "lib/lowest_common_ancestor.hpp"



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


#line 4 "test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp"
#include <iostream>
#line 6 "test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp"

int main() {
    int n; std::cin>> n;
    std::vector<std::vector<int>> edg(n);
    bool used[100003] = {};
    for (int i = 0; i < n; i++) {
        int k; std::cin >> k;
        for (int j = 0; j < k ;j++) {
            int c; std::cin >> c;
            edg[i].push_back(c);
            edg[c].push_back(i);
            used[c] = true;
        }
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!used[i]) root = i;
    }
    LowestCommonAncestor lca(edg, root);
    int q; std::cin >> q;
    while (q--) {
        int u, v; std::cin >> u >> v;
        std::cout << lca.query(u, v) << std::endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

