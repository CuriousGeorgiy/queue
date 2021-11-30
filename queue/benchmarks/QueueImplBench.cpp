#include <benchmark/benchmark.h>

#include "queue-2-stacks/Queue2Stacks_impl.h"
#include "queue-linked-list/QueueLinkedList_impl.h"

template <typename QueueTy>
static void queue_push_pop(benchmark::State& state) {
  for ([[maybe_unused]] auto _ : state) {
    QueueTy queue;
    for (ssize_t i{0}; i < state.range(0); ++i) {
      queue.push(i);
      queue.pop();
    }
  }
}

template <typename QueueTy>
static void queue_pushes_pops(benchmark::State& state) {
  for ([[maybe_unused]] auto _ : state) {
    QueueTy queue;
    for (ssize_t i{0}; i < state.range(0); ++i) {
      queue.push(i);
    }

    for (ssize_t i{0}; i < state.range(0); ++i) {
      queue.pop();
    }
  }
}

BENCHMARK_TEMPLATE(queue_push_pop, queue::Queue2Stacks<size_t>)->Range(1, 1 << 27);
BENCHMARK_TEMPLATE(queue_push_pop, queue::QueueLinkedList<size_t>)->Range(1, 1 << 27);
BENCHMARK_TEMPLATE(queue_pushes_pops, queue::Queue2Stacks<size_t>)->Range(1, 1 << 27);
BENCHMARK_TEMPLATE(queue_pushes_pops, queue::QueueLinkedList<size_t>)->Range(1, 1 << 27);
