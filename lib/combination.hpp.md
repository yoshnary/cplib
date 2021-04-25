---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/modint.hpp
    title: lib/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_C.test.cpp
    title: test/combination.aoj.DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_D.test.cpp
    title: test/combination.aoj.DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_E.test.cpp
    title: test/combination.aoj.DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_F.test.cpp
    title: test/combination.aoj.DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_G.test.cpp
    title: test/combination.aoj.DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/combination.aoj.DPL_5_I.test.cpp
    title: test/combination.aoj.DPL_5_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/combination.hpp\"\n\n\n\n#line 1 \"lib/modint.hpp\"\n\
    \n\n\n#include <iostream>\n\n// Modint\nstruct Mint {\n    static const long long\
    \ mod = (long long)1e9 + 7;\n    long long val;\n\n    Mint() { val = 0; }\n \
    \   Mint(long long a) { val = a; verify_value(); }\n\n    void verify_value()\
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
    \nMint pow(Mint a, long long b) {\n    return a.pow(b);\n}\n\n\n#line 5 \"lib/combination.hpp\"\
    \n#include <vector>\n\nconstexpr int MAX_N = 2000003;\nstd::vector<Mint> fact(MAX_N),\
    \ inv(MAX_N);\n\nvoid init_fact() {\n    fact[0] = inv[0] = 1;\n    for (long\
    \ long i = 1; i < MAX_N; i++) {\n        fact[i] = fact[i - 1] * Mint(i);\n  \
    \      inv[i] = fact[i].inv();\n    }\n}\n\n// aCb\nMint C(int a, int b) {\n \
    \   if (a < 0 || b < 0 || a < b) return 0;\n    Mint res = fact[a];\n    res *=\
    \ inv[b];\n    res *= inv[a - b];\n    return res;\n}\n\n// aPb\nMint P(int a,\
    \ int b) {\n    if (a < 0 || a < b) return 0;\n    return fact[a] * inv[a - b];\n\
    }\n\n// aHb\nMint H(int a, int b) {\n    if (b == 0) return 1;\n    return C(a\
    \ + b - 1, b);\n}\n\n\n"
  code: "#ifndef CPLIB_LIB_COMBINATION_H_\n#define CPLIB_LIB_COMBINATION_H_\n\n#include\
    \ \"../lib/modint.hpp\"\n#include <vector>\n\nconstexpr int MAX_N = 2000003;\n\
    std::vector<Mint> fact(MAX_N), inv(MAX_N);\n\nvoid init_fact() {\n    fact[0]\
    \ = inv[0] = 1;\n    for (long long i = 1; i < MAX_N; i++) {\n        fact[i]\
    \ = fact[i - 1] * Mint(i);\n        inv[i] = fact[i].inv();\n    }\n}\n\n// aCb\n\
    Mint C(int a, int b) {\n    if (a < 0 || b < 0 || a < b) return 0;\n    Mint res\
    \ = fact[a];\n    res *= inv[b];\n    res *= inv[a - b];\n    return res;\n}\n\
    \n// aPb\nMint P(int a, int b) {\n    if (a < 0 || a < b) return 0;\n    return\
    \ fact[a] * inv[a - b];\n}\n\n// aHb\nMint H(int a, int b) {\n    if (b == 0)\
    \ return 1;\n    return C(a + b - 1, b);\n}\n\n#endif  // CPLIB_LIB_COMBINATION_H_\n"
  dependsOn:
  - lib/modint.hpp
  isVerificationFile: false
  path: lib/combination.hpp
  requiredBy: []
  timestamp: '2020-05-13 18:08:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/combination.aoj.DPL_5_G.test.cpp
  - test/combination.aoj.DPL_5_I.test.cpp
  - test/combination.aoj.DPL_5_F.test.cpp
  - test/combination.aoj.DPL_5_C.test.cpp
  - test/combination.aoj.DPL_5_D.test.cpp
  - test/combination.aoj.DPL_5_E.test.cpp
documentation_of: lib/combination.hpp
layout: document
redirect_from:
- /library/lib/combination.hpp
- /library/lib/combination.hpp.html
title: lib/combination.hpp
---
