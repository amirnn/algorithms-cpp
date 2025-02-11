// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <stdexcept>
export module DSA:Sort.InsertionSort;
import :Sort.ASort;

export namespace algorithms {
template <std::totally_ordered T>
class InsertionSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override {
    if (data == nullptr)
      throw std::invalid_argument("Null pointer");
    if (data->isEmpty())
      throw std::invalid_argument("Empty data");
    // mandatory
    this->m_data = data;
    // O(n)
    if (this->isSorted()) {
      return;
    }
    auto& rdata = *data;
    size_t const size = rdata.size();
    for (size_t i = 1; i < size; ++i) {
      if (size_t const correctIndex = binarySearchCorrectIndex(0, i - 1, i);
          correctIndex != i) {
        for (size_t j = i; j > correctIndex; --j) {
          this->exchange(j, j - 1);
        }
      }
    }
  }

  /**
   *
   * @param low inclusive
   * @param high inclusive
   * @param index index
   * @return the correct index to put (push) the data. This index corresponds to
   * first item that is bigger than this item.
   */
  size_t binarySearchCorrectIndex(size_t const low, size_t const high,
                                  size_t const index) {
    if (low > high)
      throw std::invalid_argument("Index is out of range");
    auto& rdata = *this->m_data;
    if (high == low) {
      return rdata[index] < rdata[high] ? high : index;
    }
    size_t const middle = (low + high) / 2;
    if (rdata[index] < rdata[middle]) {
      return binarySearchCorrectIndex(low, middle, index);
    } else {
      return binarySearchCorrectIndex(middle + 1, high, index);
    }
  }
};
}  // namespace algorithms
