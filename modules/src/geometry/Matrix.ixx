//
// Created by amirn on 04/03/2025.
//

module;
#include <array>
#include <concepts>
#include <ranges>
#include <vector>
export module Geometry:Matrix;

export namespace geometry {

template <typename T, size_t r, size_t c, bool row_major = true,
          bool is_static = true>
  requires std::is_arithmetic_v<T>
class Matrix {
  using UnderlyingDataType =
      std::conditional_t<is_static, std::array<T, r * c>, std::vector<T>>;

  using GeneralizedUnderlyingField =
      std::conditional_t<std::is_floating_point_v<T>, long double, double>;

 public:
  Matrix() {
    if constexpr (is_static) {
      for (size_t i = 0; i < m_matrixSize; ++i) {
        m_data.at(i) = 0;
      }
    } else {
      m_data = std::vector<T>(m_matrixSize, 0);
    }
  }

  Matrix(Matrix const& other) : Matrix() {
    // if it is vector create a vector of that size
    // if constexpr (not is_static) {
    //   m_data = std::vector<T>(m_matrixSize, 0);
    // }
    for (size_t i = 0; i < m_matrixSize; ++i) {
      m_data.at(i) = other.m_data.at(i);
    }
  }

  // getters
  T& operator[](size_t const i, size_t const j) {
    size_t const index = mappedIndex(i, j);
    return m_data.at(index);
  }

  T const& operator[](size_t const i, size_t const j) const {
    size_t const index = mappedIndex(i, j);
    return m_data.at(index);
  }

 private:
  [[nodiscard]] static size_t mappedIndex(size_t const i, size_t const j) {
    if constexpr (row_major) {
      size_t const index = (i * r) + j;
      return index;
    } else {
      size_t const index = (j * c) + i;
      return index;
    }
  }

 public:
  std::ranges::random_access_range auto column(size_t const j) const noexcept {
    using namespace std::ranges::views;
    size_t stride = 0ul;
    if constexpr (row_major) {
      stride = c;
    } else {
      stride = 1;
    }
    return m_data | std::ranges::views::stride(stride) | take(r) | as_const;
  }

  std::ranges::random_access_range auto column(size_t const j) noexcept {
    using namespace std::ranges::views;
    size_t stride = 0ul;
    if constexpr (row_major) {
      stride = c;
    } else {
      stride = 1;
    }
    return m_data | std::ranges::views::stride(stride) | take(r);
  }

  /**
   * Get a copy of column
   * @param j
   * @return copy of column j
   */
  std::vector<T> columnAsVector(size_t const j) const noexcept {
    return std::ranges::to<std::vector<T>>(column(j));
  }

  std::ranges::random_access_range auto row(size_t const i) const noexcept {
    using namespace std::ranges::views;
    size_t stride = 0ul;
    if constexpr (row_major) {
      stride = 1;
    } else {
      stride = r;
    }
    return m_data | std::ranges::views::stride(stride) | take(c) | as_const;
  }

  std::ranges::random_access_range auto row(size_t const i) noexcept {
    using namespace std::ranges::views;
    size_t stride = 0ul;
    if constexpr (row_major) {
      stride = 1;
    } else {
      stride = r;
    }
    return m_data | std::ranges::views::stride(stride) | take(c);
  }

  /**
   * Get a copy of the row
   * @param i
   * @return a vector of row i
   */
  std::vector<T> rowAsVector(size_t const i) const noexcept {
    return std::ranges::to<std::vector<T>>(row(i));
  }

  // setters
  void transpose() noexcept {
    UnderlyingDataType newData;
    if constexpr (not is_static) {
      newData = std::vector<T>(m_matrixSize, 0);
    }
    for (size_t i = 0; i < r; ++i) {
      for (size_t j = 0; j < c; ++j) {
        newData.at(j, i) = m_data.at(i, j);
      }
    }
    m_data = std::move(newData);
  }

  // arithmetic
  [[nodiscard]] GeneralizedUnderlyingField determinant() const noexcept
    requires(r == c)
  {
    auto const& [p, l, u] = LUDecompose(*this);
    GeneralizedUnderlyingField product = 0;
    for (size_t i = 0; i < r; ++i) {
      product += l[i, i] * u[i, i] * p[i, i];
    }
    return product;
  }

  struct LUDecomposition {
    Matrix P;
    Matrix L;
    Matrix U;
  };

  static LUDecomposition LUDecompose(Matrix& matrix) noexcept
    requires(r == c)
  {

    return {};
  }

 private:
  UnderlyingDataType m_data;
  size_t const m_matrixSize = r * c;
};

}  // namespace geometry