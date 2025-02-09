# Copyright 2025 by Amir Nourinia
# src

add_library(datastructures-and-algorithms STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
# and https://www.kitware.com/import-cmake-the-experiment-is-over/
# also interesting, https://www.kitware.com/import-std-in-cmake-3-30/
target_sources(datastructures-and-algorithms
        PRIVATE
        #datastructures
        src/datastructures/List/AList.cpp
        src/datastructures/ListQueue/ListQueue.cpp
        src/datastructures/DynamicArray/DynamicArray.cpp
        #algorithms
        src/algorithms/Sorts/ASort/ASort.cpp
        src/algorithms/Sorts/HeapSort/HeapSort.cpp
        src/algorithms/Sorts/InsertionSort/InsertionSort.cpp
        src/algorithms/Sorts/MergeSort/MergeSort.cpp
        src/algorithms/Sorts/QuickSort/QuickSort.cpp
        src/algorithms/Sorts/SelectionSort/SelectionSort.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        include/datastructures
        include/algorithms
        # partitions
        src/datastructures
        src/algorithms
        FILES
        # data structures
        include/datastructures/List.ixx
        src/datastructures/List/AList.ixx
        src/datastructures/ListQueue/ListQueue.ixx
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

add_executable(main)
target_sources(main
        PRIVATE
        src/test/main.cpp
)

target_link_libraries(main PRIVATE datastructures-and-algorithms)

