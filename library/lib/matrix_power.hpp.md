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


# :heavy_check_mark: lib/matrix_power.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/matrix_power.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 04:31:48+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/matrix_power.yuki.1050.test.cpp.html">test/matrix_power.yuki.1050.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef CPLIB_LIB_MATRIX_POWER_H_
#define CPLIB_LIB_MATRIX_POWER_H_

#include <iostream>
#include <vector>
#include <cassert>

// Matrix power
template<typename T>
class Matrix {
public:
    Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}
    Matrix(int n, int m, T init_val) : dat(n, std::vector<T>(m, init_val)) {}
    Matrix(int n) : Matrix(n, n) {}
    Matrix(int n, T init_val) : Matrix(n, n, init_val) {}
    std::vector<T> &operator[](size_t idx) { return dat[idx]; }
    const std::vector<T> &operator[](size_t idx) const { return dat[idx]; }
    size_t size() const { return dat.size(); }

private:
    std::vector<std::vector<T>> dat;
};
template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            out << a[i][j] << " \n"[j == (int)a[i].size() - 1];
        }
    }
    return out;
}

template<typename T>
Matrix<T> matmul(const Matrix<T> &a, const Matrix<T> &b) {
    int n = (int)a.size();
    int m = (int)b[0].size();
    int r = (int)b.size();
    assert(a[0].size() == r);
    Matrix<T> ret(n, m);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> matpow(Matrix<T> a, long long p) {
    int n = (int)a.size();
    Matrix<T> ret(n);
    for (int i = 0; i < n; i++) ret[i][i] = 1;
    while (p > 0) {
        if (p & 1) ret = matmul(ret, a);
        a = matmul(a, a);
        p >>= 1LL;
    }
    return ret;
}

#endif  // CPLIB_LIB_MATRIX_POWER_H_

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/matrix_power.hpp"



#include <iostream>
#include <vector>
#include <cassert>

// Matrix power
template<typename T>
class Matrix {
public:
    Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}
    Matrix(int n, int m, T init_val) : dat(n, std::vector<T>(m, init_val)) {}
    Matrix(int n) : Matrix(n, n) {}
    Matrix(int n, T init_val) : Matrix(n, n, init_val) {}
    std::vector<T> &operator[](size_t idx) { return dat[idx]; }
    const std::vector<T> &operator[](size_t idx) const { return dat[idx]; }
    size_t size() const { return dat.size(); }

private:
    std::vector<std::vector<T>> dat;
};
template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            out << a[i][j] << " \n"[j == (int)a[i].size() - 1];
        }
    }
    return out;
}

template<typename T>
Matrix<T> matmul(const Matrix<T> &a, const Matrix<T> &b) {
    int n = (int)a.size();
    int m = (int)b[0].size();
    int r = (int)b.size();
    assert(a[0].size() == r);
    Matrix<T> ret(n, m);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> matpow(Matrix<T> a, long long p) {
    int n = (int)a.size();
    Matrix<T> ret(n);
    for (int i = 0; i < n; i++) ret[i][i] = 1;
    while (p > 0) {
        if (p & 1) ret = matmul(ret, a);
        a = matmul(a, a);
        p >>= 1LL;
    }
    return ret;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

