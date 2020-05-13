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


# :heavy_check_mark: test/rolling_hash.yuki.430.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/rolling_hash.yuki.430.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 09:41:42+09:00


* see: <a href="https://yukicoder.me/problems/no/430">https://yukicoder.me/problems/no/430</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/random_number_generator.hpp.html">lib/random_number_generator.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/rolling_hash.hpp.html">lib/rolling_hash.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <map>
#include "../lib/rolling_hash.hpp"

int main() {
    std::string s; std::cin >> s;
    int n = s.size();
    int m; std::cin >> m;
    std::vector<std::string> t(m);
    for (int i = 0; i < m; i++) std::cin >> t[i];
    DoubleRollingHash rh(s);
    auto base = rh.get_base();
    std::map<decltype(rh.hash(0, 0)), int> cnt;
    for (int d = 1; d <= 10; d++) {
        for (int i = 0; i + d <= n; i++) {
            cnt[rh.hash(i, i + d)]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto hash = DoubleRollingHash(
            t[i], base.first, base.second).hash(0, t[i].size());
        ans += cnt[hash];
    }
    std::cout << ans << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/rolling_hash.yuki.430.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <map>
#line 1 "lib/rolling_hash.hpp"



#include <vector>
#line 6 "lib/rolling_hash.hpp"
#include <utility>
#line 1 "lib/random_number_generator.hpp"



#include <random>
#include <chrono>

class RandomNumberGenerator {
public:
    RandomNumberGenerator()
        : seed(std::chrono::steady_clock::now().time_since_epoch().count())
        , mt(seed) {}

    unsigned long long operator()() { return mt(); }

    // Generate a random integer in a range [lo, hi).
    unsigned long long operator()(
        unsigned long long lo, unsigned long long hi = -1) {

        if (hi == -1) {
            hi = lo;
            lo = 0;
        }
        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);
        return dist(mt);
    }

    void set_seed(int s) { seed = s; mt = decltype(mt)(seed); }
    long long get_seed() const { return seed; }

private:
    long long seed;
    std::mt19937_64 mt;
};


#line 8 "lib/rolling_hash.hpp"

class RollingHash {
public:
    RollingHash(const std::string &s, unsigned long long base = -1)
        : base(base != -1 ? base : rng(1ULL << 12, mod))
        , base_p(s.size() + 1)
        , chash(s.size() + 1) {

        build(s);
    }

    // Hash a substring corresponding to a range [left, right).
    unsigned long long hash(int left, int right) {
        unsigned long long ret = chash[right] + mod
            - multiply(chash[left], base_p[right - left]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned long long get_base() { return base; }

private:
    static constexpr unsigned long long mod = (1ULL << 61) - 1;
    RandomNumberGenerator rng;

    const unsigned long long base;
    std::vector<unsigned long long> base_p;
    std::vector<unsigned long long> chash;

    unsigned long long multiply(unsigned long long a, unsigned long long b) {
        static constexpr unsigned long long M30 = (1ULL << 30) - 1;
        static constexpr unsigned long long M31 = (1ULL << 31) - 1;
        unsigned long long
            au = a >> 31, ad = a & M31, bu = b >> 31, bd = b & M31,
            m = ad * bu + au * bd, mu = m >> 30, md = m & M30;
        return (2 * au * bu + mu + (md << 31) + ad * bd) % mod;
    }

    void build(const std::string &s) {
        int n = s.size();
        base_p[0] = 1;
        for (int i = 0; i < n; i++) {
            chash[i + 1] = (multiply(chash[i], base) + s[i]) % mod;
            base_p[i + 1] = multiply(base_p[i], base);
        }
    }
};

class DoubleRollingHash {
public:
    DoubleRollingHash(const std::string &s,
        unsigned long long basel = -1, unsigned long long baser = -1)
        : hashl(s, basel), hashr(s, baser) {}

    std::pair<unsigned long long, unsigned long long>
    hash(int left, int right) {
        return { hashl.hash(left, right), hashr.hash(left, right) };
    }

    std::pair<unsigned long long, unsigned long long>
    get_base() { return { hashl.get_base(), hashr.get_base() }; }

private:
    RollingHash hashl, hashr;
};


#line 7 "test/rolling_hash.yuki.430.test.cpp"

int main() {
    std::string s; std::cin >> s;
    int n = s.size();
    int m; std::cin >> m;
    std::vector<std::string> t(m);
    for (int i = 0; i < m; i++) std::cin >> t[i];
    DoubleRollingHash rh(s);
    auto base = rh.get_base();
    std::map<decltype(rh.hash(0, 0)), int> cnt;
    for (int d = 1; d <= 10; d++) {
        for (int i = 0; i + d <= n; i++) {
            cnt[rh.hash(i, i + d)]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto hash = DoubleRollingHash(
            t[i], base.first, base.second).hash(0, t[i].size());
        ans += cnt[hash];
    }
    std::cout << ans << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

