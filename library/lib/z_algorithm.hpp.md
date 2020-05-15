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


# :heavy_check_mark: lib/z_algorithm.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/z_algorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-15 17:57:27+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/z_algorithm.yosupo.zalgorithm.test.cpp.html">test/z_algorithm.yosupo.zalgorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_CLIB_Z_ALGORITHM_H_
#define CPLIB_CLIB_Z_ALGORITHM_H_

#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_algorithm(const std::string &s) {
    int n = s.size();
    std::vector<int> ret(n);
    ret[0] = n;
    int begin = 1, len = 0;
    while (begin < n) {
        while (begin + len < n && s[len] == s[begin + len]) len++;
        ret[begin] = len;
        int t = 1;
        while (t < len && t + ret[t] < len) {
            ret[begin + t] = ret[t];
            t++;
        }
        begin += t; len = std::max(0, len - t);
    }
    return ret;
}

#endif  // CPLIB_CLIB_Z_ALGORITHM_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/z_algorithm.hpp"



#include <vector>
#include <string>
#include <algorithm>

std::vector<int> z_algorithm(const std::string &s) {
    int n = s.size();
    std::vector<int> ret(n);
    ret[0] = n;
    int begin = 1, len = 0;
    while (begin < n) {
        while (begin + len < n && s[len] == s[begin + len]) len++;
        ret[begin] = len;
        int t = 1;
        while (t < len && t + ret[t] < len) {
            ret[begin + t] = ret[t];
            t++;
        }
        begin += t; len = std::max(0, len - t);
    }
    return ret;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

