include_directories(../include)

add_executable(test_task6 
    main_tests.c
    ../src/integrals.c 
    )

target_link_libraries(test_task6 m)

add_test(NAME test_task6 COMMAND test_task6)
