// Copyright 2025 by Amir Nourinia

module;
#include <sys/types.h>

#include <memory>
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
    explicit Node(T&& data) : data{std::forward<T>(data)} {}

    // getters
    T& getData() noexcept { return data; }
    T const& getData() const noexcept { return getData(); }
    Node* getNext() const noexcept { return next; }
    Node* getPrev() const noexcept { return prev; }

    // setters
    void setData(T&& newData) noexcept { this->data = newData; }
    void setNext(Node* nextNode) noexcept { this->next = nextNode; }
    void setPrev(Node* prevNode) noexcept { this->prev = prevNode; }

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

  // copy constructor and assignment
  DoublyLinkedListQueue(DoublyLinkedListQueue const& other)
      : DoublyLinkedListQueue() {
    for (size_t i = 0; i < other.size(); ++i) {
      auto t = other.at(i);
      pushBack(std::move(t));
    }
  }

  DoublyLinkedListQueue& operator=(DoublyLinkedListQueue const& other) {
    if (this == &other) {
      return *this;
    }
    for (size_t i = 0; i < other.size(); ++i) {
      pushBack(other[i]);
    }
    return *this;
  }

  ~DoublyLinkedListQueue() override { DoublyLinkedListQueue::clear(); }

  // getters

  // Complexity: O(1)
  [[nodiscard]] size_t size() const noexcept override { return m_size; }

  [[nodiscard]] std::unique_ptr<AList<T>> clone() const noexcept override {
    return std::make_unique<DoublyLinkedListQueue>(*this);
  }

  // Complexity: O(n)
  [[nodiscard]] T& getItemAt(size_t const index) override {
    Node* node = getNodeAt(index);
    return node->getData();
  }

  [[nodiscard]] T const& getItemAt(size_t index) const override {
    Node* node = getNodeAt(index);
    return node->getData();
  }

 private:
  // Complexity: O(n)
  [[nodiscard]] Node* getNodeAt(size_t const index) const {
    if (this->isEmpty()) {
      throw std::out_of_range("ListQueue is empty.");
    }
    if (index >= size()) {
      throw std::out_of_range("index out of range");
    }
    if (index == 0) {
      return getHeadPointer();
    }
    if (index == size() - 1) {
      return getTailPointer();
    }
    Node* current = getHeadPointer();
    for (size_t i = 1; i <= index; ++i) {
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
  void pushAt(size_t const index, T&& item) override {
    if (index == 0) {
      pushFront(std::forward<T>(item));
      return;
    }
    if (index >= size()) {
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
  [[nodiscard]] T popAt(size_t const index) override {
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
  void set(size_t const index, T&& value) override {
    Node* node = getNodeAt(index);
    node->setData(std::forward<T>(value));
  }

  [[nodiscard]] Node*& getHeadPointer() noexcept { return m_front; }

  [[nodiscard]] Node*& getTailPointer() noexcept { return m_back; }

  [[nodiscard]] Node* const& getHeadPointer() const noexcept { return m_front; }

  [[nodiscard]] Node* const& getTailPointer() const noexcept { return m_back; }

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

  void exchange(size_t const source, size_t const target) override {
    if (source >= size() || target >= size()) {
      throw std::out_of_range("Source or destination out of range.");
    }
    Node* sourceNode = getNodeAt(source);
    Node* targetNode = getNodeAt(target);
    T sourceData{std::move(sourceNode->getData())};
    T targetData{std::move(targetNode->getData())};
    sourceNode->setData(std::move(targetData));
    targetNode->setData(std::move(sourceData));
  }

 private:
  size_t m_size = 0;
  Node* m_front = nullptr;
  Node* m_back = nullptr;
};
}  // namespace datastructures
