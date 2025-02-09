// Copyright 2025 by Amir Nourinia

#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <sstream>

import List;
import Sort;

int main(int32_t argc, char **argv) {
  using namespace datastructures;
  using namespace algorithms;
  ListQueue<double> list;

  for (auto i = 0; i < 100; i++) {
    list.pushBack(static_cast<double>(i) + 0.5 );
  }
  for (auto i = 0; i < 10; i++) {
    std::println(" list[{}] = {}", i, list[list.size() - i - 1]);
  }
  std::cout << '\n';
  std::cout.flush();
  list.clear();
  std::println(" list.size() = {}, after clear.", list.size());
  constexpr auto pi = std::numbers::pi_v<double>;
  constexpr double samples = 64.0;
  constexpr double delta = (2 * pi / samples);
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin<double>(i * delta) + 1);
  }
  std::println(" list.size() = {}. Populated again!", list.size());
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    const auto val = list.popBack() * 50;
    std::stringstream ss;
    for (auto j = 0; j < static_cast<int>(val); j++) {
      ss << "*";
    }
    std::println("{}", ss.str());
  }

  for (auto i = 0; i < static_cast<int>(samples); i++) {
    list.pushBack(std::sin<double>(i * delta) + 1);
  }
  std::println(" list.size() = {}. Populated again!", list.size());
  for (auto i = 0; i < static_cast<int>(samples); i++) {
    const auto val = list.popFront() * 100;
    std::stringstream ss;
    for (auto j = 0; j < static_cast<int>(val); j++) {
      ss << "*";
    }
    std::println("{}", ss.str());
  }

  std::println(" list.size() = {}", list.size());

  list.pushAt(0, 0);
  for (auto i = 0; i < 10; ++i) {
    list.pushAt(i, i);
  }
  std::println(" list.size() = {}", list.size());
  for (auto i = 0; i < 11; ++i) {
    std::println(" list[{}] = {}", list.size() - i - 1, list[list.size() - i - 1]);
  }

  return EXIT_SUCCESS;
}
