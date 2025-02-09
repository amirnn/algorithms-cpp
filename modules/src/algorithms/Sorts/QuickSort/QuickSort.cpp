// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
module Sort;

namespace algorithms {
    template<std::totally_ordered T>
    void QuickSort<T>::sort(typename ASort<T>::ASortableList* data) {
        if(data == nullptr) throw std::invalid_argument("Null pointer");
        this->m_data = data;
    }
}
