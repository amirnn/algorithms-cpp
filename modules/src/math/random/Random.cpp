//
// Created by amirn on 13/09/2024.
//

module;
#include <random>
#include <pcg_random.hpp>
export module DSA:Math.Random;

namespace random {
    bool bernoulli(double const p) {

        // Seed with a real random value, if available
        pcg_extras::seed_seq_from<std::random_device> seed_source;

        // Make a random number engine
        pcg32 rng(seed_source);

        std::bernoulli_distribution bernoulli_distribution(p);
        bool const value = bernoulli_distribution(rng);
        return value;
    }

    double uniform(double const a, double const b) {
        // Seed with a real random value, if available
        pcg_extras::seed_seq_from<std::random_device> seed_source;
        // Make a random number engine
        pcg32 rng(seed_source);

        // Choose a random mean between 1 and 6
        std::uniform_real_distribution<double> uniform_dist(a, b);
        double const value = uniform_dist(rng);
        return value;
    }

    Int64 uniform(Int64 const a, Int64 const b) {
        return static_cast<Int64>(uniform(static_cast<double>(a),static_cast<double>(b)));
    }

} // namespace bluecpp::random