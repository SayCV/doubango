/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@doubango.org>
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
#include "RegistrationSession.h"

RegistrationSession::RegistrationSession(SipStack* Stack)
: SipSession(Stack)
{
}

bool RegistrationSession::Register(unsigned expires)
{
	int ret = tsip_action_REGISTER(this->handle,
		TSIP_ACTION_SET_NULL());
	return (ret == 0);
}

bool RegistrationSession::UnRegister()
{
	int ret = tsip_action_UNREGISTER(this->handle,
		TSIP_ACTION_SET_NULL());
	return (ret == 0);
}

RegistrationSession::~RegistrationSession()
{
}
