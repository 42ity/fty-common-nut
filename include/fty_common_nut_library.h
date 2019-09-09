/*  =========================================================================
    fty-common-nut - generated layer of public API

    Copyright (C) 2014 - 2018 Eaton

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

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#ifndef FTY_COMMON_NUT_LIBRARY_H_INCLUDED
#define FTY_COMMON_NUT_LIBRARY_H_INCLUDED

//  Set up environment for the application

//  External dependencies
#include <czmq.h>
#include <malamute.h>
#include <cxxtools/allocator.h>
#include <fty_log.h>
#include <fty_common_mlm.h>
#include <ftyproto.h>
#include <openssl/sha.h>
#include <fty_common_socket.h>
#include <fty_security_wallet.h>

//  FTY_COMMON_NUT version macros for compile-time API detection
#define FTY_COMMON_NUT_VERSION_MAJOR 1
#define FTY_COMMON_NUT_VERSION_MINOR 0
#define FTY_COMMON_NUT_VERSION_PATCH 0

#define FTY_COMMON_NUT_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define FTY_COMMON_NUT_VERSION \
    FTY_COMMON_NUT_MAKE_VERSION(FTY_COMMON_NUT_VERSION_MAJOR, FTY_COMMON_NUT_VERSION_MINOR, FTY_COMMON_NUT_VERSION_PATCH)

#if defined (__WINDOWS__)
#   if defined FTY_COMMON_NUT_STATIC
#       define FTY_COMMON_NUT_EXPORT
#   elif defined FTY_COMMON_NUT_INTERNAL_BUILD
#       if defined DLL_EXPORT
#           define FTY_COMMON_NUT_EXPORT __declspec(dllexport)
#       else
#           define FTY_COMMON_NUT_EXPORT
#       endif
#   elif defined FTY_COMMON_NUT_EXPORTS
#       define FTY_COMMON_NUT_EXPORT __declspec(dllexport)
#   else
#       define FTY_COMMON_NUT_EXPORT __declspec(dllimport)
#   endif
#   define FTY_COMMON_NUT_PRIVATE
#elif defined (__CYGWIN__)
#   define FTY_COMMON_NUT_EXPORT
#   define FTY_COMMON_NUT_PRIVATE
#else
#   if (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define FTY_COMMON_NUT_PRIVATE __attribute__ ((visibility ("hidden")))
#       define FTY_COMMON_NUT_EXPORT __attribute__ ((visibility ("default")))
#   else
#       define FTY_COMMON_NUT_PRIVATE
#       define FTY_COMMON_NUT_EXPORT
#   endif
#endif

//  Opaque class structures to allow forward references
//  These classes are stable or legacy and built in all releases
typedef struct _fty_common_nut_credentials_t fty_common_nut_credentials_t;
#define FTY_COMMON_NUT_CREDENTIALS_T_DEFINED
typedef struct _fty_common_nut_convert_t fty_common_nut_convert_t;
#define FTY_COMMON_NUT_CONVERT_T_DEFINED
typedef struct _fty_common_nut_dump_t fty_common_nut_dump_t;
#define FTY_COMMON_NUT_DUMP_T_DEFINED
typedef struct _fty_common_nut_parse_t fty_common_nut_parse_t;
#define FTY_COMMON_NUT_PARSE_T_DEFINED
typedef struct _fty_common_nut_scan_t fty_common_nut_scan_t;
#define FTY_COMMON_NUT_SCAN_T_DEFINED
typedef struct _fty_common_nut_utils_t fty_common_nut_utils_t;
#define FTY_COMMON_NUT_UTILS_T_DEFINED


//  Public classes, each with its own header file
#include "fty_common_nut_credentials.h"
#include "fty_common_nut_convert.h"
#include "fty_common_nut_dump.h"
#include "fty_common_nut_parse.h"
#include "fty_common_nut_scan.h"
#include "fty_common_nut_utils.h"

#ifdef FTY_COMMON_NUT_BUILD_DRAFT_API

#ifdef __cplusplus
extern "C" {
#endif

//  Self test for private classes
FTY_COMMON_NUT_EXPORT void
    fty_common_nut_private_selftest (bool verbose, const char *subtest);

#ifdef __cplusplus
}
#endif
#endif // FTY_COMMON_NUT_BUILD_DRAFT_API

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
