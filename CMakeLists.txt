cmake_minimum_required(VERSION 2.6)

project( doubango )

# Tests and Dashboard submission
include( CTest )
enable_testing()

set( subModules
  tinySAK      # no dependencies
  tinyNET      # depends on SAK
  tinyHTTP     # depends on SAK, NET
  tinyXCAP     # depends on SAK, NET, HTTP
  tinyIPSec    # depends on SAK
  tinySMS      # depends on SAK
  tinySIGCOMP  # depends on SAK
  tinySDP      # depends on SAK
  tinyMSRP     # depends on SAK, NET, HTTP, SDP
  tinyMEDIA    # depends on SAK, NET, SDP
  tinyRTP      # depends on SAK, NET, MEDIA
  tinyDAV      # depends on SAK, NET, SDP, MEDIA, RTP, MSRP
  tinySIP      # 
)

foreach( mod ${subModules} )
  set( ${mod}_INCLUDE_DIR )
  add_subdirectory( ${mod} )
endforeach()

#-------------------------
# webrtc2sip as a subdir
#
#
#find_package( LibXml2 )
#if( LIBXML2_FOUND )
#  include_directories( ${LIBXML2_INCLUDE_DIR} )
#else()
#  message( FATAL_ERROR "LibXml2 mandatory library was not found." )
#endif()
#add_subdirectory( webrtc2sip )
