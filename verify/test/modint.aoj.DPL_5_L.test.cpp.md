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


# :heavy_check_mark: test/modint.aoj.DPL_5_L.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/modint.aoj.DPL_5_L.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 18:52:06+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/modint.hpp.html">lib/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L"

#include <iostream>
#include <vector>
#include "../lib/modint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    if (n < k) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<std::vector<Mint>> dp(n - k + 2, std::vector<Mint>(k + 2));
    for (int i = 0; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] += dp[i - j][j];
        }
    }
    std::cout << dp[n - k][k] << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/modint.aoj.DPL_5_L.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L"

#include <iostream>
#include <vector>
#line 1 "lib/modint.hpp"



#line 5 "lib/modint.hpp"

// Modint
struct Mint {
    static const long long mod = (long long)1e9 + 7;
    long long val;

    Mint() { val = 0; }
    Mint(long long a) { val = a; verify_value(); }

    void verify_value() {
        if (val >= mod) val %= mod;
        if (val < 0) val %= mod, val += mod;
    }

    Mint pow(long long p) const {
        Mint cur = Mint(val), ret = 1;
        while (p > 0) {
            if (p & 1) ret *= cur;
            cur *= cur;
            p >>= 1LL;
        }
        return ret;
    }
    Mint inv() const {
        if (val == 0)
            std::cerr << "WARNING: inv() is called with 0." << std::endl;
        return pow(mod - 2);
    }

    Mint operator+() const { return *this; }
    Mint operator-() const { return Mint(mod - val); }

    Mint operator+=(const Mint &a) {
        val += a.val;
        if (val >= mod) val -= mod;
        return Mint(val);
    }
    Mint operator*=(const Mint &a) {
        val *= a.val;
        if (val >= mod) val %= mod;
        return Mint(val);
    }
    Mint operator-=(const Mint &a) { return *this += -a; }
    Mint operator/=(const Mint &a) { return *this *= a.inv(); }

    Mint operator++() { return *this += Mint(1); }
    Mint operator--() { return *this -= Mint(1); }
    Mint operator++(int) {
        Mint ret = *this;
        ++(*this);
        return ret;
    }
    Mint operator--(int) {
        Mint ret = *this;
        --(*this);
        return ret;
    }

    operator long long() const { return val; }
};

Mint operator+(const Mint &a, const Mint &b) {
    long long ret = a.val + b.val;
    if (ret >= Mint::mod) ret -= Mint::mod;
    return Mint(ret);
}
Mint operator*(const Mint &a, const Mint &b) {
    long long ret = a.val * b.val;
    if (ret >= Mint::mod) ret %= Mint::mod;
    return Mint(ret);
}
Mint operator-(const Mint &a, const Mint &b) { return a + (-b); }
Mint operator/(const Mint &a, const Mint &b) { return a * b.inv(); }

std::ostream &operator<<(std::ostream &out, const Mint &a) { return out << a.val; }
std::istream &operator>>(std::istream &in, Mint &a) {
    in >> a.val;
    a.verify_value();
    return in;
}

Mint pow(Mint a, long long b) {
    return a.pow(b);
}


#line 6 "test/modint.aoj.DPL_5_L.test.cpp"

int main() {
    int n, k; std::cin >> n >> k;
    if (n < k) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<std::vector<Mint>> dp(n - k + 2, std::vector<Mint>(k + 2));
    for (int i = 0; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n - k; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] += dp[i - j][j];
        }
    }
    std::cout << dp[n - k][k] << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

