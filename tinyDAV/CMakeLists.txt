set( tinyDAV_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinyDAV_INCLUDE_DIR ${tinyDAV_INCLUDE_DIR} PARENT_SCOPE)

set( tinyDAV_DEPS
  tinySAK
  tinyNET
  tinySDP
  tinyRTP
  tinyMEDIA
  tinyMSRP
)

# Includes
include_directories(
  ${tinyDAV_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinySDP_INCLUDE_DIR}
  ${tinyRTP_INCLUDE_DIR}
  ${tinyMEDIA_INCLUDE_DIR}
  ${tinyMSRP_INCLUDE_DIR}
)

set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinyDAV_SRC 
  src/tdav.c src/tdav_session_av.c
  src/audio/tdav_consumer_audio.c
  src/audio/tdav_speakup_jitterbuffer.c
  src/audio/tdav_jitterbuffer.c
  src/audio/tdav_producer_audio.c
  src/audio/tdav_session_audio.c
  src/audio/tdav_speex_denoise.c
  src/audio/tdav_speex_jitterbuffer.c
  src/audio/tdav_speex_resampler.c
  src/audio/tdav_webrtc_denoise.c
  src/video/tdav_consumer_video.c
  src/video/tdav_converter_video.cxx
  src/video/tdav_runnable_video.c
  src/video/tdav_session_video.c
  src/video/jb/tdav_video_frame.c
  src/video/jb/tdav_video_jb.c
  src/t140/tdav_consumer_t140.c
  src/t140/tdav_producer_t140.c
  src/t140/tdav_session_t140.c
  src/msrp/tdav_consumer_msrp.c
  src/msrp/tdav_producer_msrp.c
  src/msrp/tdav_session_msrp.c
  src/codecs/amr/tdav_codec_amr.c
  src/codecs/g711/g711.c
  src/codecs/g711/tdav_codec_g711.c
  src/codecs/g722/g722_decode.c
  src/codecs/g722/g722_encode.c
  src/codecs/g722/tdav_codec_g722.c
  src/codecs/g729/tdav_codec_g729.c
  src/codecs/gsm/tdav_codec_gsm.c
  src/codecs/bv/tdav_codec_bv16.c
  src/codecs/bv/tdav_codec_bv32.c
  src/codecs/ilbc/tdav_codec_ilbc.c
  src/codecs/speex/tdav_codec_speex.c
  src/codecs/dtmf/tdav_codec_dtmf.c
  src/codecs/fec/tdav_codec_red.c
  src/codecs/fec/tdav_codec_ulpfec.c
  src/codecs/h261/tdav_codec_h261.c
  src/codecs/h263/tdav_codec_h263.c
  src/codecs/h264/tdav_codec_h264.c
  src/codecs/h264/tdav_codec_h264_rtp.c
  src/codecs/theora/tdav_codec_theora.c
  src/codecs/vpx/tdav_codec_vp8.c
  src/codecs/mp4ves/tdav_codec_mp4ves.c
  src/codecs/msrp/tdav_codec_msrp.c
  src/codecs/t140/tdav_codec_t140.c  
)

add_library( tinyDAV SHARED ${tinyDAV_SRC} )

target_link_libraries( tinyDAV
  ${tinyDAV_DEPS}
)
