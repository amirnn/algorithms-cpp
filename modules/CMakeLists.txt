# Copyright 2025 by Amir Nourinia
# src

set(ARTIFACT_NAME_DSA dsa)

add_library(${ARTIFACT_NAME_DSA} STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
# and https://www.kitware.com/import-cmake-the-experiment-is-over/
# also interesting, https://www.kitware.com/import-std-in-cmake-3-30/
target_sources(${ARTIFACT_NAME_DSA}
        PRIVATE
        # implementation units *.cpp
        #datastructures
        #algorithms
        # math
        # utils
        src/dsa/utils/io/IO.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        # interfaces
        include/dsa
        # partitions
        src/dsa/datastructures
        src/dsa/algorithms
        src/dsa/math
        src/dsa/utils
        FILES
        # main interface
        include/dsa/DSA.ixx
        # data structures
        include/dsa/datastructures/List.ixx
        src/dsa/datastructures/List/AList.ixx
        src/dsa/datastructures/ListQueue/DoublyLinkedListQueue.ixx
        src/dsa/datastructures/List/ASortableList.ixx
        src/dsa/datastructures/ListQueue/SortableDoublyLinkedListQueue.ixx
        src/dsa/datastructures/DynamicArray/DynamicArray.ixx
        src/dsa/datastructures/DynamicArray/SortableDynamicArray.ixx
        # algorithms
        include/dsa/algorithms/Sort.ixx
        src/dsa/algorithms/Sorts/ASort/ASort.ixx
        src/dsa/algorithms/Sorts/HeapSort/HeapSort.ixx
        src/dsa/algorithms/Sorts/InsertionSort/InsertionSort.ixx
        src/dsa/algorithms/Sorts/ShellSort/ShellSort.ixx
        src/dsa/algorithms/Sorts/MergeSort/MergeSort.ixx
        src/dsa/algorithms/Sorts/QuickSort/QuickSort.ixx
        src/dsa/algorithms/Sorts/SelectionSort/SelectionSort.ixx
        # math
        include/dsa/math/Math.ixx
        src/dsa/math/la/Matrix.ixx
        src/dsa/math/random/Random.ixx
        # utils
        include/dsa/utils/Utils.ixx
        src/dsa/utils/io/IO.ixx
)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/install.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/export.cmake)

add_subdirectory(test)