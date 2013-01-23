set( tinyRTP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyRTP_INCLUDE_DIR ${tinyRTP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyRTP_DEPS
  tinySAK
  tinyNET
  tinyMEDIA
)

# build include directories list
set( tinyRTP_INCLUDE_DIRECTORIES
  ${tinyRTP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinyMEDIA_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyRTP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyRTP_SRC 
  src/trtp.c
  src/trtp_manager.c
  src/trtp_srtp.c
  src/rtcp/trtp_rtcp_header.c
  src/rtcp/trtp_rtcp_packet.c
  src/rtcp/trtp_rtcp_rblock.c
  src/rtcp/trtp_rtcp_report.c
  src/rtcp/trtp_rtcp_report_bye.c
  src/rtcp/trtp_rtcp_report_fb.c
  src/rtcp/trtp_rtcp_report_rr.c
  src/rtcp/trtp_rtcp_report_sdes.c
  src/rtcp/trtp_rtcp_report_sr.c
  src/rtcp/trtp_rtcp_report_xr.c
  src/rtcp/trtp_rtcp_sdes_chunck.c
  src/rtcp/trtp_rtcp_sdes_item.c
  src/rtcp/trtp_rtcp_session.c
  src/rtp/trtp_rtp_header.c
  src/rtp/trtp_rtp_packet.c
  src/rtp/trtp_rtp_session.c
)

add_library( tinyRTP SHARED ${tinyRTP_SRC} )

target_link_libraries( tinyRTP
  ${tinyRTP_DEPS}
)
