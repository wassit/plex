// -*- c-basic-offset: 8; indent-tabs-mode: t -*-
// vim:ts=8:sw=8:noet:ai:
/*
 * Copyright (C) 2006 Evgeniy Stepanov <eugeni.stepanov@gmail.com>
 *
 * This file is part of libass.
 *
 * libass is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * libass is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with libass; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef LIBASS_LIBRARY_H
#define LIBASS_LIBRARY_H

#include "ass_cache.h"

typedef struct ass_fontdata_s {
	char* name;
	char* data;
	int size;
} ass_fontdata_t;

struct ass_library_s {
	char* fonts_dir;
	int extract_fonts;
	char** style_overrides;

	ass_fontdata_t* fontdata;
	int num_fontdata;
	ass_font_cache_t* font_cache;
};

#endif /* LIBASS_LIBRARY_H */
