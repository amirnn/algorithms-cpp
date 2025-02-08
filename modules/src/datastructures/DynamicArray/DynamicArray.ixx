// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
export module List:DynamicArray;
import :IList;

export namespace datastructures {
    template<typename T>
    class DynamicArray : IList<T> {
    public:
        [[nodiscard]] int64_t size() const noexcept override;

        [[nodiscard]] T &operator[](int64_t index) override;

        void PushFront(T &&element) noexcept override;

        void PushBack(T &&element) noexcept override;

        void pushAt(int64_t index, T &&item) override;

        [[nodiscard]] T popFront() override;

        [[nodiscard]] T popBack() override;

        [[nodiscard]] T popAt(int64_t index) override;

        void set(int64_t index, T &&value) override;

        void clear() noexcept override;

    private:
        int64_t m_size = 0;
    };
}
