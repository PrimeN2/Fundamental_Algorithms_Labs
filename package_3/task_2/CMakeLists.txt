set(SOURCE_FILES
    src/int_vector.c
    src/custom_vector.c
)

add_library(vector STATIC ${SOURCE_FILES})
target_include_directories(vector PUBLIC include)

add_executable(example_int example_int.c)
target_link_libraries(example_int vector)

