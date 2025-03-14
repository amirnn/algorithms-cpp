// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <concepts>
#include <memory>
#include <stdexcept>
export module DSA:List.SortableDoublyLinkedListQueue;

import :List.ASortableList;
import :List.DoublyLinkedListQueue;

export namespace datastructures {

template <std::totally_ordered T>
class SortableDoublyLinkedListQueue final : public ASortableList<T> {
 public:
  SortableDoublyLinkedListQueue()
      : ASortableList<T>(),
        m_list{std::make_unique<DoublyLinkedListQueue<T>>()} {}

  // copy constructor and assignment
  SortableDoublyLinkedListQueue(SortableDoublyLinkedListQueue const& other) {
    m_list = std::make_unique<DoublyLinkedListQueue<T>>(*other.m_list);
  }
  SortableDoublyLinkedListQueue& operator=(
      SortableDoublyLinkedListQueue const& other) {
    if (this != &other) {
      return *this;
    }
    m_list = std::make_unique<DoublyLinkedListQueue<T>>(*other.m_list);
    return *this;
  }

  [[nodiscard]] size_t size() const noexcept override { return m_list->size(); }

  [[nodiscard]] std::unique_ptr<AList<T>> clone() const noexcept override {
    return std::make_unique<SortableDoublyLinkedListQueue>(*this);
  }

  [[nodiscard]] T& getItemAt(size_t const index) override {
    return m_list->at(index);
  }

  [[nodiscard]] const T& getItemAt(size_t index) const override {
    return m_list->at(index);
  }

 public:
  [[nodiscard]] T popFront() override {
    return std::forward<T>(m_list->popFront());
  }

  [[nodiscard]] T popBack() override {
    return std::forward<T>(m_list->popBack());
  }

  [[nodiscard]] T popAt(size_t const index) override {
    return std::forward<T>(m_list->popAt(index));
  }

  void exchange(size_t source, size_t target) override {
    m_list->exchange(source, target);
  }

  void clear() noexcept override { m_list->clear(); }

  void pushFront(T&& element) noexcept override {
    m_list->pushFront(std::forward<T>(element));
  }
  void pushBack(T&& element) noexcept override {
    m_list->pushBack(std::forward<T>(element));
  }
  void pushAt(size_t const index, T&& item) override {
    m_list->pushAt(index, std::forward<T>(item));
  }
  void set(size_t const index, T&& value) override {
    m_list->set(index, std::forward<T>(value));
  }

 private:
  std::unique_ptr<DoublyLinkedListQueue<T>> m_list = nullptr;
};
}  // namespace datastructures