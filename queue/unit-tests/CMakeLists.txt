enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(QUEUE_TYPE "Queue2Stacks")
CONFIGURE_FILE(QueueTest.cpp.in Queue2StacksTest.cpp)
add_executable(queue-2-stacks-unit-tests
               Queue2StacksTest.cpp
               )
target_link_libraries(queue-2-stacks-unit-tests
                      queue
                      GTest::Main
                      )
gtest_discover_tests(queue-2-stacks-unit-tests)

set(QUEUE_TYPE "QueueLinkedList")
CONFIGURE_FILE(QueueTest.cpp.in QueueLinkedList.cpp)
add_executable(queue-linked-list-unit-tests
               Queue2StacksTest.cpp
               )
target_link_libraries(queue-linked-list-unit-tests
                      queue
                      GTest::Main
                      )
gtest_discover_tests(queue-linked-list-unit-tests)
