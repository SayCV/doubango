add_executable( testSAK test.c )
target_link_libraries( testSAK tinySAK )
add_test( testSAK ${CMAKE_CURRENT_BINARY_DIR}/testSAK )
