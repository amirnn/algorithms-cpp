// Copyright 2025 by Amir Nourinia

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include <numbers>


import DSA;
import SortTests;


TEST_CASE("Selection-Sort using Deque", "selection-sort-deque") {
  datastructures::SortableDoublyLinkedListQueue<double> queue;
  tests::selectionSortTest(queue, 2048, false);
  REQUIRE(queue.isSorted());
}

TEST_CASE("Selection Sort using DynamicArray", "selection-sort-dynamic-array") {
  datastructures::SortableDynamicArray<double> array;
  tests::selectionSortTest(array, 8192, false);
  REQUIRE(array.isSorted());
}

TEST_CASE("Insertion-Sort using Deque", "insertion-sort-deque") {
  datastructures::SortableDoublyLinkedListQueue<double> queue;
  tests::insertionSortTest(queue, 2048, false);
  REQUIRE(queue.isSorted());
}

TEST_CASE("Insertion-Sort using DynamicArray", "insertion-sort-dynamic-array") {
  datastructures::SortableDynamicArray<double> array;
  tests::insertionSortTest(array, 8192, false);
  REQUIRE(array.isSorted());
}

TEST_CASE("Shell-Sort using Deque", "shell-sort-deque") {
  datastructures::SortableDoublyLinkedListQueue<double> queue;
  tests::shellSortTest(queue, 2048, false);
  REQUIRE(queue.isSorted());
}

TEST_CASE("Shell-Sort using DynamicArray", "shell-sort-dynamic-array") {
  datastructures::SortableDynamicArray<double> array;
  tests::shellSortTest(array, 8192, false);
  REQUIRE(array.isSorted());
}


TEST_CASE("Merge-Sort using Deque", "merge-sort-deque") {
  datastructures::SortableDoublyLinkedListQueue<double> queue;
  tests::mergeSortTest(queue, 2048, false);
  REQUIRE(queue.isSorted());
}

TEST_CASE("Merge-Sort using DynamicArray", "merge-sort-dynamic-array") {
  datastructures::SortableDynamicArray<double> array;
  tests::mergeSortTest(array, 8192, false);
  REQUIRE(array.isSorted());
}

// int main ([[maybe_unused]] int argc,[[maybe_unused]] char** argv) {
//
//   // datastructures::SortableDoublyLinkedListQueue<double> list;
//   // tests::selectionSortTest(list);
//   // list.clear();
//   //
//   // tests::insertionSortTest(list);
//   // list.clear();
//
//   // datastructures::SortableDynamicArray<double> array;
//   // datastructures::SortableDoublyLinkedListQueue<double> queue;
//   // tests::selectionSortTest(array);
//   // array.clear();
//
//   // tests::insertionSortTest(array);
//   // array.clear();
//
//   // tests::shellSortTest(array);
//   // array.clear();
//
// }
