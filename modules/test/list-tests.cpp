// Copyright 2025 by Amir Nourinia


#include <cstdint>
#include <cstdlib>
#include <catch2/catch_test_macros.hpp>

import DSA;
import ListTests;



TEST_CASE("Deque Push-Pop", "deque-push-pop") {
  tests::listQueueTests();
  REQUIRE(true);
}

TEST_CASE("Draw sin(x) using Deque", "deque-draw-sin") {
  tests::listQueueTests();
  REQUIRE(true);
}

TEST_CASE("DynamicArray Push-Pop", "dynamic-array-push-pop") {
  tests::dynamicArrayTests();
  REQUIRE(true);
}

TEST_CASE("Draw sin(x) using DynamicArray", "dynamic-array-draw-sin") {
  tests::dynamicArrayTests();
  REQUIRE(true);
}


// int main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
//
//
//   tests::dynamicArrayTests();
//   return EXIT_SUCCESS;
// }
