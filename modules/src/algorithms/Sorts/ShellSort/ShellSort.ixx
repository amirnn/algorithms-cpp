module;
#include<concepts>
#include <stdexcept>
export module DSA:Sort.ShellSort;
import :Sort.ASort;

export namespace algorithms {
    template<std::totally_ordered T>
    class ShellSort final: public ASort<T> {
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
        }
    };

}