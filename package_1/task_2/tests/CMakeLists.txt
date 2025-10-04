include_directories(../include)

add_executable(test_task2
    main_tests.c
    ../src/primes.c
)

add_test(NAME test_task2 COMMAND test_task2)