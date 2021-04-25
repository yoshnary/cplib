---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/matrix_power.hpp
    title: lib/matrix_power.hpp
  - icon: ':heavy_check_mark:'
    path: lib/modint.hpp
    title: lib/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1050
    links:
    - https://yukicoder.me/problems/no/1050
  bundledCode: "#line 1 \"test/matrix_power.yuki.1050.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1050\"\n\n#include <iostream>\n#line 1 \"\
    lib/matrix_power.hpp\"\n\n\n\n#line 5 \"lib/matrix_power.hpp\"\n#include <vector>\n\
    #include <cassert>\n\n// Matrix power\ntemplate<typename T>\nclass Matrix {\n\
    public:\n    Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}\n    Matrix(int\
    \ n, int m, T init_val) : dat(n, std::vector<T>(m, init_val)) {}\n    Matrix(int\
    \ n) : Matrix(n, n) {}\n    Matrix(int n, T init_val) : Matrix(n, n, init_val)\
    \ {}\n    std::vector<T> &operator[](size_t idx) { return dat[idx]; }\n    const\
    \ std::vector<T> &operator[](size_t idx) const { return dat[idx]; }\n    size_t\
    \ size() const { return dat.size(); }\n\nprivate:\n    std::vector<std::vector<T>>\
    \ dat;\n};\ntemplate<typename T>\nstd::ostream &operator<<(std::ostream &out,\
    \ const Matrix<T> &a) {\n    for (int i = 0; i < (int)a.size(); i++) {\n     \
    \   for (int j = 0; j < (int)a[i].size(); j++) {\n            out << a[i][j] <<\
    \ \" \\n\"[j == (int)a[i].size() - 1];\n        }\n    }\n    return out;\n}\n\
    \ntemplate<typename T>\nMatrix<T> matmul(const Matrix<T> &a, const Matrix<T> &b)\
    \ {\n    int n = (int)a.size();\n    int m = (int)b[0].size();\n    int r = (int)b.size();\n\
    \    assert(a[0].size() == r);\n    Matrix<T> ret(n, m);\n    for (int i = 0;\
    \ i < n; i++) {\n        for (int k = 0; k < r; k++) {\n            for (int j\
    \ = 0; j < m; j++) {\n                ret[i][j] += a[i][k] * b[k][j];\n      \
    \      }\n        }\n    }\n    return ret;\n}\n\ntemplate<typename T>\nMatrix<T>\
    \ matpow(Matrix<T> a, long long p) {\n    int n = (int)a.size();\n    Matrix<T>\
    \ ret(n);\n    for (int i = 0; i < n; i++) ret[i][i] = 1;\n    while (p > 0) {\n\
    \        if (p & 1) ret = matmul(ret, a);\n        a = matmul(a, a);\n       \
    \ p >>= 1LL;\n    }\n    return ret;\n}\n\n\n#line 1 \"lib/modint.hpp\"\n\n\n\n\
    #line 5 \"lib/modint.hpp\"\n\n// Modint\nstruct Mint {\n    static const long\
    \ long mod = (long long)1e9 + 7;\n    long long val;\n\n    Mint() { val = 0;\
    \ }\n    Mint(long long a) { val = a; verify_value(); }\n\n    void verify_value()\
    \ {\n        if (val >= mod) val %= mod;\n        if (val < 0) val %= mod, val\
    \ += mod;\n    }\n\n    Mint pow(long long p) const {\n        Mint cur = Mint(val),\
    \ ret = 1;\n        while (p > 0) {\n            if (p & 1) ret *= cur;\n    \
    \        cur *= cur;\n            p >>= 1LL;\n        }\n        return ret;\n\
    \    }\n    Mint inv() const {\n        if (val == 0)\n            std::cerr <<\
    \ \"WARNING: inv() is called with 0.\" << std::endl;\n        return pow(mod -\
    \ 2);\n    }\n\n    Mint operator+() const { return *this; }\n    Mint operator-()\
    \ const { return Mint(mod - val); }\n\n    Mint operator+=(const Mint &a) {\n\
    \        val += a.val;\n        if (val >= mod) val -= mod;\n        return Mint(val);\n\
    \    }\n    Mint operator*=(const Mint &a) {\n        val *= a.val;\n        if\
    \ (val >= mod) val %= mod;\n        return Mint(val);\n    }\n    Mint operator-=(const\
    \ Mint &a) { return *this += -a; }\n    Mint operator/=(const Mint &a) { return\
    \ *this *= a.inv(); }\n\n    Mint operator++() { return *this += Mint(1); }\n\
    \    Mint operator--() { return *this -= Mint(1); }\n    Mint operator++(int)\
    \ {\n        Mint ret = *this;\n        ++(*this);\n        return ret;\n    }\n\
    \    Mint operator--(int) {\n        Mint ret = *this;\n        --(*this);\n \
    \       return ret;\n    }\n\n    operator long long() const { return val; }\n\
    };\n\nMint operator+(const Mint &a, const Mint &b) {\n    long long ret = a.val\
    \ + b.val;\n    if (ret >= Mint::mod) ret -= Mint::mod;\n    return Mint(ret);\n\
    }\nMint operator*(const Mint &a, const Mint &b) {\n    long long ret = a.val *\
    \ b.val;\n    if (ret >= Mint::mod) ret %= Mint::mod;\n    return Mint(ret);\n\
    }\nMint operator-(const Mint &a, const Mint &b) { return a + (-b); }\nMint operator/(const\
    \ Mint &a, const Mint &b) { return a * b.inv(); }\n\nstd::ostream &operator<<(std::ostream\
    \ &out, const Mint &a) { return out << a.val; }\nstd::istream &operator>>(std::istream\
    \ &in, Mint &a) {\n    in >> a.val;\n    a.verify_value();\n    return in;\n}\n\
    \nMint pow(Mint a, long long b) {\n    return a.pow(b);\n}\n\n\n#line 6 \"test/matrix_power.yuki.1050.test.cpp\"\
    \n\nint main() {\n    int m, k; std::cin >> m >> k;\n    Matrix<Mint> mat(m),\
    \ v(m, 1);\n    for (int i = 0; i < m; i++) {\n        for (int j = 0; j < m;\
    \ j++) {\n            mat[(j + i) % m][j]++;\n            mat[(j * i) % m][j]++;\n\
    \        }\n    }\n    v[0][0] = 1;\n    std::cout << matmul(matpow(mat, k), v)[0][0]\
    \ << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1050\"\n\n#include <iostream>\n\
    #include \"../lib/matrix_power.hpp\"\n#include \"../lib/modint.hpp\"\n\nint main()\
    \ {\n    int m, k; std::cin >> m >> k;\n    Matrix<Mint> mat(m), v(m, 1);\n  \
    \  for (int i = 0; i < m; i++) {\n        for (int j = 0; j < m; j++) {\n    \
    \        mat[(j + i) % m][j]++;\n            mat[(j * i) % m][j]++;\n        }\n\
    \    }\n    v[0][0] = 1;\n    std::cout << matmul(matpow(mat, k), v)[0][0] <<\
    \ std::endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/matrix_power.hpp
  - lib/modint.hpp
  isVerificationFile: true
  path: test/matrix_power.yuki.1050.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 18:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix_power.yuki.1050.test.cpp
layout: document
redirect_from:
- /verify/test/matrix_power.yuki.1050.test.cpp
- /verify/test/matrix_power.yuki.1050.test.cpp.html
title: test/matrix_power.yuki.1050.test.cpp
---
