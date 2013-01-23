set( tinyHTTP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyHTTP_INCLUDE_DIR ${tinyHTTP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyHTTP_DEPS
  tinySAK
  tinyNET
)

# build include directories list
set( tinyHTTP_INCLUDE_DIRECTORIES
  ${tinyHTTP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyHTTP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyHTTP_SRC 
  src/thttp.c src/thttp_action.c
  src/thttp_dialog.c src/thttp_event.c src/thttp_message.c
  src/thttp_session.c src/thttp_url.c src/auth/thttp_auth.c
  src/auth/thttp_challenge.c src/headers/thttp_header.c
  src/headers/thttp_header_Authorization.c
  src/headers/thttp_header_Content_Length.c
  src/headers/thttp_header_Content_Type.c
  src/headers/thttp_header_Dummy.c
  src/headers/thttp_header_ETag.c
  src/headers/thttp_header_Sec_WebSocket_Accept.c
  src/headers/thttp_header_Sec_WebSocket_Key.c
  src/headers/thttp_header_Sec_WebSocket_Protocol.c
  src/headers/thttp_header_Sec_WebSocket_Version.c
  src/headers/thttp_header_Transfer_Encoding.c
  src/headers/thttp_header_WWW_Authenticate.c
  src/parsers/thttp_parser_header.c
  src/parsers/thttp_parser_message.c
  src/parsers/thttp_parser_url.c
)

add_library( tinyHTTP SHARED ${tinyHTTP_SRC} )

# alex: to update with targets once this is taken care of
# note alex, use the DEPS list here
target_link_libraries( tinyHTTP
 tinySAK
 tinyNET
)

add_subdirectory( test )
