add_executable( testNET test.c )
target_link_libraries( testNET tinyNET )
add_test( testNET ${CMAKE_CURRENT_BINARY_DIR}/testNET )
