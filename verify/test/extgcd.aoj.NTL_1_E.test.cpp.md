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


# :heavy_check_mark: test/extgcd.aoj.NTL_1_E.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/extgcd.aoj.NTL_1_E.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 11:45:22+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E">https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/extgcd.hpp.html">lib/extgcd.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include <iostream>
#include "../lib/extgcd.hpp"

int main() {
    long long a, b; std::cin >> a >> b;
    long long x, y;
    extgcd(a, b, x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/extgcd.aoj.NTL_1_E.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include <iostream>
#line 1 "lib/extgcd.hpp"



#include <tuple>
#include <utility>

// Find x and y such that a*x + b*y = gcd(a, b)
// Return gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long ret = extgcd(b, a%b, x, y);
    std::tie(x, y) = std::make_pair(y, x - a / b * y);
    return ret;
}


#line 5 "test/extgcd.aoj.NTL_1_E.test.cpp"

int main() {
    long long a, b; std::cin >> a >> b;
    long long x, y;
    extgcd(a, b, x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

