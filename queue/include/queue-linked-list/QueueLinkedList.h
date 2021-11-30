#ifndef QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H

#include <cstdio>

namespace queue {
template <typename ValTy>
class QueueLinkedList {
 public:
  QueueLinkedList();
  QueueLinkedList(const QueueLinkedList& other);
  QueueLinkedList(QueueLinkedList&& other) noexcept;

  ~QueueLinkedList();

  QueueLinkedList& operator=(QueueLinkedList rhs);

  ValTy& front();

  [[nodiscard]] bool empty() const;
  [[nodiscard]] size_t size() const;

  void push(const ValTy& val);
  void push(ValTy&& val);
  void pop();

  void swap(QueueLinkedList other);

 private:
  struct Node {
    Node* next{nullptr};
    ValTy val;

    Node() = default;
    explicit Node(const ValTy& val);
    explicit Node(ValTy&& val);
  };

  Node* head_;
  Node* tail_ = nullptr;
  size_t sz_ = 0;
};
}  // namespace queue

#endif /* QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_H */
