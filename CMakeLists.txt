cmake_minimum_required(VERSION 3.31.0)
project("algorithms-sedgewick-cpp" VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    # warning level 4
    add_compile_options(/W4 /WX)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic
    # -Werror
    )
endif()


include("${CMAKE_CURRENT_SOURCE_DIR}/libs/libs.cmake")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/modules")