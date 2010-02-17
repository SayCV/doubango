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

/**@file tcomp_manager.h
 * @brief  SigComp Manager.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TCOMP_MANAGER_H
#define TCOMP_MANAGER_H

#include "tinysigcomp_config.h"

#include "tcomp_result.h"
#include "tcomp_compressor.h"

TCOMP_BEGIN_DECLS

typedef void tcomp_manager_handle_t;


#define TCOMP_MANAGER_CREATE()					(tcomp_manager_handle_t*)tsk_object_new(tcomp_manager_def_t)

//
//	Compression / Decompression
//
TINYSIGCOMP_API size_t tcomp_manager_compress(tcomp_manager_handle_t *handle, const void* compartmentId, size_t compartmentIdSize, const void* input_ptr, size_t input_size, void* output_ptr, size_t output_size, int stream);
#define tcomp_manager_compressUDP(handle, compartmentId, compartmentIdSize, input_ptr, input_size, output_ptr, output_size) tcomp_manager_compress((tcomp_manager_handle_t *)handle, (const void*) compartmentId, (size_t) compartmentIdSize, (const void*) input_ptr, (size_t) input_size, (void*) output_ptr, (size_t) output_size, 0)
#define tcomp_manager_compressTCP(handle, compartmentId, compartmentIdSize, input_ptr, input_size, output_ptr, output_size) tcomp_manager_compress((tcomp_manager_handle_t *)handle, (const void*) compartmentId, (size_t) compartmentIdSize, (const void*) input_ptr, (size_t) input_size, (void*) output_ptr, (size_t) output_size, 1) 
#define tcomp_manager_compressSCTP compressTCP

TINYSIGCOMP_API size_t tcomp_manager_decompress(tcomp_manager_handle_t *handle, const void* input_ptr, size_t input_size, tcomp_result_t *lpResult);
TINYSIGCOMP_API size_t tcomp_manager_getNextStreamMessage(tcomp_manager_handle_t *handle, tcomp_result_t *lpResult);

/*
*	Compartment management
*/
TINYSIGCOMP_API void tcomp_manager_provideCompartmentId(tcomp_manager_handle_t *handle, tcomp_result_t *lpResult);
TINYSIGCOMP_API void tcomp_manager_closeCompartment(tcomp_manager_handle_t *handle, const void *compartmentId, size_t compartmentIdSize);

/*
*	SigComp Parameters
*/
TINYSIGCOMP_API void tcomp_manager_setDecompression_Memory_Size(tcomp_manager_handle_t *handle, uint32_t dms);
TINYSIGCOMP_API void tcomp_manager_setState_Memory_Size(tcomp_manager_handle_t *handle, uint32_t sms);
TINYSIGCOMP_API void tcomp_manager_setCycles_Per_Bit(tcomp_manager_handle_t *handle, uint8_t cpb);
TINYSIGCOMP_API void tcomp_manager_setSigComp_Version(tcomp_manager_handle_t *handle, uint8_t version);

/*
*	Compressors
*/
TINYSIGCOMP_API void tcomp_manager_addCompressor(tcomp_manager_handle_t *handle, tcomp_compressor_compress compressor);

/*
*	Dictionnaries
*/
TINYSIGCOMP_API void tcomp_manager_addSipSdpDictionary(tcomp_manager_handle_t *handle);
TINYSIGCOMP_API void tcomp_manager_addPresenceDictionary(tcomp_manager_handle_t *handle);

TINYSIGCOMP_GEXTERN const void *tcomp_manager_def_t;

TCOMP_END_DECLS

#endif /* TCOMP_MANAGER_H */
