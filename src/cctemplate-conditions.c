/*
  Part of: CCTemplate
  Contents: definition of condition objects
  Date: May 12, 2018

  Abstract



  Copyright (C) 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  This program is  free software: you can redistribute  it and/or modify
  it under the  terms of the GNU General Public  License as published by
  the Free Software Foundation, either version  3 of the License, or (at
  your option) any later version.

  This program  is distributed in the  hope that it will  be useful, but
  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See the  GNU
  General Public License for more details.

  You should  have received  a copy  of the  GNU General  Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "cctemplate-internals.h"


/** --------------------------------------------------------------------
 ** Condition objects: error.
 ** ----------------------------------------------------------------- */

static cce_condition_static_message_fun_t	cct_condition_static_message_some_error;

static cct_descriptor_some_error_t cct_descriptor_some_error_stru = {
  /* This  "parent" field  is  set below  by  the module  initialisation
     function. */
  .descriptor.parent		= NULL,
  .descriptor.delete		= NULL,
  .descriptor.final		= NULL,
  .descriptor.static_message	= cct_condition_static_message_some_error
};

cct_descriptor_some_error_t const * const cct_descriptor_some_error_ptr = &cct_descriptor_some_error_stru;

static cct_condition_some_error_t const cct_condition_some_error_stru = {
  .runtime_error.error.root.condition.descriptor = &(cct_descriptor_some_error_stru.descriptor)
};

cct_condition_some_error_t const * const cct_condition_some_error_ptr = &cct_condition_some_error_stru;

/* ------------------------------------------------------------------ */

char const *
cct_condition_static_message_some_error (cce_condition_t const * C CCT_UNUSED)
{
  return "error";
}

/* ------------------------------------------------------------------ */

void
cct_condition_init_some_error (cct_condition_some_error_t * C)
{
  cce_condition_init_runtime_error(&(C->runtime_error));
}

cce_condition_t const *
cct_condition_new_some_error (void)
{
  return (cce_condition_t const *) cct_condition_some_error_ptr;
}

bool
cct_condition_is_some_error (cce_condition_t const * C)
{
  return cce_condition_is(C, &(cct_descriptor_some_error_ptr->descriptor));
}


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
cct_condition_init_module (void)
{
  cct_descriptor_some_error_stru.descriptor.parent	= &(cce_descriptor_runtime_error_ptr->descriptor);
}

/* end of file */
