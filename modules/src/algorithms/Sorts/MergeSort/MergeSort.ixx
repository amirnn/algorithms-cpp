// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>

#include <cassert>
#include <concepts>
#include <stdexcept>
export module DSA:Sort.MergeSort;
import :Sort.ASort;

namespace algorithms {
template <std::totally_ordered T>
class MergeSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override {
    if (data == nullptr) throw std::invalid_argument("Null pointer");
    if (data->isEmpty()) throw std::invalid_argument("Empty data");
    // mandatory
    this->m_data = data;
    auto const& rdata = *data;
    // O(n)
    if (rdata.isSorted()) {
      return;
    }
    // clone will be sorted
    std::unique_ptr<typename ASort<T>::ASortableList> clone = rdata.clone();
    sort(clone.get(), 0, rdata.size() - 1);
  }

 private:
  void sort(typename ASort<T>::ASortableList* list, size_t const low,
            size_t const high) noexcept {
    if (low >= high) return;
    size_t const mid = middle(low, high);
    sort(list, low, mid);
    sort(list, mid + 1, high);
    merge(list, low, high);
  }
  void merge(typename ASort<T>::ASortableList* list, size_t const low,
             size_t const high) noexcept {
    if (high - low < 1) return;
    // check for invariants
    assert(
        isSubArraySorted(list, low, middle(low, high)));  // left half is sorted
    assert(isSubArraySorted(list, middle(low, high) + 1,
                            high));  // right half is sorted

    auto& data = *this->m_data;
    size_t i = low;
    size_t const mid = middle(low, high);
    size_t j = middle(low, high) + 1;
    for (size_t k = low; k <= high; ++k) {
      if (j > high) data[k] = list->at(i++);
      else if (i > mid)
        data[k] = list->at(j++);
      else
        data[k] = list->at(i) <= list->at(j) ? list->at(i++) : list->at(j++);
    }
    // check that the whole [low, high] is sorted
    assert(isSubArraySorted(list, low, high));
  }
  inline static size_t middle(size_t const low, size_t const high) noexcept {
    return (low + high) / 2;
  }

  static bool isSubArraySorted(typename ASort<T>::ASortableList* list,
                               size_t const low, size_t const high) {
    for (size_t i = low; i <= high; ++i) {
      if (list->at(i) > list->at(i + 1)) {
        return false;
      }
    }
    return true;
  }
};
}  // namespace algorithms
