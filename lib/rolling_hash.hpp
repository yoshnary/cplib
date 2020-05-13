#ifndef CPLIB_LIB_ROLLING_HASH_H_
#define CPLIB_LIB_ROLLING_HASH_H_

#include "../lib/random_number_generator.hpp"

class RollingHash {
public:
    RollingHash(const std::string &s, unsigned long long base = -1)
        : base(base != -1 ? base : rng(1ULL << 12, mod))
        , base_p(s.size() + 1)
        , chash(s.size() + 1) {

        build(s);
    }

    // Hash a substring corresponding to a range [left, right).
    unsigned long long hash(int left, int right) {
        unsigned long long ret = chash[right] + mod
            - multiply(chash[left], base_p[right - left]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned long long get_base() { return base; }

private:
    static constexpr unsigned long long mod = (1ULL << 61) - 1;
    RandomNumberGenerator rng;

    const unsigned long long base;
    std::vector<unsigned long long> base_p;
    std::vector<unsigned long long> chash;

    unsigned long long multiply(unsigned long long a, unsigned long long b) {
        static constexpr unsigned long long M30 = (1ULL << 30) - 1;
        static constexpr unsigned long long M31 = (1ULL << 31) - 1;
        unsigned long long
            au = a >> 31, ad = a & M31, bu = b >> 31, bd = b & M31,
            m = ad * bu + au * bd, mu = m >> 30, md = m & M30;
        return (2 * au * bu + mu + (md << 31) + ad * bd) % mod;
    }

    void build(const std::string &s) {
        int n = s.size();
        base_p[0] = 1;
        for (int i = 0; i < n; i++) {
            chash[i + 1] = (multiply(chash[i], base) + s[i]) % mod;
            base_p[i + 1] = multiply(base_p[i], base);
        }
    }
};

class DoubleRollingHash {
public:
    DoubleRollingHash(const std::string &s,
        unsigned long long basel = -1, unsigned long long baser = -1)
        : hashl(s, basel), hashr(s, baser) {}

    std::pair<unsigned long long, unsigned long long>
    hash(int left, int right) {
        return { hashl.hash(left, right), hashr.hash(left, right) };
    }

    std::pair<unsigned long long, unsigned long long>
    get_base() { return { hashl.get_base(), hashr.get_base() }; }

private:
    RollingHash hashl, hashr;
};

#endif  // CPLIB_LIB_ROLLING_HASH_H_
