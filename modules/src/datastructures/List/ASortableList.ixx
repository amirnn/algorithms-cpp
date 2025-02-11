// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <functional>
export module DSA:List.ASortableList;
import :List.AList;
// import :Sort.ASort;

export namespace algorithms {
template <std::totally_ordered T>
class ASort;
}

export namespace datastructures {
// using: ()->ISort<T>
template <std::totally_ordered T>
class ASortableList : public AList<T> {
 public:
  ~ASortableList() override = default;

  template <typename Algorithm>
    requires std::is_base_of_v<algorithms::ASort<T>, Algorithm>
  void sort() {
    Algorithm algorithm = Algorithm();
    algorithm.sort(this);
  }
};
}  // namespace datastructures