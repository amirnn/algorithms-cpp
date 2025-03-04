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

  /**
   * the children will need to only implement this method
   */
  virtual void sort(ASortableList* data) = 0;

 protected:
  ASortableList* m_data = nullptr;
};

}  // namespace algorithms
