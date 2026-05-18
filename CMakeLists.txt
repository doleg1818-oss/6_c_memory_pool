cmake_minimum_required(VERSION 3.16)

project(c_memory_pool C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(memory_pool_example
    examples/main.c
    src/memory_pool.c
)

add_executable(test_memory_pool
    tests/test_memory_pool.c
    src/memory_pool.c
)
