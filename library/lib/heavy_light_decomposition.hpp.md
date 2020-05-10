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


# :heavy_check_mark: lib/heavy_light_decomposition.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/heavy_light_decomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 20:14:54+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/heavy_light_decomposition.aoj.3037.test.cpp.html">test/heavy_light_decomposition.aoj.3037.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp.html">test/heavy_light_decomposition.aoj.GRL_5_E.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/heavy_light_decomposition.hpp"



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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

