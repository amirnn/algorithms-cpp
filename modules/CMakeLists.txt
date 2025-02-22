# Copyright 2025 by Amir Nourinia
# src

set(ARTIFACT_NAME dsa)

add_library(${ARTIFACT_NAME} STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
# and https://www.kitware.com/import-cmake-the-experiment-is-over/
# also interesting, https://www.kitware.com/import-std-in-cmake-3-30/
target_sources(${ARTIFACT_NAME}
        PRIVATE
        # implementation units *.cpp
        #datastructures
        #algorithms
        # math
        # utils
        src/utils/io/IO.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        # interfaces
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

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/install.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/export.cmake)

add_subdirectory(test)