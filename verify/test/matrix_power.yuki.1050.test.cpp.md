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


# :heavy_check_mark: test/matrix_power.yuki.1050.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/matrix_power.yuki.1050.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 18:52:06+09:00


* see: <a href="https://yukicoder.me/problems/no/1050">https://yukicoder.me/problems/no/1050</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/matrix_power.hpp.html">lib/matrix_power.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/modint.hpp.html">lib/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include <iostream>
#include "../lib/matrix_power.hpp"
#include "../lib/modint.hpp"

int main() {
    int m, k; std::cin >> m >> k;
    Matrix<Mint> mat(m), v(m, 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            mat[(j + i) % m][j]++;
            mat[(j * i) % m][j]++;
        }
    }
    v[0][0] = 1;
    std::cout << matmul(matpow(mat, k), v)[0][0] << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/matrix_power.yuki.1050.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include <iostream>
#line 1 "lib/matrix_power.hpp"



#line 5 "lib/matrix_power.hpp"
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


#line 6 "test/matrix_power.yuki.1050.test.cpp"

int main() {
    int m, k; std::cin >> m >> k;
    Matrix<Mint> mat(m), v(m, 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            mat[(j + i) % m][j]++;
            mat[(j * i) % m][j]++;
        }
    }
    v[0][0] = 1;
    std::cout << matmul(matpow(mat, k), v)[0][0] << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

