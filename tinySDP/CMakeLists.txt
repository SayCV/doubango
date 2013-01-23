set( tinySDP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinySDP_INCLUDE_DIR ${tinySDP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinySDP_DEPS
  tinySAK
)

# build include directories list
set( tinySDP_INCLUDE_DIRECTORIES
  ${tinySDP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
)

# Includes
include_directories( ${tinySDP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinySDP_SRC 
  src/tsdp.c
  src/tsdp_message.c
  src/headers/tsdp_header.c
  src/headers/tsdp_header_A.c
  src/headers/tsdp_header_B.c
  src/headers/tsdp_header_C.c
  src/headers/tsdp_header_Dummy.c
  src/headers/tsdp_header_E.c
  src/headers/tsdp_header_I.c
  src/headers/tsdp_header_K.c
  src/headers/tsdp_header_M.c
  src/headers/tsdp_header_O.c
  src/headers/tsdp_header_P.c
  src/headers/tsdp_header_R.c
  src/headers/tsdp_header_S.c
  src/headers/tsdp_header_T.c
  src/headers/tsdp_header_U.c
  src/headers/tsdp_header_V.c
  src/headers/tsdp_header_Z.c
  src/parsers/tsdp_parser_message.c
)

add_library( tinySDP SHARED ${tinySDP_SRC} )

target_link_libraries( tinySDP
  ${tinySDP_DEPS}
)
