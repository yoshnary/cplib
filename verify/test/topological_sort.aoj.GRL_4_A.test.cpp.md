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


# :heavy_check_mark: test/topological_sort.aoj.GRL_4_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/topological_sort.aoj.GRL_4_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 15:26:50+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/topological_sort.hpp.html">lib/topological_sort.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#include "../lib/topological_sort.hpp"
#include <iostream>
#include <vector>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int s, t; std::cin >> s >> t;
        edg[s].push_back(t);
    }
    TopologicalSort topo(edg);
    std::cout << !topo.isdag << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/topological_sort.aoj.GRL_4_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#line 1 "lib/topological_sort.hpp"



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


#line 4 "test/topological_sort.aoj.GRL_4_A.test.cpp"
#include <iostream>
#line 6 "test/topological_sort.aoj.GRL_4_A.test.cpp"

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int s, t; std::cin >> s >> t;
        edg[s].push_back(t);
    }
    TopologicalSort topo(edg);
    std::cout << !topo.isdag << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

