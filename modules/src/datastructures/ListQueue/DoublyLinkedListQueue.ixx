// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>
#include <stdexcept>
#include <utility>
export module DSA:List.DoublyLinkedListQueue;
import :List.AList;

export namespace datastructures {
template <typename T>
class DoublyLinkedListQueue final : public AList<T> {
 public:
  class Node {
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

  DoublyLinkedListQueue() = default;

  // move constructor
  DoublyLinkedListQueue(DoublyLinkedListQueue&& other) noexcept
      : AList<T>{other},
        m_size{other.m_size},
        m_front{other.m_front},
        m_back{other.m_back} {
    other.m_size = 0;
    other.m_front = other.m_back = nullptr;
  }
  DoublyLinkedListQueue& operator=(DoublyLinkedListQueue&& other) noexcept {
    m_size = other.m_size;
    m_front = other.m_front;
    m_back = other.m_back;
    other.m_size = 0;
    other.m_front = other.m_back = nullptr;
    return *this;
  }

  // delete copy constructor and assignment
  DoublyLinkedListQueue(DoublyLinkedListQueue const& other) = delete;
  DoublyLinkedListQueue& operator=(DoublyLinkedListQueue const& other) = delete;

  ~DoublyLinkedListQueue() override { DoublyLinkedListQueue::clear(); }

  // getters

  // Complexity: O(1)
  [[nodiscard]] size_t size() const noexcept override { return m_size; }

  // Complexity: O(n)
  [[nodiscard]] T& getItemAt(int64_t index) override {
    Node* node = getNodeAt(index);
    return node->getData();
  }

 private:
  // Complexity: O(n)
  [[nodiscard]] Node* getNodeAt(int64_t index) {
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

 public:
  // Complexity: O(1)
  void pushFront(T&& element) noexcept override {
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

  // Complexity: O(1)
  void pushBack(T&& element) noexcept override {
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

  // Complexity: O(1)
  void pushAt(int64_t const index, T&& item) override {
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

  // Complexity: O(1)
  [[nodiscard]] T popFront() override {
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

  // Complexity: O(1)
  [[nodiscard]] T popBack() override {
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

  // Complexity: O(1)
  [[nodiscard]] T popAt(int64_t const index) override {
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
    node->getNext()->setPrev(node->getPrev());
    delete node;
    --m_size;
    return data;
  }

  // Complexity: O(1)
  void set(int64_t const index, T&& value) override {
    Node* node = getNodeAt(index);
    node->setData(std::forward<T>(value));
  }

  [[nodiscard]] Node*& getHeadPointer() noexcept { return m_front; }

  [[nodiscard]] Node*& getTailPointer() noexcept { return m_back; }

  // setters

  // Complexity: O(n)
  void clear() noexcept override {
    if (this->isEmpty()) {
      return;
    }
    while (not this->isEmpty()) {
      static_cast<void>(popFront());
    }
  }

 private:
  size_t m_size = 0;
  Node* m_front = nullptr;
  Node* m_back = nullptr;
};
}  // namespace datastructures
