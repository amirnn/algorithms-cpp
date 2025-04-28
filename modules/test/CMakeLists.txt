# modules/test

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../libs/catch2 libs/catch2)
#find_package(Catch2 3 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/catch2 REQUIRED)

# disable extra targets added by ctest
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
include(CTest)
include(Catch)

# ListQueueTests
add_executable(ListTests)
target_sources(ListTests
        PRIVATE
        list-tests.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        ListTests
        FILES
        ListTests/ListTests.ixx
)
target_link_libraries(ListTests PRIVATE dsa Catch2::Catch2WithMain)
catch_discover_tests(ListTests)

# SortTests
add_executable(SortTests)
target_sources(SortTests
        PRIVATE
        sort-tests.cpp
        PUBLIC
        FILE_SET all_modules
        TYPE CXX_MODULES
        BASE_DIRS
        SortTests
        FILES
        SortTests/SortTests.ixx
)
target_link_libraries(SortTests PRIVATE dsa Catch2::Catch2WithMain)
catch_discover_tests(SortTests)
