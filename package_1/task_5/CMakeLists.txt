include_directories(include)

add_executable(task_5 
    src/main.c
    src/utils.c
    src/processor.c)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()