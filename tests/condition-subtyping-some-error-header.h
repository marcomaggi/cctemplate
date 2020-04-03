/*
  Part of: CCTemplate
  Contents: header definitions for subtyping of "some error" conditions
  Date: May 12, 2018

  Abstract

	Header definitions for subtyping of "some error" conditions.

  Copyright (C) 2018, 2019, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#ifndef CONDITION_SUBTYPING_SOME_ERROR_HEADER_H
#define CONDITION_SUBTYPING_SOME_ERROR_HEADER_H 1


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include "cctemplate.h"
#include <stdio.h>
#include <stdlib.h>


/** --------------------------------------------------------------------
 ** Header definitions.
 ** ----------------------------------------------------------------- */

typedef struct my_descriptor_some_error_subtype_t	my_descriptor_some_error_subtype_t;
typedef struct my_condition_some_error_subtype_t	my_condition_some_error_subtype_t;

struct my_descriptor_some_error_subtype_t {
  cce_descriptor_t	descriptor;
};

struct my_condition_some_error_subtype_t {
  cct_condition_some_error_t	some_error;
  int *				data;
};

cclib_decl void cce_descriptor_set_parent_to(my_descriptor_some_error_subtype_t) (cce_descriptor_t * const D)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

/* ------------------------------------------------------------------ */

cclib_decl void my_condition_init_some_error_subtype (cce_destination_t L, my_condition_some_error_subtype_t * C, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl cce_condition_t const * my_condition_new_some_error_subtype (cce_destination_t L, int the_data)
  CCLIB_FUNC_ATTRIBUTE_NONNULL(1);

cclib_decl bool my_condition_is_some_error_subtype (cce_condition_t const * C)
  CCLIB_FUNC_ATTRIBUTE_PURE;

/* ------------------------------------------------------------------ */

cclib_decl void my_error_subtyping_init_module (void);


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#endif /* CONDITION_SUBTYPING_SOME_ERROR_HEADER_H */

/* end of file */
