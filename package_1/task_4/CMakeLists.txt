include_directories(include)

add_executable(task_4 
    src/main.c
    src/series_sum.c
    src/limit.c
    src/equation.c
    src/utils.c)

target_link_libraries(task_4 m)

# option(BUILD_TESTS "Build tests" OFF)
# if(BUILD_TESTS)
#     add_subdirectory(tests)
# endif()
