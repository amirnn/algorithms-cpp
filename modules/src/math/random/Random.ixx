// Copyright 2025 by Amir Nourinia

module;
#include <cstdint>
export module DSA:Math.Random;

export namespace random {

    /**
     * @param p probability to be true
     * @return if it was true
     */
    [[nodiscard]] bool bernoulli(double p);

    /**
     * @return a sample: double, from a uniform distribution over interval [a,b]
     */
    [[nodiscard]] double uniform(double a, double b);

    [[nodiscard]] int64_t uniform(int64_t a, int64_t b);
} // namespace bluecpp::random