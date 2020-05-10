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


# :heavy_check_mark: lib/chinese_remainder_theorem.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/chinese_remainder_theorem.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 13:15:42+09:00




## Depends on

* :heavy_check_mark: <a href="extgcd.hpp.html">lib/extgcd.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/chinese_remainder_theorem.yuki.447.test.cpp.html">test/chinese_remainder_theorem.yuki.447.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_
#define CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_

#include <utility>
#include "../lib/extgcd.hpp"

// Chinese Remainder Theorem
// Find rem such that 0 <= rem < lcm(m1, m2) and
// rem % m1 = r1 and rem % m2 = r2
// Return { -1, -1 } if such rem doesn't exist,
// otherwise return { lcm(m1, m2), rem }
std::pair<long long, long long>
crt(long long m1, long long r1, long long m2, long long r2) {
    long long x = 0, y = 0;
    long long d = extgcd(m1, m2, x, y);
    if (r1%d != r2%d) {
        return { -1, -1 };
    }
    long long lcm = m1 / d * m2;
    long long rem = ((r2 - r1) / d * x % (m2 / d)) * m1;
    rem = ((rem + r1) % lcm + lcm) % lcm;
    return { lcm, rem };
}

#endif  // CPLIB_LIB_CHINESE_REMAINDER_THEOREM_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/chinese_remainder_theorem.hpp"



#include <utility>
#line 1 "lib/extgcd.hpp"



#include <tuple>
#line 6 "lib/extgcd.hpp"

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


#line 6 "lib/chinese_remainder_theorem.hpp"

// Chinese Remainder Theorem
// Find rem such that 0 <= rem < lcm(m1, m2) and
// rem % m1 = r1 and rem % m2 = r2
// Return { -1, -1 } if such rem doesn't exist,
// otherwise return { lcm(m1, m2), rem }
std::pair<long long, long long>
crt(long long m1, long long r1, long long m2, long long r2) {
    long long x = 0, y = 0;
    long long d = extgcd(m1, m2, x, y);
    if (r1%d != r2%d) {
        return { -1, -1 };
    }
    long long lcm = m1 / d * m2;
    long long rem = ((r2 - r1) / d * x % (m2 / d)) * m1;
    rem = ((rem + r1) % lcm + lcm) % lcm;
    return { lcm, rem };
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

