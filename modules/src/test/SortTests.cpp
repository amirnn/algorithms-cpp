// Copyright 2025 by Amir Nourinia

#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <sstream>

import DSA;
import SortTests;

int main (int argc, char** argv) {

  datastructures::SortableDoublyLinkedListQueue<double> list;
  tests::selectionSortTest(list);
  list.clear();

  tests::insertionSortTest(list);
  list.clear();
}
