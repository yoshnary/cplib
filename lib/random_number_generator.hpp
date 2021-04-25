#ifndef CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_
#define CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_

#include <random>
#include <chrono>

class RandomNumberGenerator {
public:
    RandomNumberGenerator()
        : seed(std::chrono::steady_clock::now().time_since_epoch().count())
        , mt(seed) {}

    unsigned long long operator()() { return mt(); }

    // Generate a random integer in a range [lo, hi).
    unsigned long long operator()(
        unsigned long long lo, unsigned long long hi = -1) {

        if (hi == -1) {
            hi = lo;
            lo = 0;
        }
        std::uniform_int_distribution<unsigned long long> dist(lo, hi - 1);
        return dist(mt);
    }

    void set_seed(int s) { seed = s; mt = decltype(mt)(seed); }
    long long get_seed() const { return seed; }

private:
    long long seed;
    std::mt19937_64 mt;
};

#endif  // CPLIB_LIB_RANDOM_NUMBER_GENERATOR_H_
