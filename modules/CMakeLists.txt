# Copyright 2025 by Amir Nourinia
# src

add_library(dsa-cpp STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
# and https://www.kitware.com/import-cmake-the-experiment-is-over/
# also interesting, https://www.kitware.com/import-std-in-cmake-3-30/
target_sources(dsa-cpp
        PRIVATE
        #        implementation units *.cpp
        #        #datastructures
        #        #algorithms
        # math

        # utils
        src/utils/io/IO.cpp

        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        include/
        # partitions
        src/datastructures
        src/algorithms
        src/math
        src/utils
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
        src/datastructures/DynamicArray/SortableDynamicArray.ixx
        # algorithms
        include/algorithms/Sort.ixx
        src/algorithms/Sorts/ASort/ASort.ixx
        src/algorithms/Sorts/HeapSort/HeapSort.ixx
        src/algorithms/Sorts/InsertionSort/InsertionSort.ixx
        src/algorithms/Sorts/MergeSort/MergeSort.ixx
        src/algorithms/Sorts/QuickSort/QuickSort.ixx
        src/algorithms/Sorts/SelectionSort/SelectionSort.ixx
        # math
        include/math/Math.ixx
        src/math/la/Matrix.ixx
        src/math/random/Random.ixx
        # utils
        include/utils/Utils.ixx
        src/utils/io/IO.ixx
)

# ListQueueTests
add_executable(ListTests)
target_sources(ListTests
        PRIVATE
        src/test/list-tests.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        src/test/ListTests
        FILES
        src/test/ListTests/ListTests.ixx
)

target_link_libraries(ListTests PRIVATE dsa-cpp)

# SortTests
add_executable(SortTests)
target_sources(SortTests
        PRIVATE
        src/test/sort-tests.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        src/test/SortTests
        FILES
        src/test/SortTests/SortTests.ixx
)
target_link_libraries(SortTests PRIVATE dsa-cpp)
