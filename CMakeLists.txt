cmake_minimum_required(VERSION 3.5)
project(demo-polynomials)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories( include/ )

add_library(mymath STATIC src/mymath.c)
add_library(test_harness_main STATIC tests/main.c)

add_executable(polyeval src/main.c)
target_link_libraries(polyeval mymath)

add_executable(test tests/tests.c)
target_link_libraries(test test_harness_main mymath)







