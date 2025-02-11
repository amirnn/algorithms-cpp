// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
export module DSA:List.DynamicArray;
import :List.AList;

export namespace datastructures {
template <typename T>
class DynamicArray final : public AList<T> {
 public:
  [[nodiscard]] size_t size() const noexcept override { return m_size; }

  [[nodiscard]] T& getItemAt(int64_t index) override;

  void pushFront(T&& element) noexcept override;

  void pushBack(T&& element) noexcept override;

  void pushAt(int64_t index, T&& item) override;

  [[nodiscard]] T popFront() override;

  [[nodiscard]] T popBack() override;

  [[nodiscard]] T popAt(int64_t index) override;

  void set(int64_t index, T&& value) override;

  void clear() noexcept override;

 private:
  int64_t m_size = 0;
};
}  // namespace datastructures
