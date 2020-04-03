/*
  Part of: CCTemplate
  Contents: test for version functions
  Date: Thu Mar  1, 2012

  Abstract

	Test file for version functions.

  Copyright (C) 2012, 2017, 2018, 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#include <cctemplate.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc CCLIB_UNUSED, char const * const argv[] CCLIB_UNUSED)
{
  cct_library_init();

  printf("version number string: %s\n", cct_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cct_version_interface_current(),
	 cct_version_interface_revision(),
	 cct_version_interface_age());
  exit(EXIT_SUCCESS);
}

/* end of file */
