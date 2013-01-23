set( tinySIGCOMP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinySIGCOMP_INCLUDE_DIR ${tinySIGCOMP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinySIGCOMP_DEPS
  tinySAK
)

# build include directories list
set( tinySIGCOMP_INCLUDE_DIRECTORIES
  ${tinySIGCOMP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
)

# Includes
include_directories( ${tinySIGCOMP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinySIGCOMP_SRC 
  src/adler32.c
  src/compress.c
  src/deflate.c
  src/tcomp.c
  src/tcomp_buffer.c
  src/tcomp_compartment.c
  src/tcomp_compressordata.c
  src/tcomp_compressordisp.c
  src/tcomp_compressor_deflate.c
  src/tcomp_compressor_dummy.c
  src/tcomp_decompressordisp.c
  src/tcomp_deflatedata.c
  src/tcomp_deflatedata.ghost.c
  src/tcomp_deflatedata.zlib.c
  src/tcomp_dicts.c
  src/tcomp_manager.c
  src/tcomp_message.c
  src/tcomp_nackinfo.c
  src/tcomp_params.c
  src/tcomp_reqfeed.c
  src/tcomp_result.c
  src/tcomp_state.c
  src/tcomp_statehandler.c
  src/tcomp_udvm.bytecopy.c
  src/tcomp_udvm.c
  src/tcomp_udvm.instructions.c
  src/tcomp_udvm.nack.c
  src/tcomp_udvm.operands.c
  src/tcomp_udvm.statemanagment.c
  src/trees.c
  src/zutil.c
)

add_library( tinySIGCOMP SHARED ${tinySIGCOMP_SRC} )

target_link_libraries( tinySIGCOMP
  ${tinySIGCOMP_DEPS}
)
