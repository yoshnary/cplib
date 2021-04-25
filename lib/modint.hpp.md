---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/combination.hpp
    title: lib/combination.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_C.test.cpp
    title: test/combination.aoj.DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_C.test.cpp
    title: test/combination.aoj.DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_D.test.cpp
    title: test/combination.aoj.DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_D.test.cpp
    title: test/combination.aoj.DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_E.test.cpp
    title: test/combination.aoj.DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_E.test.cpp
    title: test/combination.aoj.DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_F.test.cpp
    title: test/combination.aoj.DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_F.test.cpp
    title: test/combination.aoj.DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_G.test.cpp
    title: test/combination.aoj.DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_G.test.cpp
    title: test/combination.aoj.DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_I.test.cpp
    title: test/combination.aoj.DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_I.test.cpp
    title: test/combination.aoj.DPL_5_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix_power.yuki.1050.test.cpp
    title: test/matrix_power.yuki.1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint.aoj.DPL_5_B.test.cpp
    title: test/modint.aoj.DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint.aoj.DPL_5_J.test.cpp
    title: test/modint.aoj.DPL_5_J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint.aoj.DPL_5_L.test.cpp
    title: test/modint.aoj.DPL_5_L.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint.yuki.666.test.cpp
    title: test/modint.yuki.666.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.aoj.DPL_5_A.test.cpp
    title: test/modint_pow.aoj.DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.aoj.NTL_1_B.test.cpp
    title: test/modint_pow.aoj.NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/modint.hpp\"\n\n\n\n#include <iostream>\n\n// Modint\n\
    struct Mint {\n    static const long long mod = (long long)1e9 + 7;\n    long\
    \ long val;\n\n    Mint() { val = 0; }\n    Mint(long long a) { val = a; verify_value();\
    \ }\n\n    void verify_value() {\n        if (val >= mod) val %= mod;\n      \
    \  if (val < 0) val %= mod, val += mod;\n    }\n\n    Mint pow(long long p) const\
    \ {\n        Mint cur = Mint(val), ret = 1;\n        while (p > 0) {\n       \
    \     if (p & 1) ret *= cur;\n            cur *= cur;\n            p >>= 1LL;\n\
    \        }\n        return ret;\n    }\n    Mint inv() const {\n        if (val\
    \ == 0)\n            std::cerr << \"WARNING: inv() is called with 0.\" << std::endl;\n\
    \        return pow(mod - 2);\n    }\n\n    Mint operator+() const { return *this;\
    \ }\n    Mint operator-() const { return Mint(mod - val); }\n\n    Mint operator+=(const\
    \ Mint &a) {\n        val += a.val;\n        if (val >= mod) val -= mod;\n   \
    \     return Mint(val);\n    }\n    Mint operator*=(const Mint &a) {\n       \
    \ val *= a.val;\n        if (val >= mod) val %= mod;\n        return Mint(val);\n\
    \    }\n    Mint operator-=(const Mint &a) { return *this += -a; }\n    Mint operator/=(const\
    \ Mint &a) { return *this *= a.inv(); }\n\n    Mint operator++() { return *this\
    \ += Mint(1); }\n    Mint operator--() { return *this -= Mint(1); }\n    Mint\
    \ operator++(int) {\n        Mint ret = *this;\n        ++(*this);\n        return\
    \ ret;\n    }\n    Mint operator--(int) {\n        Mint ret = *this;\n       \
    \ --(*this);\n        return ret;\n    }\n\n    operator long long() const { return\
    \ val; }\n};\n\nMint operator+(const Mint &a, const Mint &b) {\n    long long\
    \ ret = a.val + b.val;\n    if (ret >= Mint::mod) ret -= Mint::mod;\n    return\
    \ Mint(ret);\n}\nMint operator*(const Mint &a, const Mint &b) {\n    long long\
    \ ret = a.val * b.val;\n    if (ret >= Mint::mod) ret %= Mint::mod;\n    return\
    \ Mint(ret);\n}\nMint operator-(const Mint &a, const Mint &b) { return a + (-b);\
    \ }\nMint operator/(const Mint &a, const Mint &b) { return a * b.inv(); }\n\n\
    std::ostream &operator<<(std::ostream &out, const Mint &a) { return out << a.val;\
    \ }\nstd::istream &operator>>(std::istream &in, Mint &a) {\n    in >> a.val;\n\
    \    a.verify_value();\n    return in;\n}\n\nMint pow(Mint a, long long b) {\n\
    \    return a.pow(b);\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_MODINT_H_\n#define CPLIB_LIB_MODINT_H_\n\n#include <iostream>\n\
    \n// Modint\nstruct Mint {\n    static const long long mod = (long long)1e9 +\
    \ 7;\n    long long val;\n\n    Mint() { val = 0; }\n    Mint(long long a) { val\
    \ = a; verify_value(); }\n\n    void verify_value() {\n        if (val >= mod)\
    \ val %= mod;\n        if (val < 0) val %= mod, val += mod;\n    }\n\n    Mint\
    \ pow(long long p) const {\n        Mint cur = Mint(val), ret = 1;\n        while\
    \ (p > 0) {\n            if (p & 1) ret *= cur;\n            cur *= cur;\n   \
    \         p >>= 1LL;\n        }\n        return ret;\n    }\n    Mint inv() const\
    \ {\n        if (val == 0)\n            std::cerr << \"WARNING: inv() is called\
    \ with 0.\" << std::endl;\n        return pow(mod - 2);\n    }\n\n    Mint operator+()\
    \ const { return *this; }\n    Mint operator-() const { return Mint(mod - val);\
    \ }\n\n    Mint operator+=(const Mint &a) {\n        val += a.val;\n        if\
    \ (val >= mod) val -= mod;\n        return Mint(val);\n    }\n    Mint operator*=(const\
    \ Mint &a) {\n        val *= a.val;\n        if (val >= mod) val %= mod;\n   \
    \     return Mint(val);\n    }\n    Mint operator-=(const Mint &a) { return *this\
    \ += -a; }\n    Mint operator/=(const Mint &a) { return *this *= a.inv(); }\n\n\
    \    Mint operator++() { return *this += Mint(1); }\n    Mint operator--() { return\
    \ *this -= Mint(1); }\n    Mint operator++(int) {\n        Mint ret = *this;\n\
    \        ++(*this);\n        return ret;\n    }\n    Mint operator--(int) {\n\
    \        Mint ret = *this;\n        --(*this);\n        return ret;\n    }\n\n\
    \    operator long long() const { return val; }\n};\n\nMint operator+(const Mint\
    \ &a, const Mint &b) {\n    long long ret = a.val + b.val;\n    if (ret >= Mint::mod)\
    \ ret -= Mint::mod;\n    return Mint(ret);\n}\nMint operator*(const Mint &a, const\
    \ Mint &b) {\n    long long ret = a.val * b.val;\n    if (ret >= Mint::mod) ret\
    \ %= Mint::mod;\n    return Mint(ret);\n}\nMint operator-(const Mint &a, const\
    \ Mint &b) { return a + (-b); }\nMint operator/(const Mint &a, const Mint &b)\
    \ { return a * b.inv(); }\n\nstd::ostream &operator<<(std::ostream &out, const\
    \ Mint &a) { return out << a.val; }\nstd::istream &operator>>(std::istream &in,\
    \ Mint &a) {\n    in >> a.val;\n    a.verify_value();\n    return in;\n}\n\nMint\
    \ pow(Mint a, long long b) {\n    return a.pow(b);\n}\n\n#endif  // CPLIB_LIB_MODINT_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/modint.hpp
  requiredBy:
  - lib/combination.hpp
  timestamp: '2020-05-09 02:54:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix_power.yuki.1050.test.cpp
  - test/modint_pow.aoj.DPL_5_A.test.cpp
  - test/modint.aoj.DPL_5_L.test.cpp
  - test/combination.aoj.DPL_5_G.test.cpp
  - test/combination.aoj.DPL_5_G.test.cpp
  - test/combination.aoj.DPL_5_I.test.cpp
  - test/combination.aoj.DPL_5_I.test.cpp
  - test/combination.aoj.DPL_5_F.test.cpp
  - test/combination.aoj.DPL_5_F.test.cpp
  - test/modint.aoj.DPL_5_B.test.cpp
  - test/modint.aoj.DPL_5_J.test.cpp
  - test/combination.aoj.DPL_5_C.test.cpp
  - test/combination.aoj.DPL_5_C.test.cpp
  - test/combination.aoj.DPL_5_D.test.cpp
  - test/combination.aoj.DPL_5_D.test.cpp
  - test/modint.yuki.666.test.cpp
  - test/combination.aoj.DPL_5_E.test.cpp
  - test/combination.aoj.DPL_5_E.test.cpp
  - test/modint_pow.aoj.NTL_1_B.test.cpp
documentation_of: lib/modint.hpp
layout: document
redirect_from:
- /library/lib/modint.hpp
- /library/lib/modint.hpp.html
title: lib/modint.hpp
---
