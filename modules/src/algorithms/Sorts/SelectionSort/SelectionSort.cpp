// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <limits>
#include <stdexcept>
module Sort;
// import List;

namespace algorithms {
    template<std::totally_ordered T>
    void SelectionSort<T>::sort(typename ASort<T>::ASortableList *data) {
        if (data == nullptr) throw std::invalid_argument("Null pointer");
        if (data->size() <= 1) return;
        this->m_data = data;
        for (size_t i = 0; i < data->size() - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < this->m_data->size(); ++j) {
                if (this->m_data->at(j) < this->m_data->at(minIndex)) {
                    minIndex = j;
                }
            }
            if (minIndex != i) this->exchange(i, minIndex);
        }
    }
}
