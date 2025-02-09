// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>

export module List:ListQueue;
import :IList;

export namespace datastructures {
template <typename T>
class ListQueue final : public AList<T> {
 public:
  class Node;

  ~ListQueue() override;

  // getters

  [[nodiscard]] int64_t size() const noexcept override;  // Complexity: O(1)

  [[nodiscard]] T& operator[](int64_t index) override;  // Complexity: O(n)

 private:
  [[nodiscard]] Node& getNodeAt(int64_t index);  // Complexity: O(n)

 public:
  void pushFront(T&& element) noexcept override;  // Complexity: O(1)

  void pushBack(T&& element) noexcept override;  // Complexity: O(1)

  void pushAt(int64_t index, T&& item) override;  // Complexity: O(1)

  [[nodiscard]] T popFront() override;  // Complexity: O(1)

  [[nodiscard]] T popBack() override;  // Complexity: O(1)

  [[nodiscard]] T popAt(int64_t index) override;  // Complexity: O(1)

  void set(int64_t index, T&& value) override;  // Complexity: O(1)

  [[nodiscard]] Node*& getHeadPointer() const noexcept;

  [[nodiscard]] Node*& getTailPointer() const noexcept;

  // setters
  void clear() noexcept override;  // Complexity: O(n)

 private:
  int64_t m_size = 0;
  Node* m_front = nullptr;
  Node* m_back = nullptr;
};
}  // namespace datastructures
