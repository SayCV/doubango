cmake_minimum_required(VERSION 2.6)

project( doubango )

#-----------------------------------------------------------------------------
# Configuration options
option( BUILD_TESTING       "Build test suite."                   ON  )
# option( DBG_BUILD_DOCUMENTATION "Build the documentation."            OFF )
option( DBG_BUILD_WEBRTC2SIP    "Build webrtc2sip media proxy."       OFF )

# Tests and Dashboard submission
if( BUILD_TESTING )
  include( CTest )
  enable_testing()
endif()

set( subModules
  tinySAK      # no dependencies
  tinyNET      # depends on SAK
  tinyHTTP     # depends on NET
  tinyXCAP     # depends on HTTP
  tinyIPSec    # depends on SAK
  tinySMS      # depends on SAK
  tinySIGCOMP  # depends on SAK
  tinySDP      # depends on SAK
  tinyMSRP     # depends on HTTP, SDP
  tinyMEDIA    # depends on NET, SDP
  tinyRTP      # depends on MEDIA
  tinyDAV      # depends on RTP, MSRP
  tinySIP      # depends on HTTP, IPSec, MEDIA, SIGCOMP
)

foreach( mod ${subModules} )
  set( ${mod}_INCLUDE_DIR )
  add_subdirectory( ${mod} )
endforeach()

if( DBG_BUILD_WEBRTC2SIP )
  # builds tinyWrap in bindings/_common which depends on SIP
  set( tinyWrap_INCLUDE_DIR )
  add_subdirectory( bindings )
  add_subdirectory( webrtc2sip )
endif()

