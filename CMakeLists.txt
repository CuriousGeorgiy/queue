CMAKE_MINIMUM_REQUIRED(VERSION 3.16.4)

PROJECT(queue
        VERSION 0.0.0.0
        LANGUAGES CXX
        )

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
ADD_COMPILE_OPTIONS(-Werror -Wall -Wextra -Wpedantic -Wshadow)

IF (ENABLE_ASAN)
  ADD_COMPILE_OPTIONS(-fsanitize=address
                       -fsanitize-address-use-after-scope
                       -fno-omit-frame-pointer
                       -fno-optimize-sibling-calls
                      )
  ADD_LINK_OPTIONS(-fsanitize=address)
ENDIF ()

SET(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -format-style=file;
    -header-filter=.;
    )

FILE(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)
ADD_CUSTOM_TARGET(
    clang-format-queue
    COMMAND clang-format
    -i
    --sort-includes
    -style=file
    ${ALL_SOURCE_FILES}
)

ADD_SUBDIRECTORY(queue)
ADD_SUBDIRECTORY(stack)
