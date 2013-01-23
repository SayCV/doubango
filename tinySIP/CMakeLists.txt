set( tinySIP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set( tinySIP_INCLUDE_DIR ${tinySIP_INCLUDE_DIR} PARENT_SCOPE )

# set up dependencies
set( tinySIP_DEPS
  tinySAK
  tinyNET
  tinyHTTP
  tinyIPSec
  tinySDP
  tinyMEDIA
  tinySIGCOMP
)

# build include directories list
set( tinySIP_INCLUDE_DIRECTORIES
  ${tinySIP_INCLUDE_DIR}
  ${tinySAK_INCLUDE_DIR}
  ${tinyNET_INCLUDE_DIR}
  ${tinyHTTP_INCLUDE_DIR}
  ${tinyIPSec_INCLUDE_DIR}
  ${tinySDP_INCLUDE_DIR}
  ${tinyMEDIA_INCLUDE_DIR}
  ${tinySIGCOMP_INCLUDE_DIR}
)

# Includes
include_directories( ${tinySIP_INCLUDE_DIRECTORIES} )

# set( SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( tinySIP_SRC 
  src/tsip.c
  src/tsip_action.c
  src/tsip_event.c
  src/tsip_message.c
  src/tsip_ssession.c
  src/tsip_timers.c
  src/tsip_uri.c
  src/api/tsip_api_common.c
  src/api/tsip_api_info.c
  src/api/tsip_api_invite.c
  src/api/tsip_api_message.c
  src/api/tsip_api_options.c
  src/api/tsip_api_publish.c
  src/api/tsip_api_register.c
  src/api/tsip_api_subscribe.c
  src/authentication/tsip_challenge.c
  src/authentication/tsip_milenage.c
  src/authentication/tsip_rijndael.c
  src/dialogs/tsip_dialog.c
  src/dialogs/tsip_dialog_info.c
  src/dialogs/tsip_dialog_invite.c
  src/dialogs/tsip_dialog_invite.cdiv.c
  src/dialogs/tsip_dialog_invite.client.c
  src/dialogs/tsip_dialog_invite.conf.c
  src/dialogs/tsip_dialog_invite.ect.c
  src/dialogs/tsip_dialog_invite.hold.c
  src/dialogs/tsip_dialog_invite.ice.c
  src/dialogs/tsip_dialog_invite.qos.c
  src/dialogs/tsip_dialog_invite.server.c
  src/dialogs/tsip_dialog_invite.timers.c
  src/dialogs/tsip_dialog_layer.c
  src/dialogs/tsip_dialog_message.c
  src/dialogs/tsip_dialog_options.c
  src/dialogs/tsip_dialog_publish.client.c
  src/dialogs/tsip_dialog_register.c
  src/dialogs/tsip_dialog_register.client.c
  src/dialogs/tsip_dialog_register.server.c
  src/dialogs/tsip_dialog_subscribe.client.c
  src/dialogs/tsip_dialog_subscribe.server.c
  src/headers/tsip_header.c
  src/headers/tsip_header_accept.c
  src/headers/tsip_header_Accept_Contact.c
  src/headers/tsip_header_Accept_Encoding.c
  src/headers/tsip_header_Accept_Language.c
  src/headers/tsip_header_Accept_Resource_Priority.c
  src/headers/tsip_header_Alert_Info.c
  src/headers/tsip_header_Allow.c
  src/headers/tsip_header_Allow_Events.c
  src/headers/tsip_header_Authentication_Info.c
  src/headers/tsip_header_Authorization.c
  src/headers/tsip_header_Call_ID.c
  src/headers/tsip_header_Call_Info.c
  src/headers/tsip_header_Contact.c
  src/headers/tsip_header_Content_Disposition.c
  src/headers/tsip_header_Content_Encoding.c
  src/headers/tsip_header_Content_Language.c
  src/headers/tsip_header_Content_Length.c
  src/headers/tsip_header_Content_Type.c
  src/headers/tsip_header_CSeq.c src/headers/tsip_header_Date.c
  src/headers/tsip_header_Dummy.c
  src/headers/tsip_header_Error_Info.c
  src/headers/tsip_header_Event.c
  src/headers/tsip_header_Expires.c
  src/headers/tsip_header_From.c
  src/headers/tsip_header_History_Info.c
  src/headers/tsip_header_Identity.c
  src/headers/tsip_header_Identity_Info.c
  src/headers/tsip_header_In_Reply_To.c
  src/headers/tsip_header_Join.c
  src/headers/tsip_header_Max_Forwards.c
  src/headers/tsip_header_MIME_Version.c
  src/headers/tsip_header_Min_Expires.c
  src/headers/tsip_header_Min_SE.c
  src/headers/tsip_header_Organization.c
  src/headers/tsip_header_Path.c
  src/headers/tsip_header_Priority.c
  src/headers/tsip_header_Privacy.c
  src/headers/tsip_header_Proxy_Authenticate.c
  src/headers/tsip_header_Proxy_Authorization.c
  src/headers/tsip_header_Proxy_Require.c
  src/headers/tsip_header_P_Access_Network_Info.c
  src/headers/tsip_header_P_Answer_State.c
  src/headers/tsip_header_P_Asserted_Identity.c
  src/headers/tsip_header_P_Associated_URI.c
  src/headers/tsip_header_P_Called_Party_ID.c
  src/headers/tsip_header_P_Charging_Function_Addresses.c
  src/headers/tsip_header_P_Charging_Vector.c
  src/headers/tsip_header_P_DCS_Billing_Info.c
  src/headers/tsip_header_P_DCS_LAES.c
  src/headers/tsip_header_P_DCS_OSPS.c
  src/headers/tsip_header_P_DCS_Redirect.c
  src/headers/tsip_header_P_DCS_Trace_Party_ID.c
  src/headers/tsip_header_P_Early_Media.c
  src/headers/tsip_header_P_Media_Authorization.c
  src/headers/tsip_header_P_Preferred_Identity.c
  src/headers/tsip_header_P_Profile_Key.c
  src/headers/tsip_header_P_User_Database.c
  src/headers/tsip_header_P_Visited_Network_ID.c
  src/headers/tsip_header_RAck.c
  src/headers/tsip_header_Reason.c
  src/headers/tsip_header_Record_Route.c
  src/headers/tsip_header_Referred_By.c
  src/headers/tsip_header_Refer_Sub.c
  src/headers/tsip_header_Refer_To.c
  src/headers/tsip_header_Reject_Contact.c
  src/headers/tsip_header_Replaces.c
  src/headers/tsip_header_Reply_To.c
  src/headers/tsip_header_Request_Disposition.c
  src/headers/tsip_header_Require.c
  src/headers/tsip_header_Resource_Priority.c
  src/headers/tsip_header_Retry_After.c
  src/headers/tsip_header_Route.c src/headers/tsip_header_RSeq.c
  src/headers/tsip_header_Security_Client.c
  src/headers/tsip_header_Security_Server.c
  src/headers/tsip_header_Security_Verify.c
  src/headers/tsip_header_Server.c
  src/headers/tsip_header_Service_Route.c
  src/headers/tsip_header_Session_Expires.c
  src/headers/tsip_header_SIP_ETag.c
  src/headers/tsip_header_SIP_If_Match.c
  src/headers/tsip_header_Subject.c
  src/headers/tsip_header_Subscription_State.c
  src/headers/tsip_header_Supported.c
  src/headers/tsip_header_Target_Dialog.c
  src/headers/tsip_header_Timestamp.c
  src/headers/tsip_header_To.c
  src/headers/tsip_header_Unsupported.c
  src/headers/tsip_header_User_Agent.c
  src/headers/tsip_header_Via.c
  src/headers/tsip_header_Warning.c
  src/headers/tsip_header_WWW_Authenticate.c
  src/parsers/tsip_parser_header.c
  src/parsers/tsip_parser_message.c
  src/parsers/tsip_parser_uri.c src/sigcomp/tsip_sigcomp.c
  src/transactions/tsip_transac.c
  src/transactions/tsip_transac_ict.c
  src/transactions/tsip_transac_ist.c
  src/transactions/tsip_transac_layer.c
  src/transactions/tsip_transac_nict.c
  src/transactions/tsip_transac_nist.c
  src/transports/tsip_transport.c
  src/transports/tsip_transport_ipsec.c
  src/transports/tsip_transport_layer.c
  src/transports/tsip_transport_tls.c
)

add_library( tinySIP SHARED ${tinySIP_SRC} )

target_link_libraries( tinySIP
  ${tinySIP_DEPS}
)

add_subdirectory( test )
