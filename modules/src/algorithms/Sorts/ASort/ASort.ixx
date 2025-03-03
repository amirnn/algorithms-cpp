// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <concepts>
export module DSA:Sort.ASort;
import :List.ASortableList;
import :Math.Random;

export namespace algorithms {
template <std::totally_ordered T>
class ASort {
 public:
  using ASortableList = datastructures::ASortableList<T>;

  virtual ~ASort() = default;

  [[nodiscard]] bool isSorted() const noexcept {
    auto& data = *m_data;
    if (data.size() == 1) return true;
    for (size_t i = 0; i < data.size() - 1; ++i) {
      if (data[i] > data[i + 1]) {
        return false;
      }
    }
    return true;
  }

  // implements knuth's linear shuffle
  void shuffle() noexcept {
    auto& data = *m_data;
    if (data.size() <= 1) return;
    for (int i = 1; i < data.size(); ++i) {
      int64_t const target = dsa::random::uniform(0, i);
      exchange(i, target);
    }
  }

 protected:
  void exchange(int64_t const i, int64_t const j) const {
    auto& data = *m_data;
    T const temp{data[i]};
    data[i] = data[j];
    data[j] = temp;
  }

 public:
  /**
   * the children will need to only implement this method
   */
  virtual void sort(ASortableList* data) = 0;

 protected:
  ASortableList* m_data = nullptr;
};

}  // namespace algorithms
