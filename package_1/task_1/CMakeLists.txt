include_directories(include)

add_executable(task_1 src/main.c src/handlers.c)
target_link_libraries(task_1 m)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
