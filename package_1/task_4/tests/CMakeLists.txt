include_directories(../include)

add_executable(test_task4 
    main_test.c
    ../src/equation.c 
    ../src/limit.c
    ../src/series_sum.c
    ../src/utils.c)

target_link_libraries(test_task4 m)

add_test(NAME test_task4 COMMAND test_task4)
