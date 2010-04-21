/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
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

/**@file tsip_api_publish.c
 * @brief Public subscription (PUBLISH) functions.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySIP/api/tsip_api_publish.h"

#include "tinySIP/dialogs/tsip_dialog_layer.h"
#include "tinySIP/dialogs/tsip_dialog_publish.h"

#include "tsip.h"

#include "tsk_runnable.h"
#include "tsk_debug.h"

#define TSIP_PUBLISH_EVENT_CREATE( type)		tsk_object_new(tsip_publish_event_def_t, type)

int tsip_publish_event_signal(tsip_publish_event_type_t type, struct tsip_stack_s *stack, tsip_ssession_handle_t* SSESSION, short status_code, const char *phrase, const tsip_message_t* sipmessage)
{
	tsip_publish_event_t* sipevent = TSIP_PUBLISH_EVENT_CREATE(type);
	tsip_event_init(TSIP_EVENT(sipevent), stack, SSESSION, status_code, phrase, sipmessage, tsip_event_publish);

	TSK_RUNNABLE_ENQUEUE_OBJECT(TSK_RUNNABLE(stack), sipevent);

	return 0;
}

int tsip_publish(const tsip_ssession_handle_t *ss, ...)
{
	const tsip_ssession_t* session = ss;
	va_list ap;
	tsip_action_t* action;
	tsip_dialog_t* dialog;
	int ret = -1;

	if(!session || !session->stack){
		return ret;
	}
	
	va_start(ap, ss);
	if((action = tsip_action_create(atype_publish, &ap))){
		if(!(dialog = tsip_dialog_layer_find_by_op(session->stack->layer_dialog, ss))){
			dialog = tsip_dialog_layer_new(session->stack->layer_dialog, tsip_dialog_PUBLISH, ss);
		}
		ret = tsip_dialog_fsm_act(dialog, action->type, tsk_null, action);
		
		tsk_object_unref(dialog);
		TSK_OBJECT_SAFE_FREE(action);
	}
	va_end(ap);

	return ret;
}

int tsip_unpublish(const tsip_ssession_handle_t *ss, ...)
{
	const tsip_ssession_t* session = ss;
	va_list ap;
	tsip_action_t* action;
	int ret = -1;

	if(!session || !session->stack){
		return ret;
	}
	
	va_start(ap, ss);
	if((action = tsip_action_create(atype_unpublish, &ap))){
		ret = tsip_ssession_hangup(ss, action);
		TSK_OBJECT_SAFE_FREE(action);
	}
	va_end(ap);

	return 0;
}











//========================================================
//	SIP PUBLISH event object definition
//
static tsk_object_t* tsip_publish_event_ctor(tsk_object_t * self, va_list * app)
{
	tsip_publish_event_t *sipevent = self;
	if(sipevent){
		sipevent->type = va_arg(*app, tsip_publish_event_type_t);
	}
	return self;
}

static tsk_object_t* tsip_publish_event_dtor(tsk_object_t * self)
{ 
	tsip_publish_event_t *sipevent = self;
	if(sipevent){
		tsip_event_deinit(TSIP_EVENT(sipevent));
	}
	return self;
}

static int tsip_publish_event_cmp(const tsk_object_t *obj1, const tsk_object_t *obj2)
{
	return -1;
}

static const tsk_object_def_t tsip_publish_event_def_s = 
{
	sizeof(tsip_publish_event_t),
	tsip_publish_event_ctor, 
	tsip_publish_event_dtor,
	tsip_publish_event_cmp, 
};
const tsk_object_def_t *tsip_publish_event_def_t = &tsip_publish_event_def_s;
