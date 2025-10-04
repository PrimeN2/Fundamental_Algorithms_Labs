cmake_minimum_required(VERSION 3.10)
project(FUNDAMNTAL_ALGORITHMS_LABS)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -Wpedantic -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
endif()

add_subdirectory(package_1)
