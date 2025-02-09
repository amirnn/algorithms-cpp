// Copyright 2025 by Amir Nourinia

module;
#include <concepts>

// forward declaration
namespace datastructures {
    template<std::totally_ordered T>
    class ASortableList;
}

export module Sort:MergeSort;
import :ASort;

namespace algorithms {
    template<std::totally_ordered T>
    class MergeSort final: public ASort<T> {
    public:
        void sort(datastructures::ASortableList<T>* data) override;

        private:
        void merge() noexcept;
    };
}
