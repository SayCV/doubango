
/* #line 1 "tsip_parser_header_From.rl" */
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
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_From.c
 * @brief SIP From/f header as per RFC 3261 subclause 20.20.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinysip/headers/tsip_header_From.h"

#include "tinysip/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

/**@defgroup tsip_header_From_group SIP From header.
*/

/***********************************
*	Ragel state machine.
*/

/* #line 95 "tsip_parser_header_From.rl" */




tsip_header_From_t *tsip_header_From_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_From_t *hdr_from = TSIP_HEADER_FROM_CREATE();
	
	const char *tag_start;

	
/* #line 63 "../source/headers/tsip_header_From.c" */
static const char _tsip_machine_parser_header_From_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 2, 0, 2
};

static const short _tsip_machine_parser_header_From_key_offsets[] = {
	0, 0, 2, 7, 10, 31, 32, 34, 
	55, 56, 58, 61, 65, 77, 80, 80, 
	81, 85, 89, 90, 92, 95, 114, 115, 
	117, 135, 154, 159, 160, 162, 166, 185, 
	186, 188, 207, 208, 210, 213, 229, 231, 
	233, 235, 237, 239, 240, 242, 248, 266, 
	267, 274, 282, 290, 298, 300, 307, 316, 
	318, 321, 323, 326, 328, 331, 334, 335, 
	338, 339, 342, 343, 352, 361, 369, 377, 
	385, 393, 395, 401, 410, 419, 428, 430, 
	433, 436, 437, 438, 459, 480, 499, 504, 
	505, 507, 511, 530, 531, 533, 552, 570, 
	587, 605, 609, 610, 612, 628, 630, 632, 
	634, 636, 638, 639, 641, 645, 651, 671, 
	690, 695, 695, 699, 701, 703
};

static const char _tsip_machine_parser_header_From_trans_keys[] = {
	70, 102, 9, 32, 58, 82, 114, 9, 
	32, 58, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 32, 60, 65, 90, 97, 
	122, 9, 32, 43, 58, 45, 46, 48, 
	57, 65, 90, 97, 122, 9, 32, 58, 
	62, 9, 13, 32, 59, 9, 13, 32, 
	59, 10, 9, 32, 9, 32, 59, 9, 
	13, 32, 33, 37, 39, 84, 116, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 10, 9, 32, 9, 32, 33, 
	37, 39, 84, 116, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 59, 61, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 9, 13, 32, 59, 61, 10, 
	9, 32, 9, 32, 59, 61, 9, 13, 
	32, 33, 34, 37, 39, 91, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 10, 9, 32, 9, 13, 32, 33, 
	34, 37, 39, 91, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 10, 
	9, 32, 9, 32, 34, 9, 13, 34, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 32, 126, -128, -65, -128, 
	-65, -128, -65, -128, -65, -128, -65, 10, 
	9, 32, 0, 9, 11, 12, 14, 127, 
	9, 13, 32, 33, 37, 39, 59, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 10, 58, 48, 57, 65, 70, 
	97, 102, 58, 93, 48, 57, 65, 70, 
	97, 102, 58, 93, 48, 57, 65, 70, 
	97, 102, 58, 93, 48, 57, 65, 70, 
	97, 102, 58, 93, 58, 48, 57, 65, 
	70, 97, 102, 46, 58, 93, 48, 57, 
	65, 70, 97, 102, 48, 57, 46, 48, 
	57, 48, 57, 46, 48, 57, 48, 57, 
	93, 48, 57, 93, 48, 57, 93, 46, 
	48, 57, 46, 46, 48, 57, 46, 46, 
	58, 93, 48, 57, 65, 70, 97, 102, 
	46, 58, 93, 48, 57, 65, 70, 97, 
	102, 58, 93, 48, 57, 65, 70, 97, 
	102, 58, 93, 48, 57, 65, 70, 97, 
	102, 58, 93, 48, 57, 65, 70, 97, 
	102, 58, 93, 48, 57, 65, 70, 97, 
	102, 58, 93, 48, 57, 65, 70, 97, 
	102, 46, 58, 93, 48, 57, 65, 70, 
	97, 102, 46, 58, 93, 48, 57, 65, 
	70, 97, 102, 46, 58, 93, 48, 57, 
	65, 70, 97, 102, 48, 57, 46, 48, 
	57, 46, 48, 57, 46, 58, 9, 13, 
	32, 33, 37, 39, 59, 61, 65, 97, 
	126, 42, 43, 45, 46, 48, 57, 66, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 59, 61, 71, 103, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 122, 
	9, 13, 32, 33, 37, 39, 59, 61, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 59, 61, 
	10, 9, 32, 9, 32, 59, 61, 9, 
	13, 32, 33, 34, 37, 39, 91, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 10, 9, 32, 9, 13, 32, 
	33, 34, 37, 39, 91, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 122, 
	9, 13, 32, 33, 37, 39, 59, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 9, 13, 32, 33, 37, 39, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	60, 10, 9, 32, 9, 13, 34, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 32, 126, -128, -65, -128, -65, 
	-128, -65, -128, -65, -128, -65, 10, 9, 
	32, 9, 13, 32, 60, 0, 9, 11, 
	12, 14, 127, 9, 13, 32, 33, 37, 
	39, 42, 43, 58, 126, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 9, 
	13, 32, 33, 37, 39, 58, 60, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 9, 13, 32, 58, 60, 9, 
	13, 32, 59, 79, 111, 77, 109, 0
};

