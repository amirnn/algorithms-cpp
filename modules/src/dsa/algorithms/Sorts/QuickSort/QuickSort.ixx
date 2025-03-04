// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
export module DSA:Sort.QuickSort;

import :Sort.ASort;

namespace algorithms {
template <std::totally_ordered T> class QuickSort final : ASort<T> {
public:
  void sort(typename ASort<T>::ASortableList *data) override;
};

template<std::totally_ordered T>
void QuickSort<T>::sort(typename ASort<T>::ASortableList* data) {
  if(data == nullptr) throw std::invalid_argument("Null pointer");
  this->m_data = data;
}

} // namespace algorithms
