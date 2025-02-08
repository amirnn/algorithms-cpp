// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
module List;

namespace datastructures {
    template<typename T>
    class ListQueue<T>::Node {
    public:
        T getData() const noexcept { return data; }
        void setData(T &&data) noexcept { this->data = data; }

    private:
        T data;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    template<typename T>
    ListQueue<T>::~ListQueue() { ListQueue<T>::clear(); }


    template<typename T>
    int64_t ListQueue<T>::size() const noexcept { return m_size; }
}
