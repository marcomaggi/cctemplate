/*
  Part of: CCTemplate
  Contents: test for version functions
  Date: Thu Mar  1, 2012

  Abstract

	Test file for version functions.

  Copyright (C) 2012 Marco Maggi <marco.maggi-ipsu@poste.it>

  See the COPYING file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <cctemplate.h>

int
main (int argc, const char *const argv[])
{
  printf("version number string: %s\n", cct_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cct_version_interface_current(),
	 cct_version_interface_revision(),
	 cct_version_interface_age());
  exit(EXIT_SUCCESS);
}

/* end of file */
