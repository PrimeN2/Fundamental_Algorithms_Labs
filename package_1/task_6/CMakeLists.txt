include_directories(include)

add_executable(task_6 
    src/main.c
    src/integrals.c)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()