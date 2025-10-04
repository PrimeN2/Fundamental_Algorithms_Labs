include_directories(../include)

add_executable(test_task3
    main_tests.c
    ../src/handler_q.c
    ../src/handler_m.c
    ../src/handler_t.c
)

target_link_libraries(test_task3 m)

add_test(NAME test_task3 COMMAND test_task3)