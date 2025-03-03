// Copyright 2025 by Amir Nourinia

module;
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
export module DSA:List.DynamicArray;
import :List.AList;

export namespace datastructures {
template <typename T>
class DynamicArray final : public AList<T> {
 public:
  DynamicArray() : AList<T>() { m_data = new T[m_capacity]; }
  ~DynamicArray() override {
    delete[] m_data;
    m_data = nullptr;
    m_capacity = m_size = m_front = m_back = 0;
  }

  DynamicArray(const DynamicArray& other)
      : AList<T>(other),
        m_size{other.m_size},
        m_capacity{other.m_capacity},
        m_front{other.m_front},
        m_back{other.m_back} {
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_capacity, m_data);
  }
  DynamicArray& operator=(const DynamicArray& other) {
    if (this == &other) {
      return *this;
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_front = other.m_front;
    m_back = other.m_back;
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_capacity, m_data);
    return *this;
  }

  DynamicArray(DynamicArray&& other) noexcept
      : AList<T>(),
        m_size{other.m_size},
        m_capacity{other.m_capacity},
        m_front{other.m_front},
        m_back{other.m_back} {
    m_data = other.m_data;
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_front = 0;
    other.m_back = 0;
    other.m_data = nullptr;
  }
  DynamicArray& operator=(DynamicArray&& other) noexcept {
    if (this == &other) {
      return *this;
    }
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_front = other.m_front;
    m_back = other.m_back;
    m_data = other.m_data;
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_front = 0;
    other.m_back = 0;
    other.m_data = nullptr;
    return *this;
  }

  [[nodiscard]] size_t size() const noexcept override { return m_size; }

  [[nodiscard]] T& getItemAt(int64_t const index) override {
    boundsCheck(index);
    size_t t = getMappedIndex(index);
    return m_data[t];
  }

  void pushFront(T&& element) noexcept override {
    if (isFull()) expand();
    if (this->isEmpty()) {
      this->set(0,std::forward<T>(element));
      ++m_size;
      return;
    }
    --m_front;
    size_t t = getMappedIndex(0);
    m_data[t] = std::forward<T>(element);
    ++m_size;
  }

  void pushBack(T&& element) noexcept override {
    if (isFull()) expand();
    if (this->isEmpty()) {
      this->set(0,std::forward<T>(element));
      ++m_size;
      return;
    }
    size_t t = getMappedIndex(++m_size - 1);
    m_data[t] = std::forward<T>(element);
    ++m_back;
  }

  void pushAt(int64_t const index, T&& item) override {
    if (this->isEmpty()) {
      if (index != 0) throw std::out_of_range("invalid index, array is empty");
      pushBack(std::move(item));
      return;
    }
    boundsCheck(index);
    if (isFull()) expand();
    // closer to head
    if (index < m_size / 2) {
      // write data to new head
      pushFront(std::move(item));
      // exchange it until we are in the correct place
      for (size_t i = 0; i < index; ++i) {
        exchange(i, i + 1);
      }
    }
    // closer to tail
    else {
      pushBack(std::move(item));
      // exchange it until we are in the correct place
      for (size_t i = 0; i < m_size - index - 1; ++i) {
        exchange(i, i - 1);
      }
    }
    ++m_size;
  }

  [[nodiscard]] T popFront() override {
    if (this->isEmpty()) throw std::out_of_range("Empty array");
    if (isAlmostEmpty()) shrink();
    if (size() == 1) {
      T result = std::move(this->at(0));
      --m_size;
      return result;
    }
    T result = std::move(this->at(0));
    ++m_front;
    --m_size;
    return result;
  }

  [[nodiscard]] T popBack() override {
    if (this->isEmpty()) throw std::out_of_range("Empty array");
    if (isAlmostEmpty()) shrink();
    if (size() == 1) {
      T result = std::move(this->at(0));
      --m_size;
      return result;
    }
    T result = std::move(this->at(size() - 1));
    --m_back;
    --m_size;
    return result;
  }

  [[nodiscard]] T popAt(int64_t const index) override {
    boundsCheck(index);
    // closer to head
    if (index <= m_size / 2) {
      for (size_t i = index; i > 0; --i) {
        exchange(i, i - 1);
      }
      T result = std::move(popFront());
      return result;
    } else {
      for (size_t i = index; i < m_size - 1; ++i) {
        exchange(i, i + 1);
      }
      T result = std::move(popBack());
      return result;
    }
  }

  void set(int64_t const index, T&& value) override {
    if (index == 0 && m_size == 0) {
      m_data[0] = std::forward<T>(value);
      m_size = 1;
      return;
    }
    boundsCheck(index);
    m_data[getMappedIndex(index)] = std::forward<T>(value);
  }

  void clear() noexcept override {
    delete[] m_data;
    m_size = 0;
    m_capacity = 2;
    m_front = 0;
    m_back = 0;
    m_data = new T[m_capacity];
  }

 private:
  /**
   *
   * @param index is in range [head, #elements)
   * @return the actual index of data in the circular buffer
   */
  [[nodiscard]] size_t getMappedIndex(int64_t const index) const noexcept {
    int64_t const indexMod = index;
    int64_t const headMod = m_front % m_capacity;
    int64_t const secondMod = (headMod + m_capacity) % m_capacity;
    int64_t const actualIndex = (indexMod + secondMod) % m_capacity;
    return actualIndex;
  }

  void boundsCheck(int64_t const index) const {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("index out of range");
  }

  [[nodiscard]] bool isFull() const noexcept { return m_size == m_capacity; }

  [[nodiscard]] bool isAlmostEmpty() const noexcept {
    return m_size <= (m_capacity / s_shrinkFactor);
  }

  /**
   * called only when buffer is full
   */
  void expand() noexcept {
    size_t const newCapacity = m_capacity * s_expansionFactor;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < m_size; ++i) {
      newData[i] = std::move(this->at(i));
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
    m_front = 0;
    m_back = m_size - 1;
  }

  /**
   * called only when buffer is less than quarter full
   */
  void shrink() noexcept {
    size_t const newCapacity = m_capacity / s_expansionFactor;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < m_size; ++i) {
      newData[i] = std::move(this->at(i));
    }
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
    m_front = 0;
    m_back = m_size - 1;
  }

  void exchange(int64_t const source, int64_t const target) {
    if (source < 0 || target < 0 || static_cast<size_t>(source) >= m_size ||
        static_cast<size_t>(target) >= m_size)
      throw std::out_of_range("index out of range");
    T temp = std::move(this->at(source));
    set(source, std::move(this->at(target)));
    set(target, std::move(temp));
  }

 private:
  size_t m_size = 0;
  size_t m_capacity = 2;
  int64_t m_front = 0;
  int64_t m_back = 0;
  T* m_data = nullptr;
  uint32_t const s_expansionFactor = 2;
  uint32_t const s_shrinkFactor = 4;
};
}  // namespace datastructures
