set( tinySMS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinySMS_INCLUDE_DIR ${tinySMS_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinySMS_DEPS
  tinySAK
)

# build include directories list
set( tinySMS_INCLUDE_DIRECTORIES
  ${tinySMS_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
)

# Includes
include_directories( ${tinySMS_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinySMS_SRC 
  src/tsms.c
  src/tsms_address.c
  src/tsms_common.c
  src/tsms_packing.c
  src/rpdu/tsms_rpdu.c
  src/tpdu/tsms_tpdu_command.c
  src/tpdu/tsms_tpdu_deliver.c
  src/tpdu/tsms_tpdu_report.c
  src/tpdu/tsms_tpdu_status_report.c
  src/tpdu/tsms_tpdu_submit.c
)

add_library( tinySMS SHARED ${tinySMS_SRC} )

target_link_libraries( tinySMS
  ${tinySMS_DEPS}
)
