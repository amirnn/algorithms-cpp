// Copyright 2025 by Amir Nourinia

#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <sstream>

import DSA;

int main (int argc, char** argv) {
  using namespace datastructures;
  using namespace algorithms;

  SortableDoublyLinkedListQueue<double> list;

  constexpr auto pi = std::numbers::pi_v<double>;
  constexpr double samples = 1024.0;
  constexpr double delta = (2 * pi / samples);

  // for (auto i = 0; i < static_cast<int>(samples); i++) {
  //   list.pushBack(std::sin<double>(i * delta) + 1);
  // }
  // std::println(" list.size() = {}. Populated again!", list.size());
  //
  // list.sort<SelectionSort<double>>();
  // for (auto i = 0; i < static_cast<int>(samples); i++) {
  //   const auto val = list.popFront() * 100;
  //   std::stringstream ss;
  //   for (auto j = 0; j < static_cast<int>(val); j++) {
  //     ss << ".";
  //   }
  //   std::println("{}", ss.str());
  // }

  list.clear();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin<double>(i * delta) + 1);
  }
  std::println(" list.size() = {}. Populated again!", list.size());
  list.sort<InsertionSort<double>>();
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    const auto val = list.popFront() * 100;
    std::stringstream ss;
    for (auto j = 0; j < static_cast<int>(val); j++) {
      ss << ".";
    }
    std::println("{}", ss.str());
  }

}
