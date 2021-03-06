/*
 * Copyright (c) 2016 Dmitry Osipenko <digetx@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "syntax_parse.h"

#include "common.h"

void parse_annex_b(decoder_context *decoder)
{
	bitstream_reader *reader = &decoder->reader;

	decoder->NAL_start_delim = 1;

	do {
		if (!seek_to_NAL_start(reader)) {
			break;
		}

		SYNTAX_IPRINT("+++++++++++++++\n");

		parse_NAL(decoder);

		SYNTAX_IPRINT("---------------\n\n");
	} while (!reader->error);
}
