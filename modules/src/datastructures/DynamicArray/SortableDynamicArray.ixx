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

  [[nodiscard]] size_t size() const noexcept override {
    return m_array->size();
  }

 protected:
  [[nodiscard]] T& getItemAt(size_t const index) override {
    return m_array->at(index);
  }

 public:
  [[nodiscard]] T popFront() override { return m_array->popFront(); }
  [[nodiscard]] T popBack() override { return m_array->popBack(); }
  [[nodiscard]] T popAt(size_t index) override {
    return m_array->popAt(index);
  }
  void clear() noexcept override { m_array->clear(); }
  void pushFront(T&& element) noexcept override {
    m_array->pushFront(std::forward<T>(element));
  }
  void pushBack(T&& element) noexcept override {
    m_array->pushBack(std::forward<T>(element));
  }
  void pushAt(size_t index, T&& item) override {
    m_array->pushAt(index, std::forward<T>(item));
  }
  void set(size_t index, T&& value) override {
    m_array->set(index, std::forward<T>(value));
  }

 private:
  std::unique_ptr<DynamicArray<T>> m_array;
};
}  // namespace datastructures