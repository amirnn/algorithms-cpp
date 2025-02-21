# Copyright 2025 by Amir Nourinia
cmake_minimum_required(VERSION 3.31)

project(algorithms-cpp VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# thanks to: https://cmake.org/cmake/help/latest/guide/importing-exporting/index.html
# make cache variables for install destinations
include(GNUInstallDirs)

include(CMakePackageConfigHelpers)

include(${CMAKE_CURRENT_SOURCE_DIR}/libs/libs.cmake)
add_subdirectory(modules)
