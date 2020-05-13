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


# :heavy_check_mark: lib/random_number_generator.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/random_number_generator.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 08:50:08+09:00




## Required by

* :heavy_check_mark: <a href="rolling_hash.hpp.html">lib/rolling_hash.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/rolling_hash.aoj.2444.test.cpp.html">test/rolling_hash.aoj.2444.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/rolling_hash.yuki.430.test.cpp.html">test/rolling_hash.yuki.430.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_
#define CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_

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

#endif  // CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

