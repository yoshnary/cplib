---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix_power.yuki.1050.test.cpp
    title: test/matrix_power.yuki.1050.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/matrix_power.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n#include <cassert>\n\n// Matrix power\ntemplate<typename T>\nclass\
    \ Matrix {\npublic:\n    Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}\n\
    \    Matrix(int n, int m, T init_val) : dat(n, std::vector<T>(m, init_val)) {}\n\
    \    Matrix(int n) : Matrix(n, n) {}\n    Matrix(int n, T init_val) : Matrix(n,\
    \ n, init_val) {}\n    std::vector<T> &operator[](size_t idx) { return dat[idx];\
    \ }\n    const std::vector<T> &operator[](size_t idx) const { return dat[idx];\
    \ }\n    size_t size() const { return dat.size(); }\n\nprivate:\n    std::vector<std::vector<T>>\
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
    \ p >>= 1LL;\n    }\n    return ret;\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_MATRIX_POWER_H_\n#define CPLIB_LIB_MATRIX_POWER_H_\n\n\
    #include <iostream>\n#include <vector>\n#include <cassert>\n\n// Matrix power\n\
    template<typename T>\nclass Matrix {\npublic:\n    Matrix(int n, int m) : dat(n,\
    \ std::vector<T>(m)) {}\n    Matrix(int n, int m, T init_val) : dat(n, std::vector<T>(m,\
    \ init_val)) {}\n    Matrix(int n) : Matrix(n, n) {}\n    Matrix(int n, T init_val)\
    \ : Matrix(n, n, init_val) {}\n    std::vector<T> &operator[](size_t idx) { return\
    \ dat[idx]; }\n    const std::vector<T> &operator[](size_t idx) const { return\
    \ dat[idx]; }\n    size_t size() const { return dat.size(); }\n\nprivate:\n  \
    \  std::vector<std::vector<T>> dat;\n};\ntemplate<typename T>\nstd::ostream &operator<<(std::ostream\
    \ &out, const Matrix<T> &a) {\n    for (int i = 0; i < (int)a.size(); i++) {\n\
    \        for (int j = 0; j < (int)a[i].size(); j++) {\n            out << a[i][j]\
    \ << \" \\n\"[j == (int)a[i].size() - 1];\n        }\n    }\n    return out;\n\
    }\n\ntemplate<typename T>\nMatrix<T> matmul(const Matrix<T> &a, const Matrix<T>\
    \ &b) {\n    int n = (int)a.size();\n    int m = (int)b[0].size();\n    int r\
    \ = (int)b.size();\n    assert(a[0].size() == r);\n    Matrix<T> ret(n, m);\n\
    \    for (int i = 0; i < n; i++) {\n        for (int k = 0; k < r; k++) {\n  \
    \          for (int j = 0; j < m; j++) {\n                ret[i][j] += a[i][k]\
    \ * b[k][j];\n            }\n        }\n    }\n    return ret;\n}\n\ntemplate<typename\
    \ T>\nMatrix<T> matpow(Matrix<T> a, long long p) {\n    int n = (int)a.size();\n\
    \    Matrix<T> ret(n);\n    for (int i = 0; i < n; i++) ret[i][i] = 1;\n    while\
    \ (p > 0) {\n        if (p & 1) ret = matmul(ret, a);\n        a = matmul(a, a);\n\
    \        p >>= 1LL;\n    }\n    return ret;\n}\n\n#endif  // CPLIB_LIB_MATRIX_POWER_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/matrix_power.hpp
  requiredBy: []
  timestamp: '2020-05-09 04:31:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix_power.yuki.1050.test.cpp
documentation_of: lib/matrix_power.hpp
layout: document
redirect_from:
- /library/lib/matrix_power.hpp
- /library/lib/matrix_power.hpp.html
title: lib/matrix_power.hpp
---
