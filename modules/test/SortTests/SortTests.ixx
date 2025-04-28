// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <cmath>
#include <iomanip>
#include <numbers>
#include <print>
#include <sstream>
export module SortTests;

import DSA;

export namespace tests {
template <typename T>
void selectionSortTest(datastructures::ASortableList<T>& list,
                       size_t const sampleCount = 128,
                       bool const print = false) {
  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin(i * delta) + 1);
  }
  if (print) std::println(" list.size() = {}. Populated again!", list.size());

  list.template sort<SelectionSort<double>>();
  if (print) {
    for (auto i = 0; i < samples; i++) {
      const auto val = list.at(i) * 20;
      std::stringstream ss;
      for (auto j = 0; j < static_cast<int>(val); j++) {
        ss << ".";
      }
      std::println("{:100}", ss.str());
    }
    if (print) std::println(" list.size() = {}. Emptied!", list.size());
  }
}

template <typename T>
void insertionSortTest(datastructures::ASortableList<T>& list,
                       size_t const sampleCount = 128,
                       bool const print = false) {

  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  list.clear();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin(i * delta) + 1);
  }
  if (print) std::println(" list.size() = {}. Populated again!", list.size());
  list.template sort<InsertionSort<double>>();
  if (print) {
    for (auto i = 0; i < samples; i++) {
      const auto val = list.at(i) * 20;

      std::stringstream ss;
      for (auto j = 0; j < static_cast<int>(val); j++) {
        ss << ".";
      }
      std::println("{:100}", ss.str());
    }
    std::println(" list.size() = {}. Emptied!", list.size());
  }
}

template <typename T>
void shellSortTest(datastructures::ASortableList<T>& list,
                   size_t const sampleCount = 128, bool const print = false) {

  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  list.clear();
  for (auto i = 0; i < samples; i++) {
    list.pushBack(std::sin(i * delta) + 1);
  }
  if (print) std::println(" list.size() = {}. Populated again!", list.size());
  list.template sort<ShellSort<double>>();
  if (print) {
    for (auto i = 0; i < static_cast<int>(samples); i++) {
      const auto val = list.at(i) * 20;
      std::stringstream ss;
      for (auto j = 0; j < static_cast<int>(val); j++) {
        ss << ".";
      }
      std::println("{:100}", ss.str());
    }
    std::println(" list.size() = {}. Emptied!", list.size());
  }
}

template <typename T>
void mergeSortTest(datastructures::ASortableList<T>& list,
                   size_t const sampleCount = 128, bool const print = false) {

  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  list.clear();
  for (auto i = 0; i < samples; i++) {
    list.pushBack(std::sin(i * delta) + 1);
  }
  if (print) std::println(" list.size() = {}. Populated again!", list.size());
  list.template sort<MergeSort<double>>();
  if (print) {
    for (auto i = 0; i < static_cast<int>(samples); i++) {
      const auto val = list.at(i) * 20;
      std::stringstream ss;
      for (auto j = 0; j < static_cast<int>(val); j++) {
        ss << ".";
      }
      std::println("{:100}", ss.str());
    }
    std::println(" list.size() = {}. Emptied!", list.size());
  }
}


template <typename T>
void countingSortTest(datastructures::ASortableList<T>& list,
                   size_t const sampleCount = 128, bool const print = false) {

  using namespace datastructures;
  using namespace algorithms;
  constexpr auto pi = std::numbers::pi_v<double>;
  const auto samples = static_cast<double>(sampleCount);
  const double delta = (2 * pi / samples);

  list.clear();
  for (auto i = 0; i < samples; i++) {
    list.pushBack(static_cast<int32_t>((std::sin(i * delta) + 1) * 200));
  }
  if (print) std::println(" list.size() = {}. Populated again!", list.size());
  list.template sort<CountingSort<size_t>>();
  if (print) {
    for (auto i = 0; i < static_cast<int>(samples); i++) {
      const auto val = list.at(i) * 2;
      std::stringstream ss;
      for (auto j = 0; j < static_cast<int>(val); j++) {
        ss << ".";
      }
      std::println("{:100}", ss.str());
    }
    std::println(" list.size() = {}. Emptied!", list.size());
  }
}


}  // namespace tests