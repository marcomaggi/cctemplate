/*
  Part of: CCTemplate
  Contents: tests for condition objects
  Date: May 12, 2018

  Abstract

	Test file for condition objects.

  Copyright (C) 2018 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/


/** --------------------------------------------------------------------
 ** Heaaders.
 ** ----------------------------------------------------------------- */

#include "cctemplate.h"
#include <cctests.h>
#include <stdio.h>
#include <stdlib.h>
#include "condition-subtyping-some-error-header.h"


/** --------------------------------------------------------------------
 ** Testing condition objects.
 ** ----------------------------------------------------------------- */

void
test_1_1 (cce_destination_t upper_L)
/* Test for "cct_condition_some_error_t". */
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    cce_location_t	inner_L[1];

    if (1) { fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L))); }

    if (cce_location(inner_L)) {
      cce_run_body_handlers_final(L);
      cce_run_body_handlers_raise(inner_L, upper_L);
    } else {
      cctests_assert(inner_L, cct_condition_is_some_error(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCTemplate some error condition\n", __func__); }

      cctests_assert(inner_L, cce_condition_is_runtime_error(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCExceptions runtime error condition\n", __func__); }

      cctests_assert(inner_L, cce_condition_is_root(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCExceptions root condition\n", __func__); }

      cce_run_body_handlers_final(L);
      cce_run_body_handlers_final(inner_L);
    }
  } else {
    cce_raise(L, cct_condition_new_some_error());
  }
}


/** --------------------------------------------------------------------
 ** Subtyping tests.
 ** ----------------------------------------------------------------- */

void
test_2_1 (cce_destination_t upper_L)
/* Subtyping of "cct_condition_some_error_t". */
{
  cce_location_t	L[1];

  if (cce_location(L)) {
    cce_location_t	inner_L[1];

    if (1) { fprintf(stderr, "%s: static message: %s\n", __func__, cce_condition_static_message(cce_condition(L))); }

    if (cce_location(inner_L)) {
      cce_run_body_handlers_final(L);
      cce_run_body_handlers_raise(inner_L, upper_L);
    } else {
      cctests_assert(inner_L, my_condition_is_some_error_subtype(cce_condition(L)));
      if (1) {
	CCE_PC(my_condition_some_error_subtype_t, C, cce_condition(L));
	fprintf(stderr, "%s: is a subtype of CCTemplate some error, data=%d\n", __func__, *(C->data));
      }

      cctests_assert(inner_L, cct_condition_is_some_error(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCTemplate some error condition\n", __func__); }

      cctests_assert(inner_L, cce_condition_is_runtime_error(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCExceptions runtime error condition\n", __func__); }

      cctests_assert(inner_L, cce_condition_is_root(cce_condition(L)));
      if (1) { fprintf(stderr, "%s: is a CCExceptions root condition\n", __func__); }

      cce_run_body_handlers_final(L);
      cce_run_body_handlers_final(inner_L);
    }
  } else {
    cce_raise(L, my_condition_new_some_error_subtype(L, 123));
  }
}


int
main (void)
{
  cct_library_init();
  my_error_subtyping_init_module();

  cctests_init("tests for condition objects subtyping");
  {
    cctests_begin_group("condition objects");
    {
      cctests_run(test_1_1);
    }
    cctests_end_group();

    cctests_begin_group("subtyping of condition objects");
    {
      cctests_run(test_2_1);
    }
    cctests_end_group();
  }
  cctests_final();
}

/* end of file */
