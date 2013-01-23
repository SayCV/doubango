set( tinyIPSec_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set( tinyIPSec_INCLUDE_DIR ${tinyIPSec_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyIPSec_DEPS
  tinySAK
)

# build include directories list
set( tinyIPSec_INCLUDE_DIRECTORIES
  ${tinyIPSec_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyIPSec_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyIPSec_SRC 
  src/tipsec.c
  src/tipsec_common.c
  src/tipsec_racoon.c
  src/tipsec_vista.c
  src/tipsec_xp.c
)

add_library( tinyIPSec SHARED ${tinyIPSec_SRC} )

target_link_libraries( tinyIPSec
  ${tinyIPSec_DEPS}
)
