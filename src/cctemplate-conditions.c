/*
  Part of: CCTemplate
  Contents: definition of condition objects
  Date: May 12, 2018

  Abstract

	This module defines the exceptional-condition object-types for this library.

  Copyright (C) 2018, 2019 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is free  software: you can redistribute it and/or  modify it under the
  terms of the  GNU Lesser General Public  License as published by  the Free Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  This program  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctemplate-internals.h"


/** --------------------------------------------------------------------
 ** Condition objects: error.
 ** ----------------------------------------------------------------- */

static cce_condition_delete_fun_t		cct_condition_delete_some_error;
static cce_condition_final_fun_t		cct_condition_final_some_error;
static cce_condition_static_message_fun_t	cct_condition_static_message_some_error;

static cct_descriptor_some_error_t cct_descriptor_some_error = {
  /* This "parent" field is set below by the module initialisation function. */
  .descriptor.parent		= NULL,
  .descriptor.delete		= cct_condition_delete_some_error,
  .descriptor.final		= cct_condition_final_some_error,
  .descriptor.static_message	= cct_condition_static_message_some_error
};

void
cce_descriptor_set_parent_to(cct_descriptor_some_error_t) (cce_descriptor_t * const D)
{
  D->parent = cce_descriptor_pointer(cct_descriptor_some_error);
}

/* ------------------------------------------------------------------ */

void
cct_condition_final_some_error (cce_condition_t * _C)
/* Finalisation   functions    are   called    automatically   when    the   function
   "cce_condition_final()" is applied  to the argument C.  Here we  finalise only the
   fields of this type leaving untouched the fields of the parent type. */
{
  cct_condition_some_error_t * C = (cct_condition_some_error_t *) _C;
  *(C->data) = 0;
  if (1) { fprintf(stderr, "%s: finalising %p\n", __func__, (void*)C); }
  free(C->data);
}

void
cct_condition_delete_some_error (cce_condition_t * _C)
/* The  delete  function  is  called  automatically  when  the  client  code  applies
   "cce_condition_delete()" to the argument C.   Here we release memory allocated for
   the condition object. */
{
  cct_condition_some_error_t * C = (cct_condition_some_error_t *) _C;

  if (1) { fprintf(stderr, "%s: deleting %p\n", __func__, (void*)C); }
  free(C);
}

char const *
cct_condition_static_message_some_error (cce_condition_t const * C CCE_UNUSED)
{
  return "Error-1 exceptional condition";
}

/* ------------------------------------------------------------------ */

void
cct_condition_init_some_error (cce_destination_t L, cct_condition_some_error_t * C, int the_data)
/* This initialisation function must be called both by:
 *
 * - The constructor function of this object type.
 *
 * - The initialisation functions of object types derived from this type.
 *
 * Here we call  the parent's initialisation function; then we  initialise the fields
 * of this type.
 */
{
  cce_condition_init_runtime_error(&(C->runtime_error));
  C->data = cce_sys_malloc(L, sizeof(int));
  *(C->data) = the_data;
  if (1) { fprintf(stderr, "%s: initialised %p\n", __func__, (void*)C); }
}

cce_condition_t const *
cct_condition_new_some_error (cce_destination_t upper_L, int the_data)
/* This constructor function is the public  interface to the constructor of condition
 * objects of type "cct_condition_some_error_t".
 *
 * Here we:
 *
 * 1. Allocate memory for the condition object itself.
 *
 * 2. Initialise the descriptor field by calling "cce_condition_init()".
 *
 * 3. Call the initialisation function for this type.
 */
{
  cce_location_t	L[1];
  cce_error_handler_t	C_H[1];

  if (cce_location(L)) {
    cce_run_catch_handlers_raise(L, upper_L);
  } else {
    cct_condition_some_error_t * C = cce_sys_malloc_guarded(L, C_H, sizeof(cct_condition_some_error_t));

    cce_condition_init((cce_condition_t *) C, cce_descriptor_pointer(cct_descriptor_some_error));
    cct_condition_init_some_error(L, C, the_data);

    cce_run_body_handlers(L);
    if (1) { fprintf(stderr, "%s: constructed %p\n", __func__, (void*)C); }
    return (cce_condition_t const *) C;
  }
}

/* ------------------------------------------------------------------ */

bool
cct_condition_is_some_error (cce_condition_t const * C)
{
  return cce_condition_is(C, cce_descriptor_pointer(cct_descriptor_some_error));
}


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
cct_condition_init_module (void)
{
  cce_descriptor_set_parent_to(cce_descriptor_runtime_error_t)(cce_descriptor_pointer(cct_descriptor_some_error));
}

/* end of file */
