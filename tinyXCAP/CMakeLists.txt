set( tinyXCAP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyXCAP_INCLUDE_DIR ${tinyXCAP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyXCAP_DEPS
  tinySAK
  tinyNET
  tinyHTTP
)

# build include directories list
set( tinyXCAP_INCLUDE_DIRECTORIES
  ${tinyXCAP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinyHTTP_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyXCAP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyXCAP_SRC 
  src/txcap.c
  src/txcap_auid.c
  src/txcap_document.c
  src/txcap_node.c
  src/txcap_selector.c
  src/txcap_action.c
)

add_library( tinyXCAP SHARED ${tinyXCAP_SRC} )

target_link_libraries( tinyXCAP
  ${tinyXCAP_DEPS}
)
