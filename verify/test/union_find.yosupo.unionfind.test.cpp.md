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


# :heavy_check_mark: test/union_find.yosupo.unionfind.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/union_find.yosupo.unionfind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 18:52:06+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/union_find.hpp.html">lib/union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../lib/union_find.hpp"

int main() {
    int n, q; std::cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v; std::cin >> t >> u >> v;
        if (t) std::cout << uf.same(u, v) << std::endl;
        else uf.unite(u, v);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/union_find.yosupo.unionfind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#line 1 "lib/union_find.hpp"



#include <vector>

class UnionFind {
public:
    UnionFind(int n) : par(n, -1), ran(n, -1) {}

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


#line 5 "test/union_find.yosupo.unionfind.test.cpp"

int main() {
    int n, q; std::cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v; std::cin >> t >> u >> v;
        if (t) std::cout << uf.same(u, v) << std::endl;
        else uf.unite(u, v);
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

