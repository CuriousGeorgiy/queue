#ifndef QUEUE_2_STACKS_QUEUE_2_STACKS_IMPL_H
#define QUEUE_2_STACKS_QUEUE_2_STACKS_IMPL_H

#include "queue-2-stacks/Queue2Stacks.h"

namespace queue {
template <typename ElemTy>
ElemTy& Queue2Stacks<ElemTy>::front() {
  assert(!empty());

  if (!output_stack_.empty()) {
    return output_stack_.top();
  }

  while (!input_stack_.empty()) {
    output_stack_.push(input_stack_.top());
    input_stack_.pop();
  }
  return output_stack_.top();
}

template <typename ElemTy>
bool Queue2Stacks<ElemTy>::empty() const {
  return input_stack_.empty() && output_stack_.empty();
}

template <typename ElemTy>
size_t Queue2Stacks<ElemTy>::size() const {
  return input_stack_.size() + output_stack_.size();
}

template <typename ElemTy>
void Queue2Stacks<ElemTy>::push(const ElemTy& val) {
  input_stack_.push(val);
}

template <typename ElemTy>
void Queue2Stacks<ElemTy>::push(ElemTy&& val) {
  input_stack_.push(val);
}

template <typename ElemTy>
void Queue2Stacks<ElemTy>::pop() {
  assert(!empty());

  front();
  output_stack_.pop();
}

template <typename ValTy>
void Queue2Stacks<ValTy>::swap(Queue2Stacks& other) {
  std::swap(input_stack_, other.input_stack_);
  std::swap(output_stack_, other.output_stack_);
}
}  // namespace queue

#endif /* QUEUE_2_STACKS_QUEUE_2_STACKS_IMPL_H */
