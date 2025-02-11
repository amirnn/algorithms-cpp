// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>

export module DSA:Sort.MergeSort;
import :Sort.ASort;

namespace algorithms
{
template <std::totally_ordered T> class MergeSort final : public ASort<T>
{
  public:
    void sort(typename ASort<T>::ASortableList *data) override;

  private:
    void merge() noexcept;
};

template<std::totally_ordered T>
void MergeSort<T>::sort(typename ASort<T>::ASortableList* data) {
  if(data == nullptr) throw std::invalid_argument("Null pointer");
  this->m_data = data;
}

template<std::totally_ordered T>
void MergeSort<T>::merge() noexcept {
}
} // namespace algorithms
