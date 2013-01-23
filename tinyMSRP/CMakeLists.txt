set( tinyMSRP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyMSRP_INCLUDE_DIR ${tinyMSRP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyMSRP_DEPS
  tinySAK
  tinyNET
  tinyHTTP
  tinySDP
)

# build include directories list
set( tinyMSRP_INCLUDE_DIRECTORIES
  ${tinyMSRP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinyHTTP_INCLUDE_DIR}
  ${tinySDP_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyMSRP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyMSRP_SRC 
  src/tmsrp.c
  src/tmsrp_event.c
  src/tmsrp_message.c
  src/tmsrp_uri.c
  src/headers/tmsrp_header.c
  src/headers/tmsrp_header_Authentication-Info.c
  src/headers/tmsrp_header_Authorization.c
  src/headers/tmsrp_header_Byte-Range.c
  src/headers/tmsrp_header_Content-Type.c
  src/headers/tmsrp_header_Dummy.c
  src/headers/tmsrp_header_Expires.c
  src/headers/tmsrp_header_Failure-Report.c
  src/headers/tmsrp_header_From-Path.c
  src/headers/tmsrp_header_Max-Expires.c
  src/headers/tmsrp_header_Message-ID.c
  src/headers/tmsrp_header_Min-Expires.c
  src/headers/tmsrp_header_Status.c
  src/headers/tmsrp_header_Success-Report.c
  src/headers/tmsrp_header_To-Path.c
  src/headers/tmsrp_header_Use-Path.c
  src/headers/tmsrp_header_WWW-Authenticate.c
  src/parsers/tmsrp_parser_message.c
  src/parsers/tmsrp_parser_uri.c
  src/session/tmsrp_config.c
  src/session/tmsrp_data.c
  src/session/tmsrp_receiver.c
  src/session/tmsrp_sender.c
)

add_library( tinyMSRP SHARED ${tinyMSRP_SRC} )

target_link_libraries( tinyMSRP
  ${tinyMSRP_DEPS}
)
