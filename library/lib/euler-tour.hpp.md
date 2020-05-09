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


# :heavy_check_mark: lib/euler-tour.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/euler-tour.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 19:14:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/euler-tour.aoj.GRL_5_D.test.cpp.html">test/euler-tour.aoj.GRL_5_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/euler-tour.hpp"



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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

