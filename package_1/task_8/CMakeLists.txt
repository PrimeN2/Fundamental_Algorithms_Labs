include_directories(include)

add_executable(task_8
    src/main.c
    src/converter.c)

target_link_libraries(task_8 m)


if(BUILD_TESTS)
    add_subdirectory(tests)
endif()