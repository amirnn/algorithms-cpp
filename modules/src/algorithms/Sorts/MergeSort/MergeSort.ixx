// Copyright 2025 by Amir Nourinia

module;
#include <concepts>

export module Sort:MergeSort;
import :ASort;

namespace algorithms {
    template<std::totally_ordered T>
    class MergeSort final: public ASort<T> {
    public:
        void sort(typename ASort<T>::ASortableList* data) override;

        private:
        void merge() noexcept;
    };
}
