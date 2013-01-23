add_executable( testSIP test.c )
target_link_libraries( testSIP tinySIP )
add_test( testSIP ${CMAKE_CURRENT_BINARY_DIR}/testSIP )
