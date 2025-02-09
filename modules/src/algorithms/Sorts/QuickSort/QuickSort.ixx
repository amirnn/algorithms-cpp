// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
export module Sort:QuickSort;

import :ASort;

namespace algorithms {
    template<std::totally_ordered T>
    class QuickSort final: ASort<T> {
    public:
        void sort(typename ASort<T>::ASortableList* data) override;
    };
}
