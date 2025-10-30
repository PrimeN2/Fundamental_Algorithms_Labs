include_directories(include)

add_executable(task_4 
    main.c 
    src/overio.c)

target_link_libraries(task_4 m)
