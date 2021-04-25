---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/random_number_generator.hpp
    title: lib/random_number_generator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rolling_hash.aoj.2444.test.cpp
    title: test/rolling_hash.aoj.2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rolling_hash.yuki.430.test.cpp
    title: test/rolling_hash.yuki.430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/rolling_hash.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#line 1 \"lib/random_number_generator.hpp\"\n\n\
    \n\n#include <random>\n#include <chrono>\n\nclass RandomNumberGenerator {\npublic:\n\
    \    RandomNumberGenerator()\n        : seed(std::chrono::steady_clock::now().time_since_epoch().count())\n\
    \        , mt(seed) {}\n\n    unsigned long long operator()() { return mt(); }\n\
    \n    // Generate a random integer in a range [lo, hi).\n    unsigned long long\
    \ operator()(\n        unsigned long long lo, unsigned long long hi = -1) {\n\n\
    \        if (hi == -1) {\n            hi = lo;\n            lo = 0;\n        }\n\
    \        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);\n\
    \        return dist(mt);\n    }\n\n    void set_seed(int s) { seed = s; mt =\
    \ decltype(mt)(seed); }\n    long long get_seed() const { return seed; }\n\nprivate:\n\
    \    long long seed;\n    std::mt19937_64 mt;\n};\n\n\n#line 8 \"lib/rolling_hash.hpp\"\
    \n\nclass RollingHash {\npublic:\n    RollingHash(const std::string &s, unsigned\
    \ long long base = -1)\n        : base(base != -1 ? base : rng(1ULL << 12, mod))\n\
    \        , base_p(s.size() + 1)\n        , chash(s.size() + 1) {\n\n        build(s);\n\
    \    }\n\n    // Hash a substring corresponding to a range [left, right).\n  \
    \  unsigned long long hash(int left, int right) {\n        unsigned long long\
    \ ret = chash[right] + mod\n            - multiply(chash[left], base_p[right -\
    \ left]);\n        if (ret >= mod) ret -= mod;\n        return ret;\n    }\n\n\
    \    unsigned long long get_base() { return base; }\n\nprivate:\n    static constexpr\
    \ unsigned long long mod = (1ULL << 61) - 1;\n    RandomNumberGenerator rng;\n\
    \n    const unsigned long long base;\n    std::vector<unsigned long long> base_p;\n\
    \    std::vector<unsigned long long> chash;\n\n    unsigned long long multiply(unsigned\
    \ long long a, unsigned long long b) {\n        static constexpr unsigned long\
    \ long M30 = (1ULL << 30) - 1;\n        static constexpr unsigned long long M31\
    \ = (1ULL << 31) - 1;\n        unsigned long long\n            au = a >> 31, ad\
    \ = a & M31, bu = b >> 31, bd = b & M31,\n            m = ad * bu + au * bd, mu\
    \ = m >> 30, md = m & M30;\n        return (2 * au * bu + mu + (md << 31) + ad\
    \ * bd) % mod;\n    }\n\n    void build(const std::string &s) {\n        int n\
    \ = s.size();\n        base_p[0] = 1;\n        for (int i = 0; i < n; i++) {\n\
    \            chash[i + 1] = (multiply(chash[i], base) + s[i]) % mod;\n       \
    \     base_p[i + 1] = multiply(base_p[i], base);\n        }\n    }\n};\n\nclass\
    \ DoubleRollingHash {\npublic:\n    DoubleRollingHash(const std::string &s,\n\
    \        unsigned long long basel = -1, unsigned long long baser = -1)\n     \
    \   : hashl(s, basel), hashr(s, baser) {}\n\n    std::pair<unsigned long long,\
    \ unsigned long long>\n    hash(int left, int right) {\n        return { hashl.hash(left,\
    \ right), hashr.hash(left, right) };\n    }\n\n    std::pair<unsigned long long,\
    \ unsigned long long>\n    get_base() { return { hashl.get_base(), hashr.get_base()\
    \ }; }\n\nprivate:\n    RollingHash hashl, hashr;\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_ROLLING_HASH_H_\n#define CPLIB_LIB_ROLLING_HASH_H_\n\n\
    #include <vector>\n#include <string>\n#include <utility>\n#include \"../lib/random_number_generator.hpp\"\
    \n\nclass RollingHash {\npublic:\n    RollingHash(const std::string &s, unsigned\
    \ long long base = -1)\n        : base(base != -1 ? base : rng(1ULL << 12, mod))\n\
    \        , base_p(s.size() + 1)\n        , chash(s.size() + 1) {\n\n        build(s);\n\
    \    }\n\n    // Hash a substring corresponding to a range [left, right).\n  \
    \  unsigned long long hash(int left, int right) {\n        unsigned long long\
    \ ret = chash[right] + mod\n            - multiply(chash[left], base_p[right -\
    \ left]);\n        if (ret >= mod) ret -= mod;\n        return ret;\n    }\n\n\
    \    unsigned long long get_base() { return base; }\n\nprivate:\n    static constexpr\
    \ unsigned long long mod = (1ULL << 61) - 1;\n    RandomNumberGenerator rng;\n\
    \n    const unsigned long long base;\n    std::vector<unsigned long long> base_p;\n\
    \    std::vector<unsigned long long> chash;\n\n    unsigned long long multiply(unsigned\
    \ long long a, unsigned long long b) {\n        static constexpr unsigned long\
    \ long M30 = (1ULL << 30) - 1;\n        static constexpr unsigned long long M31\
    \ = (1ULL << 31) - 1;\n        unsigned long long\n            au = a >> 31, ad\
    \ = a & M31, bu = b >> 31, bd = b & M31,\n            m = ad * bu + au * bd, mu\
    \ = m >> 30, md = m & M30;\n        return (2 * au * bu + mu + (md << 31) + ad\
    \ * bd) % mod;\n    }\n\n    void build(const std::string &s) {\n        int n\
    \ = s.size();\n        base_p[0] = 1;\n        for (int i = 0; i < n; i++) {\n\
    \            chash[i + 1] = (multiply(chash[i], base) + s[i]) % mod;\n       \
    \     base_p[i + 1] = multiply(base_p[i], base);\n        }\n    }\n};\n\nclass\
    \ DoubleRollingHash {\npublic:\n    DoubleRollingHash(const std::string &s,\n\
    \        unsigned long long basel = -1, unsigned long long baser = -1)\n     \
    \   : hashl(s, basel), hashr(s, baser) {}\n\n    std::pair<unsigned long long,\
    \ unsigned long long>\n    hash(int left, int right) {\n        return { hashl.hash(left,\
    \ right), hashr.hash(left, right) };\n    }\n\n    std::pair<unsigned long long,\
    \ unsigned long long>\n    get_base() { return { hashl.get_base(), hashr.get_base()\
    \ }; }\n\nprivate:\n    RollingHash hashl, hashr;\n};\n\n#endif  // CPLIB_LIB_ROLLING_HASH_H_\n"
  dependsOn:
  - lib/random_number_generator.hpp
  isVerificationFile: false
  path: lib/rolling_hash.hpp
  requiredBy: []
  timestamp: '2020-05-13 09:41:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rolling_hash.yuki.430.test.cpp
  - test/rolling_hash.aoj.2444.test.cpp
documentation_of: lib/rolling_hash.hpp
layout: document
redirect_from:
- /library/lib/rolling_hash.hpp
- /library/lib/rolling_hash.hpp.html
title: lib/rolling_hash.hpp
---
