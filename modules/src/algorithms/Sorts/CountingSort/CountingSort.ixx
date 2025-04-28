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
  // TODO: Continue implementation from here

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
