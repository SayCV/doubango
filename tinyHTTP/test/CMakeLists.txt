add_executable( testHTTP test.c )
target_link_libraries( testHTTP tinyHTTP )
add_test( testHTTP ${CMAKE_CURRENT_BINARY_DIR}/testHTTP )
