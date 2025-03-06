// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <cassert>
#include <concepts>
#include <memory>
#include <stdexcept>
export module DSA:Sort.MergeSort;
import :Sort.ASort;

export namespace algorithms {
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
    auto clone = std::unique_ptr<typename ASort<T>::ASortableList>(
        dynamic_cast<typename ASort<T>::ASortableList*>(
            rdata.clone().release()));
    sort(clone.get(), 0, rdata.size() - 1);
  }

 private:
  void sort(typename ASort<T>::ASortableList* list, size_t const low,
            size_t const high) noexcept {
    if (low >= high) return;
    // TODO: Implement iterators for AList datastructures and implement views
    // into them
    // to make insertion sort faster
    // if (high - low > 7) {
    //   // user insertion sort
    //
    //
    // }
    // else {
      size_t const mid = middle(low, high);
      sort(list, low, mid);
      sort(list, mid + 1, high);
      // TODO: if list[middle+1] >= list[middle] we are done, and we can return
      merge(list, low, high);
    // }
  }
  void merge(typename ASort<T>::ASortableList* list, size_t const low,
             size_t const high) noexcept {
    if (high - low < 1) return;
    // check for invariants
    // left half is sorted
    assert(isSubArraySorted(list, low, middle(low, high)));
    // right half is sorted
    assert(isSubArraySorted(list, middle(low, high) + 1, high));

    auto& data = *this->m_data;
    size_t i = low;
    size_t const mid = middle(low, high);
    size_t j = middle(low, high) + 1;
    for (size_t k = low; k <= high; ++k) {
      if (j > high) data[k] = list->at(i++);
      else if (i > mid)
        data[k] = list->at(j++);
      else if (list->at(i) <= list->at(j))
        data[k] = list->at(i++);
      else
        data[k] = list->at(j++);
    }
    // need to copy sorted data back to the list
    for (size_t k = low; k <= high; ++k) {
      list->at(k) = data[k];
    }
    // check that the whole [low, high] is sorted
    assert(isSubArraySorted(list, low, high));
  }
  inline static size_t middle(size_t const low, size_t const high) noexcept {
    return (low + high) / 2;
  }

  static bool isSubArraySorted(typename ASort<T>::ASortableList* list,
                               size_t const low, size_t const high) {
    if (high - low <= 1) return true;
    for (size_t i = low; i < high; ++i) {
      if (list->at(i) > list->at(i + 1)) {
        return false;
      }
    }
    return true;
  }
};
}  // namespace algorithms
