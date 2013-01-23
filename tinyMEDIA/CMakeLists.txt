set( tinyMEDIA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyMEDIA_INCLUDE_DIR ${tinyMEDIA_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyMEDIA_DEPS
  tinySAK
  tinyNET
  tinySDP
)

# build include directories list
set( tinyMEDIA_INCLUDE_DIRECTORIES
  ${tinyMEDIA_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinySDP_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyMEDIA_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyMEDIA_SRC 
  src/tmedia.c
  src/tmedia_codec.c
  src/tmedia_codec_dummy.c
  src/tmedia_common.c
  src/tmedia_consumer.c
  src/tmedia_converter_video.c
  src/tmedia_defaults.c
  src/tmedia_denoise.c
  src/tmedia_imageattr.c
  src/tmedia_jitterbuffer.c
  src/tmedia_params.c
  src/tmedia_producer.c
  src/tmedia_qos.c
  src/tmedia_resampler.c
  src/tmedia_session.c
  src/tmedia_session_dummy.c
  src/tmedia_session_ghost.c
  src/content/tmedia_content.c
  src/content/tmedia_content_cpim.c
  src/content/tmedia_content_multipart.c
  src/content/tmedia_content_sip_frag.c
)

add_library( tinyMEDIA SHARED ${tinyMEDIA_SRC} )

target_link_libraries( tinyMEDIA
  ${tinyMEDIA_DEPS}
)
