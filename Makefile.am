## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
SUBDIRS			= src doc tests
EXTRA_DIST		= \
	INSTALL					\
	meta/scripts/cctemplate-config.in	\
	meta/scripts/cctemplate.pc.in
dist_doc_DATA		= README COPYING

bin_SCRIPTS		= meta/scripts/cctemplate-config
pkgconfigdir		= $(libdir)/pkgconfig
nodist_pkgconfig_DATA	= meta/scripts/cctemplate.pc

### end of file
