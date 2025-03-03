module;
#include <concepts>
#include <stdexcept>
export module DSA:Sort.ShellSort;
import :Sort.ASort;

export namespace algorithms {
template <std::totally_ordered T>
class ShellSort final : public ASort<T> {
 public:
  void sort(typename ASort<T>::ASortableList* data) override {
    if (data == nullptr) throw std::invalid_argument("Null pointer");
    if (data->isEmpty()) throw std::invalid_argument("Empty data");
    // mandatory
    this->m_data = data;
    // O(n)
    if (data->isSorted()) {
      return;
    }
    size_t const size = this->m_data->size();
    size_t h = generateMaximumElementUsingKnuthMethod(size);  // log(N)
    while (h >= 1) {
      for (size_t i = h; i < size; ++i) {
        for (size_t j = i; j >= h && (data->at(j) < data->at(j - h)); j -= h) {
          this->exchange(j, j - h);
        }
      }
      h = h / 3;
    }
  }

 private:
  // log(N)
  static size_t generateMaximumElementUsingKnuthMethod(size_t const size) {
    size_t h = 1;
    while (h < size / 3)
      h = 3 * h + 1;  // 1, 4, 13, 40, 121, 364, ...
    return h;
  }
};

}  // namespace algorithms