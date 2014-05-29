## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL meta/scripts/cctemplate.pc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= -Wall

## --------------------------------------------------------------------

pkgconfigdir		= $(libdir)/pkgconfig
nodist_pkgconfig_DATA	= meta/scripts/cctemplate.pc

## --------------------------------------------------------------------

AM_MAKEINFOFLAGS	= --no-split

info_TEXINFOS		= doc/cctemplate.texi
doc_cctemplate_TEXINFOS	= \
	doc/macros.texi		\
	doc/gpl-3.0.texi	\
	doc/fdl-1.3.texi

#page
#### libraries

cctemplate_CURRENT	= @cctemplate_VERSION_INTERFACE_CURRENT@
cctemplate_REVISION	= @cctemplate_VERSION_INTERFACE_REVISION@
cctemplate_AGE		= @cctemplate_VERSION_INTERFACE_AGE@

include_HEADERS		= src/cctemplate.h

lib_LTLIBRARIES		= libcctemplate.la
libcctemplate_la_LDFLAGS= -version-info $(cctemplate_CURRENT):$(cctemplate_REVISION):$(cctemplate_AGE)
libcctemplate_la_SOURCES= src/cctemplate-version.c

#page
#### tests

check_PROGRAMS	= \
	tests/version

cctemplate_tests_cppflags	= -I$(top_srcdir)/src
cctemplate_tests_ldadd		= libcctemplate.la

tests_version_CPPFLAGS		= $(cctemplate_tests_cppflags)
tests_version_LDADD		= $(cctemplate_tests_ldadd)

TESTS		= $(check_PROGRAMS)

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done

### end of file
