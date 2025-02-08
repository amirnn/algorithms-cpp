# src

add_library(datastructures-and-algorithms STATIC)
# thanks to https://gitlab.kitware.com/cmake/cmake/-/issues/25493
target_sources(datastructures-and-algorithms
        PRIVATE
        modules/algorithms/ASort.cpp
        modules/datastructures/List.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        modules/datastructures
        modules/algorithms
        FILES
        # data structures
        modules/datastructures/List.ixx
        # algorithms
        modules/algorithms/ASort.ixx
)

#add_library(algorithms STATIC)
#target_sources(algorithms
#        PUBLIC
#        FILE_SET all_modules
#        TYPE CXX_MODULES
#        BASE_DIRS modules/algorithms
#        FILES
#        modules/algorithms/ASort.ixx
#        modules/algorithms/ASort.cpp
#)
#target_link_libraries(algorithms PUBLIC datastructures)

add_executable(main)
target_sources(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
#target_link_libraries(main algorithms datastructures)

