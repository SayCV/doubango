# will be used by depending libraries
# NOTE ALEX: this is not a clean layout like in tinyDAV
# cmake will hide that to other libs
set( tinyNET_INCLUDE_DIR 
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/dhcp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/dhcp6
  ${CMAKE_CURRENT_SOURCE_DIR}/src/dns
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ice
  ${CMAKE_CURRENT_SOURCE_DIR}/src/stun
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tls
  ${CMAKE_CURRENT_SOURCE_DIR}/src/turn
)
# set it at the parent scope as well to pass it to the other modules
set( tinyNET_INCLUDE_DIR ${tinyNET_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinyNET_DEPS
  tinySAK
)

# build include directories list
set( tinyNET_INCLUDE_DIRECTORIES
  ${tinyNET_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
)

# Includes
include_directories( ${tinyNET_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyNET_SRC 
  src/tnet.c
  src/tnet_auth.c
  src/tnet_endianness.c
  src/tnet_nat.c src/tnet_poll.c
  src/tnet_socket.c
  src/tnet_transport.c
  src/tnet_transport_poll.c
  src/tnet_utils.c
  src/dhcp/tnet_dhcp.c
  src/dhcp/tnet_dhcp_message.c
  src/dhcp/tnet_dhcp_option.c
  src/dhcp/tnet_dhcp_option_sip.c
  src/dhcp6/tnet_dhcp6.c
  src/dhcp6/tnet_dhcp6_duid.c
  src/dhcp6/tnet_dhcp6_message.c
  src/dhcp6/tnet_dhcp6_option.c
  src/dns/tnet_dns.c
  src/dns/tnet_dns_a.c
  src/dns/tnet_dns_aaaa.c
  src/dns/tnet_dns_cname.c
  src/dns/tnet_dns_message.c
  src/dns/tnet_dns_mx.c
  src/dns/tnet_dns_naptr.c
  src/dns/tnet_dns_ns.c
  src/dns/tnet_dns_opt.c
  src/dns/tnet_dns_ptr.c
  src/dns/tnet_dns_regexp.c
  src/dns/tnet_dns_resolvconf.c
  src/dns/tnet_dns_rr.c
  src/dns/tnet_dns_soa.c
  src/dns/tnet_dns_srv.c
  src/dns/tnet_dns_txt.c
  src/ice/tnet_ice_candidate.c
  src/ice/tnet_ice_ctx.c
  src/ice/tnet_ice_event.c
  src/ice/tnet_ice_pair.c
  src/ice/tnet_ice_utils.c
  src/stun/tnet_stun.c
  src/stun/tnet_stun_attribute.c
  src/stun/tnet_stun_message.c
  src/tls/tnet_tls.c
  src/tls/tnet_dtls.c
  src/turn/tnet_turn.c
  src/turn/tnet_turn_attribute.c
  src/turn/tnet_turn_message.c
)

add_library( tinyNET SHARED ${tinyNET_SRC} )

# alex: to update with targets once this is taken care of
# note alex, construct a list of deps here using append
target_link_libraries( tinyNET
 tinySAK
 resolv
)

add_subdirectory( test )
