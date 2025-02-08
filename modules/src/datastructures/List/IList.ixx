// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <concepts>
#include <functional>

// forward declaration
namespace algorithms {
    template<std::totally_ordered T>
    class ASort;
}

export module List:IList;

export namespace datastructures {
    template<typename T>
    class IList {
    public:
        virtual ~IList() = default;

        // getters
        [[nodiscard]] virtual int64_t size() const noexcept = 0;

        [[nodiscard]] bool isEmpty() const noexcept { return size() == 0; }

        [[nodiscard]] virtual T &operator[](int64_t index) = 0;

        [[nodiscard]] T const &operator[](int64_t const index) const {
            return operator[](index);
        }

        [[nodiscard]] T &get(int64_t const index) {
            return operator[](index);
        }

        [[nodiscard]] T const &get(int64_t const index) const {
            return get(index);
        }

        T &getHead() {
            return operator[](0);
        }

        T const &getHead() const {
            return getHead();
        }

        T &getTail() {
            return operator[](size() - 1);
        }

        T const &getTail() const {
            return getTail();
        }

        virtual void PushFront(T &&element) noexcept = 0;

        virtual void PushBack(T &&element) noexcept = 0;

        virtual void pushAt(int64_t index, T &&item) = 0;

        [[nodiscard]] virtual T popFront() = 0;

        [[nodiscard]] virtual T popBack() = 0;

        [[nodiscard]] virtual T popAt(int64_t index) = 0;

        virtual void set(int64_t index, T &&value) = 0;

        // setters
        virtual void clear() noexcept = 0;
    };

    // using: ()->ISort<T>
    template<std::totally_ordered T>
    class ASortableList : IList<T> {
    public:
        ~ASortableList() override = default;

        void sort(std::function<algorithms::ASort<T>()> const &algorithm);
    };
}
