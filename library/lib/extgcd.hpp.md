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


# :heavy_check_mark: lib/extgcd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/extgcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 11:45:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/extgcd.aoj.NTL_1_E.test.cpp.html">test/extgcd.aoj.NTL_1_E.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_EXTGCD_H_
#define CPLIB_LIB_EXTGCD_H_

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

#endif  // CPLIB_LIB_EXTGCD_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

