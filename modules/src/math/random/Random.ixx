// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <cstdint>
#include <pcg_random.hpp>
#include <random>
export module DSA:Math.Random;

export namespace random {

/**
* @param p probability to be true
* @return if it was true
*/
template <std::floating_point T>
[[nodiscard]] bool bernoulli(T p) {

  // Seed with a real random value, if available
  pcg_extras::seed_seq_from<std::random_device> seed_source;

  // Make a random number engine
  pcg32 rng(seed_source);

  std::bernoulli_distribution bernoulli_distribution(p);
  bool const value = bernoulli_distribution(rng);
  return value;
}

/**
* @return a sample: double, from a uniform distribution over interval [a,b]
*/
template <std::floating_point T>
[[nodiscard]] T uniform(T a, T b) {
  // Seed with a real random value, if available
  pcg_extras::seed_seq_from<std::random_device> seed_source;
  // Make a random number engine
  pcg32 rng(seed_source);

  // Choose a random mean between 1 and 6
  std::uniform_real_distribution<T> uniform_dist(a, b);
  T const value = uniform_dist(rng);
  return value;
}

template <std::integral T>
[[nodiscard]] T uniform(T a, T b) {
  return static_cast<T>(uniform_dist<long double>(a, b));
}
}  // namespace random