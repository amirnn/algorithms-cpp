// Copyright 2025 by Amir Nourinia

module;
#include <cstdint>
#include <cstddef>
export module DSA:List.AList;

export namespace datastructures {
template <typename T>
class AList {
 public:
  virtual ~AList() = default;

  // getters
  [[nodiscard]] virtual size_t size() const noexcept = 0;

  [[nodiscard]] bool isEmpty() const noexcept { return size() == 0; }

 protected:
  [[nodiscard]] virtual T& getItemAt(int64_t index) = 0;

 public:
  [[nodiscard]] T& operator[](int64_t const index) { return getItemAt(index); }

  [[nodiscard]] T const& operator[](int64_t const index) const {
    return operator[](index);
  }

  [[nodiscard]] T& at(int64_t const index) { return operator[](index); }

  [[nodiscard]] T const& at(int64_t const index) const { return at(index); }

  T& getHead() { return operator[](0); }

  T const& getHead() const { return getHead(); }

  T& getTail() { return operator[](size() - 1); }

  T const& getTail() const { return getTail(); }

  [[nodiscard]] virtual T popFront() = 0;

  [[nodiscard]] virtual T popBack() = 0;

  [[nodiscard]] virtual T popAt(int64_t index) = 0;

  // setters
  virtual void clear() noexcept = 0;

  virtual void pushFront(T&& element) noexcept = 0;

  virtual void pushBack(T&& element) noexcept = 0;

  /**
   * Adds a new element at index. Increments size by 1.
   * @param index index of the new element
   * @param item to be pushed
   */
  virtual void pushAt(int64_t index, T&& item) = 0;

  /**
   * Sets the data in Node at index to value
   * List[index] = value
   * @param index
   * @param value
   */
  virtual void set(int64_t index, T&& value) = 0;
};

}  // namespace datastructures
