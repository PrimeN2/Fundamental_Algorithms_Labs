include_directories(include)

add_executable(task_3 
    src/main.c 
    src/handler_q.c 
    src/handler_m.c
    src/handler_t.c)

target_link_libraries(task_3 m)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()