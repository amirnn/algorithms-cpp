// Copyright 2025 by Amir Nourinia

module;
#include <cstdint>
#include <concepts>

// forward declaration
namespace datastructures {
    template<std::totally_ordered T>
    class ASortableList;
}

export module Sort;

export namespace algorithms {
    template<std::totally_ordered T>
    class ASort {
    public:
        using ASortableList = datastructures::ASortableList<T>;

        virtual ~ASort() = default;

        [[nodiscard]] bool isSorted() const noexcept;

        void exchange(int64_t i, int64_t j);

        /**
         * the children will need to only implement this method
         */
        virtual void sort(ASortableList data) = 0;

    protected:
        ASortableList *m_data = nullptr;
    };
}
