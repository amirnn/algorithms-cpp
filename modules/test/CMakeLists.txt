# modules/test

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

target_link_libraries(ListTests PRIVATE dsa-cpp)

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
target_link_libraries(SortTests PRIVATE dsa-cpp)