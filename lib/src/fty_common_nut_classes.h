/*  =========================================================================
    fty_common_nut_classes - private header file

    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef FTY_COMMON_NUT_CLASSES_H_INCLUDED
#define FTY_COMMON_NUT_CLASSES_H_INCLUDED

//  External API
#include "../public_include/fty_common_nut.h"

//  Internal API
#include "fty_common_nut_utils_private.h"

//  Classes Selftests
void fty_common_nut_parse_test(bool verbose);
void fty_common_nut_convert_test(bool verbose);

#endif