find_package(benchmark REQUIRED)

add_executable(queue-impl-bench
               QueueImplBench.cpp
               )
target_link_libraries(queue-impl-bench
                      queue
                      benchmark::benchmark
                      benchmark::benchmark_main
                      )
