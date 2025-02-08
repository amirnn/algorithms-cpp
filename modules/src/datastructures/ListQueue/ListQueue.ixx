// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>

export module List:ListQueue;
import :IList;

namespace datastructures {
    template<typename T>
    class ListQueue final : public IList<T> {
    public:
        class Node;

        ~ListQueue() override;

        // getters
        [[nodiscard]] int64_t size() const noexcept override;

        [[nodiscard]] T &operator[](int64_t index) override;

        void pushFront(T &&element) noexcept override;

        void pushBack(T &&element) noexcept override;

        void pushAt(int64_t index, T &&item) override;

        [[nodiscard]] T popFront() override;

        [[nodiscard]] T popBack() override;

        [[nodiscard]] T popAt(int64_t index) override;

        void set(int64_t index, T &&value) override;

        // setters
        void clear() noexcept override;

    private:
        int64_t m_size = 0;
    };
}
