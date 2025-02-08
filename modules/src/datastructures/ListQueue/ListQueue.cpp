// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
module List;

namespace datastructures {
    template<typename T>
    class ListQueue<T>::Node {
    public:
        T GetData() const noexcept { return data; }
        void SetData(T &&data) noexcept { this->data = data; }

    private:
        T data;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    template<typename T>
    ListQueue<T>::~ListQueue() { ListQueue<T>::clear(); }


    template<typename T>
    int64_t ListQueue<T>::size() const noexcept { return m_size; }

    template<typename T>
    T & ListQueue<T>::operator[](int64_t index) {
    }

    template<typename T>
    void ListQueue<T>::pushFront(T &&element) noexcept {
    }

    template<typename T>
    void ListQueue<T>::pushBack(T &&element) noexcept {
    }

    template<typename T>
    void ListQueue<T>::pushAt(int64_t index, T &&item) {
    }

    template<typename T>
    T ListQueue<T>::popFront() {
    }

    template<typename T>
    T ListQueue<T>::popBack() {
    }

    template<typename T>
    T ListQueue<T>::popAt(int64_t index) {
    }

    template<typename T>
    void ListQueue<T>::set(int64_t index, T &&value) {
    }

    template<typename T>
    void ListQueue<T>::clear() noexcept {
    }
}
