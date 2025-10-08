include_directories(../include)

add_executable(test_task8 
    main_test.c
    ../src/converter.c)

target_link_libraries(test_task8 m)

add_test(NAME test_task8 COMMAND test_task8)
