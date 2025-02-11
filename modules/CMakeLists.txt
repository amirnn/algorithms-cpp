# Copyright 2025 by Amir Nourinia
# src

add_library(datastructures-and-algorithms STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
# and https://www.kitware.com/import-cmake-the-experiment-is-over/
# also interesting, https://www.kitware.com/import-std-in-cmake-3-30/
target_sources(datastructures-and-algorithms
        PRIVATE
#        implementation units *.cpp
#        #datastructures
#        #algorithms
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        include/
        # partitions
        src/datastructures
        src/algorithms
        FILES
        # main interface
        include/DSA.ixx
        # data structures
        include/datastructures/List.ixx
        src/datastructures/List/AList.ixx
        src/datastructures/ListQueue/DoublyLinkedListQueue.ixx
        src/datastructures/List/ASortableList.ixx
        src/datastructures/ListQueue/SortableDoublyLinkedListQueue.ixx
        src/datastructures/DynamicArray/DynamicArray.ixx
        # algorithms
        include/algorithms/Sort.ixx
        src/algorithms/Sorts/ASort/ASort.ixx
        src/algorithms/Sorts/HeapSort/HeapSort.ixx
        src/algorithms/Sorts/InsertionSort/InsertionSort.ixx
        src/algorithms/Sorts/MergeSort/MergeSort.ixx
        src/algorithms/Sorts/QuickSort/QuickSort.ixx
        src/algorithms/Sorts/SelectionSort/SelectionSort.ixx
)

# ListQueueTests
add_executable(ListQueueTests)
target_sources(ListQueueTests PRIVATE src/test/ListQueueTests.cpp)
target_link_libraries(ListQueueTests PRIVATE datastructures-and-algorithms)

# SortTests
add_executable(SortTests)
target_sources(SortTests PRIVATE src/test/SortTests.cpp)
target_link_libraries(SortTests PRIVATE datastructures-and-algorithms)
