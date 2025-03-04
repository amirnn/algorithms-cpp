//
// Created by amirn on 04/03/2025.
//

module;
#include <concepts>
export module Geometry:Matrix;

export namespace geometry {

template <typename T, size_t r, size_t c, bool row_major, bool is_static>
  requires std::is_arithmetic_v<T>
class Matrix {};
} // namespace Matrix