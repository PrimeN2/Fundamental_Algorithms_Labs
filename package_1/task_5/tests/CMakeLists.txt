include_directories(../include)

add_executable(test_task5 
    main_test.c
    ../src/processor.c 
    ../src/utils.c)


add_test(NAME test_task5 COMMAND test_task5)
