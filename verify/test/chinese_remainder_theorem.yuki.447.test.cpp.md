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


# :heavy_check_mark: test/chinese_remainder_theorem.yuki.447.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/chinese_remainder_theorem.yuki.447.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 13:15:42+09:00


* see: <a href="https://yukicoder.me/problems/447">https://yukicoder.me/problems/447</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/chinese_remainder_theorem.hpp.html">lib/chinese_remainder_theorem.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/extgcd.hpp.html">lib/extgcd.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include <tuple>
#include "../lib/chinese_remainder_theorem.hpp"

int main() {
    long long x, y; std::cin >> x >> y;
    for (int i = 0; i < 2; i++) {
        long long a, b; std::cin >> a >> b;
        std::tie(y, x) = crt(y, x, b, a);
        if (x == -1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << (x == 0 ? y : x) << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/chinese_remainder_theorem.yuki.447.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include <tuple>
#line 1 "lib/chinese_remainder_theorem.hpp"



#include <utility>
#line 1 "lib/extgcd.hpp"



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


#line 6 "test/chinese_remainder_theorem.yuki.447.test.cpp"

int main() {
    long long x, y; std::cin >> x >> y;
    for (int i = 0; i < 2; i++) {
        long long a, b; std::cin >> a >> b;
        std::tie(y, x) = crt(y, x, b, a);
        if (x == -1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << (x == 0 ? y : x) << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

