#ifndef CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_
#define CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_

#include <random>
#include <chrono>

class RandomNumberGenerator {
public:
    RandomNumberGenerator()
        : seed(std::chrono::steady_clock::now().time_since_epoch().count())
        , mt(seed) {}

    long long operator()() { return mt(); }

    // Generate a random integer in a range [lo, hi).
    long long operator()(long long lo, long long hi = -1) {
        if (hi == -1) {
            hi = lo;
            lo = 0;
        }
        return std::uniform_int_distribution<long long>(lo, hi - 1)(mt);
    }

    void set_seed(int s) { seed = s; mt = decltype(mt)(seed); }
    int get_seed() const { return seed; }

private:
    int seed;
    std::mt19937_64 mt;
};

#endif  // CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_
