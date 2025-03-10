// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <limits>
#include <stdexcept>
#include <sys/types.h>
export module DSA:Sort.SelectionSort;
import :Sort.ASort;

export namespace algorithms {
template <std::totally_ordered T>
class SelectionSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override {
    if (data == nullptr) throw std::invalid_argument("Null pointer");
    if (data->isEmpty()) throw std::invalid_argument("Empty data");
    // mandatory
    this->m_data = data;
    auto& rdata = *data;
    // O(n)
    if (rdata.isSorted()) {
      return;
    }
    size_t const size = rdata.size();
    for (size_t i = 0; i < size - 1; ++i) {
      size_t minIndex = i;
      for (size_t j = i + 1; j < size; ++j) {
        if (rdata.at(j) < rdata.at(minIndex)) {
          minIndex = j;
        }
      }
      if (minIndex != i) rdata.exchange(i, minIndex);
    }
  }
};
}  // namespace algorithms
