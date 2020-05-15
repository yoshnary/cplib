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


# :heavy_check_mark: lib/knuth_morris_pratt.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/knuth_morris_pratt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 01:16:19+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp.html">test/knuth_morris_pratt.aoj.ALDS1_14_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_KNUTH_MORRIS_PRATT_H_
#define CPLIB_LIB_KNUTH_MORRIS_PRATT_H_

#include <vector>
#include <string>

// Find a string t from a string s.
// For each element i in returned vector,
// s.substr(i, t.size()) == t holds.
// Assume '#' is not in s and t.
// Actually, this is the Morris-Pratt algorithm.
std::vector<int> kmp(const std::string &s, std::string t) {
    int n = s.size(), m = t.size();
    std::vector<int> id(m + 1);
    id[0] = -1;
    int j = -1;
    for (int i = 0; i < m; i++) {
        while (j >= 0 && t[i] != t[j]) j = id[j];
        id[i + 1] = ++j;
    }
    t += '#';
    std::vector<int> ret;
    int is = 0, it = 0;
    while (is < n) {
        if (s[is] == t[it]) is++, it++;
        else if (it == 0) is++;
        else it = id[it];
        if (it == m) {
            ret.push_back(is - m);
        }
    }
    return ret;
}

#endif  // CPLIB_LIB_KNUTH_MORRIS_PRATT_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/knuth_morris_pratt.hpp"



#include <vector>
#include <string>

// Find a string t from a string s.
// For each element i in returned vector,
// s.substr(i, t.size()) == t holds.
// Assume '#' is not in s and t.
// Actually, this is the Morris-Pratt algorithm.
std::vector<int> kmp(const std::string &s, std::string t) {
    int n = s.size(), m = t.size();
    std::vector<int> id(m + 1);
    id[0] = -1;
    int j = -1;
    for (int i = 0; i < m; i++) {
        while (j >= 0 && t[i] != t[j]) j = id[j];
        id[i + 1] = ++j;
    }
    t += '#';
    std::vector<int> ret;
    int is = 0, it = 0;
    while (is < n) {
        if (s[is] == t[it]) is++, it++;
        else if (it == 0) is++;
        else it = id[it];
        if (it == m) {
            ret.push_back(is - m);
        }
    }
    return ret;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