static const char _tsip_machine_parser_header_From_single_lengths[] = {
	0, 2, 5, 3, 9, 1, 2, 9, 
	1, 2, 3, 0, 4, 3, 0, 1, 
	4, 4, 1, 2, 3, 9, 1, 2, 
	8, 9, 5, 1, 2, 4, 9, 1, 
	2, 9, 1, 2, 3, 4, 0, 0, 
	0, 0, 0, 1, 2, 0, 8, 1, 
	1, 2, 2, 2, 2, 1, 3, 0, 
	1, 0, 1, 0, 1, 1, 1, 1, 
	1, 1, 1, 3, 3, 2, 2, 2, 
	2, 2, 0, 3, 3, 3, 0, 1, 
	1, 1, 1, 11, 11, 9, 5, 1, 
	2, 4, 9, 1, 2, 9, 8, 7, 
	8, 4, 1, 2, 4, 0, 0, 0, 
	0, 0, 1, 2, 4, 0, 10, 9, 
	5, 0, 4, 2, 2, 0
};

static const char _tsip_machine_parser_header_From_range_lengths[] = {
	0, 0, 0, 0, 6, 0, 0, 6, 
	0, 0, 0, 2, 4, 0, 0, 0, 
	0, 0, 0, 0, 0, 5, 0, 0, 
	5, 5, 0, 0, 0, 0, 5, 0, 
	0, 5, 0, 0, 0, 6, 1, 1, 
	1, 1, 1, 0, 0, 3, 5, 0, 
	3, 3, 3, 3, 0, 3, 3, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	0, 1, 0, 3, 3, 3, 3, 3, 
	3, 0, 3, 3, 3, 3, 1, 1, 
	1, 0, 0, 5, 5, 5, 0, 0, 
	0, 0, 5, 0, 0, 5, 5, 5, 
	5, 0, 0, 0, 6, 1, 1, 1, 
	1, 1, 0, 0, 0, 3, 5, 5, 
	0, 0, 0, 0, 0, 0
};

static const short _tsip_machine_parser_header_From_index_offsets[] = {
	0, 0, 3, 9, 13, 29, 31, 34, 
	50, 52, 55, 59, 62, 71, 75, 76, 
	78, 83, 88, 90, 93, 97, 112, 114, 
	117, 131, 146, 152, 154, 157, 162, 177, 
	179, 182, 197, 199, 202, 206, 217, 219, 
	221, 223, 225, 227, 229, 232, 236, 250, 
	252, 257, 263, 269, 275, 278, 283, 290, 
	292, 295, 297, 300, 302, 305, 308, 310, 
	313, 315, 318, 320, 327, 334, 340, 346, 
	352, 358, 361, 365, 372, 379, 386, 388, 
	391, 394, 396, 398, 415, 432, 447, 453, 
	455, 458, 463, 478, 480, 483, 498, 512, 
	525, 539, 544, 546, 549, 560, 562, 564, 
	566, 568, 570, 572, 575, 580, 584, 600, 
	615, 621, 622, 627, 630, 633
};

