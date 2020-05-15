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


# :heavy_check_mark: test/z_algorithm.yosupo.zalgorithm.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/z_algorithm.yosupo.zalgorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-15 17:57:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/z_algorithm.hpp.html">lib/z_algorithm.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "../lib/z_algorithm.hpp"

int main() {
    std::string s; std::cin >> s;
    auto ans = z_algorithm(s);
    int n = s.size();
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/z_algorithm.yosupo.zalgorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#line 1 "lib/z_algorithm.hpp"



#include <vector>
#line 6 "lib/z_algorithm.hpp"
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


#line 6 "test/z_algorithm.yosupo.zalgorithm.test.cpp"

int main() {
    std::string s; std::cin >> s;
    auto ans = z_algorithm(s);
    int n = s.size();
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

