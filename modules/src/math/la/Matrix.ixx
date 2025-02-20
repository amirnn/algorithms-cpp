// Copyright 2025 by Amir Nourinia

module;
#include <cstdint>
export module DSA:Math.Matrix;

export namespace la {

    template <typename T>
    class Matrix {
    public:
        enum class DataMajor : uint8_t { RowMajor, ColumnMajor };
        Matrix(int64_t const rows, int64_t const cols, DataMajor data_major = DataMajor::ColumnMajor)
            : m_data_major(data_major), m_rows(rows), m_cols(cols) {
            m_data = new T[rows * cols];
            for (int64_t i = 0; i < rows * cols; i++) {
                m_data[i] = T{};
            }
        }

        explicit Matrix(int64_t n) : Matrix(n, n) {}

        ~Matrix() {
            delete[] m_data;
        }

        [[nodiscard]] int64_t GetRows() const {
            return m_rows;
        }
        [[nodiscard]] int64_t GetCols() const {
            return m_cols;
        }

        [[nodiscard]] DataMajor GetDataMajor() const {
            return m_data_major;
        }

        T& operator()(int64_t const row, int64_t const col) {
            if (m_data_major == DataMajor::ColumnMajor) {
                return m_data[col * m_rows + row];
            } else {
                return m_data[row * m_cols + col];
            }
        }
        T& operator()(int64_t const row, int64_t const col) const {
            if (m_data_major == DataMajor::ColumnMajor) {
                return m_data[col * m_rows + row];
            } else {
                return m_data[row * m_cols + col];
            }
        }

        T& operator()(int64_t const index) const {
            if (m_data_major == DataMajor::ColumnMajor) {
                auto const col = index / m_cols;
                auto const row = index % m_cols;
                return m_data[col * m_rows + row];
            } else {
                auto const row = index % m_rows;
                auto const col = index / m_cols;
                return m_data[row * m_cols + col];
            }
        }

        [[nodiscard]] int64_t GetIndex(int64_t const row, int64_t const col) const noexcept {
            if (m_data_major == DataMajor::ColumnMajor) {
                return col * m_rows + row;
            } else {
                return row * m_cols + col;
            }
        }

    private:
        DataMajor m_data_major{DataMajor::ColumnMajor};
        T* m_data;
        int64_t m_rows;
        int64_t m_cols;
    };

} // namespace bluecpp