static const unsigned char _tsip_machine_parser_header_From_indicies[] = {
	0, 0, 1, 2, 2, 3, 4, 4, 
	1, 2, 2, 3, 1, 5, 6, 5, 
	7, 8, 7, 7, 9, 7, 7, 7, 
	7, 10, 7, 10, 1, 11, 1, 12, 
	12, 1, 13, 14, 13, 7, 8, 7, 
	7, 9, 7, 7, 7, 7, 10, 7, 
	10, 1, 15, 1, 16, 16, 1, 16, 
	16, 17, 1, 18, 18, 1, 19, 19, 
	20, 21, 20, 20, 20, 20, 1, 19, 
	19, 21, 1, 22, 23, 22, 24, 25, 
	24, 26, 1, 24, 27, 24, 26, 1, 
	28, 1, 29, 29, 1, 29, 29, 26, 
	1, 26, 30, 26, 31, 31, 31, 32, 
	32, 31, 31, 31, 31, 31, 31, 1, 
	33, 1, 34, 34, 1, 34, 34, 31, 
	31, 31, 32, 32, 31, 31, 31, 31, 
	31, 31, 1, 35, 25, 35, 31, 31, 
	31, 26, 36, 31, 31, 31, 31, 31, 
	31, 1, 35, 37, 35, 26, 36, 1, 
	38, 1, 39, 39, 1, 39, 39, 26, 
	36, 1, 36, 40, 36, 41, 42, 41, 
	41, 43, 41, 41, 41, 41, 41, 41, 
	1, 44, 1, 45, 45, 1, 45, 46, 
	45, 41, 42, 41, 41, 43, 41, 41, 
	41, 41, 41, 41, 1, 47, 1, 48, 
	48, 1, 48, 48, 42, 1, 42, 54, 
	55, 56, 49, 50, 51, 52, 53, 42, 
	1, 42, 1, 49, 1, 50, 1, 51, 
	1, 52, 1, 57, 1, 42, 42, 1, 
	42, 42, 42, 1, 24, 25, 24, 41, 
	41, 41, 26, 41, 41, 41, 41, 41, 
	41, 1, 58, 1, 60, 59, 59, 59, 
	1, 62, 55, 61, 61, 61, 1, 62, 
	55, 63, 63, 63, 1, 62, 55, 64, 
	64, 64, 1, 62, 55, 1, 66, 65, 
	59, 59, 1, 67, 62, 55, 68, 61, 
	61, 1, 69, 1, 70, 71, 1, 72, 
	1, 73, 74, 1, 75, 1, 55, 76, 
	1, 55, 77, 1, 55, 1, 73, 78, 
	1, 73, 1, 70, 79, 1, 70, 1, 
	67, 62, 55, 80, 63, 63, 1, 67, 
	62, 55, 64, 64, 64, 1, 82, 55, 
	81, 81, 81, 1, 84, 55, 83, 83, 
	83, 1, 84, 55, 85, 85, 85, 1, 
	84, 55, 86, 86, 86, 1, 84, 55, 
	1, 87, 81, 81, 1, 67, 84, 55, 
	88, 83, 83, 1, 67, 84, 55, 89, 
	85, 85, 1, 67, 84, 55, 86, 86, 
	86, 1, 90, 1, 67, 91, 1, 67, 
	92, 1, 67, 1, 66, 1, 35, 25, 
	35, 31, 31, 31, 26, 36, 93, 93, 
	31, 31, 31, 31, 31, 31, 1, 35, 
	25, 35, 31, 31, 31, 26, 36, 94, 
	94, 31, 31, 31, 31, 31, 31, 1, 
	95, 25, 95, 31, 31, 31, 26, 96, 
	31, 31, 31, 31, 31, 31, 1, 95, 
	97, 95, 26, 96, 1, 98, 1, 99, 
	99, 1, 99, 99, 26, 96, 1, 96, 
	100, 96, 101, 42, 101, 101, 43, 101, 
	101, 101, 101, 101, 101, 1, 102, 1, 
	103, 103, 1, 103, 46, 103, 101, 42, 
	101, 101, 43, 101, 101, 101, 101, 101, 
	101, 1, 104, 105, 104, 106, 106, 106, 
	107, 106, 106, 106, 106, 106, 106, 1, 
	108, 109, 108, 110, 110, 110, 110, 110, 
	110, 110, 110, 110, 1, 111, 112, 111, 
	110, 110, 110, 113, 110, 110, 110, 110, 
	110, 110, 1, 114, 115, 114, 17, 1, 
	116, 1, 108, 108, 1, 122, 123, 124, 
	125, 117, 118, 119, 120, 121, 122, 1, 
	122, 1, 117, 1, 118, 1, 119, 1, 
	120, 1, 126, 1, 122, 122, 1, 111, 
	112, 111, 113, 1, 122, 122, 122, 1, 
	127, 109, 127, 110, 110, 110, 110, 128, 
	129, 110, 128, 128, 128, 110, 128, 1, 
	130, 112, 130, 110, 110, 110, 129, 113, 
	110, 110, 110, 110, 110, 110, 1, 131, 
	115, 131, 129, 17, 1, 132, 133, 134, 
	133, 135, 132, 136, 136, 1, 2, 2, 
	1, 1, 0
};

