// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
module Sort;
import List;

namespace algorithms {

    template<std::totally_ordered T>
    void MergeSort<T>::sort(datastructures::ASortableList<T>* data) {
        if(data == nullptr) throw std::invalid_argument("Null pointer");
        this->m_data = data;
    }

    template<std::totally_ordered T>
    void MergeSort<T>::merge() noexcept {
    }
}
