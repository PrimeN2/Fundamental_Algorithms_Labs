include_directories(include)

add_executable(task_3 src/custom_print.c src/flag_handler.c)

target_link_libraries(task_3 m)
