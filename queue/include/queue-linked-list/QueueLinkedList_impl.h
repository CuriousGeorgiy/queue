#ifndef QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_IMPL_H
#define QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_IMPL_H

#include "queue-linked-list/QueueLinkedList.h"

namespace queue {
template <typename ValTy>
QueueLinkedList<ValTy>::QueueLinkedList() : head_{new Node} {}

template <typename ValTy>
QueueLinkedList<ValTy>::QueueLinkedList(const QueueLinkedList& other) : QueueLinkedList() {
  sz_ = other.sz_;

  for (Node* p = other.head->next; p != nullptr; p = p->next) {
    push(p->val);
  }
}

template <typename ValTy>
QueueLinkedList<ValTy>::QueueLinkedList(QueueLinkedList&& other) noexcept : QueueLinkedList() {
  swap(other);
}

template <typename ValTy>
QueueLinkedList<ValTy>::~QueueLinkedList() {
  while (!empty()) {
    pop();
  }

  delete head_;
}

template <typename ValTy>
QueueLinkedList<ValTy>& QueueLinkedList<ValTy>::operator=(QueueLinkedList rhs) {
  swap(rhs);
  return *this;
}

template <typename ValTy>
ValTy& QueueLinkedList<ValTy>::front() {
  assert(!empty());

  return head_->next;
}

template <typename ValTy>
bool QueueLinkedList<ValTy>::empty() const {
  return sz_ == 0;
}

template <typename ValTy>
size_t QueueLinkedList<ValTy>::size() const {
  return sz_;
}

template <typename ValTy>
void QueueLinkedList<ValTy>::push(const ValTy& val) {
  ++sz_;

  if (sz_ == 1) {
    tail_ = head_->next = new Node(val);
    return;
  }

  tail_ = tail_->next = new Node(val);
}

template <typename ValTy>
void QueueLinkedList<ValTy>::push(ValTy&& val) {
  ++sz_;

  if (sz_ == 1) {
    tail_ = head_->next = new Node(val);
    return;
  }

  tail_ = tail_->next = new Node(val);
}

template <typename ValTy>
void QueueLinkedList<ValTy>::pop() {
  assert(!empty());

  Node* top = head_->next;
  head_->next = head_->next->next;
  delete top;
  --sz_;
}

template <typename ValTy>
void QueueLinkedList<ValTy>::swap(QueueLinkedList other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(sz_, other.sz_);
}

template <typename ValTy>
QueueLinkedList<ValTy>::Node::Node(const ValTy& val) : val(val) {}

template <typename ValTy>
QueueLinkedList<ValTy>::Node::Node(ValTy&& val) : val(val) {}
}  // namespace queue

#endif /* QUEUE_LINKED_LIST_QUEUE_LINKED_LIST_IMPL_H */
