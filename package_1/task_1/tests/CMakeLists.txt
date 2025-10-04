include_directories(../include)

add_executable(test_task1
    main_test.c
    ../src/handlers.c
)

target_link_libraries(test_task1 m)

add_test(NAME test_task1 COMMAND test_task1)