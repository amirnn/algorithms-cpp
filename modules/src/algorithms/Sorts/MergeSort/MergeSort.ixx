// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
#include <sys/types.h>
export module DSA:Sort.MergeSort;
import :Sort.ASort;

namespace algorithms {
template <std::totally_ordered T>
class MergeSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override {
    if (data == nullptr)
      throw std::invalid_argument("Null pointer");
    if (data->isEmpty())
      throw std::invalid_argument("Empty data");
    // mandatory
    this->m_data = data;
    // O(n)
    if (data->isSorted()) {
      return;
    }
    auto& rdata = *data;
  }

 private:
  void merge(int64_t const ll, int64_t const lh, int64_t const rl,
             int64_t const rh) noexcept {}
};
}  // namespace algorithms
