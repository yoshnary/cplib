---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L
  bundledCode: "#line 1 \"test/modint.aoj.DPL_5_L.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L\"\
    \n\n#include <iostream>\n#include <vector>\n#line 1 \"lib/modint.hpp\"\n\n\n\n\
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
    \nMint pow(Mint a, long long b) {\n    return a.pow(b);\n}\n\n\n#line 6 \"test/modint.aoj.DPL_5_L.test.cpp\"\
    \n\nint main() {\n    int n, k; std::cin >> n >> k;\n    if (n < k) {\n      \
    \  std::cout << 0 << std::endl;\n        return 0;\n    }\n    std::vector<std::vector<Mint>>\
    \ dp(n - k + 2, std::vector<Mint>(k + 2));\n    for (int i = 0; i <= k; i++) dp[0][i]\
    \ = 1;\n    for (int i = 1; i <= n - k; i++) {\n        for (int j = 1; j <= k;\
    \ j++) {\n            dp[i][j] = dp[i][j - 1];\n            if (i >= j) dp[i][j]\
    \ += dp[i - j][j];\n        }\n    }\n    std::cout << dp[n - k][k] << std::endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../lib/modint.hpp\"\n\n\
    int main() {\n    int n, k; std::cin >> n >> k;\n    if (n < k) {\n        std::cout\
    \ << 0 << std::endl;\n        return 0;\n    }\n    std::vector<std::vector<Mint>>\
    \ dp(n - k + 2, std::vector<Mint>(k + 2));\n    for (int i = 0; i <= k; i++) dp[0][i]\
    \ = 1;\n    for (int i = 1; i <= n - k; i++) {\n        for (int j = 1; j <= k;\
    \ j++) {\n            dp[i][j] = dp[i][j - 1];\n            if (i >= j) dp[i][j]\
    \ += dp[i - j][j];\n        }\n    }\n    std::cout << dp[n - k][k] << std::endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - lib/modint.hpp
  isVerificationFile: true
  path: test/modint.aoj.DPL_5_L.test.cpp
  requiredBy: []
  timestamp: '2020-05-09 18:52:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint.aoj.DPL_5_L.test.cpp
layout: document
redirect_from:
- /verify/test/modint.aoj.DPL_5_L.test.cpp
- /verify/test/modint.aoj.DPL_5_L.test.cpp.html
title: test/modint.aoj.DPL_5_L.test.cpp
---
