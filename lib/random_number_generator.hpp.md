---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/rolling_hash.hpp
    title: lib/rolling_hash.hpp
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
  bundledCode: "#line 1 \"lib/random_number_generator.hpp\"\n\n\n\n#include <random>\n\
    #include <chrono>\n\nclass RandomNumberGenerator {\npublic:\n    RandomNumberGenerator()\n\
    \        : seed(std::chrono::steady_clock::now().time_since_epoch().count())\n\
    \        , mt(seed) {}\n\n    unsigned long long operator()() { return mt(); }\n\
    \n    // Generate a random integer in a range [lo, hi).\n    unsigned long long\
    \ operator()(\n        unsigned long long lo, unsigned long long hi = -1) {\n\n\
    \        if (hi == -1) {\n            hi = lo;\n            lo = 0;\n        }\n\
    \        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);\n\
    \        return dist(mt);\n    }\n\n    void set_seed(int s) { seed = s; mt =\
    \ decltype(mt)(seed); }\n    long long get_seed() const { return seed; }\n\nprivate:\n\
    \    long long seed;\n    std::mt19937_64 mt;\n};\n\n\n"
  code: "#ifndef CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_\n#define CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_\n\
    \n#include <random>\n#include <chrono>\n\nclass RandomNumberGenerator {\npublic:\n\
    \    RandomNumberGenerator()\n        : seed(std::chrono::steady_clock::now().time_since_epoch().count())\n\
    \        , mt(seed) {}\n\n    unsigned long long operator()() { return mt(); }\n\
    \n    // Generate a random integer in a range [lo, hi).\n    unsigned long long\
    \ operator()(\n        unsigned long long lo, unsigned long long hi = -1) {\n\n\
    \        if (hi == -1) {\n            hi = lo;\n            lo = 0;\n        }\n\
    \        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);\n\
    \        return dist(mt);\n    }\n\n    void set_seed(int s) { seed = s; mt =\
    \ decltype(mt)(seed); }\n    long long get_seed() const { return seed; }\n\nprivate:\n\
    \    long long seed;\n    std::mt19937_64 mt;\n};\n\n#endif  // CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/random_number_generator.hpp
  requiredBy:
  - lib/rolling_hash.hpp
  timestamp: '2020-05-13 08:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rolling_hash.yuki.430.test.cpp
  - test/rolling_hash.aoj.2444.test.cpp
documentation_of: lib/random_number_generator.hpp
layout: document
redirect_from:
- /library/lib/random_number_generator.hpp
- /library/lib/random_number_generator.hpp.html
title: lib/random_number_generator.hpp
---
