// Copyright 2025 by Amir Nourinia

module;
#include <concepts>
#include <memory>
export module DSA:List.SortableDynamicArray;

import :List.DynamicArray;
import :List.ASortableList;

export namespace datastructures {
template <std::totally_ordered T>
class SortableDynamicArray final : public ASortableList<T> {

 public:
  SortableDynamicArray()
      : ASortableList<T>(), m_array{std::make_unique<DynamicArray<T>>()} {}

  // copy constructor
  SortableDynamicArray(SortableDynamicArray const& other)
      : SortableDynamicArray() {
    *m_array = *other.m_array;  // use the copy constructor from DynamicArray
  }

  SortableDynamicArray& operator=(SortableDynamicArray const& other) {
    if (this == &other) {
      return *this;
    }
    *m_array = *other.m_array;  // use the copy constructor from DynamicArray
    return *this;
  }

  [[nodiscard]] size_t size() const noexcept override {
    return m_array->size();
  }

  [[nodiscard]] std::unique_ptr<AList<T>> clone() const noexcept override {
    return std::make_unique<SortableDynamicArray>(*this);
  }

 protected:
  [[nodiscard]] T& getItemAt(size_t const index) override {
    return m_array->at(index);
  }

  [[nodiscard]] T const& getItemAt(size_t const index) const override {
    return m_array->at(index);
  }

 public:
  [[nodiscard]] T popFront() override { return m_array->popFront(); }
  [[nodiscard]] T popBack() override { return m_array->popBack(); }
  [[nodiscard]] T popAt(size_t const index) override {
    return m_array->popAt(index);
  }
  void clear() noexcept override { m_array->clear(); }
  void pushFront(T&& element) noexcept override {
    m_array->pushFront(std::forward<T>(element));
  }
  void pushBack(T&& element) noexcept override {
    m_array->pushBack(std::forward<T>(element));
  }

  void pushAt(size_t const index, T&& item) override {
    m_array->pushAt(index, std::forward<T>(item));
  }
  void set(size_t const index, T&& value) override {
    m_array->set(index, std::forward<T>(value));
  }

  void exchange(size_t const source, size_t const target) override {
    m_array->exchange(source, target);
  }

 private:
  std::unique_ptr<DynamicArray<T>> m_array;
};
}  // namespace datastructures