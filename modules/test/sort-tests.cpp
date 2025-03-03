// Copyright 2025 by Amir Nourinia

import DSA;
import SortTests;

int main ([[maybe_unused]] int argc,[[maybe_unused]] char** argv) {

  // datastructures::SortableDoublyLinkedListQueue<double> list;
  // tests::selectionSortTest(list);
  // list.clear();
  //
  // tests::insertionSortTest(list);
  // list.clear();

  datastructures::SortableDynamicArray<double> array;
  // datastructures::SortableDoublyLinkedListQueue<double> queue;
  // tests::selectionSortTest(array);
  // array.clear();

  // tests::insertionSortTest(array);
  // array.clear();

  tests::shellSortTest(array);
  array.clear();

}
