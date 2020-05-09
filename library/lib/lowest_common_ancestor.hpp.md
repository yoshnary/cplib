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


# :heavy_check_mark: lib/lowest_common_ancestor.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/lowest_common_ancestor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 15:54:53+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp.html">test/lowest_common_ancestor.aoj.GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

