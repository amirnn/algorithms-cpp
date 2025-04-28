// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
export module DSA:Sort.CountingSort;

import :Sort.ASort;
import :List.DynamicArray;

namespace algorithms {

template <std::totally_ordered T>
class CountingSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override;

 private:
  static T findUpperBound(typename ASort<T>::ASortableList* data);
  static T findLowerBound(typename ASort<T>::ASortableList* data);
};

template <std::totally_ordered T>
void CountingSort<T>::sort(typename ASort<T>::ASortableList* data) {
  if (data == nullptr) throw std::invalid_argument("data is null");
  this->m_data = data;
  auto upperBound = findUpperBound(this->m_data);
  auto lowerBound = findLowerBound(this->m_data);
  auto range = upperBound - lowerBound + 1;
  static_assert(std::is_integral_v<std::remove_cv_t<decltype(range)>>, "range should be integral");
  datastructures::DynamicArray<T> indices (range);
  for (auto& element : indices) { element = 0; }

  // create an array that holds the indices of each item
  for (size_t i = 0; i < range; ++i) {
    auto const& item = this->m_data->getItemAt(i);
    // count the number of each item
    if ( item == lowerBound + i ) { ++indices[i]; }
  }
  // accumulate number of items (histogram)
  for (size_t i = 1; i < range; ++i) {
    indices[i] += indices[i - 1];
  }
  // sort
  // 1. create an auxiliary array for final sorted items
  datastructures::DynamicArray<T> sorted{this->m_data->size()};
  for (size_t i = 0; i < range; ++i) {
    sorted[indices[range - i - 1]] = this->m_data->getItemAt(i);
    --indices[range - i - 1];
  }
}
template <std::totally_ordered T>
T CountingSort<T>::findUpperBound(typename ASort<T>::ASortableList* data) {
  if (data == nullptr) throw std::invalid_argument("data is null");
  T upperBound = std::numeric_limits<T>::min();
  for (size_t i = 0; i < data->getSize(); ++i) {
    T const& item = data->getElement(i);
    if (item > upperBound) upperBound = item;
  }
  return upperBound;
}
template <std::totally_ordered T>
T CountingSort<T>::findLowerBound(typename ASort<T>::ASortableList* data) {
  if (data == nullptr) throw std::invalid_argument("data is null");
  T lowerBound = std::numeric_limits<T>::max();
  for (size_t i = 0; i < data->getSize(); ++i) {
    T const& item = data->getElement(i);
    if (item < lowerBound) lowerBound = item;
  }
  return lowerBound;
}
}  // namespace algorithms
