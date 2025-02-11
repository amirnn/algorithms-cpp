//
// Created by Amir Nourinia on 11.02.25.
//
module;
#include <sys/types.h>
#include <cmath>
#include <numbers>
#include <print>
#include <sstream>
export module SortTests;

import DSA;

export namespace tests {
template <typename T>
void selectionSortTest(datastructures::ASortableList<T>& list,
                       int64_t const sampleCount = 128) {
  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin<double>(i * delta) + 1);
  }
  std::println(" list.size() = {}. Populated again!", list.size());

  list.template sort<SelectionSort<double>>();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    const auto val = list.popFront() * 100;
    std::stringstream ss;
    for (auto j = 0; j < static_cast<int>(val); j++) {
      ss << ".";
    }
    std::println("{}", ss.str());
  }
}

template <typename T>
void insertionSortTest(datastructures::ASortableList<T>& list,
                       int64_t const sampleCount = 128) {

  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  list.clear();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin<double>(i * delta) + 1);
  }
  std::println(" list.size() = {}. Populated again!", list.size());
  list.template sort<InsertionSort<double>>();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    const auto val = list.popFront() * 100;
    std::stringstream ss;
    for (auto j = 0; j < static_cast<int>(val); j++) {
      ss << ".";
    }
    std::println("{}", ss.str());
  }
}
}  // namespace tests