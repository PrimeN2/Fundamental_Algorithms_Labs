include_directories(include)

add_executable(task_2 src/main.c src/primes.c)

option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