static const char _tsip_machine_parser_header_From_trans_targs[] = {
	2, 0, 3, 4, 115, 4, 5, 95, 
	100, 11, 110, 6, 7, 7, 8, 9, 
	10, 11, 12, 13, 12, 14, 15, 16, 
	17, 47, 21, 18, 19, 20, 22, 25, 
	83, 23, 24, 26, 30, 27, 28, 29, 
	31, 46, 37, 48, 32, 33, 34, 35, 
	36, 38, 39, 40, 41, 42, 43, 16, 
	45, 44, 117, 49, 82, 50, 53, 51, 
	52, 54, 69, 55, 67, 56, 57, 65, 
	58, 59, 63, 60, 61, 62, 64, 66, 
	68, 70, 78, 71, 74, 72, 73, 75, 
	76, 77, 79, 80, 81, 84, 85, 86, 
	90, 87, 88, 89, 91, 94, 92, 93, 
	17, 47, 94, 21, 96, 98, 95, 97, 
	8, 11, 97, 8, 99, 101, 102, 103, 
	104, 105, 100, 106, 108, 109, 107, 111, 
	110, 113, 112, 112, 114, 17, 47, 21, 
	116
};

static const char _tsip_machine_parser_header_From_trans_actions[] = {
	0, 0, 0, 0, 0, 11, 11, 1, 
	1, 11, 1, 0, 0, 11, 11, 0, 
	0, 0, 1, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	7, 7, 0, 7, 0, 0, 0, 5, 
	5, 5, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 0, 0, 3, 3, 3, 
	0
};

static const int tsip_machine_parser_header_From_start = 1;
static const int tsip_machine_parser_header_From_first_final = 117;
static const int tsip_machine_parser_header_From_error = 0;

static const int tsip_machine_parser_header_From_en_main = 1;


/* #line 110 "tsip_parser_header_From.rl" */
	
/* #line 366 "../source/headers/tsip_header_From.c" */
	{
	cs = tsip_machine_parser_header_From_start;
	}

/* #line 111 "tsip_parser_header_From.rl" */
	
/* #line 373 "../source/headers/tsip_header_From.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_From_trans_keys + _tsip_machine_parser_header_From_key_offsets[cs];
	_trans = _tsip_machine_parser_header_From_index_offsets[cs];

	_klen = _tsip_machine_parser_header_From_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_From_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _tsip_machine_parser_header_From_indicies[_trans];
	cs = _tsip_machine_parser_header_From_trans_targs[_trans];

	if ( _tsip_machine_parser_header_From_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_From_actions + _tsip_machine_parser_header_From_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 50 "tsip_parser_header_From.rl" */
	{
		TSK_DEBUG_INFO("FROM:TAG");
		tag_start = p;
	}
	break;
	case 1:
/* #line 56 "tsip_parser_header_From.rl" */
	{
		int len = (int)(p  - tag_start);
		hdr_from->uri = tsip_uri_parse(tag_start, (size_t)len);
		TSK_DEBUG_INFO("FROM:PARSE_URI");
	}
	break;
	case 2:
/* #line 63 "tsip_parser_header_From.rl" */
	{
		int len = (int)(p  - tag_start);
		hdr_from->display_name = tsk_calloc(1, len+1);
		memcpy(hdr_from->display_name, tag_start, len);
		TSK_DEBUG_INFO("FROM:PARSE_DISPLAY_NAME");
	}
	break;
	case 3:
/* #line 71 "tsip_parser_header_From.rl" */
	{
		int len = (int)(p  - tag_start);
		hdr_from->tag = tsk_calloc(1, len+1);
		memcpy(hdr_from->tag, tag_start, len);
		TSK_DEBUG_INFO("FROM:PARSE_TAG");
	}
	break;
	case 4:
/* #line 79 "tsip_parser_header_From.rl" */
	{
		TSK_DEBUG_INFO("FROM:EOB");
	}
	break;
/* #line 486 "../source/headers/tsip_header_From.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 112 "tsip_parser_header_From.rl" */
	
	if( cs < 
/* #line 502 "../source/headers/tsip_header_From.c" */
117
/* #line 113 "tsip_parser_header_From.rl" */
 )
	{
		TSIP_HEADER_FROM_SAFE_FREE(hdr_from);
	}
	
	return hdr_from;
}







//========================================================
//	From header object definition
//

/**@ingroup tsip_header_From_group
*/
static void* tsip_header_From_create(void *self, va_list * app)
{
	tsip_header_From_t *From = self;
	if(From)
	{
		From->type = tsip_htype_From;
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new From header.");
	}
	return self;
}

/**@ingroup tsip_header_From_group
*/
static void* tsip_header_From_destroy(void *self)
{
	tsip_header_From_t *From = self;
	if(From)
	{
		TSK_FREE(From->display_name);
		TSK_FREE(From->tag);

		TSIP_URI_SAFE_FREE(From->uri);
		TSK_LIST_SAFE_FREE(From->params);
	}
	else TSK_DEBUG_ERROR("Null From header.");

	return self;
}

static const tsk_object_def_t tsip_header_From_def_s = 
{
	sizeof(tsip_header_From_t),
	tsip_header_From_create,
	tsip_header_From_destroy,
	0
};
const void *tsip_header_From_def_t = &tsip_header_From_def_s;