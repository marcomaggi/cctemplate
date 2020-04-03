/*
  Part of: CCTemplate
  Contents: public header file
  Date: Thu Mar  1, 2012

  Abstract

	This is the public  header file of the library, defining  the public API.  It
	must be included in all the code that uses the library.

  Copyright (C) 2012, 2017-2020 Marco Maggi <mrc.mgg@gmail.com>

  This program is free  software: you can redistribute it and/or  modify it under the
  terms of the  GNU Lesser General Public  License as published by  the Free Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  This program  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CCTEMPLATE_H
#define CCTEMPLATE_H 1

#ifdef __cplusplus
extern "C" {
#endif


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include <ccexceptions.h>
#include <ccmemory.h>
#include <ccstructs.h>
#include <ccstrings.h>

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



/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cclib_decl char const *	cct_version_string		(void);
cclib_decl int		cct_version_interface_current	(void);
cclib_decl int		cct_version_interface_revision	(void);
cclib_decl int		cct_version_interface_age	(void);


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

cclib_decl void cct_library_init (void)
  CCLIB_FUNC_ATTRIBUTE_CONSTRUCTOR;


/** --------------------------------------------------------------------
 ** Condition objects: error.
 ** ----------------------------------------------------------------- */

typedef struct cct_descriptor_some_error_t	cct_descriptor_some_error_t;
typedef struct cct_condition_some_error_t	cct_condition_some_error_t;

struct cct_descriptor_some_error_t {
  cce_descriptor_t	descriptor;
};

struct cct_condition_some_error_t {
  cce_condition_runtime_error_t	runtime_error;
  int *				data;
};

cclib_decl void cce_descriptor_set_parent_to(cct_descriptor_some_error_t) (cce_descriptor_t * D)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void cct_condition_init_some_error (cce_destination_t L, cct_condition_some_error_t * C, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl cce_condition_t const * cct_condition_new_some_error (cce_destination_t L, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1)
  CCLIB_FUNC_ATTRIBUTE_RETURNS_NONNULL;

cclib_decl bool cct_condition_is_some_error (cce_condition_t const * C)
  CCLIB_FUNC_ATTRIBUTE_PURE
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);



/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCTEMPLATE_H */

/* end of file */
