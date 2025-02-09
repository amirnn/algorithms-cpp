// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <stdexcept>
#include <utility>
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
  [[nodiscard]] Node* getNodeAt(int64_t index);  // Complexity: O(n)

 public:
  void pushFront(T&& element) noexcept override;  // Complexity: O(1)

  void pushBack(T&& element) noexcept override;  // Complexity: O(1)

  void pushAt(int64_t index, T&& item) override;  // Complexity: O(1)

  [[nodiscard]] T popFront() override;  // Complexity: O(1)

  [[nodiscard]] T popBack() override;  // Complexity: O(1)

  [[nodiscard]] T popAt(int64_t index) override;  // Complexity: O(1)

  void set(int64_t index, T&& value) override;  // Complexity: O(1)

  [[nodiscard]] Node*& getHeadPointer() noexcept;

  [[nodiscard]] Node*& getTailPointer() noexcept;

  // setters
  void clear() noexcept override;  // Complexity: O(n)

 private:
  int64_t m_size = 0;
  Node* m_front = nullptr;
  Node* m_back = nullptr;
};

template <typename T>
class ListQueue<T>::Node {
 public:
  explicit Node(T&& data) : data{data} {}

  // getters
  T& getData() noexcept { return data; }
  T const& getData() const noexcept { return getData(); }
  Node* getNext() const noexcept { return next; }
  Node* getPrev() const noexcept { return prev; }

  // setters
  void setData(T&& data) noexcept { this->data = data; }
  void setNext(Node* next) noexcept { this->next = next; }
  void setPrev(Node* prev) noexcept { this->prev = prev; }

  // friend class ListQueue<T>;
 private:
  T data;
  Node* prev = nullptr;
  Node* next = nullptr;
};

template <typename T>
ListQueue<T>::~ListQueue() {
  ListQueue::clear();
}

template <typename T>
int64_t ListQueue<T>::size() const noexcept {
  return m_size;
}

template <typename T>
T& ListQueue<T>::operator[](int64_t const index) {
  Node* node = getNodeAt(index);
  return node->getData();
}

template <typename T>
typename ListQueue<T>::Node* ListQueue<T>::getNodeAt(int64_t const index) {
  if (this->isEmpty()) {
    throw std::out_of_range("ListQueue is empty.");
  }
  if (index < 0 || index >= size()) {
    throw std::out_of_range("index out of range");
  }
  if (index == 0) {
    return getHeadPointer();
  }
  if (index == size() - 1) {
    return getTailPointer();
  }
  Node* current = getHeadPointer();
  for (int64_t i = 1; i <= index; ++i) {
    current = current->getNext();
  }
  return current;
}

template <typename T>
void ListQueue<T>::pushFront(T&& element) noexcept {
  Node* newNode = new Node{std::forward<T>(element)};
  if (this->isEmpty()) {
    getHeadPointer() = newNode;
    getTailPointer() = newNode;
  } else {
    newNode->setNext(getHeadPointer());
    getHeadPointer()->setPrev(newNode);
    getHeadPointer() = newNode;
  }
  ++m_size;
}

template <typename T>
void ListQueue<T>::pushBack(T&& element) noexcept {
  Node* newNode = new Node{std::forward<T>(element)};
  if (this->isEmpty()) {
    getHeadPointer() = newNode;
    getTailPointer() = newNode;
  } else {
    newNode->setPrev(getTailPointer());
    getTailPointer()->setNext(newNode);
    getTailPointer() = newNode;
  }
  ++m_size;
}

template <typename T>
void ListQueue<T>::pushAt(int64_t const index, T&& item) {
  if (index == 0) {
    pushFront(std::forward<T>(item));
    return;
  }
  if (index < 0 || index >= size()) {
    throw std::out_of_range("index out of range");
  }
  Node* newNode = new Node{std::forward<T>(item)};
  Node* node = getNodeAt(index);
  newNode->setPrev(node->getPrev());
  newNode->setNext(node);
  node->getPrev()->setNext(newNode);
  node->setPrev(newNode);
  ++m_size;
}

template <typename T>
T ListQueue<T>::popFront() {
  if (this->isEmpty()) {
    throw std::out_of_range("ListQueue is empty.");
  }
  if (this->size() == 1) {
    Node* node = getHeadPointer();
    T data{std::move(node->getData())};
    delete node;
    getHeadPointer() = nullptr;
    getTailPointer() = nullptr;
    --m_size;
    return data;
  } else {
    Node* node = getHeadPointer();
    T data{std::move(node->getData())};
    getHeadPointer() = getHeadPointer()->getNext();
    delete node;
    --m_size;
    return data;
  }
}

template <typename T>
T ListQueue<T>::popBack() {
  if (this->isEmpty()) {
    throw std::out_of_range("ListQueue is empty.");
  }
  if (this->size() == 1) {
    Node* node = getTailPointer();
    T data{std::move(node->getData())};
    delete node;
    getTailPointer() = nullptr;
    getHeadPointer() = nullptr;
    --m_size;
    return data;
  } else {
    Node* node = getTailPointer();
    T data{std::move(node->getData())};
    getTailPointer() = getTailPointer()->getPrev();
    delete node;
    --m_size;
    return data;
  }
}

template <typename T>
T ListQueue<T>::popAt(int64_t const index) {
  // beginning of queue
  if (index == 0) {
    return popFront();
  }
  // end of queue
  if (index == size() - 1) {
    return popBack();
  }
  // else
  Node* node = getNodeAt(index);
  T data{std::move(node->getData())};
  node->getPrev()->setNext(node->getNext());
  delete node;
  --m_size;
  return data;
}

template <typename T>
void ListQueue<T>::set(int64_t const index, T&& value) {
  Node* node = getNodeAt(index);
  node->setData(std::forward<T>(value));
}

template <typename T>
typename ListQueue<T>::Node*& ListQueue<T>::getHeadPointer() noexcept {
  return m_front;
}
template <typename T>
typename ListQueue<T>::Node*& ListQueue<T>::getTailPointer() noexcept {
  return m_back;
}

template <typename T>
void ListQueue<T>::clear() noexcept {
  if (this->isEmpty()) {
    return;
  }
  while (not this->isEmpty()) {
    static_cast<void>(popFront());
  }
}
}  // namespace datastructures
