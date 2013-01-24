
set( tinyWrap_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyWrap_INCLUDE_DIR ${tinyWrap_INCLUDE_DIR} PARENT_SCOPE)

include_directories(
  ${tinyWrap_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinyMSRP_INCLUDE_DIR}
  ${tinyMEDIA_INCLUDE_DIR}
  ${tinySMS_INCLUDE_DIR}
  ${tinyXCAP_INCLUDE_DIR}
  ${tinyHTTP_INCLUDE_DIR}
  ${tinySIP_INCLUDE_DIR}
  ${tinySDP_INCLUDE_DIR}
  ${tinyDAV_INCLUDE_DIR}
)

set( tinyWrap_SRC
  src/ActionConfig.cxx
  src/AudioResampler.cxx
  src/DDebug.cxx
  src/MediaContent.cxx
  src/MediaSessionMgr.cxx
  src/Msrp.cxx
  src/ProxyConsumer.cxx
  src/ProxyPluginMgr.cxx
  src/ProxyProducer.cxx
  src/SMSEncoder.cxx
  src/SafeObject.cxx
  src/SipCallback.cxx
  src/SipEvent.cxx
  src/SipMessage.cxx
  src/SipSession.cxx
  src/SipStack.cxx
  src/SipUri.cxx
  src/Xcap.cxx
)

add_library( tinyWrap ${tinyWrap_SRC} )

