// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <sys/types.h>
module Sort;

namespace algorithms {
    template<std::totally_ordered T>
    bool ASort<T>::isSorted() const noexcept {
        auto& data = *m_data;
        for (int64_t i = 0; i < data.size() - 1; ++i) {
            if (data[i] > data[i + 1]) {
                return false;
            }
        }
        return true;
    }

    template<std::totally_ordered T>
    void ASort<T>::exchange(int64_t i, int64_t j) {
        auto& data = *m_data;
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}
