#ifndef QUEUE_2_STACKS_QUEUE_2_STACKS_H
#define QUEUE_2_STACKS_QUEUE_2_STACKS_H

#include <cstdio>

#include "stack/Stack_impl.h"

namespace queue {
template <typename ValTy>
class Queue2Stacks {
 public:
  Queue2Stacks() = default;
  Queue2Stacks(const Queue2Stacks&) = default;
  Queue2Stacks(Queue2Stacks&&) noexcept = default;

  ~Queue2Stacks() = default;

  Queue2Stacks& operator=(const Queue2Stacks&) = default;
  Queue2Stacks& operator=(Queue2Stacks&&) noexcept = default;

  ValTy& front();

  [[nodiscard]] bool empty() const;
  [[nodiscard]] size_t size() const;

  void push(const ValTy& val);
  void push(ValTy&& val);
  void pop();

  void swap(Queue2Stacks& other);

 private:
  Stack<ValTy> input_stack_;
  Stack<ValTy> output_stack_;
};
}  // namespace queue

#endif /* QUEUE_2_STACKS_QUEUE_2_STACKS_H */
