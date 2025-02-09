// Copyright 2025 by Amir Nourinia

module;
#include <concepts>

// forward declaration
namespace datastructures {
    template<std::totally_ordered T>
    class ASortableList;
}

export module Sort:HeapSort;
import :ASort;

namespace algorithms {
    template<std::totally_ordered T>
    class HeapSort final : ASort<T> {
    public:
        void sort(typename datastructures::ASortableList<T>* data) override;
    };
}
