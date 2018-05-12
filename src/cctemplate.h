/*
  Part of: CCTemplate
  Contents: public header file
  Date: Thu Mar  1, 2012

  Abstract



  Copyright (C) 2012, 2017, 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

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

/* The  macro  CCT_UNUSED  indicates  that a  function,  function
   argument or variable may potentially be unused. Usage examples:

   static int unused_function (char arg) CCT_UNUSED;
   int foo (char unused_argument CCT_UNUSED);
   int unused_variable CCT_UNUSED;
*/
#ifdef __GNUC__
#  define CCT_UNUSED		__attribute__((__unused__))
#else
#  define CCT_UNUSED		/* empty */
#endif

#ifndef __GNUC__
#  define __attribute__(...)	/* empty */
#endif

/* I found  the following chunk on  the Net.  (Marco Maggi;  Sun Feb 26,
   2012) */
#if defined _WIN32 || defined __CYGWIN__
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cct_decl		__attribute__((__dllexport__)) extern
#    else
#      define cct_decl		__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cct_decl		__attribute__((__dllimport__)) extern
#    else
#      define cct_decl		__declspec(dllimport) extern
#    endif
#  endif
#  define cct_private_decl	extern
#else
#  if __GNUC__ >= 4
#    define cct_decl		__attribute__((__visibility__("default"))) extern
#    define cct_private_decl	__attribute__((__visibility__("hidden")))  extern
#  else
#    define cct_decl		extern
#    define cct_private_decl	extern
#  endif
#endif


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <ccexceptions.h>

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

#define CCT_PC(POINTER_TYPE, POINTER_NAME, EXPRESSION)	\
  POINTER_TYPE * POINTER_NAME = (POINTER_TYPE *) (EXPRESSION)


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cct_decl char const *	cct_version_string		(void);
cct_decl int		cct_version_interface_current	(void);
cct_decl int		cct_version_interface_revision	(void);
cct_decl int		cct_version_interface_age	(void);


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

cct_decl void cct_library_init (void)
  __attribute__((__constructor__));


/** --------------------------------------------------------------------
 ** Condition objects: error.
 ** ----------------------------------------------------------------- */

typedef struct cct_descriptor_some_error_t	cct_descriptor_some_error_t;
typedef struct cct_condition_some_error_t	cct_condition_some_error_t;

struct cct_descriptor_some_error_t {
  cce_descriptor_t			descriptor;
};

struct cct_condition_some_error_t {
  cce_condition_runtime_error_t		runtime_error;
};

cct_decl cct_descriptor_some_error_t const * const cct_descriptor_some_error_ptr;

cct_decl void cct_condition_init_some_error (cct_condition_some_error_t * C)
  __attribute__((__nonnull__(1)));

cct_decl cce_condition_t const * cct_condition_new_some_error (void)
  __attribute__((__returns_nonnull__));

cct_decl bool cct_condition_is_some_error (cce_condition_t const * C)
  __attribute__((__nonnull__(1)));


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTEMPLATE_H */

/* end of file */
