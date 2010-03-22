/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsdp_header_O.c
 * @brief SDP "o=" header (Origin).
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Uat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySDP/headers/tsdp_header_O.h"

#include "tsk_debug.h"
#include "tsk_memory.h"
#include "tsk_string.h"

#include <string.h>

/***********************************
*	Ragel state machine.
*/
%%{
	machine tsdp_machine_parser_header_U;

	# Includes
	include tsdp_machine_utils "./tsdp_machine_utils.rl";
	
	action tag{
		tag_start = p;
	}

	action parse_username{
		TSK_PARSER_SET_STRING(hdr_O->username);
	}

	action parse_sess_id{
		TSK_PARSER_SET_UINT(hdr_O->sess_id);
	}

	action parse_sess_version{
		TSK_PARSER_SET_UINT(hdr_O->sess_version);
	}
	
	action parse_nettype{
		TSK_PARSER_SET_STRING(hdr_O->nettype);
	}

	action parse_addrtype{
		TSK_PARSER_SET_STRING(hdr_O->addrtype);
	}

	action parse_addr{
		TSK_PARSER_SET_STRING(hdr_O->addr);
	}

	username = any*>tag %parse_username;
	sess_id = DIGIT+>tag %parse_sess_id;
	sess_version = DIGIT+>tag %parse_sess_version;
	nettype = any*>tag %parse_nettype;
	addrtype = any*>tag %parse_addrtype;
	addr = any*>tag %parse_addr;
	O = 'o' SP* "=" SP*<: username :>SP sess_id :>SP sess_version :>SP nettype :>SP addrtype :>SP addr;
	
	# Entry point
	main := O :>CRLF?;

}%%

int tsdp_header_O_tostring(const tsdp_header_t* header, tsk_buffer_t* output)
{
	if(header)
	{
		const tsdp_header_O_t *O = (const tsdp_header_O_t *)header;
		
		// o=alice 2890844526 2890844526 IN IP4 host.atlanta.example.com
		return tsk_buffer_appendEx(output, "%s %u %u %s %s %s",
			O->username,
			O->sess_version,
			O->sess_id,
			O->nettype,
			O->addrtype,
			O->addr
			);
		
		return 0;
	}

	return -1;
}

tsdp_header_t* tsdp_header_O_clone(const tsdp_header_t* header)
{
	if(header){
		const tsdp_header_O_t *O = (const tsdp_header_O_t *)header;
		return TSDP_HEADER_O_CREATE(O->username, O->sess_id, O->sess_version, O->nettype, O->addrtype, O->addr);
	}
	return tsk_null;
}

tsdp_header_O_t *tsdp_header_O_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsdp_header_O_t *hdr_O = TSDP_HEADER_O_CREATE_NULL();
	
	const char *tag_start;

	%%write data;
	%%write init;
	%%write exec;
	
	if( cs < %%{ write first_final; }%% ){
		TSK_DEBUG_ERROR("Failed to parse \"o=\" header.");
		TSK_OBJECT_SAFE_FREE(hdr_O);
	}
	
	return hdr_O;
}







//========================================================
//	O header object definition
//

static void* tsdp_header_O_create(void *self, va_list * app)
{
	tsdp_header_O_t *O = self;
	if(O)
	{
		TSDP_HEADER(O)->type = tsdp_htype_O;
		TSDP_HEADER(O)->tostring = tsdp_header_O_tostring;
		TSDP_HEADER(O)->clone = tsdp_header_O_clone;
		TSDP_HEADER(O)->rank = TSDP_HTYPE_O_RANK;
		
		O->username = tsk_strdup(va_arg(*app, const char*));
		O->sess_version = va_arg(*app, uint32_t);
		O->sess_id = va_arg(*app, uint32_t);
		O->nettype = tsk_strdup(va_arg(*app, const char*));
		O->addrtype = tsk_strdup(va_arg(*app, const char*));
		O->addr = tsk_strdup(va_arg(*app, const char*));
	}
	else{
		TSK_DEBUG_ERROR("Failed to create new O header.");
	}
	return self;
}

static void* tsdp_header_O_destroy(void *self)
{
	tsdp_header_O_t *O = self;
	if(O){
		TSK_FREE(O->username);
		TSK_FREE(O->nettype);
		TSK_FREE(O->addrtype);
		TSK_FREE(O->addr);
	}
	else{
		TSK_DEBUG_ERROR("Null U header.");
	}

	return self;
}
static int tsdp_header_O_cmp(const tsk_object_t *obj1, const tsk_object_t *obj2)
{
	if(obj1 && obj2){
		return tsdp_header_rank_cmp(obj1, obj2);
	}
	else{
		return -1;
	}
}

static const tsk_object_def_t tsdp_header_O_def_s = 
{
	sizeof(tsdp_header_O_t),
	tsdp_header_O_create,
	tsdp_header_O_destroy,
	tsdp_header_O_cmp
};

const void *tsdp_header_O_def_t = &tsdp_header_O_def_s;
