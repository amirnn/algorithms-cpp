// Copyright 2025 by Amir Nourinia

module;
#include<sys/types.h>
module List;

namespace datastructures {
    template<typename T>
    int64_t DynamicArray<T>::size() const noexcept { return m_size; }
}
