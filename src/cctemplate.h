/*
  Part of: CCTemplate
  Contents: public header file
  Date: Thu Mar  1, 2012

  Abstract



  Copyright (C) 2012, 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is  free software: you can redistribute  it and/or modify
  it under the  terms of the GNU General Public  License as published by
  the Free Software Foundation, either  version 3 of the License, or (at
  your option) any later version.

  This program  is distributed in the  hope that it will  be useful, but
  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
  General Public License for more details.

  You  should have received  a copy  of the  GNU General  Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CCTEMPLATE_H
#define CCTEMPLATE_H 1


/** --------------------------------------------------------------------
 ** Preliminary definitions.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* The  macro  CCTEMPLATE_UNUSED  indicates  that a  function,  function
   argument or variable may potentially be unused. Usage examples:

   static int unused_function (char arg) CCTEMPLATE_UNUSED;
   int foo (char unused_argument CCTEMPLATE_UNUSED);
   int unused_variable CCTEMPLATE_UNUSED;
*/
#ifdef __GNUC__
#  define CCTEMPLATE_UNUSED		__attribute__((__unused__))
#else
#  define CCTEMPLATE_UNUSED		/* empty */
#endif

#ifndef __GNUC__
#  define __attribute__(...)	/* empty */
#endif

/* I found  the following chunk on  the Net.  (Marco Maggi;  Sun Feb 26,
   2012) */
#if defined _WIN32 || defined __CYGWIN__
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cctemplate_decl		__attribute__((__dllexport__)) extern
#    else
#      define cctemplate_decl		__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cctemplate_decl		__attribute__((__dllimport__)) extern
#    else
#      define cctemplate_decl		__declspec(dllimport) extern
#    endif
#  endif
#  define cctemplate_private_decl	extern
#else
#  if __GNUC__ >= 4
#    define cctemplate_decl		__attribute__((__visibility__("default"))) extern
#    define cctemplate_private_decl	__attribute__((__visibility__("hidden")))  extern
#  else
#    define cctemplate_decl		extern
#    define cctemplate_private_decl	extern
#  endif
#endif


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#if 0

/* Enable everything GNU. */
#define _GNU_SOURCE		1

/* Enable latest POSIX features. */
#define _POSIX_C_SOURCE		200809L

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h> /* for offsetof() */
#include <setjmp.h>
#include <errno.h>
#include <unistd.h>

#endif


/** --------------------------------------------------------------------
 ** Constants and preprocessor macros.
 ** ----------------------------------------------------------------- */

#define CCTEMPLATE_PC(POINTER_TYPE, POINTER_NAME, EXPRESSION)	\
  POINTER_TYPE * POINTER_NAME = (POINTER_TYPE *) (EXPRESSION)


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cctemplate_decl const char *	cct_version_string		(void);
cctemplate_decl int		cct_version_interface_current	(void);
cctemplate_decl int		cct_version_interface_revision	(void);
cctemplate_decl int		cct_version_interface_age	(void);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTEMPLATE_H */

/* end of file */
